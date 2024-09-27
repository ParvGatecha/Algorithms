// Given a stream of n (about 109 ) numbers, design an O(n) time and O(k) space
// algorithm to find an element of rank k

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

int partition(vector<int>& nums, int left, int right, int pivotIndex) {
    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (nums[i] > pivotValue) {
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }

    swap(nums[storeIndex], nums[right]);
    return storeIndex;
}

int quickselect(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);

    pivotIndex = partition(nums, left, right, pivotIndex);

    if (k == pivotIndex) {
        return nums[k];
    } else if (k < pivotIndex) {
        return quickselect(nums, left, pivotIndex - 1, k);
    } else {
        return quickselect(nums, pivotIndex + 1, right, k);
    }
}

int findKthLargest(vector<int>& nums, int k) {
    return quickselect(nums, 0, nums.size() - 1, k - 1); 
}

int main() {
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    int k = 4;
    cout << "The " << k << "th largest element is " << findKthLargest(nums, k) << endl;
    return 0;
}
