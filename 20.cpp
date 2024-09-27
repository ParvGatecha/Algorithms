// Given a array A of numbers , write an O(n log n) linear time algorithm to compute
// array B, such that B[i] = j, j is the largest j such that A[j] > A[i].B[i] = n if all the
// numbers to the right of A[i] are less than or equal to A[i]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> computeNextGreater(const vector<int>& A) {
    int n = A.size();
    vector<int> B(n, n);
    stack<int> s;
    
    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] <= A[i]) {
            s.pop();
        }

        if (!s.empty()) {
            B[i] = s.top();
        }

        s.push(i);
    }

    return B;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> B = computeNextGreater(A);

    cout << "Array B: ";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
