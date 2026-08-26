class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> ans;
        for(auto &s:strs){
            vector<int> cnt(26,0);
            for(char c:s){
                cnt[c-'a']++;
            }
            string k;
            for(int x:cnt){
                k+= to_string(x)+".";
            }
            ans[k].push_back(s);
        }
        vector<vector<string>> res;
        for(auto &s:ans){
            res.push_back(move(s.second));
        }
        return res;
    }
};