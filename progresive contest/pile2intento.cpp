#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1010][1010];
int padres[1010][1010];
string pilaa,pilab;
int main(){
    cin>>N;
    cin>>pilaa>>pilab;
    dp[0][0] = 0;
    for(int i=1;i<=N;i++){
        if(pilaa[i-1]=='1' and dp[0][i-1]<1){
            dp[0][i]=dp[0][i-1]+1;
            padres[0][i] = 1;
        }
        else if(pilaa[i-1]=='0' and dp[0][i-1]>-1 and dp[0][i-1]!=3){
            dp[0][i] = dp[0][i-1]-1;
            padres[0][i] = 1;
        }
        else{
            dp[0][i] = 3;
            padres[0][i]=3;
        }
        if(pilab[i-1]=='1' and dp[i-1][0]<1){
            dp[i][0] = dp[i-1][0]+1;
            padres[i][0] = -1;
        }
        else if(pilab[i-1]=='0' and dp[i-1][0]>-1 and dp[i-1][0]!=3){
            dp[i][0] = dp[i-1][0]-1;
            padres[i][0] = -1;
        }
        else{
            dp[i][0] = 3;
            padres[i][0] = 3;
        }
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            if(pilaa[j-1]=='1' and dp[i][j-1]<1 and dp[i][j-1]!=3){
                dp[i][j] = dp[i][j-1]+1;
                padres[i][j] = 1;
            }
            else if(pilaa[j-1]=='0' and dp[i][j-1]>-1 and dp[i][j-1]!=3){
                dp[i][j] = dp[i][j-1] -1;
                padres[i][j] = 1;
            }
            else if(pilab[i-1]=='1' and dp[i-1][j]<1 and dp[i-1][j]!=3){
                dp[i][j] = dp[i-1][j]+1;
                padres[i][j] = -1;
            }
            else if(pilab[i-1]=='0' and dp[i-1][j]>-1 and dp[i-1][j]!=3){
                dp[i][j] = dp[i-1][j]-1;
                padres[i][j] = -1;
            }
            else{
                dp[i][j] = 3;
                padres[i][j] = 3;
            }
        }
    }
    string ans = "";
    int actual = padres[N][N];
    int iactual= N;
    int jactual =N;
    while(actual!=0){
        if(actual==1){
            ans+="1";
            jactual--;
        }
        else if(actual==-1){
            ans+="2";
            iactual--;
        }
        actual = padres[iactual][jactual];
    }
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
    return 0;
}
