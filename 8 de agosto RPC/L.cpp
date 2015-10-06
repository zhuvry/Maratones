#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int T,k;
int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>k;
        long long int llevo = 0;
        for(int j=0;j<k;j++){
            llevo = llevo*2;
            llevo++;
        }
        cout<<llevo<<endl;

    }
}
