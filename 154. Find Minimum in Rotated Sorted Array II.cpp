class Solution {
public:
    int findMin(vector<int>& a) {
        int n = a.size();
        int lo = 0;
        int hi = n-1;
        int mid;
        while(lo <= hi){
            mid = lo+(hi-lo)/2;
            if(a[mid] == a[hi]){
                hi--;
            }
            else if(a[mid] > a[hi]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        return a[mid];
        return 0;
    }
};
