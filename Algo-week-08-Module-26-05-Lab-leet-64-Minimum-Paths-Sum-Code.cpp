
//leetcode-64:Minimum Path Sum
#include<bits/stdc++.h>
using namespace std;
//HW:
class Solution 
{
public :
int minPathSum(vector<vector<int>>& grid)
{
    int y = grid[0].size();
    int x = grid.size();

    for(int i=1;i<x;i++)
    grid[i][0] = grid[i-1][0] + grid[i][0];//first col all value
    for(int i=1;i<y;i++)
    grid[0][i] = grid[0][i-1] + grid[0][i] ;//first row all value
    

    for(int i= 1;i<x;i++)
    for(int j=1;j<y;j++)
    grid[i][j] = min( grid[i-1][j]+grid[i][j],grid[i][j-1] + grid[i][j]);  //col wise visit and row wish visit

    return grid[x-1][y-1];

}

};

int main()
{
int x,y;
cin>>x>>y;
vector<vector<int>>dp;
for(int i=0;i<x;i++)
{
    vector<int>col;
    for(int j=0;j<y;j++)
    {
        int num;cin>>num;
        col.push_back(num);

    }
    dp.push_back(col);
}
Solution a;
cout<<a.minPathSum(dp);
return 0;

}
/*
3 3
1 3 1
1 5 1
4 2 1

out: 7
*/