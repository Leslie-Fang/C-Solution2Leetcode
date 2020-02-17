#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if(matrix.empty())
		{
			return false;
		}
		if(matrix[0].empty())
		{
			return false;
		}
		int upx = 0;
		int upy = 0;
		int downx = matrix.size()-1;
		int downy = matrix[0].size()-1;
		int temp_upx = upx;
		int temp_upy = upy;
		int temp_downx = downx;
		int temp_downy = downy;
		while(temp_upx <= downx && temp_downy >= 0)
		{
			if(matrix[temp_upx][temp_downy] == target)
			{
				return true;
			}else if(matrix[temp_upx][temp_downy] > target)
			{
				temp_downy -= 1;
			}else
			{
				temp_upx += 1;
			}
		}
		return false;
	}
};

int main(int argc, char ** argv)
{

	return 1;
}