// Given a array A of numbers , write an O(n log n) time algorithm to compute array
// B, such that B[i] = j, j is the smallest j such that A[j] < A[i].B[i] = −1 if all the
// numbers to the left of A[i] are greater than or equal to A[i]

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> computeArrayB(const vector<int>& A) {
    int n = A.size();
    vector<int> B(n, -1); // Initialize B with -1
    stack<int> s; // Stack to store indices

    // Iterate through the array A from left to right
    for (int i = 0; i < n; ++i) {
        // Pop elements from the stack while they are greater than or equal to A[i]
        while (!s.empty() && A[s.top()] >= A[i]) {
            s.pop();
        }

        // If the stack is not empty, set B[s.top()] to i
        if (!s.empty()) {
            B[s.top()] = i;
        }

        // Push the current index onto the stack
        s.push(i);
    }

    return B;
}

int main() {
    vector<int> A = {4, 5, 2, 10, 8};
    vector<int> B = computeArrayB(A);

    // Print the result
    cout << "Array B: ";
    for (int i : B) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
