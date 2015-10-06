#include <bits/stdc++.h>
using namespace std;
string a,b;
int main()
{
    while(cin>>a>>b){
        vector<int> ans;
        int veces = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]==b[i]){
                ans.push_back(a[i]);
            }
            else{
                if(veces%2 == 0){
                    ans.push_back(a[i]);
                }
                else{
                    ans.push_back(b[i]);
                }
                veces++;
            }

        }
        if(veces%2 == 0){
            for(int i=0;i<ans.size();i++){
                cout<<ans[i]-48;
            }
        }
        else{
            cout<<"impossible";
        }
        cout<<endl;
    }
}
