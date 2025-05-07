#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
using namespace std;

void troca_valor(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int var = 10;
  // int *intptr = &var;
  // int **ptrptr = &intptr;
  //
  // printf("var: %d \nEndereço de var: %p \n\n", var, &var);
  // printf("intptr: %p \nEndereço de intptr: %p \n\n", intptr, &intptr);
  // printf("var: %d \nValor apontado por intptr: %d \n\n", var, *intptr);
  // printf("ptrptr: %p \nEndereço de ptrptr: %p \n\n", ptrptr, &ptrptr);
  // printf("intptr: %p \nValor apontado por ptrptr: %p \n\n", intptr, *ptrptr);
  // printf("var: %d \n*intptr: %d \n**ptrptr: %d", var, *intptr, **ptrptr);

  int var2 = 20;
  cout << "Var1: " << var << "\nVar2: " << var2 << endl;
  troca_valor(&var, &var2);
  cout << "-------- Troca! ---------\n";
  cout << "Var1: " << var << "\nVar2: " << var2 << endl;



  return 0;
}

