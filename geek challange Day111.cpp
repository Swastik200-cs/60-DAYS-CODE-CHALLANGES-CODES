#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int maxSubstring(string &s) {
    int currSum = 0;
    int maxSum = -1;
    for (char ch : s) {
        int val = (ch == '0') ? 1 : -1;
        currSum = max(val, currSum + val);
        maxSum = max(maxSum, currSum);
    }

    return maxSum;
}

int main() {
    string s;
    cin >> s;
    cout << maxSubstring(s) << endl;
    return 0;
}