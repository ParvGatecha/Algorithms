// You are given an array of integers, there is a sliding window of size at most k which
// is moving from left to right. You can only see at most k numbers in the window.
// Each time the sliding window moves right by one position. Design an linear time
// algorithm to compute the maximum in each window

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    vector<int> result;
    if (nums.empty() || k <= 0) return result;

    deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, 4, 5, 3, 6, 7};
    int k = 3;

    vector<int> maxInWindows = maxSlidingWindow(nums, k);

    cout << "Maximums in each sliding window of size " << k << ": ";
    for (int max : maxInWindows) {
        cout << max << " ";
    }
    cout << endl;

    return 0;
}
