//
// Created by leslie-fang on 2017/6/11.
//
#include <iostream>
#include "stringiterator.h"

StringIterator::StringIterator(string compressedString) {
    char now;
    int times;
    string stimes="";
    string::iterator sit= compressedString.begin();
    while(sit !=compressedString.end()){
       // cout<<*sit<<endl;
        if(int(*sit) > 57){
            now=*sit;
            string::iterator sit2=sit+1;
            cout<<"*sit2:  "<<*(sit+1)<<endl;
            if(*(sit+1) > 57){
                cout<<"next still char"<<endl;
                uncompressedString.push_back(now);
                sit += 1;
                continue;
            }else{
                sit += 1;
                continue;
            }
            //continue;
        }
        while(int(*sit) >= 48 && int(*sit)<=57){
            stimes+=*sit;
            sit++;
            break;
        }
        cout<<stimes<<endl;
        times=atoi(stimes.c_str());
        cout<<"times:"<<times<<endl;
        stimes="";
        for(int i=0;i<times;i++){
            uncompressedString.push_back(now);
        }
        //sit--;
    }
}

bool StringIterator::hasNext() {
    if(*(snit+1) != NULL){
        return true;
    }else{
        return false;
    }
}

char StringIterator::next() {
    char re=*snit;
    snit+=1;
    return re;
}

