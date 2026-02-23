#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
class Solution {
  public:
    vector<int> findUnion(vector<int>& a, vector<int>& b) {       
        vector<int> freq(100001, 0);
        vector<int> result;      
        for(int x : a)
            freq[x] = 1;
        for(int x : b)
            freq[x] = 1;       
        for(int i = 0; i <= 100000; i++) {
            if(freq[i] == 1)
                result.push_back(i);
        }      
        return result;
    }
};
int main() {
    int n, m;
    cout << "Enter size of array a: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of array a:\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << "Enter size of array b: ";
    cin >> m;
    vector<int> b(m);
    cout << "Enter elements of array b:\n";
    for (int i = 0; i < m; i++)
        cin >> b[i];
    Solution obj;
    vector<int> ans = obj.findUnion(a, b);
    sort(ans.begin(), ans.end());
    cout << "\nUnion of arrays:\n";
    for (int x : ans)
        cout << x << " ";
    return 0;
}