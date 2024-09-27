// CPP program to find largest substring
// having count of 1s more than count
// count of 0s.
#include <bits/stdc++.h>
using namespace std;

int findLongestSub(string bin)
{
	int n = bin.length(), i;

	int sum = 0;

	unordered_map<int, int> prevSum;

	int maxlen = 0;

	int currlen;

	for (i = 0; i < n; i++) {

		if (bin[i] == '1')
			sum++;
		else
			sum--;

		if (sum > 0) {
			maxlen = i + 1;
		}

		else if (sum <= 0) {
			if (prevSum.find(sum - 1) != prevSum.end()) {
				currlen = i - prevSum[sum - 1];
				maxlen = max(maxlen, currlen);
			}
		}

		if (prevSum.find(sum) == prevSum.end())
			prevSum[sum] = i;
	}

	return maxlen;
}

int main()
{
	string bin = "1010";
	cout << findLongestSub(bin);
	return 0;
}
