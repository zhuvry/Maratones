#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    while(cin>>N){
        lli ans=0;
        lli actual = 0;
        map<lli,int> mapa;
        for(int i=0;i<N;i++){
            char signo;cin>>signo;
            lli num;cin>>num;
            if(mapa[num]==1){
                mapa[num]=0;
                actual--;
            }
            else if(mapa[num]==0 and signo=='+'){
                actual++;
                ans = max(ans,actual);
                mapa[num]=1;
            }else if(mapa[num]==0 and signo=='-'){
                ans++;
                mapa[num]=0;
            }
        }
        cout<<ans<<endl;
    }

}

