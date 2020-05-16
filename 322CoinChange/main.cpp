#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void DFS(vector<int>& coins, int amount_left, int res, int& min_res, int last){
		if(amount_left == 0){
			if(min_res == -1 || res < min_res){
				min_res = res;
			}
			return;
		}else if(last < 0 || amount_left<coins[0]){
			return;
		}
		int j = 1;
		int num = coins[last];
		while(amount_left >= num*j){
			if(min_res != -1 && res+j >= min_res){
				//剪枝
				break;
			}
			j++;
		}
		for(int k=j-1;k>=0;k--){
			if(last != 0){
				//剪枝
				if(min_res != -1 && res+k+(amount_left-num*k)/coins[last-1] >= min_res){
					break;
				}
			}
			DFS(coins, amount_left-num*k, res+k, min_res, last-1);
		}
		return;
	}
    int coinChange(vector<int>& coins, int amount) {
    	sort(coins.begin(), coins.end());
    	int min_res = -1;
    	DFS(coins, amount, 0, min_res, coins.size()-1);
    	return min_res;
    }
};

int main(int argc, char ** argv){
	Solution * mySolution = new Solution();
	int a[4] = {186,419,83,408};
	vector<int> input(a, a+4);
    cout<<mySolution->coinChange(input, 6249)<<endl;
	delete mySolution;

	return 0;
}