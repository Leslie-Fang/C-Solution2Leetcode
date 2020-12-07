#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int countNegatives(vector<vector<int> >& grid) {
    	int rows = grid.size();
    	if(rows <= 0){
    		return 0;
    	}
    	int columns = grid[0].size();
    	if(columns <= 0){
    		return 0;
    	}
    	if(grid[0][0] < 0){
    		return rows * columns;
    	}
    	if(grid[rows-1][columns-1] >= 0){
    		return 0;
    	}
    	int res = 0;
    	int max_steps = columns;
    	for(int row = 0;row<rows;row++){
    		int step = 0;
    		while(step<max_steps){
    			if(grid[row][step] < 0){
    				res += (rows-row) * (max_steps - step);
    				max_steps = step;
    				break;
    			}
    			step += 1;
    		}

    	}
    	return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}