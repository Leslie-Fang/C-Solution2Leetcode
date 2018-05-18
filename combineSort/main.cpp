#include <iostream>
using namespace std;
void merge(int * input, int * left, int leftLength,int * right, int rightLength);
void mergeSort(int * input, int inputLength);
int main(int argc, char ** argv){
	cout<<"Hello"<<endl;
	int input[10] = {4,5,12,11,8,100,78,65,45,67};
	for(int i=0;i<10;i++){
		cout<<input[i]<<endl;
	}
	mergeSort(input,10);
	for(int i=0;i<10;i++){
		cout<<input[i]<<endl;
	}
	return 1;
}

void merge(int * input, int * left, int leftLength,int * right, int rightLength){
	int i=0,j=0,k=0;
	while(i<leftLength && j<rightLength){
		if(left[i] < right[j]){
			input[k] = left[i];
			i++;
		}else{
			input[k] = right[j];
			j++;
		}
		k++;
	}
	if(i>=leftLength){
		while(j<rightLength){
			input[k] = right[j];
			j++;
			k++;
		}
	}else{
		while(i<leftLength){
			input[k] = left[i];
			i++;
			k++;
		}
	}
	return;
}

void mergeSort(int * input, int inputLength){
	if(inputLength <= 1){
		return;
	}
	int mid = inputLength/2;
	int * left,* right;
	left = new int[mid];
	right = new int[inputLength-mid];
	for(int i=0;i<inputLength;i++){
		if(i<mid){
			left[i] = input[i];
		}else{
			right[i-mid] = input[i];
		}
	}
	mergeSort(left,mid);
	mergeSort(right,inputLength-mid);
	merge(input,left,mid,right,inputLength-mid);
	delete [] left;
	delete [] right;
	return;
}