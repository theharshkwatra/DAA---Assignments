#include <iostream>
#include <vector>
using namespace std;

// Function to compute the maximum value and print selected items
int knapsack(int W, const vector<int>& val, const vector<int>& wt, vector<int>& selectedItems) {
    int n = val.size();
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int cap = 0; cap <= W; cap++) {
            int pick = 0;
            if (wt[i - 1] <= cap)
                pick = val[i - 1] + dp[i - 1][cap - wt[i - 1]];
            
            int notPick = dp[i - 1][cap];
            dp[i][cap] = max(pick, notPick);
        }
    }

    // Backtrack to find selected items
    int i = n, cap = W;
    while (i > 0 && cap > 0) {
        if (dp[i][cap] != dp[i - 1][cap]) {
            selectedItems.push_back(i); // Store 1-based index
            cap -= wt[i - 1];
        }
        i--;
    }

    return dp[n][W];
}

int main() {
    vector<int> val = {1, 2, 3};
    vector<int> wt = {4, 5, 1};
    int W = 4;

    vector<int> selectedItems;
    int result = knapsack(W, val, wt, selectedItems);

    cout << "Maximum value in knapsack: " << result << endl;
    cout << "Items selected (1-based index): ";
    for (int idx : selectedItems) {
        cout << "Item" << idx << " ";
    }
    cout << endl;

    return 0;
}
