#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int noOfWays(int m, int n, int x) {
        if (x < n || x > n * m)
            return 0;
        vector<int> a(x + 1, 0), b(x + 1, 0);
        a[0] = 1;
        for (int c = 1; c <= n; c++) {
            fill(b.begin(), b.end(), 0);
            for (int sum = 1; sum <= x; sum++) {
                for (int e = 1; e <= m; e++) {
                    if (sum - e >= 0)
                        b[sum] += a[sum - e];
                }
            }
            a = b;
        }
        return a[x];
    }
};
int main() {
    Solution obj;
    int m, n, x;
    cout << "Enter number of faces (m): ";
    cin >> m;
    cout << "Enter number of dice (n): ";
    cin >> n;
    cout << "Enter target sum (x): ";
    cin >> x;
    int result = obj.noOfWays(m, n, x);
    cout << "Number of ways: " << result << endl;
    return 0;
}