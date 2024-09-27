// Given a sequence of n numbers, representing the stock prices of a stock on different
// days, design a linear time algorithm to compute the maximum profit that you can
// make by buying and selling a stock exactly once, you can sell a stock at most k days
// after you bought it.

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <deque>

using namespace std;

int maxProfitWithinKDays(const vector<int>& prices, int k) {
    int n = prices.size();
    int maxp = 0;
    deque<int> dq;

    for(int i = 0; i<n ; i++){
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && prices[dq.back()] > prices[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            int min = prices[dq.front()];
            int profit = prices[i] - min;
            maxp = max(maxp,profit);
        }
    }
    return maxp;
}

int main() {
    vector<int> prices = {3, 2, 7, 9, 10, 3};
    int k = 3;
    cout << "Maximum profit within " << k << " days: " << maxProfitWithinKDays(prices, k) << endl;
    return 0;
}
