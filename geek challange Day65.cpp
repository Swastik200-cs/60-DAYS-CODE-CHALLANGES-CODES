#include <iostream>
using namespace std;

class Solution {
public:
    bool isPower(int x, int y) {
        if (x == 1) return y == 1;
        while (y % x == 0) {
            y /= x;
        }
        return y == 1;
    }
};
int main() {
    Solution obj;
    int x, y;
    cout << "Enter x and y: ";
    cin >> x >> y;
    if (obj.isPower(x, y)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}