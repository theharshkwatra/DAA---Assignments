#include<bits/stdc++.h>
using namespace std;


string getOptimalOrder(vector<vector<int>>& bracket, int i, int j){
    if(i+1 == j){
        return "M " + to_string(i+1);
    }

    int k = bracket[i][j];
    string left = getOptimalOrder(bracket, i, k);
    string right = getOptimalOrder(bracket, k, j);
    
    return "(" + left + " X " + right + ")";
}


int minMatrixMultiplication(vector<int>& arr, string& expression){
    int n = arr.size();

    vector<vector<int>> dp(n, vector<int> (n,0));
    vector<vector<int>> bracket(n, vector<int> (n,0));
    
    for(int len = 2; len < n; len++){
        for(int i = 0; i < n - len; i++){
            int  j = i + len;
            dp[i][j] = INT_MAX;

            for(int k = i+1; k < j; k++){
                int cost = dp[i][k] + dp[k][j] + arr[i]*arr[j]*arr[k];

                if(cost < dp[i][j]){
                    dp[i][j] = cost;
                    bracket[i][j] = k;
                }
            }
        }
    }

    expression = getOptimalOrder(bracket, 0, n-1);
    return dp[0][n-1];
}


int main(){
    vector<int> arr = {2,1,3,4};
    string expression = "";
    int result = minMatrixMultiplication(arr,expression);

    cout << "Output: " << expression << " with number of multiplications " << result << endl;
    
    return 0;
}