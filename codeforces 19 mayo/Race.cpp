#include <bits/stdc++.h>
using namespace std;
int n;
const int MAXPERSONAS = 9;
vector< pair<int,int> > llegadores; //pair tiempo jugador//
vector<int> datos;
int distancia[10];
double mediana(vector<int> datos){
    if(datos.size()%2!=0){
        return datos[(datos.size()/2)];
    }
    else{
        double valor = datos[(datos.size()/2)-1]+ datos[(datos.size()/2)];
        return  valor/2;
    }
}
double media(vector<int> datos){
    double suma = 0;
    for(int i=0;i<datos.size();i++){
        suma+=datos[i];
    }
    return suma/datos.size();
}
double desviacion(vector<int> datos,double media){
    double suma = 0;
    for(int i=0;i<datos.size();i++){
        suma+= ((datos[i]-media)*(datos[i]-media));
    }
    double desv = suma/ (datos.size());
    return sqrt(desv);
}
void solucionar(vector<int> personas,int X,int D,int N){
    memset(distancia,0,sizeof(distancia));
    datos.clear();
    llegadores.clear();
    for(int i=0;i<personas.size();i++){
        if(personas[i]<= (i/X)+1){
            distancia[personas[i]]++;
            if(distancia[personas[i]]==D){
                int tiempo = i+1-((personas[i]-1)*X);
                datos.push_back(tiempo);
                llegadores.push_back(make_pair(tiempo,personas[i]));
            }
        }
    }
    sort(llegadores.begin(),llegadores.end());
    sort(datos.begin(),datos.end());
    if(datos.size()!=N){
        cout<<"INVALID SIMULATION"<<endl;
        return;
    }

    double distribucion = 3*((media(datos)-mediana(datos))/desviacion(datos,media(datos)));
    if(abs(distribucion)>0.2){
        cout<<"INVALID SIMULATION"<<endl;
        return;
    }
    cout<<"ORDER OF RACING:";
    for(int i=0;i<llegadores.size();i++){
        cout<<" "<<llegadores[i].second;
    }
    cout<<endl;
}
int main()
{
    int T;
    while(cin>>T){
        for(int a=0;a<T;a++){
            int N,D;
            cin>>N>>D;
            string players;cin>>players;
            vector<int>personas;
            for(int i=0;i<players.size();i++){
                personas.push_back(players[i]-48);
            }
            int Q;cin>>Q;
            for(int i=0;i<Q;i++){
                int X;cin>>X;
                solucionar(personas,X,D,N);
            }
        }
    }
}
