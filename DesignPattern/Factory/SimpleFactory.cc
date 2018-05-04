/**
 * 简单工厂模式
*/

#include <iostream>
using namespace std;

/**
 * 作为程序员，可能你要消费各种各样的类，定义它，new它，使用它。当有很多的类，你就需要记住各个类的名称。
 * 如果有一个类集合，它们具有相同的特点，可以放到一起，集中创建。比如肥皂厂生产不同的肥皂，汽车厂生产不同的汽车。
 * 简单工厂模式就是这样的设计模式：
 *   提供一个工厂类，负责创建具有相同基础的类对象。比如奔驰生产厂
 *   抽象类：抽象产品，奔驰
 *   具体类：具体产品，比如奔驰5系，奔驰3系
 * 
 * 作为另一个例子，饭店厨房也是一个简单工厂。作为食客，只需要告诉后厨你想吃什么菜（输入类型），厨房给你做（工厂创建具体实例），供你消费（程序员使用实例）。
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
    virtual ~Dish(){};
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

class SimpleFactory {
public:
    Dish* CookDishes(DISHTYPE type) {
        switch(type) {
            case(CHICKEN) : 
                return new Chicken();
                break;
            
            case(SALAD) :
                return new Salad();
                break;

            case(HOTPOT) :
                return new Hotpot();
                break;
            
            case(RICE) :
                return new Rice();
                break;

            default:
                return nullptr;
        }
    }
};

int main()
{
    SimpleFactory kitchen;
    Dish *d1 = kitchen.CookDishes(RICE); // 只需传入标识对象的类型，工厂类返回相应的产品实例
    d1->eat();

    Dish *d2 = kitchen.CookDishes(HOTPOT);
    d2->eat();

    Dish *d3 = kitchen.CookDishes(SALAD);
    d3->eat();

    delete d1;
    delete d2;
    delete d3;
}

/**
 * 简单工厂缺点：
 *  
 */