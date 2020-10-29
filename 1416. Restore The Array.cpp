class Solution {
public:
    int numberOfArrays(string s, int k) {
        long n = s.length();
        long dp[n];
        memset(dp,0,sizeof(dp));
        long long mod = 1000000000+7;
        for(long i = n-1;i>=0;i--)
        {
            if(s[i]!='0')
            {
                long num = 0;
                long j;
                long temp = 0;
                for(j = i;j<n;j++)
                {
                    num = num*10+(int)(s[j]-'0');
                    if(num > k)
                    {
                        break;
                    }
                    temp = j!=n-1?(temp%mod + dp[j+1]%mod)%mod:temp;
                }
                if(num <= k)
                {
                    temp++;
                    temp = temp%mod;
                }
                dp[i] = temp%mod;
            }
        }
        return dp[0];
    }
};