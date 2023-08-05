
#include<bits/stdc++.h>
using namespace std;
 
class solution{
public:
    bool canPartition(vector<int>nums)
    {
        int n = nums.size();
        int num[105];
        int dp[205][205];
        for(int i=1;i<=n;i++)
        num[i] = nums[i-1];
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            sum = sum + num[i];
        }
        if(sum % 2 != 0)
         return false;
         sum = sum/2;
         for(int i=1;i<=n;i++)
         dp[0][i] = 0;
         for(int i=0;i<=n;i++)
         dp[i][0] = 1;
         for(int i=1;i<=n;i++)
         {
            for(int j=1;j<=sum;j++)
            {
                int ans1 = dp[i-1][j];
                if(j<num[i])
                {
                    dp[i][j] = ans1;
                }

                else
                {
                    int ans2 = dp[i-1][j-num[i]];
                    dp[i][j] = ans1 || ans2 ;
                }
            }
         } 
         if(dp[n][sum] == 1) return true;
         return false;
       
    }

};
int main()
{
     solution a;
    vector<int>a1 = {1,5,11,5};
    cout<<a.canPartition(a1);
    
 return 0;
}
/*  
#include<bits/stdc++.h>
using namespace std;
bool canPartion(int *nums,int n)
{
    int sum =0;
    for(int i=0;i<n;i++)
    {
        sum += nums[i];
    }
    if(sum % 2 !=0)
    {
        return false;
    }
    bool isSubsetSum(int*nums,int n,int sum)
    {
        if(sum == 0)
        {
            return true;
        }
        if(n==0 || sum<0)
        {
            return false;
        }
        bool canInclude = isSubsetSum(nums + 1,n-1,sum);
        bool canExclude = isSubsetSum(nums + 1,n-1,sum);
        return canInclude || canExclude;

    }
    return isSubsetSum(nums,n,sum/2);
}

    int main()
    {
      int nums[] = { 1,5,11,5};
      int n= sizeof(nums);
      if(canPartion(nums,n))
      {
        cout<<"True"<<endl;

      }
      else 
      {
        cout<<"False"<<endl;
      }
      return 0;


    }

*/
