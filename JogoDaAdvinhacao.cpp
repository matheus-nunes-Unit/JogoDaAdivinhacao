//A iostream e a biblioteca responsavel pelo fluxo de entrada e saida de dados
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{   
    cout << "************************************************" << endl;
    cout << "*******Bem vindo ao Jogo Da Adivinhacao*********" << endl;
    cout << "************************************************" << endl;

    int numero_de_tentativas;

    while (true) {
        cout << "Escolha o nivel de dificuldade" << endl;
        cout << "Facil(F) Medio(M) Dificil(D)" << endl;

        char dificuldade;
        cin >> dificuldade;

        if (dificuldade == 'F') {
            numero_de_tentativas = 15;
            break;
        }
        else if (dificuldade == 'M') {
            numero_de_tentativas = 10;
            break;
        }
        else if (dificuldade == 'D') {
            numero_de_tentativas = 5;
            break;
        }
        else {
            cout << "Escolha um nivel de dificuldade valido!" << endl;  
        }
    }
    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;

    int tentativas = 0;
    bool nao_acertou = true;
    double pontuacao = 1000;

    for(tentativas = 1;tentativas <= numero_de_tentativas;tentativas++) {
        int chute = 0;
        cout << "Tentativa " << tentativas << endl;
        cout << "Qual o seu chute? ";
        cin >> chute;
        double pontos_perdidos = abs(chute - NUMERO_SECRETO) / 2.0;
        pontuacao = pontuacao - pontos_perdidos;

        cout << "O seu chute foi " << chute << "." << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;
        if (acertou) {
            cout << "Parabens voce acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if (maior) {
            cout << "Seu chato foi maior que o numero secreto!" << endl;
        }
        else {
            cout << "Seu chute foi menor que o numero secreto!" << endl;
        }
    }
    cout << "Fim de jogo" << endl;
    if (nao_acertou) {
        cout << "Voce perdeu. Tente novamente.";
    }
    else {
        cout << "Voce acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "A sua pontuacao final foi de " << pontuacao << " pontos" << endl;
    }
    system("pause");
    exit(0);
}
