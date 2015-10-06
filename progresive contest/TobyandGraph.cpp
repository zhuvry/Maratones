#include <bits/stdc++.h>
using namespace std;
int T,n,m;
vector<int> grafo[10010];
int visitados[10010];
void dfs(int nodo){
    for(int i=0;i<grafo[nodo].size();i++){
        if(visitados[grafo[nodo][i]]==0){
            visitados[grafo[nodo][i]] = 1;
            dfs(grafo[nodo][i]);
        }
    }
}
int solve(){
    int respuesta = 0;
    for(int i=1;i<=n;i++){
        if(visitados[i]==0){
            respuesta++;
            visitados[i] = 1;
            dfs(i);
        }
    }
    respuesta = respuesta*(respuesta-1);
    respuesta = respuesta / 2;
    return respuesta;
}

int main(){
    scanf("%i",&T);
    for(int i=0;i<T;i++){
        for(int j=0;j<10010;j++){
            grafo[j].clear();
            visitados[j]=0;
        }
        scanf("%i%i",&n,&m);
        for(int j=0;j<m;j++){
            int desde,hasta;scanf("%i%i",&desde,&hasta);
            grafo[desde].push_back(hasta);
            grafo[hasta].push_back(desde);
        }
        long long int ans = solve();
        printf("%lli\n",ans);
    }
}
