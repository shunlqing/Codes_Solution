#include <iostream>
#include <functional>
#include <boost/bind.hpp>
using namespace std;

void foo(){}
void foo(int i){}

int main()
{
    //std::bind不能处理函数重载的情况，boost可以处理函数重载的情况
    // auto f1_ = std::bind(foo, _1); 错误
    // auto f2_ = std::bind(foo); 错误

    auto f1 = std::bind(static_cast<void (*)()>(foo)); 
    auto f2 = std::bind(static_cast<void (*)(int)>(foo), _1);
    auto f3 = boost::bind(foo, _1);
    auto f4 = boost::bind(foo);
    
}