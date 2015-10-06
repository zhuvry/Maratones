#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    while(scanf("%lli",&N)!=EOF){
        if(N<0)break;
        lli ans = N*(N+1);
        ans = ans/2;
        ans++;
        printf("%lli\n",ans);
    }

}
