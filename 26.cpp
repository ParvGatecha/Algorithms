// Given a sequence of n numbers and an integer k, design a linear time algorithm to
// compute the length of the maximum sum sub array , whos length is exactly k.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSumSubarrayOfLengthK(vector<int>& arr,int k) {
    int sum = 0;
    int length = 0;
    int j = 0;
    int m = 0;
    for(int i = 0; i<arr.size(); i++){
        sum += arr[i];
        while(i-j+1>k){
            sum -= arr[j];
            j++;
        }
        m = max(m,sum);
    }
    return m;
}

int main() {
    vector<int> arr = {7, 1, 55, 3, -55, 55,1};
    int len = maxSumSubarrayOfLengthK(arr,3);
    
    cout << "Maximum sum: " << len << endl;
    return 0;
}
