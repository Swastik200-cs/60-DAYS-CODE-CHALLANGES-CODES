#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
  bool valid(string s){
        if(s.size()==0) 
        return false;
        if(s.size()>1 && s[0]=='0') 
        return false;
        int num=0;
        for(char c:s){
            num=num*10+(c-'0');
        }
        return num <=255;
    }
    vector<string> generateIp(string &s) {
         vector<string> ans;
        int n=s.size();
        if(n<4 || n>12) 
        return ans;
        for(int i=1;i<=3;i++){
            for(int j=1;j<=3;j++){
                for(int k=1;k<=3;k++){
                    int l=n-(i+j+k);
                    if(l>=1 && l<=3)
            {
                string a=s.substr(0, i);
                        string b=s.substr(i, j);
                        string c=s.substr(i + j, k);
                        string d=s.substr(i + j + k, l);
                        if(valid(a) && valid(b) && valid(c) && valid(d)){
                            ans.push_back(a + "." + b + "." + c + "." + d);
                        }
            }
                }
            }
        }
        return ans;
    }
};