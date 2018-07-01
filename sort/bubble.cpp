#include <iostream>
#include "bubble.hpp"
using namespace std;

void bubble_sort(int *input,int length){
	bool exit = true;
	for(int i=0;i<length;i++){
		exit = true;
		for(int j=0;j<length-i-1;j++){
			if(input[j]>input[j+1]){
				swap(input,j,j+1);
				exit = false;
			}
		}
		if(exit){
			return;
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