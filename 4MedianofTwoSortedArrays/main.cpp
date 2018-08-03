#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);
};

int main(){
	vector<int> input1={1,2};
	vector<int> input2={};
	Solution * mySolution = new Solution();
	cout<<mySolution->findMedianSortedArrays(input1,input2)<<endl;
	return 1;
}

double Solution::findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
	int l1 = nums1.size();
	int l2 = nums2.size();
	int l = (l1+l2)/2+1;
	vector<int> res(l,0);
	int i=0,j=0,k=0;
	while(i<l1&&j<l2&&k<l){
		if(nums1[i] < nums2[j]){
			res[k]=nums1[i];
			i++;
			k++;
		}else{
			res[k]=nums2[j];
			j++;
			k++;
		}
	}
	if(i==l1){
		while(j<l2&&k<l){
			res[k]=nums2[j];
			j++;
			k++;
		}
	}else if(j==l2){
		while(i<l1&&k<l){
			res[k]=nums1[i];
			i++;
			k++;
		}
	}
	return (l1+l2)%2==0?(res[l-1]+res[l-2])/2.0:res[l-1];
}