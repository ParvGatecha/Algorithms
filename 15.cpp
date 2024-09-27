// Design a linear time algorithm to decide if a given sequence of numbers is a stack
// sequence

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isStackSequence(const vector<int>& sequence) {
    stack<int> st;
    int current_push = 1;
    int n = sequence.size();

    for (int i = 0; i < n; ++i) {
        int current = sequence[i];

        while (current_push <= current) {
            st.push(current_push);
            current_push++;
        }

        if (!st.empty() && st.top() == current) {
            st.pop();
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    vector<int> sequence = {1,3,2,5,4};
    // vector<int> sequence = {3, 1, 2};

    if (isStackSequence(sequence)) {
        cout << "The sequence is a valid stack sequence." << endl;
    } else {
        cout << "The sequence is not a valid stack sequence." << endl;
    }

    return 0;
}
