#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    while(cin>>N){
        int ans = 0;
        while(N!=0){
            lli N2 = N;
            vector<int> ordenar;
            while(N2!=0){
                ordenar.push_back(N2%10);
                N2=N2/10;
            }
            lli N3 = 0;
            sort(ordenar.begin(),ordenar.end());
            for(int i=0;i<ordenar.size();i++){
                N3*=10;
                N3+= ordenar[i];
            }
            N = N-N3;
            ans++;
        }
        cout<<ans<<endl;
    }
}
