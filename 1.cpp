#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<long long> > Matrix;

const int MATRIX_SIZE = 2;

Matrix matrix_mul(const Matrix &A, const Matrix &B, long long m) {
    Matrix C(MATRIX_SIZE, vector<long long>(MATRIX_SIZE, 0));
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

Matrix matrix_pow(Matrix base, long long power, long long m) {
    Matrix result(MATRIX_SIZE, vector<long long>(MATRIX_SIZE, 0));
    result[0][0] = result[1][1] = 1;

    while (power) {
        if (power % 2 == 1) {
            result = matrix_mult(result, base, m);
        }
        base = matrix_mult(base, base, m);
        power /= 2;
    }

    return result;
}

long long fibonacci_mod(long long n, long long m) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    Matrix T = {
        {1, 1},
        {1, 0}
    };

    Matrix T_n_minus_1 = matrix_pow(T, n - 1, m);

    long long Fn = (T_n_minus_1[0][0] * 1 + T_n_minus_1[0][1] * 0) % m;

    return Fn;
}

int main() {
    long long n = 1000000000000000000LL;
    long long m = 100000;

    cout << "F(" << n << ") % " << m << " = " << fibonacci_mod(n, m) << endl;

    return 0;
}
