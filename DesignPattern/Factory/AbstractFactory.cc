/**
 * 抽象工厂模式
*/

#include <iostream>
using namespace std;

/**
 * 工厂方法模式中，一个工厂只能生产一种具体产品。
 * 抽象工厂模式：
 *  工厂生产的产品不再是唯一的。
 *  产品具有等级结构
*/

class AudiBase{
public:
    virtual void startEngine() = 0;
};

class AudiR : public AudiBase {
public:
    virtual void startEngine() {
        cout << "Hoo~ Audi R class" << endl;
    }
};

class AudiS : public AudiBase {
public:
    virtual void startEngine() {
        cout << "Hoo~ Audi S class" << endl;
    }
};

class BenzBase{
public:
    virtual void startEngine() = 0;
};

class BenzC : public BenzBase {
public:
    virtual void startEngine() {
        cout << "Hoo~ Benz C class" << endl;
    }
};

class BenzE : public BenzBase {
public:
    virtual void startEngine() {
        cout << "Hoo~ Benz E class" << endl;
    }
};

/**
 * 抽象汽车工厂：可以生产奥迪和奔驰两种车型
*/
class FactoryBase {
public:
    virtual AudiBase* createAudi() = 0;
    virtual BenzBase* createBenz() = 0;
};

/**
 * 具体工厂1：生产奥迪S系和奔驰E
*/
class CarFactory1 : public FactoryBase {
public:
    virtual AudiBase* createAudi() {
        return new AudiS();
    }

    virtual BenzBase* createBenz() {
        return new BenzE();
    }
};

/**
 * 具体工厂2：生产奥迪S系和奔驰C系
*/
class CarFactory2 : public FactoryBase {
public:
    virtual AudiBase* createAudi() {
        return new AudiR();
    }

    virtual BenzBase* createBenz() {
        return new BenzC();
    }
};

int main()
{
    FactoryBase *f1 = new CarFactory1(); 
    BenzBase* benz1 = f1->createBenz();
    benz1->startEngine();

    AudiBase* audi1 = f1->createAudi();
    audi1->startEngine();

    FactoryBase *f2 = new CarFactory2();
    BenzBase* benz2 = f2->createBenz();
    benz2->startEngine();

    AudiBase* audi2 = f2->createAudi();
    audi2->startEngine();
}