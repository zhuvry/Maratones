#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,k;
int grafo[1010];
bool visitado[1010];
int dp[1010];
int recorrido(int i,int llevo){
    llevo = llevo+1;
    visitado[i] = true;
    if(visitado[grafo[i]]){
        return llevo;
    }
    return recorrido(grafo[i],llevo);
}
int main(){
    cin>>n>>k;
    memset(grafo,0,sizeof(grafo));
    for(int i=1;i<=n;i++){
        int enlace;cin>>enlace;
        grafo[i]=enlace;
    }
    for(int i=1;i<=n;i++){
        memset(visitado,0,sizeof(visitado));
        cout<<recorrido(i,0)<<endl;
    }
}
