# Unity知识点
## 1.线程安全的对象池模式
主要用于高效管理可重用对象的创建、获取和回收，避免频繁的内存分配与释放开销，尤其适用于多线程环境。
```c#
public interface IPoolObject
{
    void OnReset(); // 提供接口，用于重写
}
// new()约束：表示<T>必须可以通过 new T() 的方式实例化,就是模板需要有无参构造函数
public class ObjectPool<T> where T : IPoolObject，new()
{
    private Stack<T> m_CacheObjects = new Stack<T>(); // 用于维护的一个栈对象池
    private int m_CacheSize = 0; // 用于控制栈的最大长度

    public SafeObjectPool(int init = 0, int cache_size = 16)
    {
        int n = Mathf.Min(init, cache_size); // 取最小值
        // 初始化时创建 init 个对象（不超过 cache_size）
        for (int i=0; i<n; ++i)
        {
            T t = new T();
            t.OnReset();
            m_CacheObjects.Push(t);
        }
        this.m_CacheSize = cache_size;
    }

    public T Take()
    {
        T obj = default(T); // 将一个泛型类型变量 obj 初始化为其类型的默认值，若T是class类型，则返回null
        lock (m_CacheObjects)
        {
            if (m_CacheObjects.Count > 0)
            {
                obj = m_CacheObjects.Pop(); // 出栈
            }
        }
        if (obj == null)
        {
            obj = new T();
        }
        return obj;
    }

    public bool Put(T obj)
    {
        lock (m_CacheObjects)
        {
            if (m_CacheObjects.Count >= m_CacheSize)
            {
                return false;
            }
            obj.OnReset();
            m_CacheObjects.Push(obj);
        }
        return true;
    }
    public void Clear()
    {
        lock(m_CacheObjects)
        {
            m_CacheObjects.Clear();
        }
    }
}
// 使用示例
// 定义一个信号数据，用线程池管理
public class SignalData : IPoolObject // 使用线程池接口
{
    public SignalKey key; // 信号键值
    public object data; // 信号数据

    public void OnReset() // 重写线程池接口
    {
        data = null;
    }

    public static SafeObjectPool<SignalData> Pool = new SafeObjectPool<SignalData>(8, 32); // 创建静态变量信号数据线程池，创建8个初始对象，最大池的长度32
}
```
## 2.插值的应用
时间插值（线性插值）的工具类，其核心作用是根据时间推移计算一个从 0 到 1 的平滑过渡比例值（百分比），适用于动画、渐变效果或任何需要随时间平滑变化的场景。
```csharp
public class Interpolation
{
    public Interpolation(float t, bool start = false)
    {
        time = t; // 设置过渡时间
        m_count = start ? 0 : time; // 初始化计数器：start=true 表示立即开始插值，否则直接结束
    }

    // 更新插值进度，参数：时间增量
    public float Update(float dt)
    {
        // 是否完成
        if (isEnd)
        {
            return 1;
        }

        m_count += dt; // 累加时间增量
        return Mathf.Min(1, m_count / time); // 返回百分比进度
    }

    // 停止插值
    public void Stop()
    {
        m_count = time;
    }

    // 重置插值时间
    public void Reset()
    {
        m_count = 0;
    }

    public float time { get; set; } = 0;

    public float percent { get { return Mathf.Min(1, m_count / time); } }

    public bool isEnd { get { return m_count >= time; } }

    private float m_count = 0;
}
// 使用实例插值
public static void Lerp(LineStyle a, LineStyle b, float t, LineStyle to)
{
    // t是插值比例
    to.color = Color.Lerp(a.color, b.color, t);
    to.lineWidth = Mathf.Lerp(a.lineWidth, b.lineWidth, t);
    to.midSpace = Mathf.Lerp(a.midSpace, b.midSpace, t);
    to.leftDot = Mathf.Lerp(a.leftDot, b.leftDot, t);
    to.rightDot = Mathf.Lerp(a.rightDot, b.rightDot, t);
    to.yuguWidth = Mathf.Lerp(a.yuguWidth, b.yuguWidth, t);
    to.yuguClip = Mathf.Lerp(a.yuguClip, b.yuguClip, t);
    to._V_Scale = b._V_Scale;
    to._UseRoadhandrailTexture = b._UseRoadhandrailTexture;
}
```
## 3.Unity中物体对象池管理
更好的管理对象的内存。高效管理游戏对象的创建、复用和回收，减少频繁实例化（Instantiate）和销毁（Destroy）带来的性能开销
```csharp
// 统一管理多个对象池（GameObjectPool），通过名称（poolName）快速获取或创建池。
public class GameObjectPoolMgr
{
    private static Dictionary<string, GameObjectPool> pools = new Dictionary<string, GameObjectPool>(); // 对象池字典，存储多个对象池。以对象池名字作为索引

    // 静态方法：获取或创建对象池
    public static GameObjectPool GetOrCreatePool(string poolName, GameObject poolObjectPrefab, int initCount, int maxSize, Transform root, bool needRecycle = false)
    {
        if (pools.TryGetValue(poolName, out var gameObjectPool))
        {
            // 字典存在该对象池时，直接返回对应的对象池
            return gameObjectPool;
        }
        else
        {
            // 无对应的对象池，则直接创建新的
            GameObjectPool pool = new GameObjectPool(poolName,      poolObjectPrefab, initCount, maxSize, root, needRecycle);
            pools.Add(poolName, pool); // 存到字典中
            return pool;
        }
    }

    // 获取对象池
    public static GameObjectPool GetPool(string poolName)
    {
        if(pools.TryGetValue(poolName,out var gameObjectPool))
        {
            return gameObjectPool;
        }
        else
        {
            return null;
        }
    }
    // Try方法获取对象池，返回bool值
    public static bool TryGetPool(string poolName,out GameObjectPool pool)
    {
        if (pools.TryGetValue(poolName, out  pool))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
// 池配置信息类
public class PoolInfo
{
    public string poolName; // 对象池名称
    public GameObject prefab; // 对象池的预制体
    public int poolSize; // 对象池大小
    public bool fixedSize; // 是否固定大小
}

// 游戏对象池类
public class GameObjectPool
{
    private int maxSize; // 最大对象池大小
    private int poolSize; // 当前对象池大小
    private string poolName; // 对象池名称
    private Transform poolRoot; // 对象池的根节点
    private GameObject poolObjectPrefab; // 对象池的预制体
    public Stack<GameObject> availableObjStack = new Stack<GameObject>(); // 可用游戏对象的栈

    // 构造方法
    public GameObjectPool(string poolName, GameObject poolObjectPrefab, int initCount, int maxSize, Transform parent, bool needRecycle = false)
    {
        this.poolName = poolName;
        this.poolSize = initCount;
        this.maxSize = maxSize;
        this.poolRoot = parent;
        this.poolObjectPrefab = poolObjectPrefab;
        //GameObject.Instantiate(poolObjectPrefab);
        //this.poolObjectPrefab.SetActive(false);
    
        //this.poolObjectPrefab.transform.SetParent(poolRoot, false);
        //populate the pool
        for (int index = 0; index < initCount; index++)
        {
            // 添加对象到池中
            AddObjectToPool(NewObjectInstance(), needRecycle);
        }
    }

    // 创建游戏对象实例
    private GameObject NewObjectInstance()
    {
        GameObject go = GameObject.Instantiate(poolObjectPrefab);
        go.transform.SetParent(poolRoot);
        return  go;
    }


    // 对象回收到池中
    private void AddObjectToPool(GameObject go, bool needRecycle = false)
    {
        //add to pool
        if (needRecycle)
        {
            //go.AddComponent<ResName>().resName = this.poolName;
        }
        go.SetActive(false);
        // 判断可以对象的栈是否大于最大限制
        if (availableObjStack.Count < maxSize)
        {
            availableObjStack.Push(go); // 入栈
            go.transform.SetParent(poolRoot, false); // 为当前的对象设置父节点
            go.transform.localPosition = new Vector3(0, 0, 1000); // 位置
        }
        else
        {
            //Debug.LogWarningFormat("Pool full - destroy {0}", go.name);
            GameObject.Destroy(go); // 超出栈的限制，直接销毁
        }
    }   

    // 从对象池可用对象的栈获取一个对象，设置为可激活状态
    public GameObject GetVisibleObj()
    {
        GameObject go = null;
        if (availableObjStack.Count > 0)
        {
            go = availableObjStack.Pop();
        }
        else
        {
            go = NewObjectInstance();
            //Debug.LogWarning("No object available & cannot grow pool: " +     poolName);
        }
        go.SetActive(true);
        go.transform.localPosition = new Vector3(0, 0, 0);
        return go;
    }

    // 从对象池可用对象的栈获取一个对象，设置为非激活状态
    public GameObject GetUnVisibleObj()
    {
        GameObject go = null;
        if (availableObjStack.Count > 0)
        {
            go = availableObjStack.Pop();
        }
        else
        {
            go = NewObjectInstance();

            //Debug.LogWarning("No object available & cannot grow pool: " +     poolName);
        }
        go.SetActive(false);
        go.transform.localPosition = new Vector3(0, 0, 0);
        return go;
    }
    // 根据对象池名称把对象回收到池中
    public void ReturnObjectToPool(string pool, GameObject po)
    {
        if (poolName.Equals(pool))
        {
            AddObjectToPool(po);
        }
        else
        {
            MyDebugger.LogErrorFormat("Trying to add object to incorrect pool   {0} ", poolName);
        }
    }

    // 销毁对象池
    public void Release()
    {
        if (availableObjStack.Count > 0)
        {
            int cnt = availableObjStack.Count;
            for (int i = 0; i < cnt; ++i)
            {
                GameObject.Destroy(availableObjStack.Pop());
            }
        }
        availableObjStack.Clear();
        poolObjectPrefab = null;
    }
}
```
## 4.父级对象获取子物体
父级对象获取子物体的方法有多种
* （1）通过transform组件直接获取父物体
```csharp
Transform parent = gameObject.transform.parent;
```
* (2)逐级向上查找特定父级
```csharp
public T FIndParentWithComponent<T>() where T : Component
{
    Transform current = transform; // 出发点
    while (current.parent != null)
    {
        current = current.parent;
        T component = current.GetComponent<T>();
        if(component != null)
        return component;
    }
    return null;
}
```
* (3)获取根物体
```csharp
// 通过使用root属性
Transform rootTransform = transform.root;
```
* (4)使用Unity的API获取
```csharp
// 1. 使用GetParent()方法
Transform parent = transform.GetParent();
// 2.GetComponentInParent（查找特定组件）
MeshRenderer parentRenderer = GetComponentInParent<MeshRenderer>();
```
## 5.父级对象获取子物体
* （1）根据索引值获取子物体
```csharp
Transform firstChild = transform.GetChild(0); // 获取第一个子物体
Transform secondChild = transform.GetChild(1); // 获取第二个子物体
```
* （2）通过名称精确查找
```csharp
// 方法1：Transform.Find (支持路径查找)
Transform target = transform.Find("ChildName");
// 查找嵌套子物体
Transform nested = transform.Find("Child/Grandchild");

// 方法2：递归查找
public Transform FindChildRecursive(Transform parent, string name)
{
    foreach (Transform child in parent)
    {
        if (child.name == name) return child;
        Transform result = FindChildRecursive(child, name);
        if (result != null) return result;
    }
    return null;
}
```
* （3）通过组件类型查找
```csharp
// 获取所有子物体中的指定组件（包含嵌套）
Renderer[] allRenderers = GetComponentsInChildren<Renderer>(true);

// 排除自身
Renderer[] childRenderers = GetComponentsInChildren<Renderer>(false);
```
* （4）使用LINQ查询
```csharp
using System.Linq;
// 获取所有激活状态的子物体
var activeChildren = transform.Cast<Transform>()
                            .Where(t => t.gameObject.activeSelf)
                            .ToList();
```
* （5）通过标签查询
```csharp
List<GameObject> taggedChildren = new List<GameObject>();
foreach (Transform child in transform)
{
    if (child.CompareTag("Weapon"))
    {
        taggedChildren.Add(child.gameObject);
    }
}
```
## 6.代码自动生成游戏对象且规定父级
规定父级对象，在其之下生成对象池
```csharp
// 初始化管理器，主要是管理器构造函数
parkingSlotManager = new ParkingSlotManager(ParkingSlotRoot);

// ParkingSlot是预制体主体名字
public ParkingSlotManager(Transform root) : base("ParkingSlot", root, 5) // base使用父类构造函数
{
}

// 父类
public ObjectManager(string asset_name, Transform _root, int cache_size)
{
    m_AssetName = asset_name; // 资产名称
    root = _root; // 根物体

    //通过资源名称加载预制体
    string prefab_name = string.Format("pre_{0}", asset_name.ToLower()); // 规范资产名称

    // 通过对象池加载资产
    BaseManager.resMgr.SyncLoadAsset<GameObject>(prefab_name, m_AssetName, (go) =>
    {
        if (go != null)
        {
            m_Pool = GameObjectPoolMgr.GetOrCreatePool(m_AssetName, go, 1, cache_size, root);
        }
        BaseManager.resMgr.UnloadAsset(prefab_name); // 去除依赖性
    });
}
```
## 7.字符串使用的方法
* 字符串的比较 CompareTo()方法
```csharp
// 相同返回1，不同返回0
string str1 = "Hello";
int flag = str1.CompareTo("Hello");
```
* 字符串代替Replace()方法
```csharp
string str1 = "H.e.l.l.o";
string str2 = "Hello World";
// 将.转换成-  str1不会改变
string str3 = str1.Replace(".", "-");
```
* 字符串拆分
```csharp
string str1 = "Hello World";
string str[] = str1.Split(" "); // 以空格分割字符串
```
* 截取字符串
```csharp
string str1 = "Hello World";
string str2 = str1.Substring(4); // 截取第四个字符，保留之后的数组  如str2 = "o World"
string str3 = str1.Substring(5, 2); // 截取第五个字符，长度为2  如str3 = " W"
```
* 大小写转换
```csharp
string str1 = "Hello World";
// 转换为小写
string str2 = str1.ToLower();
// 转换为大写
string str3 = str1.ToUpper();
```
* 去除字符串空格(去除前后的空格)
```csharp
string str1 = "  Hello World  ";
str1.Trim();
```
* 把某个字符串拷贝到字符串数组
```csharp
copyTo(int sourceIndex, char[] destination, int destinationIndex, int count)

char[] cA = new char[20];
string str1 = "Hello World";
// sourceIndex是字符串的拷贝起始位置
// char[] destination需要拷贝到的数组
// destinationIndex是数组的拷贝起始位置
// count是拷贝的长度
str1.CopyTo(0, cA, 0 , str1.Length);
```
* 合并字符串
```csharp
string str1 = "Hello";
string str2 = "World";
string str3 = string.Concat(str1, str2);
```
* 格式化
```csharp
// 例如构建一个计算公式，输出格式化字符串
int x = 21;
int y = 33;
int sum = x + y;
string.Format("{0}+{1}={2}",x,y,sum)

// 货币形式输出
int money = 1000;
string.Format("{0:C}",money);

// 保留指定位数
int x = 12.341214;
string.Format("{0:F2}",x); // 保留两位，并且会自动四舍五入

// 自动转换百分比
string.Format("{0:P}",0.2312);

// 日期格式化
// yyyy 年份 MM 月份 dd 日 HH小时 mm 分钟 ss 秒
DataTime date = System.DateTime.Now;
string.Format("{0:yyyy-MM-dd HH:mm:ss}",date);
date.ToString("yyyy-MM-dd HH:mm:ss");
```
* 取字符串中某个字符的索引
```csharp
string str = "abcdefg";
str.IndexOf("c"); //2 获取c在这个字符串中的索引
```
* 在字符串的某个位置插入字符串
```csharp
string str = "abcdefg";
str.Insert(3,"123"); //abc123defg
```
* 字符数组拼接成字符串
```csharp
char[] cA = new char[]{'a','b','c'};
string.Join("",cA); // 第一个参数是指定字符拼接的方式
```
## 快速删除Unity项目Script文件夹下的所meta文件
```bash
# 用powershell删除
Get-ChildItem -Recurse -Filter *.meta | Remove-Item -Force
```
## 8.Unity摄像机操作
```csharp
public class CameraParam
{
    public float fov; // 摄像机视野
    public Vector3 focus; // 摄像机焦点
    public float distance; // 摄像机到焦点的距离
    public float pitch; // 摄像机俯仰角（上下）
    public float yaw; // 摄像机偏航角（左右）
    public Vector2 lensShift; // 镜头偏移：从传感器水平和垂直偏移摄像机的镜头
}
// 根据相关的参数，计算摄像机的坐标
// 原理1.根据旋转角确定焦点到摄像机的方向向量
// 2.获得方向向量后将该向量转换成单位向量，与焦点和摄像机距离相乘获得焦点到摄像机坐标的距离向量
// 3.叠加焦点坐标获得摄像机的坐标
public static Vector3 GetCameraPos(CameraParam param)
{
    // 摄像机初始方向为(0,0,-1),Vector.back
    // 根据旋转角，绕Y轴（垂直轴），绕x轴z轴（水平轴）旋转
    // 旋转顺序为 先偏航（Yaw）后俯仰（Pitch）
    Vector3 dir = Quaternion.AngleAxis(-yaw, Vector3.up) * Quaternion.AngleAxis(pitch, Vector3.right) * Vector3.back; // 这里的取反与旋转的正方向有关，偏航角变大的时候，是顺时针旋转，对于摄像机来说，偏航角变大，是向左偏移，所以取反摄像机就会往右偏，符合直观感觉

    // 计算焦点到摄像机的距离向量
    Vector3 pos = dir.normalized * distance;
    // 计算最终的摄像机坐标
    pos += focus;

    return pos;
}
```
## 9.包围盒算法
通过不断遍历顶点，确定在空间内的最小顶点和最大顶点，两点之间可以包围一个盒子，这就是包围盒。
## 10.Coroutine（协程）
是一种特殊的函数，用于实现分步执行或异步等待的逻辑。它允许你在代码中插入“暂停点”，在等待特定条件（如时间延迟、资源加载完成）时暂停执行，后续再从中断处继续运行，而不会阻塞主线程。
### 核心机制：
* 基于迭代器：IEnumerator，协程返回函数的基本类型，用yield return来定义暂停点
* 依赖MonoBehaviour：使用MonoBehaviour的StartCoroutine()和StopCoroutine()方法来启动和停止协程。
* 常见的yield return类型：</br>
1.等待下一帧继续执行：yield return null;</br>
2.等待t秒，会被Time.timeScale影响：yield return new WaitForSeconds(t);</br>
3.等待t秒，不会被Time.timeScale影响：yield return new WaitForSecondsRealtime(t);</br>
4.等待下一次FixedUpdate：yield return new WaitForFixedUpdate();</br>
5.等待一帧渲染完成：yield return new WaitForEndOfFrame();</br>
6.等待条件时成立执行：yield return new WaitUntil(() => 条件);</br>
7.y等待另一个协程完成：ield return StartCoroutine(...)</br>
### 使用场景
* 延迟执行
```csharp
IEnumerator DelayedAction()
{
    yield return new WaitForSeconds(2f);
    Debug.Log("2秒后执行！");
}
```
* 分帧处理
```csharp
IEnumerator ProcessLargeData()
{
    for (int i = 0; i < 1000; i++)
    {
        HeavyCalculation(i);
        yield return null; // 每帧处理一次，防止主线程阻塞
    }
}
```
* 等待异步操作
```csharp
IEnumerator LoadSceneAsync()
{
    AsyncOperation asyncLoad = SceneManager.LoadSceneAsync("Level1"); // 异步加载场景
    while (!asyncLoad.isDone)
    {
        float progress = asyncLoad.progress;
        UpdateLoadingBar(progress);
        yield return null;
    }
}
```
* 序列动画
```csharp
IEnumerator PlayAnimations()
{
    PlayAnimation("Jump");
    yield return new WaitForSeconds(0.5f); // 衔接下一个动画
    PlayAnimation("Attack");
}
```
## 11.材质贴图相关操作
使用代码控制材质贴图
### 设置材质的常用方法
```csharp
// 1.设置纹理
SetTexture(string propertyName, Texture texture);
// 2.设置颜色
SetColor(string propertyName, Color color);
// 3.设置浮点数 调整浮点属性（如透明度、光泽度等）
SetFloat(string propertyName, float value);
//4.设置向量 用于修改Shader中的向量参数
SetVector(string propertyName, Vector4 value);
// 5.设置矩阵 传递矩阵数据到Shader（常用于自定义空间变换）
SetMatrix(string propertyName, Matrix4x4 matrix);
// 6.设置整型 修改Shader中的整型参数（如开关、索引等）
SetInt(string propertyName, int value);
// 7.启动/禁用shader关键字 控制Shader中的多编译选项（#pragma multi_compile）
EnableKeyword(string keyword);
DisableKeyword(string keyword);
```
### UV
UV是纹理映射到3D模型表面的 二维坐标系，用于确定纹理贴图如何“包裹”模型。

U轴：水平方向（相当于2D纹理的X轴）。

V轴：垂直方向（相当于2D纹理的Y轴）。

范围：默认范围为 [0,1]，即一张纹理的完整图像对应UV的 (0,0) 到 (1,1)
### 设置贴图UV偏移量 SetTextureOffset
SetTextureOffset 用于设置材质纹理的 UV偏移量（即纹理坐标的原点偏移），通过改变偏移值可以实现 纹理滚动、动态位移 等效果
```csharp
// propertyName是纹理属性名
// offset是二维向量，偏移量
material.SetTextureOffset(string propertyName, Vector2 offset);

// 滚动纹理
public Material material;
public float scrollSpeed = 0.5f;

void Update() 
{
    float offset = Time.time * scrollSpeed;
    material.SetTextureOffset("_MainTex", new Vector2(offset, 0)); // 在U轴上进行滚动
}
```
### 控制纹理平铺（重复）比例
通过调整 UV 的缩放值，可以实现纹理的拉伸、压缩或重复效果
```csharp
public void SetTextureScale(string propertyName, Vector2 scale);
// ScaleX:控制横向的缩放比例
// ScaleY:控制纵向的缩放比例
// 等于1时是原来的缩放的参数
// 大于1，纹理会缩小，重复
// 小于1，纹理会放大，拉伸
Vector2 scale = new Vector2(ScaleX, ScaleY);
```

## 12.Unity的MonoBehaviour生命管理方法
```csharp
// 首次创建 GameObject（active = true）
//        │
//        ▼
//    Awake()       ◄── 初始化时调用一次（无论 active 状态）
//        │
//        ▼
//    OnEnable()    ◄── 对象首次激活或被重新激活时调用
//        │
//        ▼
//    Start()       ◄── 在第一次 OnEnable() 后的下一帧调用
//        │
//        ▼
//    Update()      ◄── 每帧调用（仅当对象和组件均处于激活状态）

// 当调用 SetActive(false) 或 enabled = false：
//        │
//        ▼
//    OnDisable()   ◄── 禁用时立即调用

// 当再次调用 SetActive(true) 或 enabled = true：
//        │
//        ▼
//    OnEnable()    ◄── 重新激活时调用

// 当调用 Destroy(gameObject)：
//        │
//        ▼
//    OnDisable()   ◄── 若对象当前处于激活状态
//        │
//        ▼
//    OnDestroy()   ◄── 销毁前最后一刻调用
```
