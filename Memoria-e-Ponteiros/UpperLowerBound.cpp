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


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  vector<int> v = {1, 3, 3, 5, 7};

  auto it = lower_bound(v.begin(), v.end(), 3);
  cout << *it << endl; // imprime 3

  auto it = upper_bound(v.begin(), v.end(), 3);
  cout << *it << endl; // imprime 5

  return 0;
}
