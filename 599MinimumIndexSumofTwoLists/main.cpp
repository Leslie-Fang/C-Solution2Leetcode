//
// Created by leslie-fang on 2017/6/19.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    vector<string> result;
    map<string ,int> map1;
    map<string ,int> map2;
    for(int i=0;i<list1.size();i++){
        string str1=list1[i];
        for(int j=0;j<list2.size();j++){
            string str2=list2[j];
            if(str1 == str2){
                map1[str1]=i;
                map2[str1]=j;
            }
        }
    }
    int min=map1.begin()->second+map2.find(map1.begin()->first)->second;
    result.push_back(map1.begin()->first);
  //  cout<<"min is: "<<min<<endl;
    map<string ,int>::iterator it;
    for(it=map1.begin();it != map1.end();it++){
        if(it->second+map2.find(it->first)->second < min){
            result.clear();
            result.push_back(it->first);
            min=it->second+map2.find(it->first)->second;
        }else if(it->second+map2.find(it->first)->second == min && it != map1.begin()){
            //cout<<"same"<<endl;
            result.push_back(it->first);
        }
    }
    return result;
}

int main(){

 //   ["Shogun","Tapioca Express","Burger King","KFC"]
 //   ["KFC","Burger King","Tapioca Express","Shogun"]
 //   ["dixyp","uq","q","KFC"]
 //   ["yl","fjugc","rlni","dixyp","uq","q","KFC"]

    string a[]={"dixyp","uq","q","KFC"};
    string b[]={"yl","fjugc","rlni","dixyp","uq","q","KFC"};
    //cout<<a.length()<<endl;
    vector<string> list1(a,a+4);
    vector<string> list2(b,b+4);
    vector<string> result;
    //cout<<"hello world!"<<endl;
    result=findRestaurant(list1,list2);
    for(vector<string>::iterator it3 = result.begin(); it3 != result.end();it3++){
        cout<<*it3<<endl;
    }
    //cout<<*result.begin()<<endl;
    return 0;
}
