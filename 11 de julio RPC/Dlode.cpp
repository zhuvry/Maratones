#include <bits/stdc++.h>
using namespace std;
int main(){
    long long int N;
    cin>>N;
    for(int caso=0;caso<N;caso++){
        vector<long long int> numeros;
        for(int i=1;i<=10000000;i=i*3){
            numeros.push_back(i);
        }
        reverse(numeros.begin(),numeros.end());
        long long int K;
        cin>>K;
        vector<int> ans;
        for(int i=0;i<numeros.size();i++){
            if(K<numeros[i] and ans.size()==0)continue;
            long long int residuo = K/numeros[i];
            K-=(residuo*numeros[i]);
            ans.push_back(residuo);
        }
        cout<<ans[0];
        for(int i=1;i<ans.size();i++){
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
}
