#include<bits/stdc++.h>
using namespace std;


bool isPossible(int row, int col, vector<string>& board, int n){
    int duprow = row, dupcol = col;
    
    while(row >= 0 && col >= 0){
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }

    row = duprow, col = dupcol;
    while(row >= 0){
      if(board[row][col] == 'Q') return false;
      row--;
    }

    row = duprow;
    while(row >= 0 && col < n){
      if(board[row][col] == 'Q') return false;
      row--;
      col++;
    }

  return true;
}


void solveNQueens(int row, vector<string>& board, vector<int>& current, vector<vector<int>>& result, int n){
    if(row == n){
        result.push_back(current);
        return;
    }

    for(int col = 0; col < n; col++){
        if(isPossible(row, col, board, n)){
            board[row][col] = 'Q';
            current.push_back(col + 1);
            solveNQueens(row + 1, board, current, result, n);
            board[row][col] = '.';
            current.pop_back();
        }
    }
}


int main(){
    int n = 4;
    vector<vector<int>> result;
    vector<int> current;
    vector<string> board(n, string(n, '.'));
    solveNQueens(0, board, current, result, n);

    if(!result.empty()){
        cout << "Output: [";
        for(int i = 0; i < n; i++){
            cout << result[0][i];
            if(i < n-1) cout << ",";
        }

        cout << ']' << endl;
    }

    return 0;
}