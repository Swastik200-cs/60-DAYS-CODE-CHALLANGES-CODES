#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int isPallindrome(long long int N) {
        string s = "";
        while (N) {
            s += (N % 2) + '0';
            N /= 2;
        }
        string t = s;
        reverse(t.begin(), t.end());
        return s == t;
    }
};
int main() {
    long long int N;
    cin >> N;
    Solution obj;
    cout << obj.isPallindrome(N);
    return 0;
}