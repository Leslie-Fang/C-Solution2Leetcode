//
// Created by leslie-fang on 2017/6/23.
//
#include<iostream>
#include<vector>
using namespace std;

int binarysearch(vector<int>& nums,int begin,int end,int target){
    int mid=(begin+end)/2;
    int res;
    if(target == nums[begin]){
        return begin;
    }else if(target == nums[end]){
        return end;
    }
    else if(target == nums[mid]) {
        return mid;
    }else if(target < nums[mid]){
        if(end <= begin+1){
            return -1;
        }
        res=binarysearch(nums,begin,mid,target);
    }else{
        if(end <= begin+1){
            return -1;
        }
        res=binarysearch(nums,mid,end,target);
    }
    return res;
}

int search(vector<int>& nums, int target) {
    int l=nums.size();
    if(l == 0){
        return -1;
    }
    int pivot=0;
    int i=0;
    bool findpivot=false;
    while(i<l-1){
        if(nums[i]<nums[i+1]){
            i++;
            continue;
        }else{
            findpivot=true;
            pivot=i+1;
            break;
        }
    }
    if(!findpivot){
        if(target < nums[0] || target > nums[l-1]){
            return -1;
        }else{
            return binarysearch(nums,0,l-1,target);
        }
    }else{
        if(target < nums[pivot] || target > nums[pivot-1]){
            return -1;
        }
        if(target == nums[0]){
            return 0;
        }
        else if(target > nums[0]){
            return binarysearch(nums,0,pivot-1,target);
        }else{
            return binarysearch(nums,pivot,l-1,target);
        }
    }
}

int main(){
    int a[]={3,1};
    vector<int> input(a,a+2);
    //cout<<binarysearch(input,0,3,6)<<endl;
    cout<<search(input,3)<<endl;
    return 0;
}
