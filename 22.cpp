// Given a sequence of n numbers, representing the stock prices of a stock on different
// days, design a linear time algorithm to compute the maximum profit that you can
// 3make by buying and selling a stock exactly once, you can sell a stock exactly k days
// after you bought it.

#include <iostream>
#include <vector>
using namespace std;

int maxProfitWithDelay(const vector<int>& prices, int k) {
    int n = prices.size();
    if (n <= k) return 0;

    int max_profit = 0;
    int min_price = prices[0];

    for (int i = 0; i < n - k; ++i) {
        min_price = min(min_price, prices[i]);

        int selling_price = prices[i + k];

        int potential_profit = selling_price - min_price;
        max_profit = max(max_profit, potential_profit);
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int k = 2;
    int profit = maxProfitWithDelay(prices, k);
    
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
