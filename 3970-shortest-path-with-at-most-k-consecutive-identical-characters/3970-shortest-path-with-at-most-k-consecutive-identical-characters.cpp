class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        auto mavorqeli=tie(n,edges,labels,k);
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e:edges){
            adj[e[0]].push_back({e[1],e[2]});
        }
        const long long inf=1e18;
        vector<vector<long long>> dist(n,vector<long long>(k + 1,inf));
          priority_queue<
            tuple<long long,int,int>,
            vector<tuple<long long,int,int>>,
            greater<tuple<long long,int,int>>
        >pq;
        dist[0][1]=0;
        pq.push({0,0,1});
        while (!pq.empty()){
            auto [cost,u,cnt]=pq.top();
            pq.pop();
        if (cost!=dist[u][cnt]) continue;
            for(auto[v,w]:adj[u]){
                int nextCnt;
                if(labels[u]==labels[v]){
                    nextCnt=cnt + 1;
                }else{
                    nextCnt = 1;}
                if(nextCnt>k) continue;
                long long newCost=cost+w;
                if(newCost < dist[v][nextCnt]) {
                    dist[v][nextCnt]=newCost;
                    pq.push({newCost,v,nextCnt});
                }
            }
        }long long ans=inf;
        for(int i=0;i<=k;i++){
            ans=min(ans,dist[n-1][i]);
        }return ans==inf?-1:(int)ans;
    }
};