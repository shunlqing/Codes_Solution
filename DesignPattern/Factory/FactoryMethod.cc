/**
 * 工厂方法模式
*/

#include <iostream>
using namespace std;

/**
 * 具体产品的生产交给具体工厂
*/

enum DISHTYPE {
    CHICKEN, 
    SALAD,
    HOTPOT,
    RICE,
};

class Dish{
public:
    Dish(){}
    virtual ~Dish(){}
    virtual void eat() = 0;
};

class Rice : public Dish {
    virtual void eat() {
        cout << "Rice delicious" << endl;
    }
};

class Salad : public Dish {
    virtual void eat() {
        cout << "Salad delicious" << endl;
    }
};

class Chicken : public Dish {
    virtual void eat() {
        cout << "Chicken delicious" << endl;
    }
};

class Hotpot : public Dish {
    virtual void eat() {
        cout << "Hotpot delicious" << endl;
    }
};

class FactoryBase{
public:
    virtual Dish* CookDish() = 0;
};

class ChickenFactory : public FactoryBase {
public:
    virtual Dish* CookDish() {
        return new Chicken(); 
    }
};

class SaladFactory : public FactoryBase {
public:
    virtual Dish* CookDish() {
        return new Salad(); 
    }
};

class HotpotFactory : public FactoryBase {
public:
    virtual Dish* CookDish() {
        return new Hotpot(); 
    }
};

class RiceFactory : public FactoryBase {
public:
    virtual Dish* CookDish() {
        return new Rice(); 
    }
};

int main()
{
    FactoryBase* f1 = new ChickenFactory();
    Dish* d1 = f1->CookDish();
    d1->eat();

    FactoryBase* f2 = new HotpotFactory();
    Dish* d2 = f2->CookDish();
    d2->eat();

    FactoryBase* f3 = new RiceFactory();
    Dish* d3 = f3->CookDish();
    d3->eat();

    delete(f1);
    delete(f2);
    delete(f3);
    delete(d1);
    delete(d2);
    delete(d3);
    
}

