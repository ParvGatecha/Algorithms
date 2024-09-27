#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

long long pisano_period(long long m) {
    unordered_map<string, long long> seen;
    long long F0 = 0, F1 = 1, F2 = 2;
    long long F3;
    
    seen[to_string(F0) + "," + to_string(F1) + "," + to_string(F2)] = 0;

    for (long long i = 3; i <= m * m * m; ++i) {
        long long temp = F3;
        F3 = (2 * F2 - 3 * F0) % m;
        if (F3 < 0) F3 += m;

        F0 = F1;
        F1 = F2;
        F2 = temp;

        string state = to_string(F0) + "," + to_string(F1) + "," + to_string(F2);
        if (seen.count(state)) {
            return i - seen[state];
        }
        seen[state] = i;
    }
    return m * m * m;
}

long long generalized_sequence_mod(const string &n_str, long long m) {
    
    long long period = pisano_period(m);

    long long n_mod = 0;
    for (char c : n_str) {
        n_mod = (n_mod * 10 + (c - '0')) % period;
    }

    if (n_mod == 0) return 0;
    if (n_mod == 1) return 1;
    if (n_mod == 2) return 2;

    long long F0 = 0, F1 = 1, F2 = 2, F3 = 0;
    for (long long i = 3; i <= n_mod; ++i) {
        long long temp = F3;
        F3 = (2 * F2 - 3 * F0) % m;
        if (F3 < 0) F3 += m;

        F0 = F1;
        F1 = F2;
        F2 = temp;
    }

    return F3;
}

int main() {
    // string n = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"; // Example n = 10^10000
    string n = "3";
    long long m = 100000;

    cout << "F(" << n << ") % " << m << " = " << generalized_sequence_mod(n, m) << endl;

    return 0;
}