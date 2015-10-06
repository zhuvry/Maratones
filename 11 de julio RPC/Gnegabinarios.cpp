#include <bits/stdc++.h>
using namespace std;
string num;
int main(){
    while(cin>>num){
        if(num=="11"){
            cout<<"0"<<endl;
            continue;
        }
        bool uno = true;
        int i=num.size();
        for(;i>=0;i--){
            if(num[i]=='1' and uno){
                num[i]='0';
                uno = !uno;
            }
            else if(num[i]=='1' and !uno){
                num[i]='0';
                uno = !uno;
                break;
            }
            else if(num[i]=='0' and !uno){
                num[i]='1';
                uno = !uno;
            }
            else if(num[i]=='0' and uno){
                num[i]='1';
                uno = !uno;
                break;
            }
        }
        if(i<0){
            num = "11"+num;
        }
        i = 0;
        for(;i<num.size();i++){
            if(num[i]!='0')break;
        }
        for(;i<num.size();i++){
            cout<<num[i];
        }
        cout<<endl;
    }
}
