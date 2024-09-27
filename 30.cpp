// Given an array of integers , design a Θ(n2 ) algorithm to decide if there is i, j, k such
// that A[i] + A[j] = A[k]

#include <iostream>
#include <vector>
#include <set>
using namespace std;

int countPairs(const vector<int>& A) {
    int n = A.size();
    int count = 0;
    int i = 0, j = 1;
    set<int> s(A.begin(), A.end());

    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            if(s.find(A[i]+A[j])!=s.end()){
                count++;
            }
        }
    }

    return count;
}

int main() {
    vector<int> A = {1, 2, 4, 6, 10, 14};
    int X = 3;
    int result = countPairs(A);
    
    cout << "Number of pairs where A[j] - A[i] > " << X << " is: " << result << endl;
    return 0;
}
