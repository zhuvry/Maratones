#include <bits/stdc++.h>
using namespace std;

int main(){
    char tablero[3][3];
    int a,contarx=0,contaro=0;
    cin>> a;
    for(int z=0;z<a;z++){
        contarx=0;
        contaro=0;
        for(int i =0;i<3;i++){
            for(int j=0;j<3;j++){
                char temp;cin>>temp;tablero[i][j]=temp;
                if (tablero[i][j]== 'X'){
                    contarx++;
                }
                else if (tablero[i][j]=='O'){
                    contaro++;
                }
            }
        }
        int pganar=0;
        int gananx=0;
        int ganan0=0;
        int xganarhorizontal=0;
        int xganarvertical=0;
        int xganardiagonal =0;
        for(int c=0;c<3;c++){
            if (tablero[c][0]==tablero[c][1] and tablero[c][1]==tablero[c][2] and tablero[c][0]!='.'){
                pganar++;
                if(tablero[c][0]=='X'){
                    xganarvertical++;
                    gananx++;
                }
                else{
                    ganan0++;
                }
            }
            if(tablero[0][c]==tablero[1][c] and tablero[1][c]==tablero[2][c] and tablero[0][c]!='.'){
                pganar++;
                if(tablero[0][c]=='X'){
                    xganarhorizontal++;
                    gananx++;
                }
                else{
                    ganan0++;
                }
            }
        }
        if(tablero[0][0]==tablero[1][1] and tablero[1][1]==tablero[2][2] and tablero[0][0]!='.'){
            if(tablero[0][0]=='X'){
                xganardiagonal++;
                gananx++;
            }
            else{
                ganan0++;
            }
            pganar++;
        }
        if(tablero[0][2]==tablero[1][1] and tablero[1][1]==tablero[2][0] and tablero[0][2]!='.'){
            if(tablero[0][0]=='X'){
                xganardiagonal++;
                gananx++;
            }
            else{
                ganan0++;
            }
            pganar++;
        }
        if(contaro>4){
            cout<<"no\n"<<endl;
        }
        else if(contarx==contaro+1 ){
            else if(pganar!=gananx){
                cout<<"no\n";
            }
            else if(pganar>=3){
                cout<<"no\n";
            }
            else if(pganar==2 and gananx==2 and xganardiagonal==2){
                cout<<"yes\n";
            }
            else if(pganar==2 and gananx==2 and xganarhorizontal==1 and xganarvertical==1){
                cout<<"yes\n";
            }
            else if(pganar==1 and gananx==1){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
        else if(contarx == contaro){
            if(pganar!=gananO){
                cout<<"no\n";
            }
            if(pganar==0){
                cout<<"yes\n";
            }
            else if(pganar==1 and ganan0==1){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
        }
        else {
            cout<<"no\n";
        }
    }
}
