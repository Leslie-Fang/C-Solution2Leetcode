#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int> >& matrix)
    {
		if (matrix.empty())
			return;
		for (int layer = 0; layer < matrix.size() / 2; ++layer)
		{
			int first = layer;
			int last = matrix.size() - first - 1;
			for (int i = first; i < last; ++i)
			{
				int tmp = matrix[first][i];
				matrix[first][i] = matrix[last - i + layer][first];
				matrix[last - i + layer][first] = matrix[last][last - i + layer];
				matrix[last][last - i + layer] = matrix[i][last];
				matrix[i][last] = tmp;
			}
		}
    }
};

int main(int argc, char ** argv)
{
	Solution * mySolution = new Solution();
	vector<vector<int> > input;
	mySolution->rotate(input);
	return 0;
}