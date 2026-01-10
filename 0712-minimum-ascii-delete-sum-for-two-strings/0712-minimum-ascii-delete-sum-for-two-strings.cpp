class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size(),sum1=0,sum2=0;
        int dp[n+1][m+1];
        //calculate sum of ascii values of s1.
        for(int i=0;i<n;i++)
            sum1+=s1[i];
        //calculate sum of ascii values of s2.
        for(int i=0;i<m;i++)
            sum2+=s2[i];
        //apply lcs base condition.
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0||j==0)
                    dp[i][j]=0;
            }
        }
        //apply lcs...
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=s1[i-1]+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int ans=dp[n][m];
        //final_ans = sum1-ans+sum2-ans=>sum1+sum2-2*ans
        return sum1+sum2-2*ans;
    }
};