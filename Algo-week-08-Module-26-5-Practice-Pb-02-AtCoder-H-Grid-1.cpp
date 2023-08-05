//https://atcoder.jp/contests/dp/tasks/dp_h

#include<bits/stdc++.h>
using namespace std;

//code:ok;
/*
#include <bits/stdc++.h> 
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    fast_io;
    ll ro,co;
    cin>>ro>>co;
    ll mod = 1e9+7;

    vector< vector<ll>> dp(ro+1, vector<ll> (co+1,0));
    dp[0][0] = 1;

    for(ll i=0;i<ro;i++)
    {
        string s;
        cin>>s;
        for(ll j=0;j<co;j++)
        {
            if(s[j] == '.')
            {
                if(i>0)
                {
                    dp[i][j] += dp[i-1][j];
                    dp[i][j] %= mod;
                }
                if(j>0)
                {
                    dp[i][j] += dp[i][j-1];
                    dp[i][j] %= mod;
                }
            }
            else
            dp[i][j] = 0;

        }
    }
    cout<<dp[ro-1][co-1]<<endl;

    return 0;
}
*/
int main()
{
long long ro,col;
cin>>ro>>col;
long long mod = 1e9 + 5;
vector<vector<long long>>dp(ro + 1,vector<long long>(col+1,0));
dp[0][0] = 1;
for( long long i =0;i<ro;i++)
{
    string s;
    cin>>s;
    for(long long j=0;j<col;j++)
    {
        if(s[j] == '.')
        {
            if(i>0)
            {
                dp[i][j] += dp[i-1][j];
                dp[i][j] %= mod;
            }
            if(j>0)
            {
              dp[i][j] += dp[i][j-1];
              dp[i][j] %= mod;
            }
            
        }
        else
        dp[i][j] = 0;
    }
}
cout<<dp[ro-1][col-1]<<endl;
return 0;

}


/*
5 2
. .
# .
. .
. #
. .

out: 0

5 5
. . # . .
. . . . .
# . . . #
. . . . .
. . # . .
out:24
*/