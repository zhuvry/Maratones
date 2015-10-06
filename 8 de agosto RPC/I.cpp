#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
int main(){
    cin>>n;
    vector<int> edificios(n);
    map<int,int> mapa;
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        edificios[i]=temp;
        mapa[temp]++;
    }
    sort(edificios.begin(),edificios.end());
    reverse(edificios.begin(),edificios.end());
    int ans =n;
    for(int i=0;i<n;i++){
        if(edificios[i]<=n-i){
            ans = min(ans,i + edificios[i]);
        }
    }
    cout<<ans<<endl;
}

