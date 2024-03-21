#include <iostream>
#include <string.h>
#include <time.h>
using namespace std;

//declaração de funções e declaração de variaveis globais
string jogoDavelha[3][3], xDox = "X", bola = "O";
int jMax = 9, jogadas = 0, coluna = 0, linha = 0, opc = 0;
bool colunas(string jogada);
bool linhas(string jogada);
bool diagonais(string jogada);
bool jogadaFeita(int coluna, int linha);

//inicio do programa
int main(){
    cout << "BEM vindo ao jogo da velha" << endl;
    cout << "DESEJA JOGAR[1 - SIM/ 2 - NAO]: " <<  endl;
    cin >> opc;
    while(1 < opc && opc >= 2){
        cout << "entre com numeros validos" << endl;
        cin >> opc;
        if(opc == 2){
            cout << "Encerrando programa" << endl;
            break;
        }
    }
    cout << "okay, vamos jogdar" << endl;
    //inicio do loop inifinito que so acaba quando um dos dois jogadores ganharem
    while(true){
        if(jogadas == jMax){
            cout << "ninguem ganhou" << endl;
            break;
        }
        cout << "TABULEIRO" << endl;
            cout << "[" << jogoDavelha[0][0] << "]" << "[" << jogoDavelha[0][1] << "]" << "[" << jogoDavelha[0][2] << "]" << endl;
            cout << "[" << jogoDavelha[1][0] << "]" << "[" << jogoDavelha[1][1] << "]" << "[" << jogoDavelha[1][2] << "]" << endl;
            cout << "[" << jogoDavelha[2][0] << "]" << "[" << jogoDavelha[2][1] << "]" << "[" << jogoDavelha[2][2] << "]" << endl;
            cout << " " << endl;
        //jogador numero 1
        cout << "primeiro jogador" << endl;
        cout << "Escolha a coluna com a numeracao de [0/1/2]" << endl;
        cin >> coluna;
        while(0 < coluna && coluna > 2){
            cout << "Escolha um numero que esta entre 0 a 2" << endl;
            cin >> coluna;
        }
        cout << "Escolha a linha que deseja jogar com a numeracao de [0/1/2]" << endl;
        cin >> linha;
         while(0 < linha && linha > 2){
            cout << "Escolha um numero que esta entre 0 a 2" << endl;
            cin >> linha;
        }
        jogadas++;
       
        if(jogadaFeita(coluna, linha)){
            continue;

        }
        jogoDavelha[coluna][linha] = bola;

        if(colunas(bola) || linhas(bola) || diagonais(bola)){
            cout << "Parabens o jogador numero 1 ganhou" << endl;
            break;
        }
        
    //jogador numero 2 
    cout << "segundo jogador" << endl;
        cout << "Escolha a coluna com a numeracao de [0/1/2]" << endl;
        cin >> coluna;
        while(0 < coluna && coluna > 2){
            cout << "Escolha um numero que esta entre 0 a 2" << endl;
            cin >> coluna;
        }
        cout << "Escolha a linha que deseja jogar com a numeracao de [0/1/2]" << endl;
        cin >> linha;
         while(0 < linha && linha > 2){
            cout << "Escolha um numero que esta entre 0 a 2" << endl;
            cin >> linha;
        }
        jogadas++;
       
        if(jogadaFeita(coluna, linha)){
            continue;

        }
        jogoDavelha[coluna][linha] = xDox;    
        if(colunas(xDox) || linhas(xDox) || diagonais(xDox)){
            cout << "Parabens o jogador numero 2 ganhou" << endl;
            break;
        }
        


    }

}

//função booleana para verificar se e o jogadaor conseguiu completar a coluna
//a função verifica os numeros das colunas de 0 a 2 para conseguir indeficar as jogdas nas matrizes
//se for verdader ele retorna true e o verifica qual jogador ganhou
bool colunas(string jogada){
    for(int i = 0; i < 3; i++){
        if(jogoDavelha[i][0] == jogada && jogoDavelha[i][1] == jogada && jogoDavelha[i][2] == jogada){
            return true;
        }
    }
    return false;
}
//função booleana para verificar se e o jogadaor conseguiu completar as linhas
//a função verifica os numeros das linhas de 0 a 2 para conseguir indeficar as jogdas nas matrizes
//se for verdader ele retorna true e o verifica qual jogador ganhou
bool linhas(string jogada){
    for(int i = 0; i < 3; i++){
        if(jogoDavelha[0][i] == jogada && jogoDavelha[1][i] == jogada && jogoDavelha[2][i] == jogada){
            return true;
        }
    }
    return false;
}
//função booleana para verificar se e o jogadaor conseguiu completar as diagonais
//a função verifica os numeros das diagonais de 0 a 2 para conseguir indeficar as jogdas nas matrizes
//se for verdader ele retorna true e o verifica qual jogador ganhou
bool diagonais(string jogada){
    if((jogoDavelha[0][0] == jogada && jogoDavelha[1][1] == jogada && jogoDavelha[2][2] == jogada) ||
    (jogoDavelha[2][0] == jogada && jogoDavelha[1][1] == jogada && jogoDavelha[0][2] == jogada)){
        return true;
    }
    return false;
}
//função que eu ainda estou tentando melhorar para que retorne se a jogada ja foi feita

bool jogadaFeita(int coluna, int linha){
    return jogoDavelha[coluna][linha] == xDox || jogoDavelha[coluna][linha] == bola;
}