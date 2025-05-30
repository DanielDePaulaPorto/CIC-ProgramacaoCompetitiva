#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;



int main(){
    FASTIO

    const int N=1e5+1;
    int volume[N], temperatura[N];
    int qtd_montes[N];
    int prefixo_temperaturas[N];    // prefixo_temperaturas[i] é a soma acumulada das temperaturas até o dia i
    int resposta[N];

    int n;
    cin>>n;

    for(int i = 0; i < n; i++){
        cin>>volume[i];
    }

    for(int i = 0; i < n; i++){
        cin>>temperatura[i];
        prefixo_temperaturas[i] += temperatura[i];      // inicializa com as temperaturas do dia i
    }

    for(int i = 1; i < n; i++){
        prefixo_temperaturas[i] += prefixo_temperaturas[i - 1]; // Atualiza com a soma acumulada das temperaturas
    }

    for(int i = 0; i < n; i++){
        qtd_montes[i] += 1;
        // acha o primeiro dia em que o derretimento total ultrapassa volume[i] (considerando o que já foi derretido até ontem)
        auto it = upper_bound(prefixo_temperaturas, prefixo_temperaturas + n, volume[i] + (i ? prefixo_temperaturas[i - 1] : 0));
        if(it == prefixo_temperaturas + n){
            continue;   // O monte não morreu antes do último dia
        }
        // it - prefixo_temperaturas = Dia em que o monte derrete completamente
        resposta[it - prefixo_temperaturas] += volume[i] - *prev(it) + (i ? prefixo_temperaturas[i - 1] : 0); // quanto falta para completar o derretimento total
        qtd_montes[it - prefixo_temperaturas] -= 1;
    }

    for(int i = 0; i < n; i++){
        if(i) {
            qtd_montes[i] += qtd_montes[i - 1];     // Atualiza a quantidade de montes em cada dia
        }
        // Derretimento do dia = (resto de monte)+(número de montes vivos)x(temperatura do dia)
        cout << resposta[i] + temperatura[i] * qtd_montes[i] << ' ';
    }

    return 0;
}
