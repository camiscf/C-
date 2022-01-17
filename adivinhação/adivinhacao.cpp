#include<iostream>
#include<stdlib>
#include<ctime>

using namespace std;

int main (){
    cout << "**************************************\n* Olá! Este é um jogo de adivinhação *\n**************************************\n";

    cout <<"Escolha a dificuldade:\n(F) Fácil\n(M) Médio\n(D) Difícil\n";

    char dificuldade;
    cin >> dificuldade;

    int tentativas;
    if(dificuldade == 'F'){
        tentativas = 15;
    }
    else if (dificuldade == 'M'){
        tentativas = 10;
    }
    else if (dificuldade == 'D'){
        tentativas = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() %100;

    bool nao_acertou = true;
    double pontos = 1000.0;

    for (int i = 1; i <= tentativas; i++){
        int chute;
        cout << "Tentativa " << i << endl;
        cout << "Qual seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs(chute - NUMERO_SECRETO)/2.0;
        pontos -= pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;
        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;

        if (acertou)
        {
            cout << "Parabéns! Você acertou o número secreto!" << endl;
            break;
        }
        else if (maior)
        {
            cout << "Seu chute foi maior que o número secreto!" << endl;
        }
        else
        {
             cout << "Seu chute foi menor que número secreto!" << endl;
        }

}
cout << "Fim de jogo!" << endl;

if(nao_acertou){
    cout << "Você esgotou suas tentativas!";
}else{
cout.precision(2);
cout << fixed;
cout << "Sua pontuação: " << pontos << endl;    
}



}
