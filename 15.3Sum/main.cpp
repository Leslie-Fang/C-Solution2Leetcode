//
// Created by leslie-fang on 2017/9/2.
//
#include<iostream>
#include<vector>
#include<set>
using namespace std;

//if a num in nums has been scanned, we never need to scan it again, because it would cause the duplicate set
vector<vector<int> > threeSum(vector<int>& nums) {
    vector<vector<int> > res;
    set<int> scaneed,scaneed2;
    int find = 0;
    for(vector<int>::iterator it=nums.begin();it != nums.end();it++){
        if(scaneed.find(*it) == scaneed.end()) {
            cout<<"1 level: "<<*it<<endl;
            scaneed2.clear();
            for(vector<int>::iterator it2=it+1;it2 != nums.end();it2++){
                cout<<"2 level: "<<*it2<<endl;
                if(scaneed.find(*it2) == scaneed.end() && scaneed2.find(*it2) == scaneed2.end()){
                    for(vector<int>::iterator it3=it2+1;it3 != nums.end();it3++){
                        cout<<"3 level: "<<*it3<<endl;
                        if(scaneed.find(*it3) == scaneed.end()){
                            if(*it+*it2+*it3 == 0){
                                vector<int> *subres = new vector<int>;
                                subres->push_back(*it);
                                subres->push_back(*it2);
                                subres->push_back(*it3);
                                res.push_back(*subres);
                                find = 1;
                                break;
                            }
                        }else{
                            continue;
                        }
                    }
                    scaneed2.insert(*it2);
                }else{
                    continue;
                }
            }
            scaneed.insert(*it);
        }else{
            continue;
        }

    }
    return res;
}


int main(){
    //int input[6] = {-1, 0, 1, 2, -1, -4};
    int input[] = {0,0,0,0};
    vector<int> vinput(input, input+4) ;
    vector<vector<int> > res = threeSum(vinput);
//    vector<vector<int> >::iterator it=res.begin();
//    for(vector<int>::iterator it2=it->begin();it2 != it->end();it2++){
//        cout<<*it2<<endl;
//    }


    cout<<"Hello world!"<<endl;
    return 1;
}