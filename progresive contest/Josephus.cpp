#include <bits/stdc++.h>
using namespace std;
int N,K;
vector<int> valores;
int modulo(int valor, int mod){
    if(valor>=0){
        return valor%mod;
    }
    else{
        return (mod - (abs(valor)%mod))%mod;
    }
}
int main(){
    while(cin>>N>>K){
        if(N==0){
            break;
        }
        valores.clear();
        for(int i=1;i<=N;i++){
            valores.push_back(i);
        }
        int posicion = 1;
        bool derecha = true;
        while(valores.size()>1){
            if(derecha){
                posicion = modulo(posicion+(K-2),valores.size());
                valores.erase(valores.begin()+ posicion);
            }
            else{
                posicion = modulo(posicion-(K-1),valores.size());
                valores.erase(valores.begin()+posicion);
            }
            derecha = !derecha;
        }
        cout<<valores[0]<<endl;
    }
}
