#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    int longestKSubstr(string &s, int k) {
        unordered_map<char,int> mp;
        int x = 0, y = 0;
        int a = -1;
        while(y < s.size()) {
            mp[s[y]]++;
            while(mp.size() > k) {
                mp[s[x]]--;
                if(mp[s[x]] == 0)
                    mp.erase(s[x]);
                x++;
            }
            if(mp.size() == k) {
                a = max(a, y - x + 1);
            }
            y++;
        }
        return a;
    }
};
int main() {
    Solution obj;
    string s;
    int k;
    cout << "Enter string: ";
    cin >> s;
    cout << "Enter k: ";
    cin >> k;
    int result = obj.longestKSubstr(s, k);
    cout << "Longest substring length with exactly " << k 
         << " distinct characters: " << result << endl;
    return 0;
}