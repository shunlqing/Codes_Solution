#include <stdio.h>

auto hello = []() { printf("Hello World\n"); };

auto hello_int = [](int val) { printf("Hello value is %d\n"); };

class op {
public:
    void operator()() {
        printf("a.out \n");
    }
};

int main(int argc, char **argv)
{
    hello();
    hello_int(4);

    auto la = [argc, argv]() { printf("param: %d, path is : %s\n", argc, argv[0]); };
    la();
    op a;
    a();

    return 0;
}