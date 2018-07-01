#include <iostream>
#include "quick.hpp"
using namespace std;

void quick_sort(int * input,int start,int end){
	int length = end-start+1;
	if(length <= 1){
		return;
	}
	int left=start;
	int right=end;
	int judge = start;
	while(1){
		while(input[left]<=input[judge]){
			left ++;
			if(left>right || left>=end){
				break;
			}
		}
		while(input[right]>input[judge]){
			right --;
			if(left>right || right<=start){
				break;
			}
		}
		if(left<right){
			swap(input,left,right);
			continue;
		}else{
			swap(input,judge,right);
			quick_sort(input,start,right-1);
			quick_sort(input,right+1,end);
			break;
		}
	}
	return;
}
template<typename T>
void swap(T * input,int start,int end){
	T temp=input[start];
	input[start] = input[end];
	input[end] = temp;
	return;
}