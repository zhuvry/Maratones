#include <bits/stdc++.h>
using namespace std;
int N;
string pilaa,pilab;
map<pair<int,int>,string> mapa;
string solve(int a,int b,int direccion,string llevo){
    if(mapa[make_pair(a,b)]!=""){
        cout<<"lo use"<<endl;
        return mapa[make_pair(a,b)];
    }
    if(a>N-1 or b>N-1){
        mapa[make_pair(a,b)]=llevo;
        return llevo;
    }
    if(a==N-1 and b==N-1){
        mapa[make_pair(a,b)]=llevo;
        return llevo;
    }
    if(pilaa[a+1]=='1' and direccion<1 and a<N-1){

        string ans = solve(a+1,b,direccion+1,llevo+"1");
        if(ans.size()==2*N){
            mapa[make_pair(a,b)]=ans;
            return ans;
        }
    }
    if(pilaa[a+1]=='0' and direccion>-1 and a<N-1){
        string ans = solve(a+1,b,direccion-1,llevo+"1");
        if(ans.size()==2*N){
            mapa[make_pair(a,b)]=ans;
            return ans;
        }
    }
    if(pilab[b+1]=='1' and direccion<1 and b<N-1){
        string ans = solve(a,b+1,direccion+1,llevo+"2");
        if(ans.size()==2*N){
            mapa[make_pair(a,b)]=ans;
            return ans;
        }
    }
    if(pilab[b+1]=='0' and direccion>-1 and b<N-1){
        string ans = solve(a,b+1,direccion-1,llevo+"2");
        if(ans.size()==2*N){
            mapa[make_pair(a,b)]=llevo;
            return ans;
        }
    }
    return llevo;
}
int main(){
    mapa.clear();
    cin>>N;
    cin>>pilaa>>pilab;
    cout<<solve(-1,-1,0,"")<<endl;
    return 0;
}
