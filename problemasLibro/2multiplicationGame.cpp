#include <bits/stdc++.h>
using namespace std;
map<int,bool> mapa;
long long int n;
bool gana(long long int a,bool jugador){
    if(a*9>=n){
        mapa[a] = 1;
        return jugador;
    }
    if(mapa.count(a)>0){
        if(mapa[a]==1){
            return jugador;
        }
        else{
            return !jugador;
        }
    }
    for(int i=2;i<=9;i++){
        if(gana(a*i,!jugador)==jugador){
            mapa[a] =1;
            return jugador;
        }
    }
    mapa[a] = 0;
    return !jugador;
}
int main()
{
    while (cin>>n){
        mapa.clear();

        bool respuesta = gana(1,0);
        if(!respuesta){
            cout<<"Stan wins."<<endl;
        }
        else{
            cout<<"Ollie wins."<<endl;
        }
    }

}
