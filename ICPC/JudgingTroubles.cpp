#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli T;
map<string,lli> mapa;
string temp;
lli N;
int main(){
    while(cin>>N){
        mapa.clear();
        for(lli j=0;j<N;j++){
            cin>>temp;
            mapa[temp]++;
        }
        lli ans=0;
        for(lli j=0;j<N;j++){
            string temp;cin>>temp;
            if(mapa[temp]>0){
                ans++;
                mapa[temp]--;
            }
        }
        cout<<ans<<endl;
    }
}

