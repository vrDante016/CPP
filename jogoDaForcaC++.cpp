#include <iostream>
#include <queue>
using namespace std;

int main(){
    //declarações de variaveis e estou usando uma lista/queue 
    queue <char> palavraForca;
    string palavras, secreta ,sinal = "-";
    char letra;
    int tamanho = 0, chances = 6, acertos = 0;
    bool letraCerta = false;

    cout << "Bem vindo ao jogo da forca:" << endl;
    cout << "Entre com a palavra" << endl;
    cin >> palavras;

    for(char c : palavras){
        tamanho++;
        palavraForca.push(c);
        secreta += sinal;
    }

    while(chances > 0 && acertos < tamanho){
        cout << "A palavra secreta é: " << " " << secreta << endl;
        cout << "quantidade de chances: " << " " << chances << endl;
        cout << "Entre com a letra: " << endl;
        cin >> letra;
        letraCerta = false;
        for(int i = 0; i < tamanho; i++){
            if(palavras[i] == letra){
                if(secreta[i] == sinal[0]){
                    secreta[i] = letra;
                    acertos++;

                }
            letraCerta = true;

            }
        }
        if(!letraCerta){
            chances--;
        } 
    }
    if(acertos == tamanho){
        cout << "parabens o jogador ganhou " << endl;
    }else if(chances < 0){
        cout << "O jogador perdeu" << endl;

    }


}