#include <bits/stdc++.h>
using namespace std;
char tablero[1010][1010];
pair<bool,bool> tablero2[1010][1010]; //se llega por arriba y por abajo//
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int r,c,s;
bool dfs1(int i,int j){
    if(tablero[i][j]=='#')return false;
    for(int a=0;a<4;a++){
        int nexti= i+dx[a];
        int nextj = j+dy[a];
        if(nexti<0 or nextj<0 or nexti>r+1 or nextj>=c)continue;
        if(tablero2[nexti][nextj].first==0 and tablero2[i][j].first==1 and tablero[nexti][nextj]=='.'){
            tablero2[nexti][nextj].first = 1;
            if(dfs1(nexti,nextj))return true;
        }
    }
    if(tablero2[i][j].first == 1 and tablero2[i][j].second==1)return true;
}
bool dfs2(int i,int j){
    if(tablero[i][j]=='#')return false;
    for(int a=0;a<4;a++){
        int nexti= i+dx[a];
        int nextj = j+dy[a];
        if(nexti<0 or nextj<0 or nexti>r+1 or nextj>=c)continue;
        if(tablero2[nexti][nextj].second==0 and tablero2[i][j].second==1 and tablero[nexti][nextj]=='.'){
            tablero2[nexti][nextj].second = 1;
            if(dfs2(nexti,nextj))return true;
        }
    }
    if(tablero2[i][j].first == 1 and tablero2[i][j].second==1)return true;
    return false;
}
bool actualizar(int i,int j){
    if(tablero[i][j]=='#')return false;
    for(int a=0;a<4;a++){
        int nexti = i+dx[a];
        int nextj = j+dy[a];
        if(nexti<0 or nextj<0 or nexti>r+1 or nextj>=c)continue;
        if(tablero2[i][j].first==0 and tablero2[nexti][nextj].first==1){
            tablero2[i][j].first = 1;
            if(dfs1(i,j))return true;
        }
        if(tablero2[i][j].second==0 and tablero2[nexti][nextj].second==1){
            tablero2[i][j].second = 1;
            if(dfs2(i,j))return true;
        }
    }
}
int main(){
    while(scanf("%d%d%d",&r,&c,&s)!=EOF){
        memset(tablero,0,sizeof(tablero));
        memset(tablero2,0,sizeof(tablero2));
        deque<int> decola[1010];
        for(int i=1;i<=r;i++){
            scanf("%s", tablero[i]);
            for(int j=0;j<c;j++){
                if(tablero[i][j]=='#') decola[j].push_back(i);
            }
        }
        for(int j=0;j<c;j++){
            tablero2[0][j].first= true;
            tablero2[r+1][j].second = true;
        }
        int estado1 = 0;
        int estado2 = 0;
        for(int j=0;j<c;j++){
            if(dfs1(0,j))estado1=1;
            if(dfs2(r+1,j))estado1=1;
        }
        for(int a=1;a<=s;a++){
            int columna;scanf("%d",&columna);

            if(estado1==0 and estado2==0){
                if(columna>0){//alien shot
                    columna--;
                    int fila = decola[columna].front();decola[columna].pop_front();
                    tablero[fila][columna] = '.';
                    if(actualizar(fila,columna))estado2=a;
                }else{
                    columna = abs(columna);
                    columna--;
                    int fila=decola[columna].back();decola[columna].pop_back();
                    tablero[fila][columna] = '.';
                    if(actualizar(fila,columna))estado2=-a;
                }
            }
        }

        if(estado1!=0){
            printf("0\n");
        }
        else if(estado2!=0){
            printf("%d\n",estado2);
        }
        else{
            printf("X\n");
        }
    }
}
