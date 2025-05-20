#include <bits/stdc++.h>
 
using namespace std;
vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void solve(){

    int n, m; cin >> n >> m;
    
    vector<vector<pair<int, int>>> fathers(n+2, vector<pair<int, int>>(m+2));
    vector<vector<bool>> vis(n+2, vector<bool>(m+2, false));
    vector<vector<char>> mat(n+2, vector<char> (m+2, '#'));
    string ans = "";

    pair<int, int> startPoint = {0, 0}, endPoint = {0, 0};

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++){
            cin >> mat[i][j];

            if(mat[i][j] == 'A') startPoint = {i, j};
            if(mat[i][j] == 'B') endPoint = {i, j};
        }

    queue<pair<int, int>> bfs;

    bfs.push({startPoint.first, startPoint.second});
    vis[startPoint.first][startPoint.second] = true;

    while(!bfs.empty()){

        int x, y;
        tie(x, y) = bfs.front(); bfs.pop();

        for(auto[xi, yi] : dirs){

            if(x+xi > n || x+xi <= 0 || y+yi > m || y+yi <= 0 || vis[x+xi][y+yi] || mat[x+xi][y+yi] == '#') continue;

            vis[x+xi][y+yi] = true;

            fathers[x+xi][y+yi] = {x, y};

            bfs.push({x+xi, y+yi});
        }
    }

    if(!vis[endPoint.first][endPoint.second]){

        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    while(endPoint.first && endPoint.second){

        pair<int, int> newA = fathers[endPoint.first][endPoint.second];

        if(!newA.first){

            endPoint = newA;
            continue;
        }

        if(newA.first < endPoint.first){

            ans.push_back('D');
            endPoint = newA;
            continue;
        }

        if(newA.first > endPoint.first){

            ans.push_back('U');
            endPoint = newA;
            continue;
        }

        if(newA.second < endPoint.second){

            ans.push_back('R');
            endPoint = newA;
            continue;
        }

        if(newA.second > endPoint.second){

            ans.push_back('L');
            endPoint = newA;
            continue;
        }
    }
    
    cout << ans.size() << '\n';
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

int32_t main() { 
  
    int t = 1;
    // cin >> t;
    // Uso isso aqui pra questões q tem vários casos de teste
    while(t--)
        solve();
 
return 0;
}