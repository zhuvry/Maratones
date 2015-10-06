#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n,T;
char tablero[12][12];
int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};
int come(int i,int j){
    int comomas = 0;
    for(int a=0;a<4;a++){
        if(tablero[i+dx[a]][j+dy[a]]=='B' and tablero[i+2*dx[a]][j+2*dy[a]]=='#'){
            tablero[i][j] = '#';
            tablero[i+dx[a]][j+dy[a]] = '#';
            tablero[i+2*dx[a]][j+2*dy[a]] = 'W';
            comomas=max(comomas,1+come(i+2*dx[a],j+2*dy[a]));
            tablero[i][j] = 'W';
            tablero[i+dx[a]][j+dy[a]] = 'B';
            tablero[i+2*dx[a]][j+2*dy[a]] = '#';
        }
    }
    return comomas;
}
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        for(int j=1;j<=10;j++){
            for(int k=1;k<=10;k++){
                cin>>tablero[j][k];
            }
        }
        int ans = 0;
        for(int j=1;j<=10;j++){
            for(int k=1;k<=10;k++){
                if(tablero[j][k]=='W'){
                    ans = max(ans,come(j,k));
                }
            }
        }
        cout<<ans<<endl;
    }
}
