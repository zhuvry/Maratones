
#include <bits/stdc++.h>
using namespace std;
long long int T,n;
string palabra;
int main()
{
    while (cin>>T){
        for(int i=0;i<T;i++){
            cin>>n>>palabra;
            n = n%palabra.size();
            for(int j=palabra.size()-n;j<palabra.size();j++){
                cout<<palabra[j];
            }
            for(int j=0;j<palabra.size()-n;j++){
                cout<<palabra[j];
            }
            cout<<endl;
        }
    }
}
