#include<bits/stdc++.h>
using namespace std;

bool isSafe(int node, int color, vector<int>& colors, vector<vector<int>>& graph, int n){
    for(int i = 0; i < n; i++){
        if(graph[node][i] == 1 && colors[i] == color){
            return false;
        }
    }
    return true;
}

void solveGraphColoring(int node, vector<vector<int>>& graph, int m, int n, vector<int>& colors, vector<vector<int>>& allSolutions){
    if(node == n){
        allSolutions.push_back(colors);
        return;
    }

    for(int col = 1; col <= m; col++){
        if(isSafe(node, col, colors, graph, n)){
            colors[node] = col;
            solveGraphColoring(node + 1, graph, m, n, colors, allSolutions);
            colors[node] = 0; // backtrack
        }
    }
}

int main(){
    int n = 4; // number of nodes
    int m = 3; // number of colors

    // Example graph (adjacency matrix)
    vector<vector<int>> graph = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };

    vector<int> colors(n, 0);
    vector<vector<int>> allSolutions;

    solveGraphColoring(0, graph, m, n, colors, allSolutions);

    if(!allSolutions.empty()){
        cout << "All valid colorings:\n";
        for(auto& solution : allSolutions){
            cout << "[";
            for(int i = 0; i < n; i++){
                cout << solution[i];
                if(i < n - 1) cout << ",";
            }
            cout << "]\n";
        }
    } else {
        cout << "No solution exists" << endl;
    }

    return 0;
}
