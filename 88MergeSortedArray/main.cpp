#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};
int main(int argc, char ** argv){
	cout<<"hello world!"<<endl;
	int a[3] = {1,2,3};
	int b[3] = {2,5,6};
	vector<int> nums1(begin(a), end(a));
	vector<int> nums2(begin(b), end(b));
	Solution * mySolution = new Solution();
	mySolution->merge(nums1,3,nums2,3);
	// for(vector<int>::iterator it=nums1.begin();it != nums1.end();it++){
	// 	cout<<*it<<endl;
	// }
	delete mySolution;
	return 1;
}

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
	if(n==0){
		return;
	}else if(m==0){
		nums1.clear();
		for(int i=0;i<nums2.size();i++){
			//cout<<temp[i]<<endl;
			nums1.push_back(nums2[i]);
		}
		return;
	}
	int * temp = new int[n+m];
	int cm = m;
	int cn = n;
	int point = 0;
	while(1){
		if(nums1[cm-m] <= nums2[cn-n]){
			temp[point]=nums1[cm-m];
			point++;
			if(--m == 0){
				for(int i=cn-n;i<cn;i++){
					//cout<<nums2[i]<<endl;
					temp[point] = nums2[i];
					point++;
				}
				break;
			}
		}else{
			temp[point]=nums2[cn-n];
			point++;
			if(--n == 0){
				for(int i=cm-m;i<cm;i++){
					//cout<<nums1[i]<<endl;
					temp[point] = nums1[i];
					point++;
				}
				break;
			}
		}
	}
	nums1.clear();
	//cout<<temp[0]<<endl;
	for(int i=0;i<cn+cm;i++){
		cout<<temp[i]<<endl;
		nums1.push_back(temp[i]);
	}
	delete [] temp;
	return;
}