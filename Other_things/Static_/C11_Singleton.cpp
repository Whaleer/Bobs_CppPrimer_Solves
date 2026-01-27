#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

using namespace std;

/*
单例模式（Singleton Pattern）的特点：
1. 保证一个类只有一个实例，并提供一个全局访问点。
2. 构造函数私有化，防止外部创建对象。
3. 提供静态方法获取唯一实例（如 getInstance()）。
4. C++11 标准局部静态变量初始化是线程安全的，保证多线程环境下只创建一个实例。
5. 实例通常在第一次使用时延迟初始化。
6. 禁止拷贝和赋值操作，防止产生新的实例。
*/


class Singleton
{
public:
    static Singleton &getInstance()
    {
        // C++11 guarantees thread-safe initialization for function-local static
        static Singleton instance; // C++11 标准规定，静态局部变量的初始化是线程安全的
        cout << "getInstance called by thread: " << this_thread::get_id() << endl;
        return instance;
    }
    void showMessage()
    {
        cout << "singleton call:(" << this << ") say hello ! " << endl;
    }

private:
    Singleton()
    {
        // Simulate complex initialization
        cout << "singleton created: thread:" << std::this_thread::get_id() << endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    ~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;
};

void worker()
{
    Singleton::getInstance().showMessage();
}

int main()
{

    vector<thread> threads;
    cout << "Starting threads..." << endl;
    for (int i = 0; i < 5; ++i)
    {
        threads.emplace_back(worker);
    }
    for (auto &thread : threads)
    {
        thread.join();
    }
    cout << "All threads joined. Main thread exiting." << endl;
    return 0;
}