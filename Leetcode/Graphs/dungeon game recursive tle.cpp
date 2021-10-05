class Solution {
public:
    int solve(vector<vector<int>>& mat, int i, int j){
        int n = mat.size();
        int m = mat[0].size();
        // Base case : we have crossed the matrix, ie. out of bound
        /// if current row crosses then my row is below the princess or 
        /// if current column crosses then my column is ahead the column of princess
        /// and beacause we can go only down and right so we wont be able reach princess
        if(i == n || j == m)    
            return 1e9+5; 
        
		// Base Case : we have reached our destination ie. last cell
        /// we reached princess , cheers return this cost;
        if(i == n-1 and j == m-1)   
            return (mat[i][j] <= 0) ? 1 - mat[i][j] : 1;
        
        /// now we must try all possible paths , we ask our right and and down cell
        int IfWeGoRight = solve(mat , i , j+1);
        int IfWeGoDown = solve(mat , i+1 , j);
        
        /// min of either values and then cost of this cell
        int minHealthRequired =  min(IfWeGoRight , IfWeGoDown) - mat[i][j];
        
        /// What if we get some health if we arrive at some cell ? 
        //my guess is we still need 1 health in first case to arrive at that cell - cases like 
        //these need to be figure out by yourself.
        //at any cell what health do we need ? - since we can go only down and right 
        //therefore min health required will be minimun health required if we go right or down, 
        return ( minHealthRequired <= 0 ) ? 1 : minHealthRequired;   
        
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        return solve(dungeon, 0, 0);
    }
};