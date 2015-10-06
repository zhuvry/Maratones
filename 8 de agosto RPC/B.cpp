#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int T;
int main(){
    cin>>T;
    string sonidos;
    for(int i=0;i<T;i++){
        getline(cin,sonidos);
        vector<string> entradas;
        map<string,int> salidas;
        getline(cin,sonidos);
        stringstream ss(sonidos);
        string temp;
        while(ss>>temp){
            entradas.push_back(temp);
        }
        string primera,segunda,tercera;
        while(cin>>primera>>segunda>>tercera){
            if(primera=="what" and segunda=="does")break;
            salidas[tercera] = 2;
        }
        string cuarta,quinta;
        cin>>cuarta>>quinta;
        vector<string> ans;
        for(int j=0;j<entradas.size();j++){
            if(salidas[entradas[j]]!=2){
                ans.push_back(entradas[j]);
            }
        }
        for(int j=0;j<ans.size();j++){
            cout<<ans[j];
            if(j!=ans.size()){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
