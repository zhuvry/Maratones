#include <bits/stdc++.h>
using namespace std;
long long int C,n;
bool solucionar(){
    bool resultado = true;
    long long int dentro = 0;
    long long int salen,entran,esperan;
    for(int i=0;i<n;i++){
        cin>>salen>>entran>>esperan;
        dentro-=salen;
        if(dentro<0){
            resultado = false;
        }
        dentro+=entran;
        if(dentro>C){
            resultado = false;
        }
        if(esperan>0 and dentro<C){
            resultado = false;
        }
    }
    if(dentro!=0 or esperan!=0){
        resultado = false;
    }
    return resultado;
}
int main(){
    cin>>C>>n;
    if(solucionar()){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }
}
