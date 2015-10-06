#include <bits/stdc++.h>
using namespace std;

int main(){
   /* vector<int> vect;
    vect.push_back(23);
    vect.push_back(11);
    vect.push_back(13);
    sort(vect.begin(),vect.end());
    for(int i=0;i<vect.size();i++){
        cout<<vect[i]<<endl;
    }*/
    int numcasos;
    vector<int>salario;
    cin>>numcasos;
    for(int i=0;i<numcasos;i++){
        salario.clear();
        for (int j=0;j<3; j++){
            int a;cin>>a;salario.push_back(a);
        }
        sort(salario.begin(),salario.end());
        cout<<"Case "<<i+1<<": "<<salario[1]<<"\n";
    }


}
