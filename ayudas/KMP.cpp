#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli N;
vector<int> tabla(string needle){
    int m = needle.size();
    vector<int> border(m);
    border[0] = 0;
    for (int i = 1; i < m; ++i){
        border[i] = border[i - 1];
        while (border[i] > 0 and needle[i] != needle[border[i]]){
            border[i] = border[border[i] - 1];
        }
        if (needle[i] == needle[border[i]]){
            border[i]++;
        }
    }
    return border;
}
int primera(string base,vector<int> tabla,string needle,int inicial){
    int n = base.size();
    int m = needle.size();
    int seen = 0;

    for (int i = inicial; i < n; ++i){
        while (seen > 0 and base[i] != needle[seen]){
            seen = tabla[seen - 1];
        }
        if (base[i] == needle[seen]) seen++;
        if (seen == m){
            return i;
        }
    }
    return -2;
}
int main(){
    while(scanf("%lli",&N)!=EOF){
        string base;
        cin>>base;
        for(int i=0;i<N;i++){
            string problem;cin>>problem;
            vector<string> subpalabras;
            string temp="";
            for(int j=0;j<problem.size();j++){
                if(problem[j]=='*'){
                    if(temp.size()>0){
                        subpalabras.push_back(temp);
                        temp = "";
                    }
                    else{
                        continue;
                    }
                }
                else{
                    temp+=problem[j];
                }
            }
            if(temp.size()>0){
                subpalabras.push_back(temp);
                temp = "";
            }
            int actual = -1;
            for(int j=0;j<subpalabras.size();j++){
                vector<int> tab = tabla(subpalabras[j]);
                actual = primera(base,tab,subpalabras[j],actual+1);
                if(actual==-2)break;
            }
            if(actual==-2){
                cout<<"no"<<endl;
            }
            else{
                cout<<"yes"<<endl;
            }
        }
    }
}
