#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define UNVISITED 0
vector<int> dfs_low,dfs_num,dfs_parent;
vector< vector<ii> > AdjList;
vector<bool> articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren,V;
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

            if(dfs_low[v.first] > dfs_num[u])
                printf(" Edge (%d, %d) is a bridge\n",u,v.first);

            dfs_low[u] = min(dfs_low[u],dfs_low[v.first]);
        }
        else if(v.first!=dfs_parent[u])
            dfs_low[u] = min(dfs_low[u],dfs_num[v.first]);
    }
}
int main(){
    int n;
    while(cin>>V>>n){
        AdjList = vector< vector<ii> >(V);
        for(int i=0;i<n;i++){
            int u,v;cin>>u>>v;
            AdjList[u].push_back(make_pair(v,1));
            AdjList[v].push_back(make_pair(u,1));
        }
        dfsNumberCounter = 0;dfs_num.assign(V,UNVISITED);dfs_low.assign(V, 0);
        dfs_parent.assign(V, 0); articulation_vertex.assign(V, 0);
        printf("Bridges:\n");
        for (int i = 0; i < V; i++){
            if(dfs_num[i]==UNVISITED){
                cout<<"primera "<<i<<endl;
                dfsRoot = i;rootChildren=0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1);
            }
        }
        printf("Articulation Points:\n");
        for(int i=0;i<V;i++){
            if (articulation_vertex[i]){
                printf(" Vertex %d\n", i);
            }
        }
        cout<<"aqui"<<endl;
        for(int i=0;i<V;i++){
            cout<<"vertice "<<i<<endl;
            cout<<"dfs num es "<<dfs_num[i]<<endl;
            cout<<"dfs low es "<<dfs_low[i]<<endl;
        }
    }


}
