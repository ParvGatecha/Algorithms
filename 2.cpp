#include <iostream>
#include <vector>
#include <string>

using namespace std;

long long pisano_period(long long m) {
    long long prev = 0, curr = 1;
    for (long long i = 0; i < 6*m; ++i) {
        long long temp = (prev + curr) % m;
        prev = curr;
        curr = temp;
        if (prev == 0 && curr == 1) {
            
            return i + 1;
        }
    }
    return m * m;
}

long long fibonacci_mod(const string &n_str, long long m) {
    long long period = pisano_period(m);
    cout<<" period: "<<period<<endl;
    long long n_mod = 0;
    for (char c : n_str) {
        n_mod = (n_mod * 10 + (c - '0')) % period;
    }

    if (n_mod == 0) return 0;
    if (n_mod == 1) return 1;

    long long prev = 0, curr = 1;
    for (long long i = 2; i <= n_mod; ++i) {
        long long temp = (prev + curr) % m;
        prev = curr;
        curr = temp;
    }

    return curr;
}

int main() {
    // string n = "10000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000"; // Example n = 10^10000
    // long long m = 100000;  // Example m = 10^5
    string n = "7";
    long long m = 4;

    cout << "F(" << n << ") % " << m << " = " << fibonacci_mod(n, m) << endl;

    return 0;
}
