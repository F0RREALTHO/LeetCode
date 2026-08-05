class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int st = 0;
        while(target.size()){
            int x = target.front();
            target.erase(target.begin());
            while(st<x-1){
                ans.push_back("Push");
                ans.push_back("Pop");
                st++;
            }
            ans.push_back("Push");
            st++;
        }
        return ans;
    }
};