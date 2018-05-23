/**
 * 分析以下代码
*/
#include <new>
class A {
public:
    int a;
};

void func(void)
{
    char buf[1024];
    A* ptr = new A;
    A* ptr2 = new (buf) A; //带位置的new

    delete ptr; //离开作用域要删除
}

int main()
{
    func();
}