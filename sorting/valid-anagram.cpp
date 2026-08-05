class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.empty() || t.empty()) return true;
        if(s.length()!=t.length()) return false;

        vector<int> mp(26,0);
        for(char c: s) mp[c-'a']++;
        for(char k: t) mp[k-'a']--;

        for(int i =0; i<26;i++){
            if(mp[i]!=0) return false;
        }
        return true;
    }
};