// Given n, radius of a circle with (0, 0) as center, write a linear time algorithm to
// compute the number of lattice (integer) points inside the circle

#include <iostream>
#include <cmath>

using namespace std;

long long int countLatticePointsInsideCircle(int r) {
    long long int count = 0;

    for (long long int x = 0; x <= r; ++x) {
        long long int y_max = static_cast<long long int>(sqrt(r * r - x * x));
        count += (y_max+1);
    }

    count = 4 * count - 4 * r - 7;

    return count;
}

int main() {
    int r = 1000000;
    int result = countLatticePointsInsideCircle(r);
    
    cout << "Number of lattice points inside the circle: " << result << endl;

    return 0;
}
