// Given a sequence of n numbers, representing the stock prices of a stock on different
// days, design a linear time algorithm to compute the maximum profit that you can
// make by buying and selling a stock exactly once, you can sell a stock at least k days
// after you bought it.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxProfitAfterKDays(const vector<int>& prices, int k) {
    int n = prices.size();
    if (n <= k) return 0;

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = k; i < n; ++i) {
        min_price = min(min_price, prices[i - k]);

        int potential_profit = prices[i] - min_price;
        max_profit = max(max_profit, potential_profit);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 7, 3, 6, 8};
    int k = 2;
    int profit = maxProfitAfterKDays(prices, k);
    
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
