#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
long long int T;
double EPS = 0.0000001;
struct Circulo{
public:
    lli x;
    lli y;
    lli r;
};
bool seTocan(Circulo a,Circulo b){
    double dist = sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2));
    if(abs(dist-(a.r+b.r)<=EPS))return true;
    return false;
}
int main(){
    scanf("%lli",&T);
    int direccion[1010];
    for(int i=0;i<T;i++){
        memset(direccion,0,sizeof(direccion));
        vector<Circulo> circulos;
        lli n;scanf("%lli",&n);
        for(int j=0;j<n;j++){
            lli x,y,r;
            scanf("%lli%lli%lli",&x,&y,&r);
            Circulo a;a.x = x;a.y = y;a.r=r;
            circulos.push_back(a);
        }
        vector<pair<Circulo,int> > solucion;
        solucion.push_back(make_pair(circulos[0],true));
        direccion[0] = 1;
        for(int a=0;a<n;a++){
            if(a>= solucion.size())break;
            Circulo actual = solucion[a].first;
            int dir = solucion[a].second;
            for(int b=0;b<n;b++){
                Circulo evaluar = circulos[b];
                if(direccion[b]!=0)continue;
                if(actual.x==evaluar.x and actual.y==evaluar.y)continue;
                if(seTocan(actual,evaluar)){
                    direccion[b]= -dir;
                    solucion.push_back(make_pair(evaluar,-dir));
                }

            }
        }
        for(int a=0;a<n;a++){
            if(direccion[a]==0){
                printf("not moving\n");
            }
            lli arriba= circulos[0].r;
            lli abajo = circulos[a].r;
            lli gcd = __gcd(arriba,abajo);
            arriba = arriba/gcd;
            abajo = abajo/gcd;
            if(direccion[a]==1){
                if(abajo==1){
                    printf("%lli clockwise\n",arriba);
                    continue;
                }
                printf("%lli/%lli clockwise\n",arriba,abajo);
            }
            if(direccion[a]==-1){
                if(abajo==1){
                    printf("%lli counterclockwise\n",arriba);
                    continue;
                }
                printf("%lli/%lli counterclockwise\n",arriba,abajo);
            }
        }
    }

}
