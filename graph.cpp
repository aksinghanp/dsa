//course schedule (directed graph)
//prerequisite type
//check for cycle using dfs
class Solution {
public:
    bool DFScycle(vector<int>adj[],int node,vector<int>&visited,vector<int>recst){
        visited[node]=1;
        recst[node]=1;
        for(auto x:adj[node]){
            if(visited[x]==0){
                if(DFScycle(adj,x,visited,recst))
                    return true;
            }
            else if(recst[x]==1)
                return true;
        }
        recst[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>adj[numCourses];
        for(auto it:prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        vector<int>visited(numCourses,0),recst(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(DFScycle(adj,i,visited,recst))
                    return false;
            }
        }
        return true;
    }
};


//Evaluate Division
// a/b=2.0,b/c=3.0,a/c=6.0

class Solution {
public:
   void dfs(string s,string d,map<string,vector<pair<string,double>>> &m,set<string> v,double &ans,double temp){
       if(v.find(s)!=v.end()){
           return;
       }
           v.insert(s);
           if(s==d){
            ans=temp;
            return;   
           }else{
               for(auto a:m[s]){
                   dfs(a.first,d,m,v,ans,temp*a.second);
               }
           }
   
   } 
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>&q ) {
        
        map<string,vector<pair<string,double>>> m;
        
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],v[i]});
            m[e[i][1]].push_back({e[i][0],1/v[i]});
        }
        
        vector<double> res;
        
        for(int i=0;i<q.size();i++){
            string s=q[i][0];
            string d=q[i][1];
            set<string> vis;
            double ans=-1.0;
            if(m.find(s)!=m.end()){
              dfs(s,d,m,vis,ans,1.0);  
            }
            res.push_back(ans);
        }
       return res; 
    }
};


//no of provinces
//no of connected components(union find)
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int i){
        if(parent[i]!=i){
            return parent[i]=find(parent[i]);
        }
        return i;
    }

  void unionfind(int x,int y){
		int x_root=find(x);
		int y_root=find(y);
		if(x_root==y_root){
			return;
		}
		if(rank[x]>rank[y]){
			parent[y_root]=x_root;
		}
		else if(rank[y]>rank[x]){
			parent[x_root]=y_root;
		}
		else if(rank[y]==rank[x]){
			parent[x_root]=y_root;
			rank[y_root]++;
		}
	}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();

        parent.resize(n,0);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               if(isConnected[i][j]==1){
                   unionfind(i,j);
               }
           }
        }

       set<int> s;        
       for(int i=0;i<n;i++){
          s.insert(find(i));
       }
       return s.size();
    }
};