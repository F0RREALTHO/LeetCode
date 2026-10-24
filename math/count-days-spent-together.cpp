class Solution {
public:

    vector<int> monthDays = {31,28,31,30,31,30,31,31,30,31,30,31};
    int idx(string a){
        int m = stoi(a.substr(0,2));
        int d = stoi(a.substr(3,2));
        int ans = d;
        for(int i =0;i<m-1;i++){
            ans+=monthDays[i];
        }
        return ans;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int a1 , a2, l1, l2;
        a1 = idx(arriveAlice), a2 = idx(arriveBob), l1 = idx(leaveAlice), l2 = idx(leaveBob);

        vector<int> day(367,0);
        day[a1]++;
        day[a2]++;
        day[l1+1]--;
        day[l2+1]--;

        int st = max(a1,a2);
        int ed = min(l1,l2);
        return max(0,ed-st+1);
    }
};