class Solution {
public:
    long solve(vector<vector<long>>&dp,vector<long>&ps,long l,long r){
        if(l == r){
            return 0;
        }
        if(dp[l][r] != -1){
            return dp[l][r];
        }
        long ans = 0;
        for(long i = l;i<r;i++){
            long lsum = 0,rsum = 0;
            if(l == 0){
                lsum = ps[i];
            }
            else{
                lsum = ps[i]-ps[l-1];
            }
            rsum = ps[r]-ps[i];
            if(lsum < rsum){
                ans = max(ans,solve(dp,ps,l,i)+lsum);
            }
            else if(lsum == rsum){
                ans = max({ans,lsum+solve(dp,ps,l,i),rsum+solve(dp,ps,i+1,r)});
            }
            else{
                ans = max(ans,solve(dp,ps,i+1,r)+rsum);
            }
        }
        return dp[l][r] = ans;
    }
    int stoneGameV(vector<int>& sv) {
        long n = sv.size();
        vector<long>ps(n,0);
        ps[0] = sv[0];
        for(long i = 1;i<n;i++){
            ps[i] = ps[i-1]+sv[i];
        }
        vector<vector<long>>dp(n,vector<long>(n,-1));
        return solve(dp,ps,0,n-1);
    }
};
