#include <bits/stdc++.h>
using namespace std;
typedef pair<long long int,long long int> dist_node;
typedef pair<long long int,long long int> edge;
const long long int MAXN =300005;
const long long int INF = pow(2,60);
vector<edge> g[MAXN];
long long int d[MAXN];
long long int p[MAXN];
long long int sume[MAXN];
void dijkstra(long long int s,long long int n){
    for(long long int i=0;i<=n;i++){
        d[i]= INF; p[i]=-1;sume[i]=INF;
    }
    priority_queue<dist_node,vector<dist_node>,greater<dist_node> > q;
    d[s] = 0;
    sume[s]=0;
    q.push(dist_node(0,s));
    while(!q.empty()){
        long long int dist =q.top().first;
        long long int cur =q.top().second;
        q.pop();
        if(dist>d[cur])continue;
        for(long long int i=0;i<g[cur].size();++i){

            long long int next =g[cur][i].first;
            long long int w_extra = g[cur][i].second;
            if(d[cur] + w_extra <= d[next] and w_extra<sume[next]){
                d[next] = d[cur] + w_extra;
                p[next] = cur;
                sume[next] = w_extra;
                q.push(dist_node(d[next],next));

            }
        }
    }
}
int main()
{
    map< pair<long long int,long long int>,long long int > mapa;
    long long int n,m;
    while(cin>>n>>m){
        for(long long int i=0;i<m;i++){
            long long int u1,v1,w1;
            cin>>u1>>v1>>w1;
            g[u1].push_back(make_pair(v1,w1));
            g[v1].push_back(make_pair(u1,w1));
            mapa[make_pair(u1,v1)] = i+1;
            mapa[make_pair(v1,u1)] = i+1;
        }
        long long int fuente;cin>>fuente;
        dijkstra(fuente,n);
        vector<long long int> ans;
        long long int tam = 0;
        for(long long int i=1;i<=n;i++){
            if(i!=fuente){
                tam+= (d[i]-d[p[i]]);
            }
            if(p[i]!=-1){
                pair<long long int,long long int> par = make_pair(i,p[i]);
                ans.push_back(mapa[par]);
            }
        }
        cout<<tam<<endl;
        for(long long int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i<ans.size()-1){
                cout<<" ";
            }

        }
        cout<<endl;
    }
}
