#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
struct Punto{
    lli x;
    lli y;
};
struct Segmento{
    lli x0;
    lli y0;
    lli x1;
    lli y1;
};
vector<lli> numeros;

bool intersecta(Segmento seg,Punto pun,lli numero,lli direccion ){
    if(direccion==0){
        if(pun.x<= max(seg.x0,seg.x1) and pun.x>= min(seg.x0,seg.x1)){
            if(pun.y<= seg.y0 and pun.y+numero>= seg.y0){
                return true;
            }
        }
    }
    if(direccion==1){
        if(pun.y<= max(seg.y0,seg.y1) and pun.y>= min(seg.y0,seg.y1)){
            if(pun.x<= seg.x0 and pun.x+numero>=seg.y0){
                return true;
            }
        }
    }
    if(direccion==2){
        if(pun.x<= max(seg.x0,seg.x1) and pun.x>= min(seg.x0,seg.x1)){
            if(pun.y>= seg.y0 and pun.y-numero<=seg.y0){
                return true;
            }
        }
    }
    if(direccion==3){
        if(pun.y<=max(seg.y0,seg.y1) and pun.y>=min(seg.y0,seg.y1)){
            if(pun.x>=seg.x0 and pun.x-numero<=seg.x0){
                return true;
            }
        }
    }
    return false;
}
lli dx[4]={0,1,0,-1};
lli dy[4]={1,0,-1,0};

void solve(){
    lli j=0;
    lli direccion = 0;
    vector<Segmento> vect(N);
    Punto punt;punt.x = 0;punt.y = 0;
    for(j=0;j<N;j++){
        lli num = numeros[j];
        Segmento seg;
        lli k = j-2;
        for(lli r=0;r<10 and k>=0;r++,k--){
            if(intersecta(vect[k],punt,numeros[j],direccion)){
                printf("%lli\n",j);
                return;
            }
        }
        seg.x0 = punt.x;
        seg.y0 = punt.y;
        seg.x1 = punt.x + (num*dx[direccion]);
        seg.y1 = punt.y + (num*dy[direccion]);
        punt.x = seg.x1;
        punt.y = seg.y1;
        vect[j] = seg;
        direccion++;
        direccion%=4;
    }
    printf("OK\n");
    return;
}

int main(){
    while(scanf("%lli",&N)!=EOF){
        numeros.clear();
        for(int j=0;j<N;j++){
            lli num;scanf("%lli",&num);
            numeros.push_back(num);
        }
        solve();

    }

}
