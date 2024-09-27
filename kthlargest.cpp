#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& arr, int left, int right) {
    int randomPivotIndex = left + rand() % (right - left + 1);
    swap(arr[randomPivotIndex], arr[right]);
    int pivot = arr[right];
    
    int i = left;
    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]);
    return i;
}

int quickSelect(vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        int count = right - pivotIndex + 1;

        if (count == k) {
            return arr[pivotIndex];
        } else if (k < count) {
            return quickSelect(arr, pivotIndex + 1, right, k);
        } else {
            return quickSelect(arr, left, pivotIndex - 1, k - count);
        }
    }
    return -1;
}

int main() {
    srand(time(0));

    int n, k;
    cin >> n >> k;

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int result = quickSelect(arr, 0, n - 1, k);

    cout << result << endl;

    return 0;
}
