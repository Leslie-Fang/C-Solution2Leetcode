#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void DFS(vector<vector<char>>& grid, int i, int j, int& count)
    {

		    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size() or grid[i][j] != '1')
		        return ;
		    grid[i][j] = '#';
		    DFS(grid, i+1, j, count);
		    DFS(grid, i-1, j, count);
		    DFS(grid, i, j+1, count);
		    DFS(grid, i, j-1, count);

    	
    }
    int numIslands(vector<vector<char>>& grid) {
    	if(grid.size() == 0)
    	{
    		return 0;
    	}
    	int count = 0;
    	for(int i =0 ;i<grid.size();i++)
    	{
    		for(int j=0;j<grid[0].size();j++)
    		{
    			if(grid[i][j] == '1')
    			{
    				DFS(grid,i,j,count);
    				count += 1;
    			}
    			
    		}
    	}
        
        return count;
    }

};

int main(int argc, char** argv)
{

	return 1;
}