#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define UNVISITED 0
vector<int> dfs_low,dfs_num,dfs_parent;
vector< vector<ii> > AdjList;
vector<bool> articulation_vertex;
int dfsNumberCounter,dfsRoot,rootChildren;
vector<ii> puentes;

typedef long long int lli;
lli V = 100050;
vector<pair<lli,lli> > grafo[100050]; //pair destino, tiempo
vector<pair<lli,lli> > grafo2[100050];
lli s,t;
lli n,m;
lli distancia[100050];
lli distancia2[100050];
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

    while(scanf("%lli%lli%lli%lli",&n,&m,&s,&t)!=EOF){
        map<pair<lli,lli>,int> mapa;
        map<pair<pair<lli,lli>,lli>,int> mapa2;
        puentes.clear();
        AdjList = vector< vector<ii> >(V);

        vector<pair<pair<lli,lli>,lli> > entradas;
        for(int i=0;i<100050;i++){
            grafo[i].clear();
            grafo2[i].clear();
        }
        memset(distancia,0,sizeof(distancia));
        memset(distancia2,0,sizeof(distancia2));
        for(int i=0;i<m;i++){
            lli origen,destino,tiempo;
            scanf("%lli%lli%lli",&origen,&destino,&tiempo);
            grafo[destino].push_back(make_pair(origen,tiempo));
            grafo2[origen].push_back(make_pair(destino,tiempo));
            entradas.push_back(make_pair(make_pair(origen,destino),tiempo));
            mapa2[make_pair(make_pair(origen,destino),tiempo)]++;
            mapa2[make_pair(make_pair(destino,origen),tiempo)]++;
        }
        priority_queue<pair<lli,lli> > cola; //tiempo ciudad
        priority_queue<pair<lli,lli> > cola2;

        cola.push(make_pair(0,t));
        cola2.push(make_pair(0,s));
        while(cola.size()>0){
            pair<lli,lli> caminoActual = cola.top();cola.pop();
            if(distancia[caminoActual.second]==0){
                distancia[caminoActual.second]=caminoActual.first;
            }else{
                distancia[caminoActual.second]= min(distancia[caminoActual.second],caminoActual.first);
            }
            for(int i=0;i<grafo[caminoActual.second].size();i++){
                cola.push(make_pair(caminoActual.first+grafo[caminoActual.second][i].second,grafo[caminoActual.second][i].first));
            }
        }
        while(cola2.size()>0){
            pair<lli,lli> caminoActual = cola2.top();cola2.pop();
            if(distancia2[caminoActual.second]==0){
                distancia2[caminoActual.second]=caminoActual.first;
            }else{
                distancia2[caminoActual.second]= min(distancia2[caminoActual.second],caminoActual.first);
            }
            for(int i=0;i<grafo2[caminoActual.second].size();i++){
                cola2.push(make_pair(caminoActual.first+grafo2[caminoActual.second][i].second,grafo2[caminoActual.second][i].first));
            }

        }
        lli caminomascorto = distancia[s];
        for(int i=0;i<entradas.size();i++){
            lli tiem = entradas[i].second;
            lli distdesdemeta = distancia[entradas[i].first.second];
            lli distdesdeorigen = distancia2[entradas[i].first.first];
            lli recorrido =tiem+distdesdemeta+distdesdeorigen;
            lli restar = recorrido-caminomascorto;
            if(restar==0){
                lli origen = entradas[i].first.first;
                lli destino = entradas[i].first.second;
                AdjList[origen].push_back(make_pair(destino,tiem));
                AdjList[destino].push_back(make_pair(origen,tiem));
            }
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
        for(int i=0;i<puentes.size();i++){
            mapa[make_pair(puentes[i].first,puentes[i].second)] = 2;
            mapa[make_pair(puentes[i].first,puentes[i].second)] = 2;
        }
        for(int i=0;i<entradas.size();i++){
            lli tiem = entradas[i].second;
            lli distdesdemeta = distancia[entradas[i].first.second];
            lli distdesdeorigen = distancia2[entradas[i].first.first];
            lli recorrido =tiem+distdesdemeta+distdesdeorigen;
            lli restar = recorrido-caminomascorto;
            lli origen = entradas[i].first.first;
            lli destino = entradas[i].first.second;
            if(distancia[entradas[i].first.first]==0){
                printf("NO\n");
            }
            else if(distancia2[entradas[i].first.second]==0){
                printf("NO\n");
            }
            else if(restar==0 and (mapa2[make_pair(make_pair(origen,destino),tiem)]==1 or mapa2[make_pair(make_pair(destino,origen),tiem)]==1)){
                if(mapa[make_pair(origen,destino)]==2 or mapa[make_pair(destino,origen)]==2){
                    printf("YES\n");
                }
                else{
                    if(tiem-restar<=1){
                        printf("NO\n");
                    }
                    else{
                        printf("CAN 1\n");
                    }
                }

            }
            else if(tiem-restar<=1){
                printf("NO\n");
            }
            else{
            	if(restar+1<1){
            		printf("NO\n");
            	}
            	else{
            		printf("CAN %lli\n",restar+1);
            	}

            }
        }
    }
}
