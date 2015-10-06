#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
map<string,lli> mapa;
lli T;
int main(){
    while(scanf("%lli",&T)!=EOF){
        if(T==0)break;
        mapa.clear();
        lli ans = 0;
        for(int i=0;i<T;i++){
            lli cartas;scanf("%lli",&cartas);
            for(int j=0;j<cartas;j++){
                string temp;cin>>temp;
                if(mapa[temp]==0){
                    mapa[temp]=1;
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
}

