#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        string n;
        char k;
        cin >> n >> k;
        
        int count = 0;
        for (char digit : n) {
            if (digit == k) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}
