#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,m;
int colores[200010]; //1 blanco 2 negro
int colores2[200010];
vector< pair<int,int> > grafo[200010];
int validoscolor[6] = {1,1,1,2,2,2};
int validospeso[6] = {2,1,0,2,1,0};
int colorresultante[6] = {-1,2,1,2,1,-1};
int primero(int k,int col[],int ini){
    int ans = 0;
    queue<int> cola;
    cola.push(k);
    col[k] = ini;
    if(ini==2)ans++;
    while(cola.size()>0){
        int nodo = cola.front();cola.pop();
        for(int j=0;j<grafo[nodo].size();j++){
            int peso= grafo[nodo][j].second;
            int destino = grafo[nodo][j].first;
            for(int k=0;k<6;k++){
                if(validoscolor[k]==col[nodo] and validospeso[k]==peso){
                    if(colorresultante[k]==-1)
                    {
                        return -1;
                    }
                    if(col[destino]==0){
                         col[destino] = colorresultante[k];
                         if(colorresultante[k]==2)ans++;
                         cola.push(destino);
                         break;
                    }
                    else if(col[destino]!=colorresultante[k]){
                        return -1;
                    }
                    break;
                }
            }
        }
    }
    return ans;
}

int main(){
    memset(colores,0,sizeof(colores));
    memset(colores2,0,sizeof(colores2));
    for(int i=0;i<200010;i++){
        grafo[i].clear();
    }
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int origen,destino,tam;
        cin>>origen>>destino>>tam;
        grafo[origen].push_back(make_pair(destino,tam));
        grafo[destino].push_back(make_pair(origen,tam));
    }
    int ans=0;
    for(int i=0;i<=n;i++){
        if(colores[i]==0 and colores2[i]==0){
            int tempans1 = primero(i,colores,1);
            int tempans2 = primero(i,colores2,2);
            if(tempans1==-1 and tempans2==-1){
                ans = -1;
                break;
            }
            if(tempans1==-1)tempans1=tempans2;
            if(tempans2==-1)tempans2=tempans1;
            tempans1 = min(tempans1,tempans2);
            tempans2 = min(tempans1,tempans2);
            ans+=tempans1;
        }
    }
    if(ans<0){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<ans<<endl;
    }
}

