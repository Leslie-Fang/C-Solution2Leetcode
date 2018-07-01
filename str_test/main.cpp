#include <iostream>
using namespace std;
char *strcpy(char *dest, char *src);
char *strcat(char *dest, const char *src);
int main(){
	cout<<"Hello"<<endl;
	char input[10] = "ab";
	char res[50];
	strcpy(res,input);
	cout<<"done"<<endl;
	cout<<res<<endl;
	strcat(res,"uuu");
	cout<<res<<endl;
	// delete [] input;
	// delete [] res;
	return 0;
}
char *strcpy(char *dest, char *src){
	int point=0;
	char * ret = dest;
	while(src[point] != '\0'){
		cout<<src[point]<<endl;
		dest[point] = src[point];
		point++;
	}
	dest[point] = '\0';
	return ret;
}
char *strcat(char *dest, const char *src){
	int point = 0;
	while(dest[point] != '\0'){
		point++;
	}
	int i=0;
	while(src[i] != '\0'){
		dest[point] = src[i];
		point++;
		i++;
	}
	dest[point] = '\0';
	return dest;

}