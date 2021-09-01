#include<iostream>
#include<cstdlib>
#include <locale.h>

using namespace std;

const int TMax=10;

struct tFila {
    int Inicio, Fim, Tam = 0;
    int Elem[TMax];
};

void Primeiro(tFila F){
    if(F.Tam == 0)
    	cout << "Fila Vazia\n" <<endl;
    else
    	cout << "1º elemento da Fila: " <<F.Elem[F.Inicio+1]<<endl;
}

void Inserir(tFila &F, int V){
        if(F.Tam == TMax)
		cout << "Capacidade Esgotada";
    else {
        F.Fim = (F.Fim + 1) % TMax;
        F.Elem[F.Fim] = V;
        F.Tam++;
    }
}

void FurarFila(tFila &F, int V){
    if(F.Tam == TMax)
		cout << "Capacidade Esgotada\n";
    else {
        F.Fim = F.Fim+1;
        for(int i = F.Fim;i>0;i--){
          F.Elem[i] = F.Elem[i-1]; 
        }
        F.Elem[F.Inicio+1] = V;
        F.Tam++;
    }
}

void Remover(tFila &F) {
	if(F.Tam == 0)
	    cout << "Fila Vazia\n";
   	else{
    	F.Inicio = (F.Inicio+1)% TMax;
    	F.Tam--;
	}
}

int mapear_valor (int v){
	return v % TMax;
}     

void Visualiza(tFila F){
    int cont=1;
    int aux = mapear_valor(F.Inicio+1);
    if(F.Tam == 0){
	    cout << "Fila Vazia\n";
    }else{
    while (F.Tam > cont-1){
    	cout <<cont<< "º valor: "<< F.Elem[aux] << endl;
    	cont++;
    	F.Inicio++;
    	aux = mapear_valor(aux+1);
    }
	}
}

int main(){
	setlocale(LC_ALL,"PORTUGUESE");
  tFila F;

    F.Inicio = 0;
    F.Fim = 0;
    F.Tam = 0;
    
    int V, opc, pos;
    
    do{
    	cout << "Escolha uma opção:\n";
    	cout << "1 - Acessar o primeiro elemento\n";
    	cout << "2 - Inserir um elemento\n";
      cout << "3 - Furar Fila\n";
    	cout << "4 - Remover um elemento\n";
    	cout << "5 - Visualizar\n";
    	cout << "6 - Sair\n";
    	cin >> opc;
    	system("clear");
    
    	switch(opc){
	        case 1:
				    Primeiro(F);
          break;
          case 2:
				    cout <<"Insira um inteiro qualquer:\n";
            cin >> V;
            Inserir(F, V);
        	break;
          case 3:
            cout <<"Insira um inteiro qualquer:\n";
            cin >> V;
            FurarFila(F,V);
          break;
          case 4:
				    Remover(F);
          break;
          case 5:
				    Visualiza(F); 
          break;
          case 6:
            cout<<"Saindo ...";
          break;
   		}
	}while(opc!=6);

}
