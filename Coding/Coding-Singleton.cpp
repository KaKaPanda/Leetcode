// C++11 静态特性 -- 懒汉模式
// C++11 标准规定局部的静态对象在多线程场景下，只有初次访问才会被创建实例，后续都是直接获取。
// 若未创建成功，其他线程就会等待，不会出现竞争的情况。而且资源会自动被销毁释放。

class Singleton {
public:
    static Singleton* GetInstance() {
        static Singleton* m_instance;
        return m_instance;
    }

private:
    // 避免直接构造
    Singleton() {};
    ~Singleton() {};
    // 避免赋值拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
};




// C++11 静态特性 -- 饿汉模式
// 程序启动阶段会初始化类的静态变量。
// 优点是不会有线程安全问题，缺点是浪费内存。
// static对象在不同编译单元中的初始化顺序是未定义的。如果在初始化完成之前调用 Instance() 方法会返回一个未定义的实例。

class Singleton {
public:
    static Singleton* GetInstance() {
        return m_instance;
    }
private:
    // 避免直接构造
    Singleton() {};
    ~Singleton() {};
    // 避免赋值拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* m_instance;
};
Singleton* Singleton::m_instance = new Singleton();




// 懒汉模式 —— 非线程安全

class Singleton {
public:
    static Singleton* GetInstance() {
        if (m_instance == nullptr) {
            m_instance = new Singleton();
        }
        return m_instance;
    }
private:
    // 避免直接构造
    Singleton() {};
    ~Singleton() {};
    // 避免赋值拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* m_instance;
};
Singleton* Singleton::m_instance = nullptr;




// 懒汉模式 —— 线程安全
#include <mutex>
// #include <boost/thread.hpp>
using namespace std;

class Singleton {
public:
    static Singleton* GetInstance() {
        if (m_instance == nullptr) {
            lock_guard<mutex> lock(m_mutex);
            if (m_instance == nullptr) {
                m_instance = new Singleton();
            }
        }
        return m_instance;
    }
private:
    // 避免直接构造
    Singleton() {};
    ~Singleton() {};
    // 避免赋值拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static Singleton* m_instance;
    static mutex m_mutex;
};
Singleton* Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;




// 懒汉模式 —— 线程安全 —— 内存泄漏优化
// 单例类中new出来的实例没有得到释放，所以需要用智能指针来delete这个对象。
#include <mutex>
#include <boost>
// #include <boost/thread.hpp>
using namespace std;

class Singleton {
public:
    static Singleton* GetInstance() {
        if (m_instance == nullptr) {
            lock_guard<mutex> lock(m_mutex);
            if (m_instance == nullptr) {
                m_instance.reset(new Singleton(), destroyInstance);
            }
        }
        return m_instance;
    }

    static void destroyInstance(Singleton* m_instance) {
        delete m_instance;
    }
    
private:
    // 避免直接构造
    Singleton() {};
    ~Singleton() {};
    // 避免赋值拷贝
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;

    static boost::shared_ptr<Singleton> m_instance;
    static mutex m_mutex;
};
boost::shared_ptr<Singleton> Singleton::m_instance = nullptr;
mutex Singleton::m_mutex;