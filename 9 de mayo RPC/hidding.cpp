#include <bits/stdc++.h>
using namespace std;
int N;
int main(){
    while(cin>>N){
        long long int ans = 0;
        map<long long int,int> mapa;
        long long int cero =0;
        long long int sumatoria = 0;
        int temp;scanf("%i",&temp);
        mapa[temp]++;
        ans += mapa[cero];
        sumatoria+=temp;

        for(int i=1;i<N;i++){
            int temp;scanf("%i",&temp);
            cero -= temp;
            mapa[cero+temp]++;
            ans += mapa[cero];
        }
        printf("%lli\n",ans);
    }
}
