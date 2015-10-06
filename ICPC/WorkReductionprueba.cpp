#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N,fin,num1,num2;
lli dp[100050];
lli cuesta(lli tengo){
    if(dp[tengo]!=-1){
        return dp[tengo];
    }
    lli precioizq = -1;
    lli precioder = -1;
    if(tengo/2==fin){
        precioizq = num1*(tengo-fin);
        precioder = num2;
        dp[tengo] = min(precioizq,precioder);
        return dp[tengo];
    }
    if(tengo/2<fin){
        dp[tengo] = num1*(tengo-fin);
        return dp[tengo];
    }
    dp[tengo] = min(cuesta(tengo-1)+num1,cuesta(tengo/2)+num2);
    return dp[tengo];
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++){
        lli actual,empresas;cin>>actual>>fin>>empresas;
        vector<pair<int,string> > ans;
        for(int j=0;j<empresas;j++){
            string datos;
            cin>>datos;
            string emp = "";
            num1=0;
            num2=0;
            int a=0;
            for(int a=0;a<100050;a++){
                dp[a]=-1;
            }
            for(a=0;a<datos.size();a++){
                if(datos[a]==':')break;
                emp+=datos[a];
            }
            a++;
            for(;a<datos.size();a++){
                if(datos[a]==',')break;
                num1 = num1*10 + datos[a]-'0';
            }
            a++;
            for(;a<datos.size();a++){
                num2 = num2*10+datos[a]-'0';
            }
            lli respuesta = cuesta(actual);
            ans.push_back(make_pair(respuesta,emp));
        }
        sort(ans.begin(),ans.end());
        cout<<"Case "<<i+1<<endl;
        for(int x=0;x<ans.size();x++){
            cout<<ans[x].second<<" "<<ans[x].first<<endl;
        }
    }
}
