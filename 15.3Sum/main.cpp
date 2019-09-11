//
// Created by leslie-fang on 2017/9/2.
//
#include<iostream>
#include<vector>
#include<iterator>
#include <algorithm> 
#include<set>
#include<map>
using namespace std;

//if a num in nums has been scanned, we never need to scan it again, because it would cause the duplicate set
void twoSum(int target, int mydelete, map<int, int> numCount, vector<vector<int> > &res){
    numCount.erase(numCount.begin(), next(numCount.find(mydelete),1));
    map<int, int>::iterator it;
    map<int, int>::iterator it2;
    vector<int> sub;
    for(it = numCount.begin();it != numCount.end();it++)
    {
        if(it->first*2 > target)
        {
            break;
        }
        if(it->second >= 2)
        {
            if(it->first + it->first == target)
            {
                sub.clear();
                sub.push_back(mydelete);
                sub.push_back(it->first);
                sub.push_back(it->first);
                res.push_back(sub);
                break;
            }
        }
        if(it->second >= 1)
        {
            for(it2 = next(it,1); it2 != numCount.end();it2++)
            {
                if(it->first + it2->first > target)
                {
                    break;
                }
                if(it->first + it2->first == target)
                {
                    sub.clear();
                    sub.push_back(mydelete);
                    sub.push_back(it->first);
                    sub.push_back(it2->first);
                    res.push_back(sub);
                }
            }
        }
    }
    return;
}

vector<vector<int> > threeSum(vector<int>& nums) {
    //std::sort(nums.begin(), nums.end()); 
    vector<vector<int> > res;
    map<int, int> numCount;
    map<int, int>::iterator it;
    map<int, int>::iterator it2;
    vector<int> sub;
    for(int i=0;i<nums.size();i++)
    {
        it = numCount.find(nums[i]);
        if( it != numCount.end())
        {
            it->second += 1;
        }else
        {
            numCount.insert(pair<int, int>(nums[i], 1));
        }
    }
    for(it = numCount.begin();it != numCount.end();it++)
    {
        if(it->first > 0)
        {
            break;
        }
        if(it->second >= 3 && it->first == 0)
        {
            sub.clear();
            sub.push_back(0);
            sub.push_back(0);
            sub.push_back(0);
            res.push_back(sub);
            break;
        }
        if(it->second >= 2 && next(it,1) != numCount.end())
        {
            sub.clear();
            sub.push_back(it->first);
            sub.push_back(it->first);
            int subres = it->first + it->first;
            if(subres + prev(numCount.end(),1)->first >= 0)
            {
                for(it2 = next(it,1); it2 != numCount.end();it2++)
                {
                    if(subres+it2->first > 0)
                    {
                        break;
                    }
                    if(subres+it2->first == 0)
                    {
                        sub.push_back(it2->first);
                        res.push_back(sub);
                        break;
                    }
                }
            }
        }
        if(it->second >= 1)
        {
            if(it->first + 2*(prev(numCount.end(),1)->first) >= 0)
            {
                if(it->first + next(it,1)->first*2 > 0)
                {
                    break;
                }
                twoSum(-it->first, it->first, numCount, res);
            }
        }

    }
    return res;
}


int main(){
    //int input[6] = {-1, 0, 1, 2, -1, -4};
    int input[] = {0,0,0,0};
    vector<int> vinput(input, input+4) ;
    vector<vector<int> > res = threeSum(vinput);
    cout<<"Hello world!"<<endl;
    return 1;
}