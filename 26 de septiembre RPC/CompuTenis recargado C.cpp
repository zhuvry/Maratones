#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N,S,J,D;
int main(){
    while(cin>>N>>S>>J>>D){
        string sets;cin>>sets;
        int A,B,AA,BB;
        A=0;B=0;AA=0;BB=0;
        for(int i=0;i<sets.size();i++){
            if(sets[i]=='A')A++;
            if(sets[i]=='B')B++;
            if(B-A >= D and B>=J){
                BB++;
                A=0;
                B=0;
            }
            else if(A-B>=D and A>=J){
                AA++;
                A=0;
                B=0;
            }
        }
        cout<<AA<<" "<<BB<<endl;
    }
}
