/**
 * 单例模式
*/

#include <iostream>
#include <cassert>
using namespace std;

/**
 * 懒汉模式：在第一次调用GetInstance才分配实例
 * 1. 使用static 保存唯一对象指针， 使用static函数获取唯一指针
 * 2. 析构问题
 *    析构时机应该是在程序退出时，程序退出会释放所有的静态成员。为此我们定义一个类作为静态成员，它的析构里面设置对唯一实例的释放
*/

class Singleton {
private:
    Singleton() {}

public:
    class Garbo {
    public:
        Garbo() {
            cout << "Garbo::Garbo()" << endl;
        }
        ~Garbo() {
            if(s_instance_ != nullptr)
            {
                cout << "Garbo::~Garbo()" << endl;
                delete s_instance_;                
            }
        }
    };

    static Singleton* GetInstance() {
        if(s_instance_ == nullptr) {
            //Lock()
            if(s_instance_ == nullptr) {
                s_instance_ = new Singleton();
            }
            //Unlock()
        }
        
        return s_instance_;
    }

private:
    static Singleton* s_instance_;
    static Garbo garbo_;
};

Singleton* Singleton::s_instance_ = nullptr;
Singleton::Garbo Singleton::garbo_ = Singleton::Garbo();

/**
 * 使用局部静态变量的懒汉模式
 *  局部静态变量的生命周期：第一次使用时初始化到全局结束，会自动析构
 *  单纯使用局部静态变量，只是解决了拥有一个静态区实例，且这个实例是进程持久性的。但还是不能阻止在栈上创建新的实例，
 *  因为还存在拷贝构造函数。
 * 
 * 局部静态变量的线程安全性
 *  C++0X以后，要求编译器保证内部静态变量的线程安全性，可以不加锁
*/  
class Singleton1 {
private:
    Singleton1() {}
    Singleton1(Singleton1&)； // 2 把拷贝构造函数也禁止了，同时声明为不实现，即使友元也不行
    Singleton1& operator=(Singleton1&); // 复制运算符有必要禁止吗？
public:
    // static Singleton1* GetInstance() {
    //     cout << "Singleton1::GetInstance()" << endl;
    //     static Singleton1 instance; // 局部静态变量
    //     return &instance;
    // }

    static Singleton1& GetInstance() {
        //Lock
        static Singleton1 instance;
        //Unlock
        return instance;
    }
};

/**
 * 饿汉模式：无论是否调用该实例，在程序初始化时就分配好，并在以后返回实例
 * 线程安全性：静态初始化实例保证线程安全性。
 *  静态实例初始化在程序开始时进入主函数之前就以单线程的方式完成初始化，不必担心多线程的问题
*/
class SingletonStatic {
private:
    SingletonStatic() {}

public:
    class Garbo {
    public:
        Garbo() {
            cout << "Garbo::Garbo()" << endl;
        }
        ~Garbo() {
            if(s_instance_ != nullptr)
            {
                cout << "Garbo::~Garbo()" << endl;
                delete s_instance_;                
            }
        }
    };

    static SingletonStatic* GetInstance() {
        return s_instance_;
    }

private:
    static SingletonStatic* s_instance_;
    static Garbo garbo_;
};

SingletonStatic* SingletonStatic::s_instance_ = new SingletonStatic();
SingletonStatic::Garbo SingletonStatic::garbo_ = SingletonStatic::Garbo();


int main()
{
    Singleton * p1 = Singleton::GetInstance();
    Singleton * p2 = Singleton::GetInstance();
    assert(p1 == p2);
    cout << p1 << ", " << p2 << endl;

    // Singleton1 *p3 = Singleton1::GetInstance();
    // Singleton1 *p4 = Singleton1::GetInstance();
    // assert(p3 == p4);
    // cout << p3 << ", " << p3 << endl;

    Singleton1 &s1 = Singleton1::GetInstance();
    Singleton1 &s2 = Singleton1::GetInstance();
    assert(&s1 == &s2);
    cout << &s1 << ", " << &s2 << endl;
    // Singleton1 s3(s1); // 拷贝构造函数被设为私有
    // cout << &s3 << endl;
}
