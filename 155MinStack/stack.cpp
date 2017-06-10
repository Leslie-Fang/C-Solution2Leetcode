#include "stack.h"

MinStack::MinStack() {
    start.value=0;
    start.Next=NULL;
    current=&start;
    min=0;
    startarr = false;
};

void MinStack::push(int x){
    if(!startarr){
        start.value=x;
        start.Next=NULL;
        current=&start;
        last=&start;
        startarr = true;
        min=x;
        return;
    }
    last=new Element;
    last->value=x;
    last->Next=NULL;
    current->Next=last;
    current=last;
    //to save run time, during the push operation would update the min value
    if(x<=min){
        min=x;
    }
    return;
};

void MinStack::pop(){
    last=&start;
    //if only have one element left, would re init the obj
    if(last->Next == NULL){
        start.value=0;
        start.Next=NULL;
        current=&start;
        last=&start;
        startarr = false;
        min=0;
        return;
    }
    while(last->Next->Next){
        last=last->Next;
    }
    //if the min number is the last element, have to find the small value in the arr after pop the last element
    if(min == last->Next->value){
        Element *c=&start;
        min=start.value;
        while(c->Next){
            if(c->value <= min){
                min = c->value;
            }
            c=c->Next;
        }
    }
    last->Next=NULL;
    current=last;
};

int MinStack::top(){
    return last->value;
};
int MinStack::getMin(){
    return min;
};


