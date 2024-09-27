#include<bits/stdc++.h>
using namespace std;

long maxScore(long n, long k, const vector<long>& nums) {
    long left = k;
    long right = k;
    long min_val = nums[k];
    long max_score = min_val;

    while (left > 0 || right < n - 1) {
        if (left > 0 && (right == n - 1 || nums[left - 1] >= nums[right + 1])) {
            left--;
            min_val = min(min_val, nums[left]);
        } else {
            right++;
            min_val = min(min_val, nums[right]);
        }

        max_score = max(max_score, min_val * (right - left + 1));
    }

    return max_score;
}

int main() {
    long n, k;
    cin >> n >> k;
    vector<long> nums(n);
    for (long i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    long result = maxScore(n, k, nums);
    cout << result << endl;

    return 0;
}
