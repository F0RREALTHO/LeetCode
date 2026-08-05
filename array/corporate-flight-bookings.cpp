class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> pre(n+2,0);

        for(int i =0; i<bookings.size();i++){
            int l = bookings[i][0], r = bookings[i][1], x = bookings[i][2];
            pre[l]+=x;
            pre[r+1]-=x;
        }
        vector<int> ans(n,0);
        ans[0]= pre[1];
        for(int i =1; i<n;i++){
            ans[i] = ans[i-1]+pre[i+1];
        }

        return ans;
    }
};