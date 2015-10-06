#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(cin>>n){
        long long int derechaPas = - pow(2,60);
        long long int xPas = -pow(2,60);
        long long int ans = 0;
        for(int i=0;i<n;i++){
            long long int x,h;
            cin>>x>>h;
            if(x-h > derechaPas){
                ans++;
                derechaPas = x;
                xPas = x;
            }
            else if(derechaPas >= x){
                if(x-h>xPas){
                    derechaPas = x;
                    xPas= x;
                }
                else{
                    derechaPas = x+h;
                    xPas = x;
                }

            }
            else{
                ans++;
                derechaPas = x+h;
                xPas=x;

            }
        }
        cout<<ans<<endl;
    }


}
