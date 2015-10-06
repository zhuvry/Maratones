#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
long long int T;
 vector<int> ans;
void mostrar(){
    reverse(ans.begin(),ans.end());
    for(int j=0;j<ans.size();j++){
        printf("%i",ans[j]);
    }
    printf("\n");
}
int main(){
    scanf("%lli",&T);
    for(int i=0;i<T;i++){
        long long int num;scanf("%lli",&num);
        int div = 9;
        ans.clear();
        while(true){
            if(div==1 and num==1){
                if(ans.size()==0){
                    ans.push_back(1);
                }
                mostrar();
                break;

            }
            if(div==1 and num!=1){
                printf("-1\n");
                break;
            }
            if(num%div==0){
                num=num/div;
                ans.push_back(div);
                continue;
            }
            else{
                div--;
                continue;
            }
        }
    }
}
