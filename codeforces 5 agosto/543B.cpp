#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>

typedef long long int lli;
int n,m,s0,t0,s1,t1,l0,l1;
vector<int> grafo[3005];
int dp[3005][3005];
int main(){
    scanf("%d%d",&n,&m);
    memset(grafo,0,sizeof(grafo));
    memset(dp,0,sizeof(dp));
    for(int i=0;i<m;i++){
        int a,b;scanf("%i%i",&a,&b);
        grafo[a].push_back(b);
        grafo[b].push_back(a);
    }
    scanf("%d%d%d",&s0,&t0,&l0);
    scanf("%d%d%d",&s1,&t1,&l1);
    for(int i=1;i<=n;i++){
        queue<int> cola;
        cola.push(i);
        dp[i][i] = 0;
        while(cola.size()>0){

            int actual = cola.front();cola.pop();
            for(int j=0;j<grafo[actual].size();j++){
                int destino = grafo[actual][j];
                if(i==destino)continue;
                if(dp[i][destino]==0){
                    dp[i][destino] = dp[i][actual]+1;
                    cola.push(destino);
                }
            }
        }
    }
    int ans = -1;
    if(dp[s0][t0]<=l0 and dp[s1][t1]<=l1)
    {
        ans = m-dp[s0][t0]-dp[s1][t1];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==2 and j==3){
                }
                if(dp[s0][i]!=-1 and dp[i][j]!=-1 and dp[j][t0]!=-1 and dp[s1][i]!=-1 and dp[j][t1]!=-1){
                    if(dp[s0][i]+dp[i][j]+dp[j][t0]<=l0 and dp[s1][i]+dp[i][j]+dp[j][t1]<=l1){
                        ans = max(ans,m-dp[s0][i]-dp[i][j]-dp[j][t0]-dp[s1][i]-dp[j][t1]);
                    }
                    if(dp[s0][i]+dp[i][j]+dp[j][t0]<=l0 and dp[s1][j]+dp[i][j]+dp[i][t1]<=l1){
                        ans = max(ans,m-dp[s0][i]-dp[i][j]-dp[j][t0]-dp[s1][j]-dp[i][t1]);
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}
