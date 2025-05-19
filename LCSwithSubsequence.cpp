#include<bits/stdc++.h>
using namespace std;


string getLCS(string s1, string s2, vector<vector<int>>& dp){
    string LCS = "";
    int i = s1.size();
    int j = s2.size();
    while(i > 0 && j > 0){
        if(s1[i-1] == s2[j-1]){
            LCS += s1[i-1];
            i--;
            j--;
        }else if(s1[i-1] > s2[j-1]){
            i--;
        }else{
            j--;
        }
    }

    reverse(LCS.begin(),LCS.end());
    return LCS;
}


int longestCommonSubsequence(string s1, string s2, string& lcsResult){
    int n = s1.size();
    int m = s2.size();

    vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    lcsResult = getLCS(s1,s2,dp);
    return dp[n][m];
}

int main(){
    string s1 = "abcde";
    string s2 = "ace";
    string lcs = "";
    cout << longestCommonSubsequence(s1,s2,lcs) << endl;
    cout << lcs << endl;

    return 0;
}