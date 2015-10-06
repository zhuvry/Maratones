#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    while(scanf("%lli",&N)!=0){
        if(N==0)break;
        int ans = 0;
        for(int i=0;i<N;i++){
            lli actual;scanf("%lli",&actual);
            ans = ans^actual;
        }
        if(ans==0)
        {
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }
}

