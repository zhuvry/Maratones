#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    while(cin>>n){
        vector<int> ans(0);
        for(int i=0;i<n;i++){
            bool valido = true;
            for(int j=0;j<n;j++){
                int temp;cin>>temp;
                if(temp==1 or temp==3){
                    valido = false;
                }
            }
            if(valido){
                ans.push_back(i+1);
            }
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i<ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }


}
