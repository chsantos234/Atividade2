#include <iostream>
#include <locale>
#include<stdio.h>
#include<string.h>
#include <algorithm>
#include <cctype>
#include <string>
using namespace std;

#define MAXTAM 1000
typedef int TipoApontador;
typedef char TipoChave;

typedef struct{
  TipoChave Chave;
}TipoItem;

typedef struct{
  TipoItem Item[MAXTAM];
  TipoApontador Topo;
}TipoPilha;

void FPVazia(TipoPilha *Pilha){
  Pilha->Topo = 0;
}

int Vazia(TipoPilha *Pilha){
  return (Pilha->Topo == 0);
}

void Empilha(TipoItem x,TipoPilha *Pilha){
  if(Pilha->Topo == MAXTAM){cout << "Erro: Pilha cheia!\n";}
  else{
    Pilha->Item[Pilha->Topo] = x;
    Pilha->Topo++;
  }
}

TipoItem Desempilha(TipoPilha *Pilha){
  if(Vazia(Pilha)){
    cout << "Erro: Pilha vazia!\n" << endl;
  }
  else{
    Pilha->Topo--;
    return Pilha->Item[Pilha->Topo];
  }
}

int Tamanho(TipoPilha *Pilha){
  return Pilha->Topo;
}
void PutItem(TipoItem *Chave, char c){
  Chave -> Chave = c;
}
string Inversion(string Input,TipoItem x,TipoPilha Pilha){
  
  string resposta = " ";
  for(int i = 0; i < Input.length();i++){
    if (strcmp(&Input[i], "") != 0){
      PutItem(&x,Input[i]);
      Empilha(x,&Pilha);
    }
  }
  int tamanho = Tamanho(&Pilha) - 1;
  for(int i = 0; i <= tamanho; i++){
    char retorno;
    retorno = Desempilha(&Pilha).Chave;
    resposta += retorno;
  }
  return resposta;
}

int main() {
  string input;
  string substring;
  string result;
  int espaco = 0;
  int contador = 0;
  
  cout << "Digite uma frase:\n";
  getline(cin,input);
  TipoItem Chave;
  TipoPilha Pilha;
  FPVazia(&Pilha);
  

  transform(input.begin(), input.end(), input.begin(),
  [](unsigned char c){ return tolower(c); });

  input += " ";

  for (int i=0; i<input.length(); i++){
    if (isspace(input[i]) && contador == 0 ){
      substring = input.substr(0, i);
      result += Inversion(substring, Chave, Pilha);
      result += " ";
      contador += i + 1;
      espaco += 1;
    }
    else if (isspace(input[i]) && contador != 0){
      substring = input.substr(contador, i-contador);
      result += Inversion(substring, Chave, Pilha);
      result += " ";
      contador = i+1;
      espaco -= 1;
    }
  }

  cout << "Resultado final:\n";
  cout << result;

  return 0;
}
