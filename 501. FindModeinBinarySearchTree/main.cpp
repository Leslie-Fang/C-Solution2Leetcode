#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<int> findMode(TreeNode* root);
};

void DFS(TreeNode* root, map<int, int> & mapStudent);

int main(int argc,char** argv){
	TreeNode root(10);
	Solution * mySolution = new Solution();
	//cout<<mySolution->findMode(&root)<<endl;
	mySolution->findMode(&root);

	return 0;
}

vector<int> Solution::findMode(TreeNode* root){
	vector<int> res;
	map<int, int> mapStudent; 
	if(root == NULL){
		return res;
	}
	DFS(root,mapStudent);
	int max = 0;
	//res.push_back(mapStudent.begin()->first);
	for(map<int,int>::iterator it=mapStudent.begin();it != mapStudent.end();it++){
		if(it->second > max){
			max = it->second;
			res.clear();
			res.push_back(it->first);
		}else if(it->second == max){
			res.push_back(it->first);
		}
	}
	return res;
}

void DFS(TreeNode* root, map<int, int> & mapStudent){
	map<int,int>::iterator it;
	if(root != NULL){
		it = mapStudent.find(root->val);
		if(it == mapStudent.end()){
			mapStudent.insert(pair<int, int>(root->val, 1));
		}else{
			it->second ++;
		}
	}
	if(root->left !=NULL){
		DFS(root->left,mapStudent);
	}
	if(root->right !=NULL){
		DFS(root->right,mapStudent);
	}
	return;
}