#include <iostream>
using namespace std;

class Solution {
public:
    string profession(int level, int pos) {
        pos--;
        int flips = 0;
        while (pos) {
            flips += pos & 1;
            pos >>= 1;
        }
        return (flips % 2) ? "Doctor" : "Engineer";
    }
};

int main() {
    int level, pos;
    cout << "Enter level: ";
    cin >> level;
    cout << "Enter position: ";
    cin >> pos;
    Solution obj;
    cout << "Profession: " << obj.profession(level, pos) << endl;
    return 0;
}