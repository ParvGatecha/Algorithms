// Given two sorted arrays of size m and n respectively and an integer k, design an
// O(log k) algorithm to find an element of rank k in the merged array.

#include <iostream>
#include <vector>
using namespace std;

int kthLargest(vector<int> A, vector<int> B, int la, int ra, int lb, int rb, int k)
{
    cout<<la<<" "<<ra<<" "<<lb<<" "<<rb<<" "<<k<<endl;
    if (ra<la)
        return B[rb-k+1];
    if (rb<lb)
        return A[ra-k+1];

    int ma = la + (ra - la) / 2;
    int mb = lb + (rb - lb) / 2;
    int n = (ra-la) + (rb-lb) + 2;
    if (k<=n/2) {
        if (A[ma] < B[mb])
            return kthLargest(A,B,ma+1,ra,lb,rb,k);
        else
            return kthLargest(A,B,la,ra,mb+1,rb,k);
    }
    else {
        if (A[ma] < B[mb])
            return kthLargest(A,B,la,ra,lb,mb-1,k-(rb-mb+1));
        else
            return kthLargest(A,B,la,ma-1,lb,rb,k-(ra-ma+1));
    }
}


int main()
{
    // Sample Input
    vector<int> A = { 2, 3, 6, 7, 9 };
    vector<int> B = { 1, 4, 8, 10 };
    int n = A.size()-1, m = B.size()-1;
    int k = 2;

    cout << kthLargest(A,B,0,n,0,m,k)<<endl;
    return 0;
}
