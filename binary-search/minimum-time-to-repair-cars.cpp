class Solution {
public:
    #define ll long long
    #define all(a) (a).begin(), (a).end()
    #define rep(i, j, k) for (ll i = j; i < k; i++)

    bool canRepairInTime(vector<int>& ranks, ll cars, ll mid) {
        ll total_cars = 0;
        ll n = ranks.size();
        rep(i, 0, n) {
            ll maxCars = (ll)sqrt(mid / ranks[i]);
            total_cars += maxCars;
            if (total_cars >= cars) return true;
        }
        return false;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        ll low = 1;
        ll high = *min_element(all(ranks)) * (ll)cars * cars;
        ll ans = high;

        while (low <= high) {
            ll mid = low + (high - low) / 2;
            if (canRepairInTime(ranks, cars, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
