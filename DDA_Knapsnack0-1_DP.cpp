#include <iostream>
#include <algorithm>
using namespace std;

int knapsack(int weight[], int profit[], int n, int W) {
    int dp[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (weight[i - 1] <= w)
                dp[i][w] = max(profit[i - 1] + dp[i - 1][w - weight[i - 1]],
                               dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // find which items were taken
    cout << "Items taken: ";
    int w = W;
    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << i << " ";
            w -= weight[i - 1];
        }
    }
    cout << endl;

    return dp[n][W];
}

int main() {
    int n, W;
    cout << "Enter number of items: ";
    cin >> n;

    int weight[n], profit[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter weight and profit of item " << i + 1 << ": ";
        cin >> weight[i] >> profit[i];
    }

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int maxProfit = knapsack(weight, profit, n, W);
    cout << "Maximum profit = " << maxProfit << endl;

    return 0;
}
