#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
        int gcd(int a, int b) {
            // Code here
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    int pour(int fromJug,int toJug,int d) {
         int from = fromJug; 
         int to = 0; 
         int step = 1;        
         while (from != d && to != d) {
            int temp = min(from, toJug - to);
            to += temp;
            from -= temp;
            step++;
            if (from == d || to == d)
                break;
            if (from == 0) {
                from = fromJug;
                step++;
            }
            if (to == toJug) {
                to = 0;
                step++;
            }
        }
         return step;
    }
    int minSteps(int m, int n, int d) {
         if (d > max(m, n))
            return -1;
            if (d % gcd(m, n) != 0)
            return -1;
        if (d == m || d == n)
            return 1;

        return min(pour(m, n, d), pour(n, m, d));
    }
};

int main() {
    Solution obj;
    int m, n, d;
    cout << "Enter Jug1 Capacity (m): ";
    cin >> m;
    cout << "Enter Jug2 Capacity (n): ";
    cin >> n;
    cout << "Enter Target (d): ";
    cin >> d;
    int result = obj.minSteps(m, n, d);
    if (result == -1)
        cout << "Not possible to measure " << d << " liters.\n";
    else
        cout << "Minimum steps required: " << result << endl;
    return 0;
}