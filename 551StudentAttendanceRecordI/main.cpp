#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int a_number = 0;
        int c_L = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == 'A'){
                c_L = 0;
                a_number += 1;
                if(a_number >= 2)
                {
                    return false;
                }
            }else if(s[i] == 'L'){
                c_L += 1;
                if(c_L >= 3)
                {
                    return false;
                }
            }else{
                c_L = 0;
            }
        }
        return true;
    }
};

int main(int argc, char ** argv){
    string input;
    getline(cin, input);
    Solution * mySolution = new Solution();
    cout<<mySolution->checkRecord(input)<<endl;
    delete mySolution;
}

