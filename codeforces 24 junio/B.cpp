#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(cin>>n){
        int mayor = 0;
        map<string,int> mapa;
        for(int i=0;i<n;i++){
            string temp;cin>>temp;
            mapa[temp]++;
            mayor = max(mayor,mapa[temp]);
        }
        cout<<mayor<<endl;

    }

}
