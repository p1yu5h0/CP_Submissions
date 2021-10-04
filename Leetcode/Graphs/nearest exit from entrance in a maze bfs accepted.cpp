class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
    queue<pair<int,int>> q;    
    int row=maze.size(),col=maze[0].size(),ans=0;
    q.push({entrance[0],entrance[1]});
    while(!q.empty()){

        for(int n=0; n<q.size();n++){
            int i=q.front().first,j=q.front().second;
            q.pop();
            if(maze[i][j]=='+') 
                continue;

            maze[i][j]='+';
            if((!i || !j || i==row-1 || j==col-1) && !(i == entrance[0] && j == entrance[1])) 
                return ans;

            if(i>0 && maze[i-1][j]!='+') 
                q.push({i-1,j});
 
            if(i<row-1 && maze[i+1][j]!='+') 
                q.push({i+1,j});

            if(j>0 && maze[i][j-1]!='+')
                q.push({i,j-1}); 

            if(j<col-1 && maze[i][j+1]!='+')
                q.push({i,j+1}); 

        }
        ans++;
    }
    return -1;
    }
};
/*
BFS
*/