// Given a sequence of n numbers, representing the stock prices of a stock on different
// days, design a linear time algorithm to compute the maximum profit that you can
// make by buying and selling a stock exactly once, you can sell a stock only after you
// buy it

#include <iostream>
#include <vector>
using namespace std;

int maxProfit(const vector<int>& prices) {
    if (prices.empty()) return 0;

    int min_price = prices[0]; 
    int max_profit = 0;

    for (int price : prices) {
        if (price < min_price) {
            min_price = price;
        }

        int profit = price - min_price;
        if (profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    int profit = maxProfit(prices);
    
    cout << "Maximum profit: " << profit << endl;
    return 0;
}
