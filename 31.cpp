// Given an array of integers , design an efficient algorithm to decide if there is i, j, k, l
// such that A[i] − 2A[j] = A[k] − 3A[l].

#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
using namespace std;

bool findIndicesWithGivenEquation(const vector<int>& A) {
    int n = A.size();
    unordered_map<int, vector<pair<int, int>>> hashMap;

    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            int diff1 = A[i] - A[k];
            hashMap[diff1].emplace_back(i, k);
        }
    }

    for (int j = 0; j < n; ++j) {
        for (int l = 0; l < n; ++l) {
            int diff2 = 2 * A[j] - 3 * A[l];

            if (hashMap.find(diff2) != hashMap.end()) {
                for (auto& pair : hashMap[diff2]) {
                    int i = pair.first;
                    int k = pair.second;

                    if (i != j && i != l && k != j && k != l) {
                        cout << "Found indices: i = " << i << ", j = " << j 
                             << ", k = " << k << ", l = " << l << endl;
                        return true;
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    vector<int> A = {1, 5, 3, 2, 8, 10};
    bool result = findIndicesWithGivenEquation(A);
    
    if (result) {
        cout << "Indices satisfying the equation were found." << endl;
    } else {
        cout << "No indices satisfy the equation." << endl;
    }

    return 0;
}
