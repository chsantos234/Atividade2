#include <iostream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

#define MAXTAM 1000

typedef int TipoApontador;
typedef char Tipoletra;

typedef struct{
  Tipoletra letra;
} TipoItem;

typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Topo;
} TipoPilha;

void itemcolocado(TipoItem *Letra, char a){
  Letra -> letra = a;
}

void FPVazia(TipoPilha *Pilha){
  Pilha -> Topo = 0;
}

int Vazia (TipoPilha *Pilha){
  return (Pilha -> Topo == 0);
}

void Empilha (TipoItem x, TipoPilha *Pilha){
  if (Pilha -> Topo == MAXTAM){
    printf("erro, tamanho maximo da pilha\n");
  }
  else{
    Pilha -> Item[Pilha -> Topo] = x;
    Pilha -> Topo++;
  }
}

TipoItem Desempilha (TipoPilha *Pilha){
  if (Vazia(Pilha)){
    cout << "erro, pilha vazia" << endl;
  }
  else{
    Pilha -> Topo--;
    return Pilha -> Item[Pilha -> Topo];
  }
}

int Tamanho(TipoPilha *Pilha){
  return Pilha ->Topo;
}

string reverter(string frase, TipoItem it, 
TipoPilha p){
  for (int i=0; i<frase.length(); i++){
    if (strcmp(&frase[i], "") != 0){
      itemcolocado(&it, frase[i]);
      Empilha(it, &p);
    }
  }
  int tamanhoPilha = Tamanho(&p) - 1 ;
  string result = "";
  for (int i=0; i <= tamanhoPilha ; i++){
    char t;
    t = Desempilha(&p).letra;
    result += t;
  }
  return result;
}

int main() {
  string frase;
  
  cout << "digite:";

  getline(cin,frase);

  for_each(frase.begin(), frase.end(), [](char & c){
    c = ::tolower(c);
  });
  
  cout << "\nsua frase é: " << frase << "\n" << endl;
  TipoPilha p;

  FPVazia(&p);

  TipoItem it;

  frase += " ";
  string sub;
  string resultado;
  int count = 0;
  int space = 0;
  for (int i=0; i<frase.length(); i++){
    if (isspace(frase[i]) && count ==0 ){
      sub = frase.substr(0, i);
      resultado += reverter(sub, it, p);
      resultado += " ";
      count += i + 1;
      space += 1;
    }
    else if (isspace(frase[i]) && count != 0){
      sub = frase.substr(count, i-count);
      resultado += reverter(sub, it, p);
      resultado += " ";
      count = i+1;
      space -= 1;
    }
  }
  cout << "frase revertida: "<<  resultado << endl;

  return 0;
}
