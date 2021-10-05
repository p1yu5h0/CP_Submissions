class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j, vector<vector<int>>& dp){
        int n = mat.size();
        int m = mat[0].size();
        
        if(dp[i][j] != 1e9+5){
            return dp[i][j];
        }
        if(i == n || j == m)    
            return  1e9+5; 
        if(i == n-1 and j == m-1)   
            return dp[i][j] = (mat[i][j] <= 0) ? 1 - mat[i][j] : 1;
        
        
        int IfWeGoRight = solve(mat , i , j+1, dp);
        int IfWeGoDown = solve(mat , i+1 , j, dp);
        
        
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) - mat[i][j];
       
        return dp[i][j] = ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;   
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n + 1 , vector<int>(m + 1 , 1e9+5));
        return solve(dungeon, 0, 0, dp);
    }
};