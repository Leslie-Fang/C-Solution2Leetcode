//
// Created by leslie-fang on 2017/6/20.
//
#include <iostream>
#include <vector>
using namespace std;

int maxDistance(vector<vector<int> >& arrays) {
    bool cmin=false;
    bool cmax=false;
    bool samearr=false;
    int linenumber=0;
    int min=arrays[0][0];
    int max=arrays[0][0];
    int smin=arrays[0][0];
    int smax=arrays[0][0];
    for(int i=0;i<arrays.size();i++) {
        cmin=false;
        cmax=false;
        for (vector<int>::iterator it = arrays[i].begin(); it != arrays[i].end(); it++) {
            cout<<*it<<endl;
            if(min >= *it){
                min=*it;
                cmin=true;
                samearr=false;
            }
            if(max <= *it){
                max=*it;
                cmax=true;
                samearr=false;
            }
        }
        if(cmin && cmax){
            samearr=true;
            linenumber=i;
        }
    }
    if(samearr){
        cout<<"hhh"<<endl;
        arrays.erase(arrays.begin()+linenumber);
        smin=arrays[0][0];
        smax=arrays[0][0];
        for(int i=0;i<arrays.size();i++) {
            for (vector<int>::iterator it = arrays[i].begin(); it != arrays[i].end(); it++) {
                if(smin >= *it){
                    smin=*it;
                }
                if(smax<=*it){
                    smax=*it;
                }
            }
        }
        cout<<max<<endl;
        cout<<min<<endl;
        cout<<smax<<endl;
        cout<<smin<<endl;
        if((max-smin)>(smax-min)){
            return (max-smin);
        }else{
            return (smax-min);
        }
    }else{
        cout<<"nnn"<<endl;
        return (max-min);
    }

}

int main(){
    vector<int> it1;
    it1.push_back(1);
    it1.push_back(5);
   //it1.push_back(3);
    vector<int> it2;
    it2.push_back(3);
    it2.push_back(4);
  /*  vector<int> it3;
    it3.push_back(1);
    it3.push_back(2);
    it3.push_back(3);*/
    vector< vector<int> > arrays;
    arrays.push_back(it1);
    arrays.push_back(it2);
   // arrays.push_back(it3);

    cout<<maxDistance(arrays)<<endl;
  //  cout<<"Hello world!"<<endl;
    return 0;
}
