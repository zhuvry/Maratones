#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
int main(){
    cin>>N;
    int c = 5/2;
    cout<<c<<endl;
    for(int i=0;i<N;i++){
        lli actual,fin,empresas;cin>>actual>>fin>>empresas;
        vector<pair<int,string> > ans;
        for(int j=0;j<empresas;j++){
            string datos;
            cin>>datos;
            string emp = "";
            lli num1=0;
            lli num2=0;
            int a=0;
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
            lli tengo = actual;
            lli costo = 0;
            while(tengo!=fin){
                lli precioder = -1;
                lli destino = fin;
                if(tengo/2 >=fin){
                    precioder = num2;
                    destino = tengo/2;
                }
                lli precioizq = num1*(tengo-destino);
                tengo = destino;
                if(precioder>0){
                    costo+= min(precioder,precioizq);
                }
                else{
                    costo+=precioizq;
                }
            }
            ans.push_back(make_pair(costo,emp));
        }
        sort(ans.begin(),ans.end());
        cout<<"Case "<<i+1<<endl;
        for(int x=0;x<ans.size();x++){
            cout<<ans[x].second<<" "<<ans[x].first<<endl;
        }

    }
}
