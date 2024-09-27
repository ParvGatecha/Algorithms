#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

int partition(vector<pair<int, int>>& arr, int left, int right, int pivotIndex) {
    int pivotValue = arr[pivotIndex].second;
    swap(arr[pivotIndex], arr[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (arr[i].second < pivotValue) {
            swap(arr[i], arr[storeIndex]);
            storeIndex++;
        }
    }

    swap(arr[storeIndex], arr[right]);
    return storeIndex;
}

int quickselect(vector<pair<int, int>>& arr, int left, int right, int k) {
    if (left == right) {
        return arr[left].second;
    }

    int pivotIndex = left + rand() % (right - left + 1);

    pivotIndex = partition(arr, left, right, pivotIndex);

    if (k == pivotIndex) {
        return arr[k].second;
    } else if (k < pivotIndex) {
        return quickselect(arr, left, pivotIndex - 1, k);
    } else {
        return quickselect(arr, pivotIndex + 1, right, k);
    }
}


int quickselectm(vector<int>& nums, int left, int right, int k) {
    if (left == right) {
        return nums[left];
    }

    int pivotIndex = left + rand() % (right - left + 1);

    int pivotValue = nums[pivotIndex];
    swap(nums[pivotIndex], nums[right]);
    int storeIndex = left;

    for (int i = left; i < right; i++) {
        if (nums[i] < pivotValue) {
            swap(nums[i], nums[storeIndex]);
            storeIndex++;
        }
    }
    swap(nums[storeIndex], nums[right]);

    if (k == storeIndex) {
        return nums[k];
    } else if (k < storeIndex) {
        return quickselectm(nums, left, storeIndex - 1, k);
    } else {
        return quickselectm(nums, storeIndex + 1, right, k);
    }
}

int findMedian(vector<int>& nums) {
    int n = nums.size();
    int medianIndex = (n - 1) / 2;
    return quickselectm(nums, 0, n - 1, medianIndex); 
}
vector<int> findKClosestToMedian(vector<int>& nums, int k) {
    int n = nums.size();
    int median = findMedian(nums);
    
    vector<pair<int, int>> distArr(n);
    for (int i = 0; i < n; i++) {
        distArr[i] = make_pair(nums[i], abs(nums[i] - median));
    }

    quickselect(distArr, 0, n - 1, k - 1);
    
    vector<int> result;
    for (int i = 0; i < k; i++) {
        result.push_back(distArr[i].first);
    }

    return result;
}

int main() {
    vector<int> nums = {7, 4, 1, 8, 9, 10, 2, 3, 5, 6};
    int k = 3;
    vector<int> result = findKClosestToMedian(nums, k);
    
    cout << "The " << k << " numbers closest to the median are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
