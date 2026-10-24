class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
        int n = a.size();
        for(int i=0;i<n;i++) if(a[i]<0) a[i] =-a[i];

        sort(a.begin(),a.end());
        int l =0, r = n-1;
        long long ans = 0;
        while(l<r){
            ans += a[r]*a[r];
            ans -= a[l]*a[l];
            l++;r--;
        }
        if(l==r) ans+=a[r]*a[r];
        return ans;
    }
};