//
// Created by leslie-fang on 2017/6/26.
//
#include<iostream>
#include<vector>
#include<map>
using namespace std;

int leastInterval(vector<char>& tasks, int n) {
    int res=0;
    map<char,int> tasks2number;
    vector<char> cur;
    vector<char> myres;
    for(vector<char>::iterator it = tasks.begin();it != tasks.end();it++){
        if(tasks2number.find(*it) == tasks2number.end()){
            tasks2number[*it]=1;
        }else{
            tasks2number[*it] +=1;
        }
    }
   for(map<char,int>::iterator it=tasks2number.begin();it != tasks2number.end();it++){
        cout<<it->first<<" : "<<it->second<<endl;
    }
    while(!tasks2number.empty()){
        bool finish=false;
        for(map<char,int>::iterator it=tasks2number.begin();it != tasks2number.end();it++){
            bool find= false;
            if(it->second != 0){
                for(vector<char>::iterator it2 = cur.begin();it2 != cur.end();it2++){
                    if( *it2 == it->first){
                        find=true;
                        break;
                    }
                }
            }
            if(find){
                continue;
            }else{
                cout<<"push: "<<it->first<<endl;
                cur.push_back(it->first);
                if(cur.size()>n){
                    cur.erase(cur.begin());
                  //  cout<<"cur.size() is: "<<cur.size()<<endl;
                }
                res +=1;
                myres.push_back(it->first);
                it->second -=1;
                finish=true;
                if(it->second == 0){
                    tasks2number.erase(it);
                    break;
                }
            }
        }
        //should be idle
        if(!finish){
            cout<<"push: idle"<<endl;
            cur.push_back('0');
            if(cur.size()>n){
                cur.erase(cur.begin());
              //  cout<<"cur.size() is: "<<cur.size()<<endl;
            }
            res +=1;
            myres.push_back('0');
        }
    }
    return res;
}

int main(){
    char input[]={'A','A','A','A','A','A','B','C','D','E','F','G'};
    int n=3;
    vector<char> tasks(input,input+12);
    cout<<leastInterval(tasks,n)<<endl;
    return 1;
}
