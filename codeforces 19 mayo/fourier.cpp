#include <bits/stdc++.h>
using namespace std;
# define M_PIl 3.141592653589793238462643383279502884L
int n;
double serie(int t,int n){
    double pi = M_PIl;
    double resultado =pi*pi;
    resultado/=3;
    for(int i=1;i<n;i++){
        double termino = (pow(-1,i));
        termino *= cos(i*t);
        termino /= (pow(i,2));
        resultado+= (4*termino);
    }
    return resultado;
}
int main()
{

    cout<<serie(2,100000)<<endl;
}
