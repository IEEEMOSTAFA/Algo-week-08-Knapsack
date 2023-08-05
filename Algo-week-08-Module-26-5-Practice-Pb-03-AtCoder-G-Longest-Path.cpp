//https://atcoder.jp/contests/dp/tasks/dp_g
//G-Longest Path
#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph(100005,vector<int>());
int distances[100005];
int dfs(int node)
{
    if(distances[node] != -1)
    return distances[node];
    int longest_path = 0;

    for(auto child:graph[node])
    {
        longest_path = max(longest_path,dfs(child));
    }

    return distances[node] = 1+ longest_path;


}



int main()
{
    int node,edge;
    cin>>node>>edge;
     memset(distances,-1,sizeof distances);
     for(int i=0;i<edge;i++)
     {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);

     }
     int result = 0;
     for(int i=1;i<node+1;i++)
     {
        result = max(result,dfs(i));
     }
     cout<<result - 1<<endl;
}
/*
4 5
1 2
1 3
3 2
2 4
3 4

out:3


*/