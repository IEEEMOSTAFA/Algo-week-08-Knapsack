//Memoization:
/*
-state:f(n,m)  -> numbers of unique paths from (0,0) to (n,m)
-recurrance : (n,m) -> ->f(n-1,m) + f(n,m-1)
-base case:f(0,0) = 1

*/
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
int dp[N][N];
int unique_paths(int n,int m)
{
    //base_case
    if(n ==0 && m == 0)
    {
        return 1;
    }
    //if result is already calculated return it
    if(dp[n][m] != -1)
    {
        return dp[n][m];
    }

    //3.calculate result from smaller sub-problem
    int ans = 0;
   if(n>0) ans += unique_paths(n-1,m);
   if(m>0) ans += unique_paths(n,m-1);
   

    dp[n][m] = ans;
    return ans;

}

int main()
{
int ro,col;
cin>>ro>>col;

for(int i=0;i<ro;i++)
{
    for(int j=0;j<col;j++)
    {
        dp[i][j] = -1;
    }
}

cout<<unique_paths(ro-1,col-1)<<endl;
return 0;

}