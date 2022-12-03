 vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
      vector<int> res(V,INT_MAX);
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
      pq.push({0,S});
      res[S]=0;
      while(!pq.empty()){
         auto x=pq.top(); //ispe jaana h
         pq.pop();
         int dis=x.first;
         int node=x.second;
         for(auto it:adj[node]){
             int curdis=it[1];
             int curpos=it[0];
             if(res[curpos]>dis+curdis){
                 res[curpos]=dis+curdis;
                 pq.push({res[curpos],curpos});
             }
         }
      }
      return res;
    }


//Network Delay time
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> g[n+1]; 
        for(int i=0;i<times.size();i++){
           g[times[i][0]].push_back({times[i][1],times[i][2]});
        }
    int ans=0;    
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
	vector<int> distTo(n+1,INT_MAX);//1-indexed array for calculating shortest paths
	distTo[k] = 0;
	pq.push(make_pair(0,k));	// (dist,source)
	while( !pq.empty() ){
		int dist = pq.top().first;
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int,int> >::iterator it;
		for( it = g[prev].begin() ; it != g[prev].end() ; it++){
			int next = it->first;
			int nextDist = it->second;
			if( distTo[next] > distTo[prev] + nextDist){
				distTo[next] = distTo[prev] + nextDist;
				pq.push(make_pair(distTo[next], next));
			}
		}
	}

    for(int i=1;i<distTo.size();i++){
        ans=max(ans,distTo[i]);
    }
    if(ans==INT_MAX)
    return -1;
    return ans;
    }
};    