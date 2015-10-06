#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define UNVISITED 0
vector<int> dfs_low,dfs_num,dfs_parent;
vector< vector<ii> > AdjList;
vector<bool> articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren,V;
vector<ii> puentes;
void articulationPointAndBridge(int u){
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if(dfs_num[v.first]== UNVISITED){
            dfs_parent[v.first] = u;
            if(u==dfsRoot)rootChildren++;

            articulationPointAndBridge(v.first);

            if(dfs_low[v.first]>=dfs_num[u])
                articulation_vertex[u]=true;

            if(dfs_low[v.first] > dfs_num[u]){
                ii puente = make_pair(min(u,v.first),max(u,v.first));
                puentes.push_back(puente);
            }

            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        }
        else if(v.first!=dfs_parent[u])
            dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}
int main(){
    int n;
    while(cin>>V>>n){
        if(V==0 and n==0){
            break;
        }
        puentes.clear();
        AdjList = vector< vector<ii> >(V);
        for(int i=0;i<n;i++){
            int u,v;cin>>u>>v;
            AdjList[u].push_back(make_pair(v,1));
            AdjList[v].push_back(make_pair(u,1));
        }
        dfsNumberCounter = 0;dfs_num.assign(V,UNVISITED);dfs_low.assign(V, 0);
        dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
        for (int i = 0; i < V; i++){
            if(dfs_num[i]==UNVISITED){
                dfsRoot = i;rootChildren=0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        sort(puentes.begin(),puentes.end());
        cout<<puentes.size();
        for(int i=0;i<puentes.size();i++){
            cout<<" "<<puentes[i].first<<" "<<puentes[i].second;
        }
        cout<<endl;
    }

}
