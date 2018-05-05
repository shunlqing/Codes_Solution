/**
 * 策略模式
*/
#include <iostream>
using namespace std;

/**
 * 对象行为型模式
*/

/**
 * 
*/

class Strategy{
public:
    virtual void algorithm() = 0;
};

class ConcreteStrategyA : public Strategy {
public:
    virtual void algorithm() {
        cout << "ConcreteStrategy A~" << endl;
    };
};

class ConcreteStrategyB : public Strategy {
public:
    virtual void algorithm() {
        cout << "ConcreteStrategy B~" << endl;
    };
};

class Context {
public:
    void algorithm() {
        st_->algorithm();
    }
    void setStrategy(Strategy* st) {
        st_ = st;
    }

private:
    Strategy* st_;
};

int main()
{
    Context *cxt = new Context();

    Strategy *s1 = new ConcreteStrategyA();
    cxt->setStrategy(s1);
    cxt->algorithm();

    Strategy *s2 = new ConcreteStrategyB();
    cxt->setStrategy(s2);
    cxt->algorithm();

    delete cxt;
    delete s1;
    delete s2;
}
