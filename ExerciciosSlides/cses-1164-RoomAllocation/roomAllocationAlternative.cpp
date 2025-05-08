#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;

  vector<tuple<int, int, int>> v(t);

  for(int i = 0; i < t; i++){

    int x, y; cin >> x >> y;

    v[i] = {x, y, i};
  }

  sort(v.begin(), v.end());

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<int> resp(t);

  int maior = 0;

  for(int i = 0; i < t; i++){

    auto [x, y, idx] = v[i];

    if(pq.empty()){

      pq.push({y, 1});
      resp[idx] = 1;

      continue;
    }

    auto aux = pq.top();

    if(aux.first < x){

      resp[idx] = aux.second;
      pq.pop();
      pq.push({y, aux.second});

      maior = max(maior, resp[idx]);

    } else{
      pq.push({y, pq.size()+1});
      resp[idx] = pq.size();
      maior = max(maior, resp[idx]);
    }
  }


  cout << maior << '\n';
  for(auto n : resp) cout << n << ' ';
  return 0;
}