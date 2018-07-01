#include <iostream>
#include "insert.hpp"
using namespace std;

void insert_sort(int * input,int length){
	for(int i=0;i<length;i++){
		for(int j=i;j>0;j--){
			if(input[j] < input[j-1]){
				swap(input,j-1,j);
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