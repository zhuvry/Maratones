#include <bits/stdc++.h>
using namespace std;
int n,m;
int destinoi,destinoj;
char estado[510][510];
bool dfs(int i,int j)
{
    if(i==destinoi and j-1==destinoj){
        if(estado[i][j-1]=='X'){
            return true;
        }
    }
    if(i+1 == destinoi and j== destinoj){
        if(estado[i+1][j]=='X')
        {
            return true;
        }
    }
    if(i==destinoi and j+1==destinoj){
        if(estado[i][j+1]=='X'){
            return true;
        }
    }
    if(i-1==destinoi and j==destinoj){
        if(estado[i-1][j]=='X'){
            return true;
        }
    }
    if(j>0 and estado[i][j-1]=='.'){
        estado[i][j-1] = 'X';
        if(dfs(i,j-1)){
            return true;
        }
        //estado[i][j-1] = '.';
    }
    if(i<n-1 and estado[i+1][j]=='.'){
        estado[i+1][j] = 'X';
        if(dfs(i+1,j)){
            return true;
        }
        //estado[i+1][j] = '.';
    }
    if(j<m-1 and estado[i][j+1]=='.'){
        estado[i][j+1] = 'X';
        if(dfs(i,j+1)){
            return true;
        }
        //estado[i][j+1] = '.';
    }
    if(i>0 and estado[i-1][j]=='.'){
        estado[i-1][j] = 'X';
        if(dfs(i-1,j)){
            return true;
        }
        //estado[i-1][j] = '.';
    }
    return false;

}
void solve(int origeni,int origenj){
        if(abs(origeni-destinoi)==1 and origenj==destinoj and estado[destinoi][destinoj]=='X'){
            cout<<"YES"<<endl;
            return;
        }
        else if(abs(origenj-destinoj)==1 and origeni==destinoi and estado[destinoi][destinoj]=='X'){
            cout<<"YES"<<endl;
            return;
        }
        if(abs(origenj-destinoj)==1 and origeni==destinoi and estado[destinoi][destinoj]=='.'){
            origeni = destinoi;
            origenj = destinoj;
            estado[destinoi][destinoj] ='X';
        }
        if(abs(origeni-destinoi)==1 and origenj==destinoj and estado[destinoi][destinoj]=='.'){
            origeni = destinoi;
            origenj = destinoj;
            estado[destinoi][destinoj] ='X';
        }

        if(dfs(origeni,origenj)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while(cin>>n>>m){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>estado[i][j];
            }
        }
        int origeni,origenj;
        cin>>origeni>>origenj;
        cin>>destinoi>>destinoj;
        origeni--;origenj--;destinoi--;destinoj--;
        solve(origeni,origenj);
    }
}
