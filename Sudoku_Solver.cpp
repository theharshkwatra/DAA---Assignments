#include<bits/stdc++.h>
using namespace std;


bool isPossible(int row, int col, int val, vector<vector<int>>& board){
    for(int i = 0; i < 9; i++){
        if(board[row][i] == val) return false;
    }

    for(int i = 0; i < 9; i++){
        if(board[i][col] == val) return false;
    }

    int duprow = (row/3)*3, dupcol = (col/3)*3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[duprow + i][dupcol + j] == val) return false;
        }
    }

    return true;
}


bool sudokuSolver(vector<vector<int>>& board){
    for(int row = 0; row < 9; row++){
        for(int col = 0; col < 9; col++){
            if(board[row][col] == 0){
                for(int val = 1; val <= 9; val++){
                    if(isPossible(row, col, val, board)){
                        board[row][col] = val;
                        if(sudokuSolver(board)) return true;
                        board[row][col] = 0;
                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main(){
    vector<vector<int>> board = {
        {3, 0, 6, 5, 0, 8, 4, 0, 0}, 
      	{5, 2, 0, 0, 0, 0, 0, 0, 0}, 
      	{0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0}, 
      	{9, 0, 0, 8, 6, 3, 0, 0, 5}, 
      	{0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0}, 
      	{0, 0, 0, 0, 0, 0, 0, 7, 4}, 
      	{0, 0, 5, 2, 0, 6, 3, 0, 0}};

        sudokuSolver(board);

        for(int row = 0; row < 9; row++){
            for(int col = 0; col < 9; col++){
                cout << board[row][col] << " ";
            }
            cout << endl;
        }

        return 0;
}