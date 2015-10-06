#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N,K;
int main(){
    while(cin>>N>>K){
        vector<lli> numeros;
        map<lli,lli> mapa;
        for(int i=0;i<N;i++){
            lli ai;cin>>ai;
            mapa[ai]++;
            if(mapa[ai]==1){
                numeros.push_back(ai);
            }
        }
        sort(numeros.begin(),numeros.end());
        lli ans = 0;
        for(int i=0;i<numeros.size();i++){
            lli base = numeros[i];
            mapa[base]--;
            mapa[base*K]--;
            mapa[base*K*K]--;
            lli multiplicador = mapa[base]+1;
            multiplicador*=(mapa[base*K]+1);
            multiplicador*=(mapa[base*K*K]+1);
            mapa[base]++;
            mapa[base*K]++;
            mapa[base*K*K]++;
            ans+=multiplicador;
        }
        cout<<ans<<endl;
    }
}
