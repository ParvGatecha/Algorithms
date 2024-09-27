// Given a sequence of n numbers and an integer k, design a linear time algorithm to
// compute the length of the maximum sum sub array , whos length is at least k.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSumSubarrayOfLengthAtleastK(vector<long long int>& a,int k) {
    int n = a.size();
        long long int sum = 0;
        for(long long int i = 0; i < k; i++){
            sum += a[i];
        }
        long long int maxsum = sum;
        long long int p = maxsum;
        for(long long int  i = k; i < n; i++){
            sum = sum + a[i] - a[i - k];
            p = max(p + a[i], sum);
            maxsum = max(maxsum, p);
        }
        return maxsum; 
}

int main() {
    vector<long long int> arr = {7, 1, 55, 3, -55, 5,1};
    int len = maxSumSubarrayOfLengthAtleastK(arr,4);
    
    cout << "Maximum sum: " << len << endl;  // Output the result
    return 0;
}
