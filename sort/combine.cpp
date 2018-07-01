#include <iostream>
#include "combine.hpp"
using namespace std;
void comblne_sort(int * input,int start,int end){
	if(end == start){
		return;
	}
	// static int count=0;
	// count++;
	// cout<<count<<endl;
	int middle = (start+end)/2;
	int * left = new int[middle+1];
	int * right = new int[end-start-middle];
	for(int i=0;i<=end;i++){
		if(i<=middle){
			left[i] = input[i];
		}else{
			right[i-middle-1] = input[i];
		}
	}
	comblne_sort(left,0,middle);
	comblne_sort(right,0,end-start-middle-1);
	combine(left,middle+1,right,end-start-middle,input);
	delete [] left;
	delete [] right;
	return;
}

template<typename T>
void swap(T * input,int start,int end){
	T temp=input[start];
	input[start] = input[end];
	input[end] = temp;
	return;
}

void combine(int * left, int leftlength, int * right, int rightlength, int * des){
	int i=0,j=0,count=0;;
	while(i<leftlength && j< rightlength){
		if(left[i]<right[j]){
			des[count] = left[i];
			i++;
		}else{
			des[count] = right[j];
			j++;
		}
		count++;
	}
	if(i==leftlength){
		while(j< rightlength){
			des[count] = right[j];
			j++;
			count++;
		}
	}else{
		while(i< leftlength){
			des[count] = left[i];
			i++;
			count++;
		}
	}
	return;
}