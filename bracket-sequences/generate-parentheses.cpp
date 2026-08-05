class Solution {
public:
    void f(int n, string s,int op, vector<string>& ans){
        if(count(s.begin(), s.end(), '(') == n){
            while(s.size()!=2*n) s.push_back(')');
            ans.push_back(s);
            return;
        }
        f(n,s+'(', op+1,ans);
        if(op>0) f(n,s+')',op-1,ans);

    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        f(n,"",0,ans);
        return ans;
    }
};