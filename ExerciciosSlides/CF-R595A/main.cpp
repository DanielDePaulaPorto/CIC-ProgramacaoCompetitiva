/*
 * No Terminal do Linux, digite:
 * compilar:
 *     g++ main.cpp -std=c++17 -o mainbin
 * executar
 *     ./mainbin
 */

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int q,n,a;

    cin >> q;
    while(q--){ //para cada teste
      cin >> n;
      vector<int> v;
      while(n--){ //para cada número da lista
        cin >> a;
        v.push_back(a);
      }
      sort(v.begin(),v.end());

      bool seguidos = false;
      for(int i=0;i< v.size()-1 ;i++){
        if(v[i] == v[i+1]-1){
          seguidos = true;
          break;
        }
      }
      if(seguidos){
        cout << "2" << endl;
      }else {
        cout << "1" << endl;
      }
    }
    return 0;
}