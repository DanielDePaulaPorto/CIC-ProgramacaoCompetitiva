/*
 * No Terminal do Linux, digite:
 * compilar:
 *     g++ main.cpp -std=c++17 -o mainbin
 * executar
 *     ./mainbin
 */

#include <iostream>
#define ll long long
using namespace std;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll x,y;
    int t;

    cin >> t;
    while(t--){
      cin >> x >> y;
      if(x-y>1)
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
    }
    return 0;
}