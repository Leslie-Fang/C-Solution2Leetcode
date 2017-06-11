//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
#include "stringiterator.h"

using namespace std;

int main(){
    StringIterator * a= new StringIterator("x6");
    cout<<a->uncompressedString.size()<<endl;
    for(vector<char>::iterator it=a->uncompressedString.begin();it!=a->uncompressedString.end();it++){
        cout<<*it<<endl;
    }
/*    cout<<a->next()<<endl;
    cout<<a->next()<<endl;
    cout<<a->next()<<endl;
    cout<<a->next()<<endl;
    cout<<a->next()<<endl;
    cout<<a->next()<<endl;
    cout<<a->hasNext()<<endl;
    cout<<a->next()<<endl;
    cout<<a->hasNext()<<endl;*/

    delete a;
    return 0;
}

