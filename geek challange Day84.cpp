#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool isValid(string str) {
        int count = 0;
        for(char ch : str) {
            if(ch == '(')
                count++;
            else if(ch == ')') {
                count--;
                if(count < 0)
                    return false;
            }
        }
        return count == 0;
    }
    vector<string> validParenthesis(string &s) {
        vector<string> ans;
        unordered_set<string> visited;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        bool found = false;
        while(!q.empty()) {

            string curr = q.front();
            q.pop();
            if(isValid(curr)) {

                ans.push_back(curr);
                found = true;
            }
            if(found)
                continue;
            for(int i = 0; i < curr.size(); i++) {
                if(curr[i] != '(' && curr[i] != ')')
                    continue;
                string next =
                    curr.substr(0, i) +
                    curr.substr(i + 1);
                if(visited.find(next) == visited.end()) {

                    visited.insert(next);
                    q.push(next);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    Solution obj;
    vector<string> result =
        obj.validParenthesis(s);
    cout << "\nValid Parentheses Strings:\n";
    for(string str : result) {
        cout << str << endl;
    }
    return 0;
}