#include <TaskQuene.h>
#include <thread> // 模拟多线程的头文件
using namespace std;
int main()
{
    TaskQuene *taskQ = TaskQuene::getInstance();

    // 创建线程1 生产者
    thread t1([=]()
              {
        // 产生数据
        for(int i = 0;i<100;i++)
        {
            taskQ->addTask(i+108);
            cout<<"+++push data: "<<i+108<<"\tthreadID: "<<this_thread::get_id()<<endl;
            // 当前的线程休眠一段时间
            this_thread::sleep_for(chrono::milliseconds(500)); // 每循环一次就休眠500毫秒
        } });

    // 创建线程2 消费者
    thread t2([=]()
              {
        this_thread::sleep_for(chrono::milliseconds(100));
        while(!taskQ->isEmpty())
        {
            int num = taskQ->takeTask();
            cout<<"+++take data: "<<num<<"\tthreadID: "<<this_thread::get_id()<<endl;
            taskQ->popTask();
            this_thread::sleep_for(chrono::milliseconds(1000)); // 每循环一次就休眠500毫秒
        } });

        t1.join(); // 阻塞main线程
        t2.join();

    return 0;
}