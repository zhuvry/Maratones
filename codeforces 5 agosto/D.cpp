#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N,K,A,M;
lli jugar(){
    vector<lli> jugadas;
    lli caben = N/A;
    int i=0;
    for(i=0;i<M;i++){
        lli jugada;cin>>jugada;
        jugada--;
        jugadas.push_back(jugada);
        lli atras = -1;
        lli delante = N;
        for(int j=0;j<jugadas.size();j++){
            if(jugada-jugadas[j]>0 and jugadas[j]>atras){
                atras = jugadas[j];
            }
            if(jugada-jugadas[j]<0 and jugadas[j]<delante){
                delante = jugadas[j];
            }
        }
        lli cabian = abs(delante-atras-1)/A;
        lli cabran = abs(delante-(jugada+1))/A + abs(jugada-1-atras)/A;
        caben= caben-(cabian-cabran);
        if(caben<K){

            for(int j=i+1;j<M;j++){
                cin>>jugada;
            }
            return i;
        }

    }
    return -2;
}
int main(){
    while(cin>>N>>K>>A){
        cin>>M;
        cout<<jugar()+1<<endl;
    }
}
