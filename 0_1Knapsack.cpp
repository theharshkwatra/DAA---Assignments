#include<bits/stdc++.h>
using namespace std;


int knapsack(int W, vector<int>& wt, vector<int>& val, vector<int>& selectedItems){
    int n = val.size();

    vector<vector<int>> dp(n+1, vector<int> (W + 1, 0));

    for(int i = 1; i <= n; i++){
        for(int cap = 0; cap <= W; cap++){
            int pick = 0;
            if(wt[i - 1] <= cap){
                pick = val[i-1] + dp[i-1][cap - wt[i - 1]];
            }

            int notPick = dp[i - 1][cap];
            dp[i][cap] = max(pick, notPick);
        }
    }


    int i = n, cap = W;
    while(i > 0 )


    return dp[n][W];
}


int main(){
    vector<int> wt = {5, 3, 8, 6};
    vector<int> val = {2, 3, 4, 5};
    int W = 7;


    return 0;
}