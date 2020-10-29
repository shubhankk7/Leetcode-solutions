class Solution {
public:
    long solve(vector<vector<long>>&dp,vector<int>& nums1, vector<int>& nums2,long i,long j){
        if(i >= nums1.size() or j>=nums2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        long x = nums1[i]*nums2[j]+solve(dp,nums1,nums2,i+1,j+1);
        long y = x;
        long z = x;
        if(i+1<nums1.size()){
            y = solve(dp,nums1,nums2,i+1,j);
        }
        if(j+1<nums2.size()){
            z = solve(dp,nums1,nums2,i,j+1);
        }
        return dp[i][j] = max({(long)nums1[i]*nums2[j],x,y,z});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<long>>dp(nums1.size(),vector<long>(nums2.size(),-1));
        return solve(dp,nums1,nums2,0,0);
    }
};
