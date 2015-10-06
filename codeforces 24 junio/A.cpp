#include <bits/stdc++.h>
using namespace std;
string s;
int main()
{
    while(cin>>s){
        cout<<(s.size()+1)*26-s.size()<<endl;
    }
}
