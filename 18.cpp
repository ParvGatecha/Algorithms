// Given a array A of numbers , write a linear time algorithm to compute array B, such
// that B[i] = j, j is the largest j < i such that A[j] > A[i].B[i] = −1 if all the numbers
// to the left of A[i] are less than or equal to A[i].

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> computeNextGreaterToLeft(const vector<int>& A) {
    int n = A.size();
    vector<int> B(n, -1);
    stack<int> s;

    for (int i = 0; i < n; ++i) {
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
    vector<int> B = computeNextGreaterToLeft(A);

    cout << "Array B: ";
    for (int i = 0; i < B.size(); ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
