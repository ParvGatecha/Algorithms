// Given a sequence of n numbers and an integer k, design a linear time algorithm to
// compute the length of the maximum sum sub array , whos length is at most k.

#include <iostream>
#include <vector>
#include <deque>
#include <numeric>
#include <climits>

using namespace std;

int maxSumSubarrayOfLengthAtmostK(vector<int>& arr,int a,int b) {
    //  int sum =0, cnt =0, maxcnt =0;
    // for(int i=0; i<arr.size();i++){
    //     if(arr[i] >k){
    //         sum =0;
    //         cnt = 0;
    //         continue;
    //     }
    //     if((sum +arr[i]) <= k){
    //         cnt++;
    //         sum += arr[i];
    //     }
    //     else{
    //         cnt++;
    //         sum += arr[i];
    //         while(sum > k){
    //             sum -= arr[i-cnt+1];
    //             cnt--;
    //         }
    //     }
    //     maxcnt = max(cnt, maxcnt);
    // }
    // return maxcnt;





    int n = arr.size();

    vector<long long> prefix_sums(n + 1, 0);
    partial_sum(arr.begin(), arr.end(), prefix_sums.begin() + 1);
    // for(auto i:prefix_sums){
    //     cout<<i<<" ";
    // }
    cout<<endl;
    deque<int> deq;
    long long answer = LLONG_MIN;
    int d = b - a;

    for (int i = 0; i <= n + d; ++i) {
        if (!deq.empty() && deq.front() < i - d) {
            deq.pop_front();
        }

        if (i <= n) {
            while (!deq.empty() && prefix_sums[deq.back()] <= prefix_sums[i]) {
                deq.pop_back();
            }
            deq.push_back(i);
        }

        if (i >= b) {
            answer = max(answer,prefix_sums[deq.front()] - prefix_sums[i - b]);

            // cout<<answer<<endl;
        }
    }

    return answer;

   
}

int main() {
    vector<int> arr = {-1,-1,-2,-5,-2,-2};
    int a = 1;  //Smallest length
    int b = 3;  //Largest length
    int len = maxSumSubarrayOfLengthAtmostK(arr,a,b);
    
    cout << "Maximum sum: " << len << endl;
    return 0;
}