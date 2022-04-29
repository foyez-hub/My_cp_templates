#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair


void somuchfun(){



#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Input.txt","r",stdin);
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Output.txt","w",stdout);
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Error.txt","w",stderr);
#endif



}

const ll INF=1e18;
                  //u->v    weight
vector< pair< pair<int,int>,int>  >  adj(100000);


bool bellmanFord(int source,int node){


    vector<ll> dis(node+1,INF);
    
    dis[source]=0;
    for (int i = 1; i <=node-1; ++i) {

       for(auto V:adj){
           int u=V.first.first;
           int v=V.first.second;
           int weight=V.second;

           if(dis[u]+weight<dis[v]){
               dis[v]=dis[u]+weight;

           }

       }
        
    }


    for(auto V:adj){
        int u=V.first.first;
        int v=V.first.second;
        int weight=V.second;

        if(dis[u]+weight<dis[v]){
            return false;


        }

    }

    return true;



}


int main()
{
  somuchfun();

  int t;
  cin>>t;
    while (t--) {


        int n, m;
        cin >> n >> m;
        adj.clear();

        for (int i = 0; i < m; ++i) {

            int u, v, wt;
            cin >> u >> v >> wt;
//            u--;
//            v--;
            adj.pb({{u, v}, wt});


        }

        if (bellmanFord(0, n)) {
            cout << "not possible" << endl;
        } else {
            cout << "possible" << endl;
        }
    }
}
