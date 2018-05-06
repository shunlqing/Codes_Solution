/**
 * 用两个栈实现队列
*/

#include <stack>
#include <iostream>
using namespace std;

template <typename T> 
class CQueue {
public:
    CQueue(void){};
    ~CQueue(void) {};

    void appendTail(const T& node);
    T deleteHead();

private:
    stack<T> stack1;
    stack<T> stack2;
};

template <typename T>
void CQueue<T>::appendTail(const T& node)
{
    stack1.push(node);
}

template <typename T>
T CQueue<T>::deleteHead()
{
    if(!stack2.empty()) {
        T t = stack2.top();
        stack2.pop();
        return t;
    } else {
        while(!stack1.empty()) {
            T t = stack1.top();
            stack1.pop();
            stack2.push(t);
        }

        if(!stack2.empty()) {
            T t = stack2.top();
            stack2.pop();
            return t;
        } else {
            cout << "Queue is empty" << endl;
            throw;
        }
    }
}

int main()
{
    CQueue<int> qt;
    qt.appendTail(1);
    qt.appendTail(2);
    qt.appendTail(3);
    cout << qt.deleteHead() << endl;
    cout << qt.deleteHead() << endl;
    cout << qt.deleteHead() << endl;
    // cout << qt.deleteHead() << endl; 
}