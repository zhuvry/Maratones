#include <bits/stdc++.h>
using namespace std;
int H,W;

int solucion;
int iE,jE,tam;
string programa;
char tablero[105][105];
int mapa[105][105][6][13];
struct Robot{
public:
    int i;
    int j;
    int direccion;
};
void avanzar(Robot &a){
    if(a.direccion==0 and a.i>0 and tablero[a.i-1][a.j]!='X'){
        a.i--;
    }
    if(a.direccion==1 and a.j<W-1 and tablero[a.i][a.j+1]!='X'){
        a.j++;
    }
    if(a.direccion==2 and a.i<H-1 and tablero[a.i+1][a.j]!='X'){
        a.i++;
    }
    if(a.direccion==3 and a.j>0 and tablero[a.i][a.j-1]!='X'){
        a.j--;
    }
}
void cambiar(Robot &r,char orden){
    if(orden == 'R'){
        r.direccion++;
        r.direccion %= 4;
    }
    if(orden == 'L'){
        r.direccion--;
        if(r.direccion==-1){
            r.direccion = 3;
        }
    }
    if(orden == 'S'){
        avanzar(r);
    }
}

bool solve(Robot &actual,int &instruccion){
    if(actual.i==iE and actual.j==jE){
        return true;
    }
    if(mapa[actual.i][actual.j][actual.direccion][instruccion]==-1){
        return false;
    }
    if(mapa[actual.i][actual.j][actual.direccion][instruccion]==1){
        return true;
    }
    mapa[actual.i][actual.j][actual.direccion][instruccion]=-1;
    int acti = actual.i;
    int actj = actual.j;
    int dir = actual.direccion;
    int inst = instruccion;
    cambiar(actual,programa[instruccion]);
    instruccion++;

    instruccion= instruccion%tam;
    if(solve(actual,instruccion)){
        mapa[acti][actj][dir][inst]=1;
        return true;
    }
    return false;
}
int main(){
    while(scanf("%i%i",&H,&W) != EOF){
        memset(mapa,0,sizeof(mapa));
        solucion =0;
        int puntos = 0;
        for(int i=0;i<H;i++){
            scanf("%s", &tablero[i]);
            for(int j=0;j<W;j++){
                if(tablero[i][j]=='E'){
                    iE = i;
                    jE = j;
                }
                if(tablero[i][j]=='.'){
                    puntos++;
                }
            }
        }
        scanf("%i",&tam);
        char programa2[tam];scanf("%s",&programa2);
        programa = "";
        for(int i=0;i<tam;i++){
            programa += programa2[i];
        }
        for(int a=0;a<H;a++){
            for(int b=0;b<W;b++){
                if(tablero[a][b]!='.')continue;
                Robot actual;
                actual.i = a;
                actual.j = b;
                actual.direccion = 0;
                int inst=0;
                solve(actual,inst);
            }
        }
        for(int i=0;i<H;i++){
            for(int j=0;j<W;j++){
                if(mapa[i][j][0][0]==1){
                    solucion++;
                }
            }
        }
        solucion++;
        if(solucion==puntos+1){
            printf("OK\n");
        }
        else{
            printf("%i\n",solucion);
        }
    }

}
