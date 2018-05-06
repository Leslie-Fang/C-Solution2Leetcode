#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
    Employee(int id,int importance,vector<int> subordinates);
};

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id);
};
void DFSgetImportance(vector<Employee*> employees, int id, int & count);
int main(int argc, char ** argv){
	cout<<"Hello!"<<endl;
	vector<Employee*> employees;
	int id=1;
	int importance =100;
	vector<int> subordinates;
	subordinates.push_back(1);
	Employee * myEmployee = new Employee(id,importance,subordinates);
	Solution * mySolution = new Solution();

	employees.push_back(myEmployee);
	mySolution->getImportance(employees,id);

}
Employee::Employee(int id,int importance,vector<int> subordinates){
	this->id = id;
	this->importance = importance;
	this->subordinates = subordinates;
}
int Solution::getImportance(vector<Employee*> employees, int id){
	int count =0;
	DFSgetImportance(employees, id, count);
	return count;
}

void DFSgetImportance(vector<Employee*> employees, int id, int & count){
	vector<Employee*>::iterator it;
	vector<int>::iterator it2;
	for(it = employees.begin();it != employees.end();it++){
		if((*it)->id == id){
			//cout<<(*it)->id <<endl;
			count += (*it)->importance;
			if((*it)->subordinates.size() == 0){
				return;
			}else{
				for(it2=(*it)->subordinates.begin();it2 !=(*it)->subordinates.end();it2++){
					DFSgetImportance(employees,*it2,count);
				}
				return;
			}
		}
	}
	return;
}