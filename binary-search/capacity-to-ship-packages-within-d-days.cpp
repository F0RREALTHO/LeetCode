class Solution {
public:
#define ll long long
#define all(a) (a).begin(),(a).end()

    bool func(vector<int>&weights , ll mid , ll days){
        ll load = 0;
        ll dayC = 1;
        for(int i = 0; i<weights.size();i++){
            if(weights[i]>mid) return false;
            if(load + weights[i]>mid){
                dayC++;
                load = weights[i];
                
                if(dayC>days) return false;
            } else {
                load +=weights[i];
            }

        }
        return true;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        ll high = accumulate(all(weights),0LL) , low = 1;
        

    // high = high * 2;
    ll ans = 0;
        while(low<=high){
        ll mid = (low+high)/2;
        if(func(weights,mid,days)){
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

};