#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int> >& matrix) {
		vector<int> res;
		int cur_row=0;
		int cur_col=0;
		int row_num = matrix.size();
		if(row_num == 0){
			return res;
		}
		int col_num = matrix[0].size();
		if(col_num == 0){
			return res;
		}
		bool left_down = false;
		while(1){
			//cout<<"left_down is: "<<left_down<<endl;
			//cout<<"Push row: "<<cur_row << " col: " << cur_col<<endl;
			res.push_back(matrix[cur_row][cur_col]);
			if(cur_row == row_num-1 && cur_col == col_num-1){
				break;
			}
			if(left_down){
				if(cur_row+1 >= row_num || cur_col - 1< 0){
					left_down = !left_down;
					if(cur_row+1 >= row_num && cur_col - 1<= 0){
						cur_col += 1;
					}else if(cur_row+1 >= row_num){
						cur_col += 1;
					}else{
						cur_row += 1;
					}
				}else{
					cur_row += 1;
					cur_col -= 1;
				}
			}else{
				if(cur_row-1 < 0 || cur_col + 1>= col_num){
					left_down = !left_down;
					if(cur_row-1 <= 0 && cur_col + 1>= col_num){
						cur_row += 1;
					}else if(cur_row-1 <= 0){
						cur_col += 1;
					}else{
						cur_row += 1;
					}
				}else{
					cur_row -= 1;
					cur_col += 1;
				}
			}
		}
		return res;
    }
};

int main(int argc, char ** argv){

	return 0;
}