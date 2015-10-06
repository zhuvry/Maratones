#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    while(cin>>N){
        vector<lli> casas(N+4);
        casas[0] = 0;

        for(int i=1;i<=N;i++){
            cin>>casas[i];
        }
        for(int i=1;i<=N;i++){
            lli minima = min(abs(casas[i]-casas[i-1]),abs(casas[i]-casas[i+1]));
            lli maxima = max(abs(casas[i]-casas[1]),abs(casas[i]-casas[N]));
            if(i==1){
                minima= abs(casas[i]-casas[i+1]);
            }
            if(i==N){
                minima = abs(casas[i]-casas[i-1]);
            }
            cout<<minima<<" "<<maxima<<endl;
        }
    }

}

