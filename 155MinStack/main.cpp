#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

int main() {
    MinStack *a = new MinStack();
    a->push(-2);
    a->push(0);
    a->push(-3);
    cout<<a->getMin()<<endl;
    a->pop();
    cout<<a->top()<<endl;
    cout<<a->getMin()<<endl;

  /*  a->push(2147483646);
    a->push(2147483646);
    a->push(2147483647);
    cout<<a->top()<<endl;
    a->pop();
    cout<<a->getMin()<<endl;
    a->pop();
    cout<<a->getMin()<<endl;
    a->pop();
    cout<<"pop last element"<<endl;
    a->push(2147483647);
    cout<<a->top()<<endl;
    cout<<a->getMin()<<endl;
    a->push(-2147483648);
    cout<<a->top()<<endl;
    cout<<a->getMin()<<endl;
    a->pop();
    cout<<a->getMin()<<endl;*/
    delete a;
    return 0;
}