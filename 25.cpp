// Given a sequence of n numbers design a linear time algorithm to compute the length
// of the maximum sum sub array.

#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int maxSumSubarray(vector<int>& arr) {
    int sum = 0;
    int length = 0;
    int j = 0;
    int m = 0;
    for(int i = 0; i<arr.size(); i++){
        sum+=arr[i];
        if(sum<0){
            sum = 0;
            j = i;
        }
        if(sum>m){
            length = i-j;
            m = sum;
        }
        else if(sum==m){
            length = max(length,i-j+1);
        }
    }
    return length;
}

int main() {
    vector<int> arr = {7, 1, 5, 3, -55, 55,1};
    int len = maxSumSubarray(arr);
    
    cout << "Maximum sum length: " << len << endl;
    return 0;
}
