#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N,P,T,C,S;
vector<pair<lli,lli> > planos;
int dx[6] = {0,0,1,-1,-1,1};
int dy[6] = {1,-1,0,0,1,-1};
void solve(){
    lli actual = 0;
    lli celdas = 0;
    for(int j=0;j<planos.size();j++){
        for(int k=0;k<planos[j].second;k++){
            celdas++;
            if(actual!=0){
                actual-=2;
            }
            actual+= planos[j].first;
            if(actual>=P){
                printf("Je treba %lli celku.\n",celdas);
                return;
            }
        }
    }
    printf("Kapacita zakladny je pouze %lli lidi.\n",actual);
}
int main(){
    scanf("%lli",&N);
    for(int i=0;i<N;i++){
        scanf("%lli%lli",&P,&T);
        planos.clear();
        for(int j=0;j<T;j++){
            scanf("%lli%lli",&C,&S);
            lli cant = 0;
            map<pair<lli,lli>,lli> mapa;
            for(int k=0;k<S;k++){
                lli x,y;scanf("%lli%lli",&x,&y);
                mapa[make_pair(x,y)] = 6;
                cant+=6;
                for(int a=0;a<6;a++){
                    pair<lli,lli> pos = make_pair(x+dx[a],y+dy[a]);
                    if(mapa.count(pos)==1){
                        cant-=2;
                    }
                }
            }
            planos.push_back(make_pair(cant,C));
        }
        sort(planos.begin(),planos.end());
        reverse(planos.begin(),planos.end());
        solve();
    }

}
