# fdbus
## 什么是fdbus?</br>
1.是一种新型的IPC机制</br>
2.FDBus构筑于socket（Unix domain和TCP）之上，采用Google protobuf做序列化和反序列化。</br>
3.FDBus支持字符串形式的名字作为server地址，通过name server自动为server分配Unix domain地址和TCP端口号，实现client和server之间用服务名字寻址。</br>

## 主要方法
使用fdbus通信时，需要启动name_server服务，在开启服务端和客户端开始工作。
```cpp
/*----------------客户端---------------------*/
#include<iostream>
#include <stdlib.h>
#include <iostream>
#include <fdbus/fdbus.h> // 要导入正确的fdbus.h文件

//提供命名空间
using namespace ipc::fdbus;

// FDBusClient客户端公开继承CBaseClient类，可以进行基类一些方法的重写
class FDBusClient : public CBaseClient
{
public:
        // 使用构造函数，使用初始化列表给父类CBaseWorker赋值
        // 参数：字符串常量 CBaseWorker类型的指针
        // CBaseWorker* worker = 0相当于是一个空指针，并且表示参数具有默认值（CBaseWorker* worker = nullptr）
        FDBusClient(const char* name, CBaseWorker* worker = 0)
                : CBaseClient(name, worker)
        {
        }
protected:
        // 重写onOnline方法
        // onOnline服务端上线时触发
        // 参数：在这里传递一个CFdbOnlineInfo类型的常量值
        // CFdbOnlineInfo:它用于在 FDBus 框架中传递关于连接信息的上下文数据。通常，在线信息结构体会包含与客户端或服务端的连接状态相关的详细信息，例如客户端标识、连接的唯一标识符（如 mSid）、连接时间等。
        void onOnline(const CFdbOnlineInfo& info) override
        {
                printf("........ [%s] onOnline mSid=%d.............\n", name().c_str(), info.mSid);

                std::vector<int32_t> subIDs;
                subIDs.push_back(1);

                // CFdbMsgSubscribeList 是 FDBus 框架中的一个类型，用于表示订阅消息的列表。FDBus 是一个轻量级的 IPC（进程间通信）框架，支持基于事件的消息传递机制，其中一个重要的功能就是订阅-发布（publish-subscribe）模式
                CFdbMsgSubscribeList subscribe_list;
                for (auto id : subIDs)
                {       //addNotifyItem添加订阅项，传入id添加到订阅消息列表
                        addNotifyItem(subscribe_list, id);
                }
                // 发送请求，发送到服务器上
                subscribe(subscribe_list);
        }

        // 重写onOffline方法
        // 服务端下线时触发
        void onOffline(const CFdbOnlineInfo& info) override
        {
                printf("Offline...\n");
        }

        // 重写onReply方法
        // 接收到服务端的消息时候触发
        // CBaseJob 是 FDBus 框架中的一个类，通常用于表示一个基础作业（job）或任务对象。在 FDBus 中，CBaseJob 可能是一个基类，它封装了消息传递机制中的基本操作和数据结构。FDBus 作为一个轻量级的进程间通信（IPC）框架，通过作业和消息的概念，管理客户端和服务器之间的通信。
        // 参数:CBaseJob::Ptr是一个只能指针类型，指向CBaseJob
        void onReply(CBaseJob::Ptr& msg_ref) override
        {       // castToMessage是将msg_ref这个只能指针转换成指向CBaseMessage对象
                auto msg = castToMessage<CBaseMessage*>(msg_ref);
                // 打印收到的消息的代码（msg->code()）
                printf("[%s] onReply msgcode=%d\n", name().c_str(), msg->code());
        }

        // 重写onStatus方法
        // 接收到服务端状态更新时触发
        void onStatus(CBaseJob::Ptr& msg_ref, int32_t error_code, const char* description) override
        {
                std::string sError = "[error] ";
                sError += "code:" + std::to_string(error_code) + ";";
                sError += "detail:";
                sError += description;
        }

        // 重写onBroadcast方法
        // 接收到服务端的广播时候触发
        void onBroadcast(CBaseJob::Ptr& msg_ref) override
        {       // 预定义__FUNCTION__代表本函数名的字符串
                printf("[%s]\n", __FUNCTION__);
                // 将msg_ref这个智能指针转换成指向CBaseMessage对象
                auto msg = castToMessage<CBaseMessage*>(msg_ref);

        }
};
```
```cpp
/*----------客户端入口----------*/
int main(int argc, char **argv)
{
        // FDB_CONTEXT 是一个全局或单例对象，用于管理整个进程的上下文环境（context），常用于初始化和维护消息传递的环境，以下代码先初始化fdbus环境
        FDB_CONTEXT->enableLogger(false); // 禁用FDBus 的日志功能
        FDB_CONTEXT->start(); //启动上下文进程，是传递消息的基础

        // 创建工作线程和启动线程
        auto spWorker = std::make_shared<CBaseWorker>(); // CBaseWorker 是一个工作线程的类对象，这里使用 std::make_shared 创建了一个智能指针 spWorker
        spWorker->start(); // 启动线程

        std::string url(FDB_URL_SVC); // FDB_URL_SVC = "svc://" 
        url += "org.fdbus.xtest-server"; // 创建域名
        auto client = new FDBusClient("TestClient", spWorker.get()); // 创建一个客户端对象，关联工作线程spWorker
        client->connect(url.c_str()); // 客户端连接到指定的服务器地址

        // 将主线程转换为一个工作线程，使其可以直接参与消息处理而不是退出。这通常用于保持进程活跃以持续处理消息或其他任务
        CBaseWorker background_worker;
        background_worker.start(FDB_WORKER_EXE_IN_PLACE); // #define FDB_WORKER_EXE_IN_PLACE       (1 << 0) FDB_WORKER_EXE_IN_PLACE是一个整型的值 在 (1 << 0) 中，1 被向左移动了 0 位，实际上数值并没有发生改变。因此，(1 << 0) 等于 1。
        
        
}
```

```cpp
/*-------------服务端---------------*/
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <fdbus/fdbus.h>

using namespace ipc::fdbus;

#define XCLT_TEST_SINGLE_DIRECTION 0
#define XCLT_TEST_BI_DIRECTION     1

// CXServer公开继承CBaseServer服务端
class CXServer : public CBaseServer
{
public:
    CXServer(const char *name, CBaseWorker *worker = 0)
        : CBaseServer(name, worker)
    {
       
    }
   
protected:
    // 重写onOnline方法
    // 客户端上线时触发
    void onOnline(const CFdbOnlineInfo &info) override
    {
                printf("%s\n",__FUNCTION__);
    }

    // 重写onOffline方法
    // 客户端下线时触发
    void onOffline(const CFdbOnlineInfo &info) override
    {
                printf("%s\n", __FUNCTION__);
    }

    // 重写onInvoke方法
    // 接收到客户端的消息时触发
    void onInvoke(CBaseJob::Ptr &msg_ref) override
    {
                //printf("%s\n", __FUNCTION__);
        auto msg = castToMessage<CBaseMessage *>(msg_ref);
        
        // 更加语句消息的代码来处理不同的逻辑
        switch (msg->code())
        {
            case XCLT_TEST_BI_DIRECTION:
            {
                // 根据有效载荷大小，记录字节数
                incrementReceived(msg->getPayloadSize());
                // 函数发送回复消息，回复消息使用与收到的消息相同的 msg_ref、有效载荷数据（getPayloadBuffer()）和大小（getPayloadSize()）。
                msg->reply(msg_ref, msg->getPayloadBuffer(), msg->getPayloadSize());
            }
            break;
            case XCLT_TEST_SINGLE_DIRECTION:
                // 只是简单的记录字节数
                incrementReceived(msg->getPayloadSize());
            break;
        }
    }
private:
    uint64_t mTotalBytesReceived; //总共收到消息的字节数
    uint64_t mTotalRequest; // 总共的请求数量
    uint64_t mIntervalBytesReceived; // 在某个时间接受到消息的字节数
    uint64_t mIntervalRequest; // 记录在某个时间间隔内收到的请求数的变量

    // 传递消息的有效载荷大小，记录接收到的字节数。
    void incrementReceived(uint32_t size)
    {
        mTotalBytesReceived += size;
        mIntervalBytesReceived += size;
        mTotalRequest++;
        mIntervalRequest++;
    }
};
```
```cpp
/*-------------服务端入口-------------*/
int main(int argc, char **argv)
{
    // 初始化fdbus环境
    FDB_CONTEXT->enableLogger(false);
    FDB_CONTEXT->start();

    // 创建服务端并且开启TCP通信
    auto server = new CXServer(FDB_XTEST_NAME);
        server->TCPEnabled();
    server->bind(); // 绑定服务，使其开始监听来自客户端的连接请求

    // 将主线程转换为一个工作线程，使其可以直接参与消息处理而不是退出。这通常用于保持进程活跃以持续处理消息或其他任务
    CBaseWorker background_worker;
    background_worker.start(FDB_WORKER_EXE_IN_PLACE);
}
```
