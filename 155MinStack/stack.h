//
// Created by leslie-fang on 2017/6/10.
//

#ifndef INC_155MINSTACK_STACK_H
#define INC_155MINSTACK_STACK_H
#include <iostream>
#include <string>
using namespace std;

struct Element{
    int value;
    Element *Next;
};

class MinStack {
public:
    /** initialize your data structure here. */
    Element start;
    Element *current;
    Element *last;
    bool startarr;
    int min;


    MinStack() ;

    void push(int x);

    void pop();

    int top();

    int getMin();

};


#endif //INC_155MINSTACK_STACK_H
