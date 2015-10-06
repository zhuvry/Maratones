#include <bits/stdc++.h>
using namespace std;
int n1,n2,k1,k2;
long long int dp[102][102][22];
long long int modulo = 100000000;

int main(){
    cin>>n1>>n2>>k1>>k2;
    dp[0][1][1]=1;
    dp[1][0][11]=1;
    for(int i=0;i<=n2;i++){
        for(int j=0;j<=n1;j++){
            for(int x=11;x<=10+k2;x++){
                if(j>0){
                    dp[i][j][1] += dp[i][j-1][x];
                    dp[i][j][1]%=modulo;
                }
            }
            for(int a=2;a<=k1;a++){
                if(j>0){
                    dp[i][j][a] += dp[i][j-1][a-1];
                    dp[i][j][a]%=modulo;
                }
            }
            for(int x=1;x<=k1;x++){
                if(i>0){
                    dp[i][j][11] += dp[i-1][j][x];
                    dp[i][j][11]%=modulo;
                }
            }
            for(int a=12;a<=10+k2;a++){
                if(i>0){
                    dp[i][j][a] += dp[i-1][j][a-1];
                    dp[i][j][a]%=modulo;
                }
            }
        }
    }
    long long int ans = 0;
    for(int a=0;a<22;a++){
        ans+= dp[n2][n1][a];
        ans%=modulo;
    }
    cout<<ans<<endl;
}
