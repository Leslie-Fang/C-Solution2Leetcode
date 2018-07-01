#include <iostream>
#include "heap.hpp"
using namespace std;

void heap_sort(int * input,int length){
	heap_build(input,length);
	for(int i=length-1;i>0;i--){
		swap(input,0,i);
		heap_part_build(input,i);
		//heap_build(input,i);
	}
	return;
}

void heap_build(int * input,int length){
	//step1, down to up
	for(int i=length-1;i>0;i--){
		if(input[i]>input[(i-1)/2]){
			swap(input,i,(i-1)/2);
		}
	}
	//step2,up to down
	int point =0;
	while(1){
		if((point+1)*2-1 > length-1){
			break;
		}else{
			if(input[point] < input[(point+1)*2-1]){
				swap(input,point,(point+1)*2-1);
			}
		}
		if((point+1)*2 > length-1){
			break;
		}else{
			if(input[point] < input[(point+1)*2]){
				swap(input,point,(point+1)*2);
			}
		}
		point++;
	}
	return;
}

void heap_part_build(int * input,int length){
	int point =0;
	while(1){
		if((point+1)*2-1 > length-1){
			break;
		}else if((point+1)*2 > length-1){
			if(input[point] < input[(point+1)*2-1]){
				swap(input,point,(point+1)*2-1);
				point = (point+1)*2-1;
			}
			break;
		}else{
			if(input[point] < input[(point+1)*2-1] || input[point] < input[(point+1)*2]){
				if(input[(point+1)*2-1] > input[(point+1)*2]){
					swap(input,point,(point+1)*2-1);
					point = (point+1)*2-1;
					continue;
				}else{
					swap(input,point,(point+1)*2);
					point = (point+1)*2;
					continue;
				}
			}else{
				break;
			}
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