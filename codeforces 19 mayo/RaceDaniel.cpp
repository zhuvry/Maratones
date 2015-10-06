#include <bits/stdc++.h>

using namespace std;
const int MAX_PLAYERS = 6;
const int MAX_SIM = 300;

string simulation;
int players[MAX_PLAYERS][MAX_SIM+1];
int results[MAX_PLAYERS];
int n, x, d;
vector<int> sorted_results;

double median()
{
    cout<<"n es "<<n<<endl;
    if(n % 2 == 0)
        return ((double)sorted_results[(n/2)-1]+(double)sorted_results[n/2])/ 2;
    else
        return (double)sorted_results[n/2];
}

double mean()
{
    int total = 0;
    for(int i = 0; i < n; ++i){
        total += sorted_results[i];
    }
    return (double)total / n;
}

double std_dev(double mean)
{
    double variance = 0;
    for(int i = 0; i < n; ++i){
        variance += pow(sorted_results[i] - mean,2);
    }
    variance /= (n-1);
    return sqrt(variance);
}


bool solve(int x)
{
    sorted_results.clear();
     for(int player = 0; player < n; ++player){
        int starting = x * player + 1;
        int lossed = players[player][starting-1];
        int ending = starting;
        while(true){
            if(ending >= simulation.size()){
                cout<<"INVALID SIMULATION\n";
                return false;
            }
            if(players[player][ending] - lossed >= d){
                break;
            }
            ++ending;
        }
        //cout<<"Player " <<player+1<<" ="<< ending - starting +1 <<'\n';
        results[player] = ending - starting + 1;
        sorted_results.push_back(results[player]);
    }
    sort(sorted_results.begin(),sorted_results.end());
    double u = mean();
    cout<<"media es "<<(double)u<<endl;
    cout<<"mediana es "<<(double)median()<<endl;
    cout<<"desviacion es "<<std_dev(u)<<endl;
    double asim = 3.0 * ((double)u - (double)median() ) / std_dev(u);
    cout<<"asim es "<<endl;
    //cout << asim <<'\n';
    if(abs(asim) > 0.20){
        cout<<"INVALID SIMULATION\n";
        return false;
    }
    //for(int i =0; i < n; ++i)
    //    cout<<sorted_results[i]<<' ';

    cout<<"ORDER OF RACING: ";
    for(int i = 0; i < n; ++i){
        for(int player = 0; player < n; ++player){
            if(results[player] == sorted_results[i]){
                cout << player+1 << " ";
                results[player] = -1;
                break;
            }
        }
    }
    cout<<"\n";
    return true;
}

int main()
{
    //ios_base::sync_with_stdio(false);

    int t;
    cin >>t;
    for(int test = 0; test < t; ++test){
        cin >> n >> d >> simulation;
        memset(players, 0, sizeof(players[0][0]) * MAX_PLAYERS * MAX_SIM);
        for(int i = 1; i < simulation.size()+1; ++i){
            int selected = simulation[i-1]-'1';
            for(int player = 0; player < n; ++player){
                if(player == selected){
                    players[player][i] = players[player][i-1] + 1;
                }
                else
                    players[player][i] = players[player][i-1];
            }
        }

        int q;
        cin >> q;
        for(int i = 0; i < q; ++i){
            cin>>x;
            solve(x);
        }
    }


    return 0;
}
