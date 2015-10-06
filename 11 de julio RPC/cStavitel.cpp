#include <bits/stdc++.h>

using namespace std;
#define All(x) x.begin(),x.end()
#define pb(x) push_back(x)
typedef long long int lli;
int N,K;
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        vector<lli> frontal;
        vector<lli> lateral;
        map<lli,lli> mapa;
        cin>>K;
        for(int j=0;j<K;j++){
            lli temp;cin>>temp;
            frontal.pb(temp);
            mapa[temp]++;
        }
        for(int j=0;j<K;j++){
            lli temp;cin>>temp;
            lateral.pb(temp);
        }
        sort(All(frontal));
        sort(All(lateral));
        lli menor = 0;
        for(int i=0;i<frontal.size();i++){
            menor+= frontal[i];
        }
        for(int i=0;i<lateral.size();i++){
            if(mapa[lateral[i]]>0){
                mapa[lateral[i]]--;
            }
            else{
                menor+=lateral[i];
            }
        }
        lli mayor = 0;
        for(int i=0;i<frontal.size();i++){
            for(int j=0;j<lateral.size();j++){
                mayor+= min(frontal[i],lateral[j]);
            }
        }
        printf("Minimalni budova obsahuje %lli kostek, maximalni %lli kostek.\n",menor,mayor);

    }
}
