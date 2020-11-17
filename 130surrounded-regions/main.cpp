#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	void search(int row_index, int column_index, vector<vector<char> >& board, vector<vector<int> > &visited, vector<vector<int> > &negative_list){
		if(board[row_index][column_index] == 'X' || visited[row_index][column_index] != 0 || !surrend){
			return;	
		}
		if(negative_list[row_index][column_index] == 1){
			surrend = false;
			return;
		}
		visited[row_index][column_index] = 1;
		to_clear.push_back(make_pair(row_index, column_index));
		if(row_index-1 >= 0 && row_index+1 < board.size() && column_index-1 >= 0 && column_index+1 < board[0].size()){
			search(row_index-1, column_index, board, visited, negative_list);
			search(row_index+1, column_index, board, visited, negative_list);
			search(row_index, column_index-1, board, visited, negative_list);
			search(row_index, column_index+1, board, visited, negative_list);
		}else{
			surrend = false;
		}
		// if(surrend){
		// 	board[row_index][column_index] = 'X';
		// }else{
		// 	negative_list[row_index][column_index] = 1;
		// }
		return;
	}

    void solve(vector<vector<char> >& board) {
    	int rows = board.size();
    	if(rows <= 0){
    		return;
    	}
    	int columns = board[0].size();
    	vector<vector<int> > negative_list(rows, vector<int>(columns));
		for(int i=0;i<rows;i++){
			for(int j=0;j<columns;j++){
				if(board[i][j] == 'O' && negative_list[i][j] != 1){
					to_clear.clear();
					surrend = true;
					vector<vector<int> > visited(rows,vector<int>(columns));
					search(i, j, board, visited, negative_list);
					if(surrend){
						for(auto item:to_clear){
							board[item.first][item.second] = 'X';
						}
					}else{
						for(auto item:to_clear){
							negative_list[item.first][item.second] = 1;
						}	
					}
				}
			}
		}
        return;
    }

    vector<pair<int, int> > to_clear;
    bool surrend;
};

int main(int argc, char ** argv){
	return 0;
}