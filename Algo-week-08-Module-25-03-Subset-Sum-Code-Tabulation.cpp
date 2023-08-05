/*
-state: fun(n,target) -> returns 1 if it is possible to create a subset from numbers
                         1 to n and from the sum "target"



-recarance : fun(n,target) -> fun(n-1, target) OR
                                fun(n-1, target  -nums[n]) if target >= nums[n]

-base_case: fun(0,target) -> 1 if target == 0
                                else 0
*/
/*
6 9
3 34 4 12 5 2

target = 9 
1 5
5
out: 1
6 1
3 34 4 12 5 2
out:0
True hole output: 1
False hole output: 0

*/
//Memoization::
//Same problem we show in geeksforGeeks
#include<bits/stdc++.h>
using namespace std;
const int N = 101;
const int M = 1e5 + 5;
int nums[N];
int dp[N][M];

int main()
{
int n,m;
cin>>n>>m;
for(int i=1;i<=n;i++)
{
    cin>>nums[i];
}
//handle base case
dp[0][0] = 1;

for(int i=1;i<=m;i++)
{
    dp[0][i] = 0;
}
//loop over the state:

for(int i=0;i<=n;i++)
{
    for(int target=0;target<=m;target++)
    {
        //2.1 .calculate answer from smaller sub-problems
        /*
        fun(n,target) -> fun(n-1, target) OR
                         fun(n-1, target  -nums[n]) if target >= nums[n]
        */
        int ans1 = dp[i-1][target];
        if(target < nums[i])
        {
            dp[i][target] = ans1;
        }
        else
        {
            int ans2 = dp[i-1][target - nums[i]];
            dp[i][target] = ans1 || ans2;
        }
    }
}
cout<<dp[n][m]<<endl;
return 0;
}