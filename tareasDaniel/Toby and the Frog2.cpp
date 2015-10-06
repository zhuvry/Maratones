#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int T,meta;
double arreglo[5010][5010];
double dp(int i,int j){
    if(i<0 or j<0){
        return 0;
    }
    if(j!=0 and i==0){
        arreglo[i][j] = 0;
        return 0;
    }
    if(i>j)return 0;
    if(i*10<j)return 0;
    if(arreglo[i][j]!=-1){
        return arreglo[i][j];
    }
    double sumatoria = 0;
    double divisor = min(meta-j+1,10);
    sumatoria+= (1.0/divisor)*dp(i-1,j-1);
    double divisor2 = min(meta-(j-11)+1,10);
    sumatoria-= (1.0/divisor2)*dp(i-1,j-11);
    sumatoria+= dp(i,j-1) ;
    arreglo[i][j] = sumatoria;
    return sumatoria;
}
int main(){
    while(cin>>T){
        for(int i=0;i<T;i++){
            for(int a=0;a<5010;a++){
                for(int b=0;b<5010;b++){
                    arreglo[a][b]=-1;
                }
            }

            arreglo[0][0] = 1;
            cin>>meta;
            double ans = 0;
            for(int j=0;j<5010;j++){
                ans+= (dp(j,meta)*j);
            }
            printf("%.10lf\n",ans);
        }
    }
}
