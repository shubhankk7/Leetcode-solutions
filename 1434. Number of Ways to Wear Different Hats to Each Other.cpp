class Solution {
public:
    long mod = 1000000007;
    long n;
    long fmask;
    long solve(vector<vector<long>>&dp,vector<vector<int>>&p,long mask,long start){
        if(mask == fmask){
            return 1;
        }
        if(start >= p.size()){
            return 0;
        }
        if(dp[start][mask] != -1) return dp[start][mask];
        long rv = 0;
        rv += solve(dp,p,mask,start+1)%mod;
        rv %= mod;
        for(long i = 0;i<p[start].size();i++){
            if(mask & (1<<p[start][i])) continue;
            rv += solve(dp,p,(mask|1<<(p[start][i])),start+1)%mod;
            rv %= mod;
        }
        return dp[start][mask] = rv%mod;
    }
    int numberWays(vector<vector<int>>& h) {
        vector<vector<int>>p(41);
        for(long i =0 ;i<h.size();i++){
            for(long j = 0;j<h[i].size();j++){
                p[h[i][j]].push_back(i);
            }
        }
        this->n = h.size();
        long mask = 0;
        fmask = 0;
        for(long i = 0;i<n;i++) fmask+=pow(2,i);
        vector<vector<long>>dp(41,vector<long>(fmask+1,-1));
        return solve(dp,p,mask,0);
    }
};
