#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define endl '\n'
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

#define MAX_QUARTOS 100000

using namespace std;

typedef struct {
    int entrada;
    int saida;
    int quarto;
    int ordem_input;
}Hospede;

struct compara_hospede_PQ {
    bool operator()(const Hospede& a, const Hospede& b) const {
        if (a.saida != b.saida)
            return a.saida > b.saida;
        return a.entrada > b.entrada;
    }
};

int main(){
    FASTIO

    int n; // número de hóspedes
    priority_queue<Hospede, vector<Hospede>, compara_hospede_PQ> pq_alocacao_hospedes;
    vector<Hospede> v_lista_hospedes;

    priority_queue<int, vector<int>,greater<int>> pq_quartos_disponiveis;
    int maior_alocacao_simultanea = 0;
    int ultimo_hospede_que_saiu = 0;

    // Não preciso inicializar a pilha com todos os quartos disponíveis.
    // Vamos deixar para ir criando os quartos à medida que for necessários.
    // Sempre que um quarto deixar de ser utilizado, colocamos ele na pilha
    // de disponíveis para poder ser usado para o próximo que precisar

    cin >> n;
    int e,s;

    // Lê entradas
    for (int i = 0; i < n; i++) {
        cin >> e >> s;
        Hospede h = {e,s,-1,i};
        v_lista_hospedes.push_back(h);
    }

    // Ordena pela entrada, depois pela saída. Vamos processar os hóspedes pela ordem em que forem entranto
    sort(v_lista_hospedes.begin(), v_lista_hospedes.end(),
     [](const Hospede &a, const Hospede &b) {
         if (a.entrada != b.entrada)
             return a.entrada < b.entrada;
         return a.saida < b.saida;
     });

    // Vai alocando hóspede por hóspede usando uma fila de prioridade
    for (int i = 0; i < n; i++) {
        // Sempre que tiver alguém na fila que vai sair antes do próximo entrar, eu posso tirar ele da fila
        while (!pq_alocacao_hospedes.empty() && pq_alocacao_hospedes.top().saida < v_lista_hospedes[i].entrada) {
            Hospede h = pq_alocacao_hospedes.top(); //Primeiro cara a sair
            pq_alocacao_hospedes.pop();

            // Devolve também o quarto ocupado por ele para o pool de quartos ocupados
            int quarto = h.quarto;
            pq_quartos_disponiveis.push(quarto);
            ultimo_hospede_que_saiu++;
        }
        // Recupera o primeiro quarto disponível no pool/pilha de quartos disponíveis
        int quarto;
        if (!pq_quartos_disponiveis.empty()) {
            quarto = pq_quartos_disponiveis.top();
            pq_quartos_disponiveis.pop();
        } else {
            // Quer dizer que esse quarto não havia sido criado antes. Não preciso inserir para retirar em seguida
            quarto = ++maior_alocacao_simultanea;
        }

        // Atribui o quarto que foi ocupado para o Hóspede
        v_lista_hospedes[i].quarto = quarto;
        // v_quartos_ocupados.push_back(quarto);

        // Insere o hóspede na fila de prioridades
        pq_alocacao_hospedes.push(v_lista_hospedes[i]);

        // verifica se a ocupação simultânea é a maior registrada
        if (maior_alocacao_simultanea < pq_alocacao_hospedes.size()) {
            maior_alocacao_simultanea = pq_alocacao_hospedes.size();
        }
    }

    // Ordena pela ordem de input
    sort(v_lista_hospedes.begin(), v_lista_hospedes.end(),
     [](const Hospede &a, const Hospede &b) {
         return a.ordem_input < b.ordem_input;
     });

    cout << maior_alocacao_simultanea << endl;
    for (int i = 0; i < v_lista_hospedes.size(); i++) {
        cout << v_lista_hospedes[i].quarto << " ";
    }

    return 0;
}