#include <bits/stdc++.h>
using namespace std;
long long int n,ti;
int main()
{
    while(cin>>n){
        vector<long long int> cola(n);
        for(int i=0;i<n;i++){
            cin>>ti;
            cola[i] = ti;
        }
        sort(cola.begin(),cola.end());

        long long int sumatoria = 0;
        int i = 0;
        int descartados = 0;
        while(i<cola.size()){
            if(cola[i]>=sumatoria){
                sumatoria+= cola[i];
                i++;
            }
            else{
                i++;
                descartados++;
            }
        }
        cout<<n-descartados<<endl;
    }
}
