#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main(){

    lli N,K;
    scanf("%lli",&N);
    for(int i=0;i<N;i++){
        scanf("%lli",&K);
        lli izq =  0;
        lli der = 2000000;
        lli ans = pow(2,62);
        for(int j=0;j<K;j++){
            lli tempizq;scanf("%lli",&tempizq);
            lli tempder;scanf("%lli",&tempder);
            izq = max(izq-1,tempizq);
            der = min(der+1,tempder);
            ans = min(ans,abs(der-izq));
        }
        printf("K prechodu reky je treba %lli pontonu.\n",ans);
    }

}
