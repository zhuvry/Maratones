#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli n;
map<string,lli> mapa;
string temp;

lli pow(lli base,lli exp){
    int ans = 1;
    for(int i=1;i<=exp;i++){
        ans*=base;
    }
    return ans;
}
int main(){
    n = 3;
    lli p = (3 * (pow(2,n-1)-1));
    lli q = (3* (pow(2,n)-1));
    lli r = (9* (pow(2,n-1)-1));
    cout<<p<<" "<<q<<" "<<r<<endl;
    lli amigoA = pow(2,n)*p*q;
    lli amigoB = pow(2,n)*r;
    cout<<amigoA<<" "<<amigoB<<endl;
}

