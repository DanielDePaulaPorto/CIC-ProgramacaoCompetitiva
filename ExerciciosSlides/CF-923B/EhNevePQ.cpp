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
    int volume[N],temperatura[N];
    int n;
    int derretido_total=0;     //soma acumulada das temperaturas
    int derretido_hoje=0;      // Volume derretido no dia i
    priority_queue<int,vector<int>,greater<int> > pq;    // pq para armazenar quando cada monte se acaba

    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>volume[i];
    }
    for(int i=1;i<=n;i++){
        cin>>temperatura[i];
    }

    for(int i=1;i<=n;i++){
        derretido_hoje=0;
        int ontem=derretido_total;
        pq.push(volume[i]+derretido_total);           // Adiciona o novo monte do dia i. Volume + quanto já derreteu até agora
        derretido_total+=temperatura[i];                // Atualiza o derretido_total para contabilizar o derretimento do dia i
        while(pq.size() && pq.top()<=derretido_total){  // Enquanto existir monte que derrete completamente hoje...
            int u=pq.top();
            pq.pop();                                   // Remove o monte
            derretido_hoje=derretido_hoje+u-ontem;      // Acrescenta ao derretido_hoje o quanto derreteu hoje
        }
        derretido_hoje+=pq.size()*temperatura[i];       // Montes restantes que não derreteram totalmente hoje, mas derreteram alguma coisa
        cout<<derretido_hoje<<" ";
    }

    return 0;
}