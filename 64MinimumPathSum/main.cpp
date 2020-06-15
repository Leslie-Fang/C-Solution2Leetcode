#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        //int res = 0;
        // int column_index = 0;
        // int row_index = 0;
        //cout<<grid[0][0]<<endl;
        int m = grid[0].size();
        int n = grid.size();
        for(int i=0;i<n;i++){
        	for(int j=0;j<m;j++){
        		if(i==0 && j == 0){
        			continue;
        		}else if(i == 0 && j != 0){
        			grid[i][j] = grid[i][j-1] + grid[i][j];
        		}else if(i != 0 && j == 0){
					grid[i][j] = grid[i-1][j] + grid[i][j];
        		}else{
        			grid[i][j] = min(grid[i-1][j], grid[i][j-1])+ grid[i][j];
        		}
        	}
        }
        return grid[n-1][m-1];
    }
};

int main(int argc, char ** argv){

	return 0;
}