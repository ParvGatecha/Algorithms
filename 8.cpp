#include <iostream>
#include <string>

using namespace std;

int countDenseSubstrings(const string& s) {
    int n = s.size();
    int left = 0, right = 0;
    int count = 0, res = 0;

    while (right < n) {
        if (s[right] == '1') {
            count++;
        }
        while (count < right - left) {
            if (s[left] == '1') {
                count--;
            }
            left++;
        }
        res += right - left + 1;
        right++;
    }

    return res;
}

int main() {
    string input1 = "10011101";
    string input2 = "10101";
    string input3 = "000111";

    cout << "Result for '10011101': " << countDenseSubstrings(input1) << endl;
    cout << "Result for '10101': " << countDenseSubstrings(input2) << endl;
    cout << "Result for '000111': " << countDenseSubstrings(input3) << endl;

    return 0;
}