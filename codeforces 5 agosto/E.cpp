#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
vector<pair<lli,lli> > grafo[100050]; //pair destino, tiempo
vector<pair<lli,lli> > grafo2[100050];
lli s,t;
lli n,m;
lli distancia[100050];
lli distancia2[100050];
lli yes[100050];
int main(){

    while(cin>>n>>m>>s>>t){

        vector<pair<pair<lli,lli>,lli> > entradas;
        for(int i=0;i<100050;i++){
            grafo[i].clear();
            grafo2[i].clear();
        }
        memset(distancia,0,sizeof(distancia));
        memset(distancia2,0,sizeof(distancia2));
        memset(yes,0,sizeof(yes));
        for(int i=0;i<m;i++){
            lli origen,destino,tiempo;
            cin>>origen>>destino>>tiempo;
            grafo[destino].push_back(make_pair(origen,tiempo));
            grafo2[origen].push_back(make_pair(destino,tiempo));
            entradas.push_back(make_pair(make_pair(origen,destino),tiempo));
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
                cout<<"YES"<<endl;
            }
            else if(tiem-restar <1){
                cout<<"NO"<<endl;
            }
            else{
                cout<<restar+1<<endl;
            }
        }
    }
}
