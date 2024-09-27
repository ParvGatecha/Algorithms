// Given a array A of numbers , write a linear time algorithm to compute array B, such
// that B[i] = j, j is the smallest j > i such that A[j] < A[i].B[i] = n if all the numbers
// to the right of A[i] are greater than or equal to A[i]

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> computeNextSmaller(const vector<int>& A) {
    int n = A.size();
    vector<int> B(n, n);
    stack<int> s;

    for (int i = n - 1; i >= 0; --i) {
        while (!s.empty() && A[s.top()] >= A[i]) {
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
    vector<int> B = computeNextSmaller(A);

    cout << "Array B: ";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
