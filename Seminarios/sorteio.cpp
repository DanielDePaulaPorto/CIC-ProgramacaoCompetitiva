#include <bits/stdc++.h>
#include <fstream>
#include <random>

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

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 100);

    vector<string> duplas;
    vector<string> temas;

    ifstream arquivo_duplas("Seminarios/duplas.txt");

    if (!arquivo_duplas) {
        cerr << "Erro ao abrir o arquivo duplas !" << endl;
        return 1;
    }
    string linha_dupla;
    while (getline(arquivo_duplas, linha_dupla)) {
        if (arquivo_duplas.fail()) {
            std::cerr << "Erro durante a leitura do arquivo duplas!" << endl;
            break;
        }
        duplas.push_back(linha_dupla);
    }
    arquivo_duplas.close();

    ifstream arquivo_temas("Seminarios/temas.txt");

    if (!arquivo_temas) {
        cerr << "Erro ao abrir o arquivo temas !" << endl;
        return 1;
    }
    string linha_tema;
    while (getline(arquivo_temas, linha_tema)) {
        if (arquivo_temas.fail()) {
            std::cerr << "Erro durante a leitura do arquivo temas!" << endl;
            break;
        }
        temas.push_back(linha_tema);
    }
    arquivo_temas.close();

    cout << "Duplas: " << duplas.size() << endl;
    cout << "Temas: " << temas.size() << endl;


    while (duplas.size()> 0) {
        int d = distrib(gen) % duplas.size();
        int t = distrib(gen) % temas.size();

        string dupla = duplas[d];
        string tema = temas[t];

        cout << tema << " - " << dupla << endl;

        duplas.erase(duplas.begin() + d);
        temas.erase(temas.begin() + t);
    }


    return 0;
}