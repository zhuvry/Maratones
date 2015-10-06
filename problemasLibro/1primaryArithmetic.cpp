#include <bits/stdc++.h>
using namespace std;
long long int a,b;

int main()
{
    while (cin>>a>>b){
        if(a==0 and b==0){
            break;
        }
        int r = 0;
        int llevo= 0;
        while(a>0 or b>0){
            int suma = (a%10)+(b%10);
            suma += llevo;
            a/=10;
            b/=10;
            if(suma>=10){
                r++;
                llevo = 1;
            }
            else{
                llevo=0;
            }
        }
        if(r==0){
            printf("No carry operation.\n");
        }
        else if(r==1){
            printf("%i carry operation.\n",r);

        }
        else{
            printf("%i carry operations.\n",r);
        }
    }

}
