#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli T;
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        lli n;cin>>n;

        queue<pair<lli,lli> > cola;
        lli ans = 0;
        for(int j=0;j<n;j++){

            queue<pair<lli,lli> > cola2;
            lli actual;cin>>actual;
            map<lli,bool> mapa;
            while(cola.size()>0){
                pair<lli,lli> par = cola.front();cola.pop();
                lli numero = par.first;
                numero = __gcd(numero,actual);
                if(mapa[numero]==false){
                    cola2.push(make_pair(numero,par.second+1));
                    ans = max(ans,numero*(par.second+1));
                    mapa[numero]=true;
                }
            }
            cola2.push(make_pair(actual,1));
            ans = max(ans,actual);
            cola = cola2;
        }
        cout<<ans<<endl;
    }
}
