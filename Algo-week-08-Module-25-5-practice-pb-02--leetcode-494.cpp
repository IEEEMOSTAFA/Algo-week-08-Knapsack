
#include<bits/stdc++.h>
using namespace std;
 
class solution{
public:
    bool findTargetSumWays(vector<int>&nums,int target)
    {
       int n = nums.size();
       int N = 800;
       int dp[n+1][N*2 + 1];
       memset(dp,0,sizeof(dp));
       int num[21];
       for(int i=1;i<=n;i++)
       num[i] = nums[i-1];
       dp[1][N-num[1]] = 1;
       dp[1][N+num[1]] = 1;
       for(int i=2;i<=n;i++)
       {
        for(int j=-N;j<=N;j++)
        {
            dp[i][N+j] = dp[i-1][N + j+ num[i]] + dp[i-1][N + j - num[i]];
        }
       }
       return dp[n][N+target];
       
    }

};
int main()
{
    
    vector<int>a1 = {1,1,1};
    int t = 1;
     solution a;
    cout<<a.findTargetSumWays(a1,t);
    
 return 0;
}
