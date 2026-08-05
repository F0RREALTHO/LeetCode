class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        if (n == 0) return vector<int>(nums1.size(), -1);
        vector<int> nge(n,-1);
        stack<int> st;
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            if(!st.empty()){
                nge[i]=st.top();
            }
            st.push(nums2[i]);
        }

        unordered_map<int,int> mp;
        for(int i = 0 ; i < n ; i++){
            mp[nums2[i]]=nge[i];
        }

        vector<int> ans;
        for(int x:nums1){
            ans.push_back(mp[x]);
        }
        return ans;
    }
};