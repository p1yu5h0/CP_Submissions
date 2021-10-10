class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        //standard dijkstra problem
        
        //first lets make an adjency listg with the help of matrix
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        //by this our list is ready 
        
        //since this question required min time hence we use the dijkstra algo 
        //to start from the source and reach the maximum time of the signal in the output array 
        
        //in dijkstra we know that we use min heap 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        //in the pair the first element represent distance and the second represent the node 
        
        //we also make our distance array in which we need to store the minimum distance required
        vector<int> distto(n+1, INT_MAX);
        
        //lets begin our algo
        
        pq.push({0, k}); //here 0 is the distance from source to source and k is the source
        distto[k] = 0;
        
        while(!pq.empty()){
            // int dist = pq.top().first;
            int prev = pq.top().second;
            pq.pop();
            
            for(auto it : adj[prev]){
                int next = it.first;
                int nextdist = it.second;
                if(distto[next] > distto[prev] + nextdist){
                    distto[next] = distto[prev] + nextdist;
                    pq.push({distto[next], next});
                }
            }
        }
        
        //since now we may have filled our distance array
        //lets find the maximum time inside the whole distance array
        int maxtime = 0;
        for(int i=1; i<=n; i++){
            maxtime = max(maxtime, distto[i]);
        }
        if(maxtime==INT_MAX){
            return -1;
        }
        return maxtime;
    }
};