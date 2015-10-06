#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

typedef long long int lli;
lli V = 100050;
vector<pair<lli,lli> > grafo[100050]; //pair destino, tiempo
vector<pair<lli,lli> > grafo2[100050];
vector<pair<lli,lli> > grafoshortest[100050];
lli s,t;
lli n,m;
lli distancia[100050];
lli distancia2[100050];
lli distancia3[100050];
lli puentes[100050];

int main(){

    while(scanf("%lli%lli%lli%lli",&n,&m,&s,&t)!=EOF){

        vector<pair<pair<lli,lli>,lli> > entradas(m);
        map<pair<pair<lli,lli>,lli>,int> mapa2;
        for(int i=0;i<100050;i++){
//            grafo[i].clear();
//            grafo2[i].clear();
            distancia[i]=-1;
            distancia2[i]=-1;
            distancia3[i]=-1;
        }
        for(int i=0;i<m;i++){
            lli origen,destino,tiempo;
            scanf("%lli%lli%lli",&origen,&destino,&tiempo);
            grafo[destino].push_back(make_pair(origen,tiempo));
            grafo2[origen].push_back(make_pair(destino,tiempo));
            entradas[i]=(make_pair(make_pair(origen,destino),tiempo));
            mapa2[make_pair(make_pair(origen,destino),tiempo)]++;
            mapa2[make_pair(make_pair(destino,origen),tiempo)]++;
        }

        priority_queue<pair<lli,lli> > cola; //tiempo ciudad origen
        priority_queue<pair<lli,lli> > cola2;
        priority_queue<pair<lli,lli> > cola3;
        cola.push(make_pair(0,t));
        cola2.push(make_pair(0,s));
        while(cola.size()>0){
            pair<lli,lli> caminoActual = cola.top();cola.pop();
            pair<lli,lli> caminosiguiente;
            if(cola.size()>0) caminosiguiente= cola.top();
            if(distancia[caminoActual.second]==-1){
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
            if(distancia2[caminoActual.second]==-1){
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
            if(distdesdemeta==-1 or distdesdeorigen==-1)continue;
            if(restar==0){
                lli origen = entradas[i].first.first;
                lli destino = entradas[i].first.second;
                grafoshortest[destino].push_back(make_pair(origen,tiem));
            }
        }
        cola3.push(make_pair(0,t));
        while(cola3.size()>0){
            pair<lli,lli> caminoActual = cola3.top();cola3.pop();
            if(distancia3[caminoActual.second]==-1){
                distancia3[caminoActual.second]=caminoActual.first;
            }else{
                distancia3[caminoActual.second]= min(distancia[caminoActual.second],caminoActual.first);
            }
            for(int i=0;i<grafo[caminoActual.second].size();i++){
                cola.push(make_pair(caminoActual.first+grafo[caminoActual.second][i].second,grafo[caminoActual.second][i].first));
            }
        }

        for(int i=0;i<entradas.size();i++){
            lli tiem = entradas[i].second;
            lli distdesdemeta = distancia[entradas[i].first.second];
            lli distdesdeorigen = distancia2[entradas[i].first.first];
            lli recorrido =tiem+distdesdemeta+distdesdeorigen;
            if(distdesdemeta<0 or distdesdeorigen<0 or tiem<0)recorrido = -1;
            lli restar = recorrido-caminomascorto;
            lli origen = entradas[i].first.first;
            lli destino = entradas[i].first.second;
        }
    }
}
