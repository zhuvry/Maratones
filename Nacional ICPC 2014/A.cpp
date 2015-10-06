#include <bits./stdc++.h>

using namespace std;
vector<pair<int,int> > numeros; //numero, usado o no?
int m,n,value;
int tablero[5][5];
int evaluar(int i,int j,int diri,int dirj){
    int sum = 0;
    while(i>=0 and j>=0){
        sum+= tablero[j][i];
        i+=diri;
        j+=dirj;
    }
    if(sum>value)return 1;
    if(sum<value)return-1;
    return 0;
}
bool ans(int i,int j){
    for(int a=0;a<numeros.size();a++){
        if(numeros[a].second==0){
            tablero[j][i] = numeros[a].first;
            numeros[a].second = 1;
            int evaluacionhorizontal = evaluar(i,j,-1,0);
            int evaluacionvertical = evaluar(i,j,0,-1);
            int evaluaciondiagonalderecha=0;
            int evaluaciondiagonalizquierda=0;
            if(i==0 and j==n-1){
                evaluaciondiagonalderecha = evaluar(i,j,1,-1);
            }
            if(i==n-1 and j==n-1){
                evaluaciondiagonalizquierda = evaluar(i,j,-1,-1);
            }
            if(i==n-1 and evaluacionhorizontal!=0){
                tablero[j][i] = 0;
                numeros[a].second = 0;
                continue;
            }
            if(j==n-1 and evaluacionvertical!=0){
                tablero[j][i] = 0;
                numeros[a].second = 0;
                continue;
            }
            if(i==0 and j==n-1 and evaluaciondiagonalderecha!=0){
                tablero[j][i] = 0;
                numeros[a].second = 0;
                continue;
            }
            if(i==n-1 and j==n-1){
                if(evaluaciondiagonalizquierda==0)return true;
                tablero[j][i] = 0;
                numeros[a].second = 0;
                return false;
            }
            if(ans((i+1)%n,j+((i+1)/n)))return true;
            numeros[a].second = 0;
            tablero[j][i] = 0;
        }
    }
    return false;
}
int main(){
    string line;
    while(getline(cin,line)){
        numeros.clear();
        m = 0;
        stringstream ss(line);
        int num;int sum=0;
        while(ss>>num){
            m++;
            numeros.push_back(make_pair(num,0));
            sum+=num;
        }
        if(m==0)break;
        n = sqrt(m);
        value = sum/n;
        if((m!=1 and m!=4 and m!=9 and m!=16)or sum%n!=0){
            cout<<"N"<<endl;
            continue;
        }
        if(ans(0,0)){
            cout<<"Y"<<endl;
        }
        else{
            cout<<"N"<<endl;
        }

    }
}
