// Given an array of sorted integers and an integer X > 0 , design a linear time algorithm
// to count the number of pair elements in the array such that A[j] − A[i] > X.

#include <iostream>
#include <vector>
using namespace std;

int countPairsWithDifferenceGreaterThanX(const vector<int>& A, int X) {
    int n = A.size();
    int count = 0;
    int i = 0, j = 1;

    while (i < n && j < n) {
        while (j < n && A[j] - A[i] <= X) {
            j++;
        }
        
        if (j < n) {
            count += (n - j);
        }

        i++;
        
        if (j <= i) {
            j = i + 1;
        }
    }

    return count;
}

int main() {
    vector<int> A = {1, 2, 4, 7, 10, 14};
    int X = 3; 
    int result = countPairsWithDifferenceGreaterThanX(A, X);
    
    cout << "Number of pairs where A[j] - A[i] > " << X << " is: " << result << endl;
    return 0;
}
