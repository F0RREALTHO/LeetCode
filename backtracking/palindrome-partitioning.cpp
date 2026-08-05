class Solution {
public:

    bool is_palindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }

    void f(vector<vector<string>>& ans,vector<string>& cur ,string s, int n, int idx){
        if(idx==n){
            ans.push_back(cur);
            return;
        }

        for(int i = idx; i<n; i++){
            if(is_palindrome(s,idx,i)){
                cur.push_back(s.substr(idx,i-idx+1));
                f(ans,cur,s,n,i+1);
                cur.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        int n = s.length();
        f(ans,cur,s,n,0);

        return ans;
    }
};