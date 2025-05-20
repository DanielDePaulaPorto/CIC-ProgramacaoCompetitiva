#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

// Estrutura para armazenar as opções possíveis de movimento
typedef struct {
    char direcao;
    int linha;
    int coluna;
}movimento;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

string bfs(vector<vector<bool>>& mapa, pii ini, pii fim, int n , int m);

int main(){
    FASTIO

    int n,m;
    pii inicio;
    pii fim;

    cin >> n >> m;

    vector<vector<bool>> mapa(n+2, vector<bool>(m+2)); //Matriz de bits para representar o mapa
    string linha;

    // pulo a primeira linha para deixar de padding antes do mapa
    for (int l =1; l <= n; l++) {
        // pulo a primeira coluna para deixar de padding antes do mapa
        cin >> linha;
        for (int c = 0; c < m; c++) {
            mapa[l][c+1]=(linha[c] == '.' || linha[c] == 'A' || linha[c] == 'B');
            if (linha[c] == 'A') {
                inicio = {l,c+1};
            } else if (linha[c] == 'B') {
                fim = {l,c+1};
            }
        }
        // pulo a última coluna para deixar de padding depois do mapa
    }
    // pulo a última linha para deixar de padding depois do mapa

    string caminho = bfs(mapa,inicio,fim,n,m);

    if (caminho.size() == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl << caminho.size() << endl;
        for (int i = caminho.size()-1; i>=0;i--) {
            char c = caminho[i];
            cout << c;
        }
        cout << endl;
    }

    return 0;
}

string bfs(vector<vector<bool>>& mapa, pii ini, pii fim, int n , int m){
    vector<char> caminho;
    caminho.reserve(n * m);
    vector<vector<movimento>> pai(n+2, vector<movimento>(m+2)); // Matriz de pais para o BFS
    vector<movimento> direcoes = {{'D',1,0},
        {'U',-1,0},
        {'R',0,1},{'L',0,-1}};
    queue<pii> q;
    q.push(ini);
    mapa[ini.first][ini.second] = false; //Marca o ponto inicial como visitado (como bloqueado para não ser possível voltar por esse caminho)
    while(!q.empty()){
        pii no_atual = q.front();
        q.pop();
        for(movimento mov: direcoes){ // verifica se pode se movimentar nas 4 direções possíveis
            pii possivel_no = {no_atual.first + mov.linha, no_atual.second + mov.coluna};

            if ( possivel_no == fim) {
                // faz o caminho inverso para definir o caminho até chegar no fim
                pii anterior = no_atual;
                caminho.push_back(mov.direcao);
                while(anterior != ini) {
                    // movimento mov_realizado = pai.at(anterior);
                    movimento mov_realizado = pai[anterior.first][anterior.second];
                    anterior = {anterior.first - mov_realizado.linha,anterior.second - mov_realizado.coluna};
                    caminho.push_back(mov_realizado.direcao);
                }
                return string(caminho.begin(), caminho.end());
            } else if (mapa[possivel_no.first][possivel_no.second]) {
                q.push(possivel_no);
                pai[possivel_no.first][possivel_no.second] = mov;  // Registra de onde veio para chegar neste nó
                mapa[possivel_no.first][possivel_no.second] = false; // marca como visitado para não processar novamente
            }
        }
    }
    return "";
}