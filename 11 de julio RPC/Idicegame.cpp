#include <bits/stdc++.h>
using namespace std;

int a1,b1,a2,b2,a3,b3,a4,b4;
vector<int> primeros;
int main(){
    cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
    primeros.clear();
    for(int i=a1;i<=b1;i++){
        for(int j=a2;j<=b2;j++){
            primeros.push_back(i+j);
        }
    }
    long long int gana = 0;
    long long int pierde = 0;
    for(int i=a3;i<=b3;i++){
        for(int j=a4;j<=b4;j++){
            for(int k=0;k<primeros.size();k++){
                if(i+j<primeros[k])pierde++;
                if(i+j>primeros[k])gana++;
            }
        }
    }
    if(gana==pierde){
        cout<<"Tie"<<endl;
    }
    if(gana>pierde){
        cout<<"Emma"<<endl;
    }
    if(pierde>gana){
        cout<<"Gunnar"<<endl;
    }
}
