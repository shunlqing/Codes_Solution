/**
实现：
class A;
A a;
a = a + 10;
*/

class A {
public:
    A& operator=(const A& a)
    {   
    }

    friend A operator+(const A& lhs, int val)
    {

    }
};

int main()
{
    A a;
    a = a + 10;
}