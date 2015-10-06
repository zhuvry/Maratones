#include <bits/stdc++.h>
using namespace std;
long long int s;
int main()
{
    while (scanf("%lli",&s) and s){
        long double n = sqrt(1+(8*s));
        n = ceil((n-1)/2);
        long long int paginas = n;
        long long int pagina = ((paginas)*(paginas+1))/2;
        pagina-=s;
        if(pagina==0){
            paginas++;
            pagina = paginas;
        }
        printf("%lli %lli\n",pagina,paginas);
    }
}
