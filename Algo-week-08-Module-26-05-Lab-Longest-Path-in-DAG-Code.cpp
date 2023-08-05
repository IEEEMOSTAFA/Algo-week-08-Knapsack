/*

-state:f(n) -> Longest distance from root to n
-recurance:f(n) = max{ f(p_1),f(p_2),f(p_3).......f(p_m) } + 1
                    where p_i is an immediate parent of node n

-base case:f(root) = 0

node------->[chaild_1,child_2-----]

child ------> [parent1,parent2 ----]

*/
//Memoization:
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<int>parent_list[N];
int dp[N];
int root,target_node;
int max_distance(int node)
{
    //1.base case
    if(node == root )
    {
      return 0;
    }
    //2.return result if already calculated
    if(dp[node] != -1)
    {
        return dp[node];
    }
    //3.calculate result from smaller nodes
    int ans = 0;
    for(int parent : parent_list[node])
    {
      int parent_dist = max_distance(parent);
      ans = max(ans,parent_dist);

    }
    ans++;

    dp[node] = ans ;
    //return dp[node];
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;

    for (int  i = 0; i <m; i++)
    {
        int u,v; //there exist an edge from u to v (u-->v)
        cin>>u>>v;
        parent_list[v].push_back(u);


    }
    for(int i=1; i<=n; i++)
    {
        dp[i] = -1;
    }
 cin>>root>>target_node;
 cout<<max_distance(target_node)<<endl;
 return 0;
}

/*
4 4

1 3
3 4
1 4
4 2

1 2   //1=root   2=koto  number node a jacci
out:3

*/