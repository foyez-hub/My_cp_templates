#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
#define pb push_back
#define mp make_pair
const ll INF = 1e18;


void somuchfun() {


#ifndef ONLINE_JUDGE
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Input.txt", "r", stdin);
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Output.txt", "w", stdout);
    freopen("C:\\Users\\user\\CLionProjects\\foyez_cp_playground\\Error.txt", "w", stderr);
#endif


}

map<string, vector<pair<string, int> > > adj;
map<string, bool> visited;
vector<pair<int, int> > lenOfPath;
stack<int> stk;
int pathcnt = 0;
int weightcnt = 0;

int cnt = 0;

void dfs(string source, string destination) {


    visited[source] = true;

    if (source == destination) {


        lenOfPath.pb({(pathcnt - 1), weightcnt});
        pathcnt--;
        if (stk.size() >= 1) {
            weightcnt -= stk.top();
            stk.pop();
        }
        cnt++;
        visited[destination] = false;
        return;
    }
//    cout << source << endl;


    for (auto child: adj[source]) {
        if (!visited[child.first]) {
            weightcnt += child.second;
            stk.push(child.second);
            pathcnt++;
            dfs(child.first, destination);
        }
    }


    pathcnt--;
    if (stk.size() >= 1) {
        weightcnt -= (stk.top());
        stk.pop();
    }

    visited[source] = false;

}


int main() {
    somuchfun();

    int t;
    cin >> t;
    int tcase = 1;
    while (t--) {
        while (!stk.empty()) stk.pop();
        visited.clear();
        adj.clear();
//        for(auto i:adj){
//
//            i.second.clear();
//        }
        lenOfPath.clear();
     //   cout<<stk.size()<<" "<<lenOfPath.size()<<" "<<adj.size()<<" "<<visited.size()<<endl;

        cout << "Scenario #" << tcase << endl;
        tcase++;


        int n;
        cin >> n;
        for (int i = 0; i < n; ++i) {
            string node;
            cin >> node;
            visited[node] = false;

        }

        int m;
        cin >> m;


        for (int i = 0; i < m; ++i) {

            string u, v;
            int wt;
            cin >> u >> v >> wt;
            adj[u].pb({v, wt});


        }

         pathcnt = 0;
         weightcnt = 0;

         cnt = 0;
        dfs("Calgary", "Fredericton");
        //cout << cnt << endl;
         //for(auto i:lenOfPath) cout<<i.first <<"<-len "<<i.second<<"<-weight"<<endl;
        int qq;
        cin >> qq;


        while (qq--) {

            //tcase++;
            int tt;
            cin >> tt;
            int mini = 1000000;
            int flag = 0;
            for (int i = 0; i < lenOfPath.size(); ++i) {
//            cout<<tt<<"<-tt   lenofpath->"<<lenOfPath[i].first<<"  weight->"<<lenOfPath[i].second<<endl;
                if (lenOfPath[i].first <= tt) {
                    flag = 1;

                    // cout<<tt<<"<-tt   lenofpath->"<<lenOfPath[i].first<<"  weight->"<<lenOfPath[i].second<<endl;
                    mini = min(mini, lenOfPath[i].second);
                }


            }

            if (flag == 1) cout << "Total cost of flight(s) is $" << mini << endl;
            else cout << "No satisfactory flights" << endl;

        }
    }
}