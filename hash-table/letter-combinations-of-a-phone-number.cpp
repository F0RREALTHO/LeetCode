class Solution {
public:

    void f(string digits, int n, map<char,string>& mp,vector<string>& ans, string cur, int i){
        if(cur.length()==n){
            ans.push_back(cur);
            return;
        }

        char ch = digits[i];
        for(auto s:mp[ch]){
            cur+=s;
            
            f(digits,n,mp,ans,cur,i+1);

            cur.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char,string> mp = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        int n = digits.length();
        vector<string> ans;
        string cur;
        map<char,bool> vis;

        f(digits,n,mp,ans,cur,0);

        return ans;
    }
};