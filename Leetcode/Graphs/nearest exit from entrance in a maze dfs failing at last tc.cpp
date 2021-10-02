class Solution {
public:
    int dfs(vector<vector<char>>& maze,int i, int j,int istart,int jstart, vector<vector<int>>& dp){
        if((i!=istart || j!=jstart) and (!i || !j || i==maze.size()-1 || j==maze[0].size()-1))
            return 0;
        
        int ret=10000; 
        maze[i][j] = '+';
        
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        if(i<maze.size()-1 && maze[i+1][j]!='+') 
            ret=min(ret,1+dfs(maze,i+1,j,istart,jstart,dp));
        
        if(i>0 && maze[i-1][j]!='+') 
            ret=min(ret,1+dfs(maze,i-1,j,istart,jstart,dp));
        
        if(j<maze[0].size()-1 && maze[i][j+1]!='+') 
            ret=min(ret,1+dfs(maze,i,j+1,istart,jstart,dp));
        
        if(j>0 && maze[i][j-1]!='+') 
            ret=min(ret,1+dfs(maze,i,j-1,istart,jstart,dp));
        
        
        maze[i][j] = '.';
        return dp[i][j] = ret;
    }
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<vector<int>> dp(maze.size()+1, vector<int> (maze[0].size()+1 , -1));
        int ans=dfs(maze,entrance[0],entrance[1],entrance[0],entrance[1], dp);  
        if(ans>=10000){
            return -1;
        } 
        return ans;
    }
};
/*
DFS is failing at last test case :( 😣
DP cannot be used here.
Why? because we have to calculate all the solutions and return the minimum, but with DP, we return the first encountered solution.
The reason some solutions were accepted because there wasn't any test case supportive to prove wrong. Now, the same solution will give wrong answer.

https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/discuss/1426920/c%2B%2B-oror-fully-explained-oror-bfs-oror-beginner-friendly
(read this why dfs fails)

https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/discuss/1461710/C%2B%2B-or-Why-DFS-gives-TLE-or-BFS-and-DFS-solutions-or-Short-and-simple
(dfs v/s bfs)
*/
