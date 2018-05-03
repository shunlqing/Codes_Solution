#include <iostream>
#include <vector>
#include <memory>
#include <cstdio>
#include <fstream>
#include <cassert>
#include <functional>

struct B {
    virtual void bar() { std::cout << "B::bar\n"; }
    virtual ~B() = default;
};

struct D : B {
    D() { std::cout << "D::D\n"; }
    ~D() { std::cout << "D::~D\n"; }
    void bar() override { std::cout << "D::bar\n"; }
};

/**
 * std::unique_ptr作为参数
 * 
*/
std::unique_ptr<D> pass_through(std::unique_ptr<D> p)// 右值参数
{
    p->bar();
    return p;
}

void close_file(std::FILE* fp) { std::fclose(fp); }

int main()
{
    std::cout << "unique owner ship semantics demo\n";
    {
        auto p = std::make_unique<D>(); //C++14 内部new了一个D 
        auto q = pass_through(std::move(p));
        assert(!p);
        q->bar();
    }

    std::cout << "运行时多态\n";
    {
        std::unique_ptr<B> p = std::make_unique<D>();
        p->bar();

        std::vector<std::unique_ptr<B>> v; // uniqur_ptr可以作为容器元素
        v.push_back(std::make_unique<D>());
        v.push_back(std::move(p));
        v.emplace_back(new D);
        for(auto &p : v) p->bar();
    }

    std::cout << "Custom deleter demo\n";
    std::ofstream("demo.txt") << 'x';
    {
        std::unique_ptr<std::FILE, decltype(&close_file)> fp(std::fopen("demo.txt", "r"), &close_file);
        if(fp) {
            std::cout << (char)std::fgetc(fp.get()) << '\n';
        }
    }

    std::cout << "Custom lambda-expression deleter demo\n";
    {
        std::unique_ptr<D, std::function<void(D*)>> p(new D, [](D* ptr){
            std::cout << "destroying from a custom deleter...\n";
            delete ptr;
        });
        p->bar();
    }

    std::cout << "Array form of unique_ptr demo\n";
    {
        std::unique_ptr<D[]> p{new D[3]};
    }
}