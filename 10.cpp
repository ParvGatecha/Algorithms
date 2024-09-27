// Given a binary string of length n, design a linear time algorithm to compute the
// length of the largest sub-string which contains equal number of 0’s and 1’s.


#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int largestEqualSubstringLength(const string& binaryString) {
    unordered_map<int, int> sumMap;
    sumMap[0] = -1;

    int maxLength = 0;
    int cumulativeSum = 0;

    for (int index = 0; index < binaryString.size(); ++index) {
        if (binaryString[index] == '1') {
            cumulativeSum += 1;
        } else {
            cumulativeSum -= 1;
        }

        if (sumMap.find(cumulativeSum) != sumMap.end()) {
            int length = index - sumMap[cumulativeSum];
            maxLength = max(maxLength, length);
        } else {
            sumMap[cumulativeSum] = index;
        }
    }

    return maxLength;
}

int main() {
    string binaryString = "1100010110";
    int result = largestEqualSubstringLength(binaryString);
    cout << "Length of the largest substring with equal number of 0's and 1's: " << result << endl; // Output: 6
    return 0;
}
