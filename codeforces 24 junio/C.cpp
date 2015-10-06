#include <bits/stdc++.h>
using namespace std;
int k;
vector<int> bolas;
long long int factoriales[1000];
vector<int> combi;
long long int permutacion(){

    long long int arriba = 0;
    long long int abajo=1;
    for(int i=0;i<combi.size();i++){
        abajo*= factoriales[combi[i]];
        arriba+= combi[i];
    }
    if(arriba==0){
        return 0;
    }

    long long int ans = factoriales[arriba]/abajo;
    for(int i=0;i<combi.size();i++){
        if(i>0){
            combi[i-1]++;
        }
        combi[i]--;
        if(combi[i]==-1){
            continue;
        }
        ans+= permutacion();
    }
    combi[combi.size()-1]++;
    return ans;
}
int main()
{
    factoriales[0] = 1;
    for(int i=1;i<1000;i++){
        factoriales[i]=factoriales[i-1]*i;
    }
    combi.push_back(0);
    combi.push_back(1);
    combi.push_back(1);
    cout<<permutacion()<<endl;
    while(cin>>k){
        for(int i=0;i<k;i++){
            int temp;cin>>temp;
            combi.push_back(temp-1);
        }
    }

}
