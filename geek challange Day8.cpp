#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int h = 0;
        for (int i = 0; i < citations.size(); i++) {
            if (citations[i] >= i + 1)
                h = i + 1;
            else
                break;
        }
        return h;
    }
};
int main() {
    int n;
    cout << "Enter number of papers: ";
    cin >> n;
    vector<int> citations(n);
    cout << "Enter citation counts:\n";
    for (int i = 0; i < n; i++) {
        cin >> citations[i];
    }
    Solution obj;
    int result = obj.hIndex(citations);
    cout << "H-Index = " << result << endl;
    return 0;
}