/**
 * 建造者模式
*/

#include <iostream>
using namespace std;

class Product {
public:
    void setPartA(string a) { partA_ = a; }
    void setPartB(string b) { partB_ = b; }
    void setPartC(string c) { partC_ = c; }
    void show() const {
        cout << "partA: " << partA_ << "\npartB: " 
            << partB_ << "\npartC: " << partC_ << endl;
    }
private:
    string partA_;
    string partB_;
    string partC_;
};

class Builder {
public:
    // 抽象基类的虚函数要么实现，要么声明为纯虚函数
    // virtual void buildPartA(); 引发 undefine reference to 'vtable for Builder'
    virtual void buildPartA() = 0;    
    virtual void buildPartB() = 0;
    virtual void buildPartC() = 0;

    virtual Product* getResult() = 0;

    virtual ~Builder(){};
};

class ConcreteBuilderA : public Builder {
public:
    virtual void buildPartA() {
        if(prod_ == nullptr)
            prod_ = new Product();
        prod_->setPartA("A style");
    }
    virtual void buildPartB() {
        if(prod_ == nullptr)
            prod_ = new Product();
        prod_->setPartB("B style");

    }
    virtual void buildPartC() {
        if(prod_ == nullptr)
            prod_ = new Product();
        prod_->setPartC("C style");
    }
    virtual Product* getResult() {
        Product* tmp = prod_;
        prod_ = nullptr;
        return tmp;
    }

private:
    Product* prod_;
};

class Director {
public:
    Builder* pbuilder_;

    Product* construct() {
        pbuilder_->buildPartA();
        pbuilder_->buildPartB();
        pbuilder_->buildPartC();

        return pbuilder_->getResult();
    }

    void setBuilder(Builder* bler) {
        pbuilder_ = bler;
    }
};

int main()
{
    ConcreteBuilderA* builder = new ConcreteBuilderA();
    Director director;
    director.setBuilder(builder);
    Product* pd = director.construct();
    pd->show();

    delete builder;
    delete pd;

}
