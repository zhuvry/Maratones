#include <bits/stdc++.h>
using namespace std;
int T,N;
vector<int> grafo[110];
int respuestas[110][110];
int visitados[110];
void dfs(int origen,int betado){
    respuestas[betado][origen] = 0;
    visitados[origen] =1;
    for(int i=0;i<grafo[origen].size();i++){
        int destino = grafo[origen][i];
        if(visitados[destino]!=1 and destino!=betado){
            dfs(destino,betado);
        }
    }
}
void reiniciar(){
    for(int a=0;a<110;a++){
        for(int b=0;b<110;b++){
            respuestas[a][b] =1;
        }
    }
    for(int i=0;i<110;i++){
        grafo[i].clear();
    }
}
int main()
{
    cin>>T;
    for(int i=1;i<=T;i++){
        cin>>N;

        for(int a=0;a<N;a++){
            for(int b=0;b<N;b++){
                int aux;cin>>aux;
                if(aux==1){
                    grafo[a].push_back(b);
                }
            }
        }
        for(int a=0;a<110;a++){
            for(int b=0;b<110;b++){
                respuestas[a][b]=1;
            }
        }

        for(int a=1;a<N;a++){
            for(int i=0;i<110;i++){
                visitados[i]=0;
            }
            dfs(0,a);
        }
        string linea ="+";
        for(int i=0;i<2*N-1;i++){
            linea+="-";
        }
        linea+="+";
        cout<<"Case "<<i<<":"<<endl;

        for(int i=0;i<N;i++){
            cout<<linea<<endl;
            for(int j=0;j<N;j++){
                if(respuestas[i][j]==1){
                    cout<<"|Y";
                }
                else{
                    cout<<"|N";
                }
            }
            cout<<"|"<<endl;
        }
        cout<<linea<<endl;
    }

}

