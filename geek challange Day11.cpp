#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int equalSumSpan(vector<int> &a1, vector<int> &a2) {
        unordered_map<int,int> mp;
        int sum = 0, ans = 0;
        for(int i = 0; i < a1.size(); i++) {
            sum += a1[i] - a2[i];
            if(sum == 0)
                ans = i + 1;
            if(mp.count(sum))
                ans = max(ans, i - mp[sum]);
            else
                mp[sum] = i;
        }
        return ans;
    }
};
int main() {
    int n;
    cout << "Enter size of arrays: ";
    cin >> n;
    vector<int> a1(n), a2(n);
    cout << "Enter elements of array a1: ";
    for(int i = 0; i < n; i++)
        cin >> a1[i];
    cout << "Enter elements of array a2: ";
    for(int i = 0; i < n; i++)
        cin >> a2[i];
    Solution obj;
    int result = obj.equalSumSpan(a1, a2);
    cout << "Longest Common Span Length = " << result << endl;
    return 0;
}