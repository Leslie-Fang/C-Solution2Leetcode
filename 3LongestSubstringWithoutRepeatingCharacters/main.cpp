//
// Created by leslie-fang on 2017/6/18.
//
# include <iostream>
# include <string>
# include <map>

using namespace std;

map<char,int> longest;

int findlengthOfLongestSubstring(int max,int it,string s){
    if(it == s.size()){
        return 0;
    }
    map<char,int>::iterator iffind,iffind2;
    while(it < s.size()){
        iffind=longest.find(s[it]);
        if(iffind == longest.end()){
            longest[s[it]]=it;
        }else{
           /* for(map<char,int>::iterator it = longest.begin(); it != longest.end();it++){
                cout<<it->first<<endl;
            }*/
            int it3=it++;
            iffind2=longest.find(s[it3]);
            while(iffind2 != longest.end()){
                iffind=iffind2;
                it3++;
                iffind2=longest.find(s[it3]);
            }
            if(longest.size() >= max){
                max=longest.size();
            }
            longest.clear();
            int it2=iffind->second+1;
            max=findlengthOfLongestSubstring(max,it2,s);
            break;
        }
        it++;
    }
    if(longest.size() >= max){
        max=longest.size();
    }
    return max;
}

int lengthOfLongestSubstring(string s) {
    int max=0;
    if(s.length() == 0){
        return 0;
    }
//    cout<<"In the lengthOfLongestSubstring start: "<<s<<endl;
    max=findlengthOfLongestSubstring(max,0,s);

    return max;
}

int main(){
    cout<<"Hello world!"<<endl;
   /* string test="test";
    char a;
    for(string::iterator it = test.begin(); it != test.end();it++){
        a=*it;
        cout<<a<<endl;
    }*/
    cout<<lengthOfLongestSubstring("c")<<endl;
    return 0;
}
