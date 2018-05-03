#include <vector>
#include <memory>
#include <cstdlib>
#include <iostream>
using namespace std;

class D {
public:
    int a;
    int b;
    int c;
    int * pa;
    D(){
        a = 10;
        b = 20;
        c = 30;
        pa = &a;
        cout << "D::D()\n";
    }

    ~D() {
        cout << this << endl;
        cout << "D::~D()\n";
    }
};

auto delfunc = [](D* p) {
    cout << "delfunc called\n";
    delete p;
};

int main()
{
    /**
     * 不要使用裸指针初始化shared_ptr,导致多个控制块
    */
    D* p = new D;
    shared_ptr<D> p1(p, delfunc);
    cout << p1.use_count() << endl;
    {
        cout << p1->a << " " << p1->b << " " << p1->c << endl;        
        shared_ptr<D> p2(p, delfunc);        
        cout << p1.use_count() << "," << p2.use_count() << endl; //引用计数都是1，说明p1, p2使用的是两个不同的控制块来计数
        //p1被析构，相应的D对象被析构
    }
    cout << p1->a << " " << p1->b << " " << p1->c << endl; //  
    
}