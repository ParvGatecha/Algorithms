// Given a binary string S of length n, design a linear time algorithm to compute k,
// such that the number of 0’s in S[0..k] is equal to number of 1’s in S[k+1..n-1]

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;
int FindIndex(string s){
    int n = s.size(),k=0;

    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            k++;
        }
    }

    return k-1;
}
int main() {
    string s = "000";
    int result = FindIndex(s);
    cout << "Index is: " << result << endl;
    return 0;
}