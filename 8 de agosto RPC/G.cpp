#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
int n;
vector<int> diferencias1;
vector<int> diferencias2;
vector<int> tabla;
int dist(int a,int b){
    if(a<=b)return b-a;
    else{
        return 360000-a+b;
    }
}
void tablar(){
    int m = diferencias2.size();
    tabla = vector<int> (m);
    tabla[0] = 0;
    for (int i = 1; i < m; ++i){
        tabla[i] = tabla[i - 1];
        while (tabla[i] > 0 and diferencias2[i] != diferencias2[tabla[i]]){
            tabla[i] = tabla[tabla[i] - 1];
        }
        if (diferencias2[i] == diferencias2[tabla[i]]){
            tabla[i]++;
        }
    }
}
bool primera(){
    int inicial = 0;
    int n = diferencias1.size();
    int m = diferencias2.size();
    int seen = 0;

    for (int i = inicial; i < n; ++i){
        while (seen > 0 and diferencias1[i] != diferencias2[seen]){
            seen = tabla[seen - 1];
        }
        if (diferencias1[i] == diferencias2[seen]) seen++;
        if (seen == m){
            return true;
        }
    }
    return false;
}

int main(){
    cin>>n;
    vector<int> reloj1(n);
    vector<int> reloj2(n);
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        reloj1[i] = (temp);
    }
    for(int i=0;i<n;i++){
        int temp;cin>>temp;
        reloj2[i] = (temp);
    }
    sort(reloj1.begin(),reloj1.end());
    sort(reloj2.begin(),reloj2.end());
    diferencias1.clear();
    diferencias2.clear();

    for(int i=0;i<n;i++){
        diferencias1.push_back(dist(reloj1[i],reloj1[(i+1)%n]));
        diferencias2.push_back(dist(reloj2[i],reloj2[(i+1)%n]));
    }
    for(int i=0;i<n;i++){
        diferencias1.push_back(diferencias1[i]);
    }

    tabla.clear();
    tablar();
    if(primera()){
        cout<<"possible"<<endl;
    }
    else{
        cout<<"impossible"<<endl;
    }

}

