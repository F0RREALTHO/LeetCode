class Solution {
public:
int search(vector<int>& a,int x){
    int n = a.size();
    int low = 0; 
    int high = n-1;
    int ans = -1;

    // if(n==0 ) return -1

    while(low<=high){
        int mid = (low+high)/2;
        if(a[mid]==x) {
            ans = mid;
            break;
        }
        else if(a[mid]<x){
            low = mid + 1;
        }
        else high = mid - 1;
    }
    return ans;
}
};
