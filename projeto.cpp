#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

struct personagem{
  int id;
  char nomePersona[25];
  char nomeCriador[25];
  char nomeTitulo[30];
  char descricao[200];
};

void shellSortPersona(personagem lista[], int tamanho) {
  int gaps[6] = {1, 4, 10, 23, 57, 132};
  int posGap = 5;

  while(gaps[posGap] > tamanho){
    posGap--;
  }

  personagem aux;
  int j;

  while( posGap >= 0){
    int gap = gaps[posGap];
    
    for(int i = gap; i < tamanho; i++){
      aux = lista[i];
      j = i;
      while ((j >= gap) and (aux.id < lista[j - gap].id)){
        lista[j] = lista[j - gap];
        j = j - gap;
      }
    lista[j] = aux;
    }
      posGap--;
     }
  }

void shellSortNome(personagem lista[], int tamanho) {
  int gaps[6] = {1, 4, 10, 23, 57, 132};
  int posGap = 5;

  while(gaps[posGap] > tamanho){
    posGap--;
  }

  personagem aux;
  int j;

  while( posGap >= 0){
    int gap = gaps[posGap];
    
    for(int i = gap; i < tamanho; i++){
      aux = lista[i];
      j = i;
      while ((j >= gap) and strcmp(lista[j - gap].nomePersona, aux.nomePersona) > 0){
        lista[j] = lista[j - gap];
        j = j - gap;
      }
      lista[j] = aux;
    }
      posGap--;
     }
  }

void busca(personagem lista[],int tamanho){
	char pesquisa[30];
    bool achou = false;
    cout << "Digite o nome do personagem para a busca: ";
    cout<<endl;
    cin.ignore();
    cin.getline(pesquisa,30);
    
    for (int i=0; i<tamanho; i++){
		if(lista[i].id != -1){
        if (strcmp(lista[i].nomePersona,pesquisa) == 0){
            achou = true;
            cout<<endl;
            cout<<"Posicao: "<<lista[i].id;
			cout<<endl;
			cout<<"Nome do Personagem: "<<lista[i].nomePersona<<endl<<"Criador: "<<lista[i].nomeCriador<<endl<<"Titulo do Desenho: "<<lista[i].nomeTitulo<<endl<<"Mesorregiao: "<<lista[i].descricao<<endl<<endl;
		}
        }
    }
    if (!achou){
        cout<<"Personagem nao encontrado!" << endl;
    }
}

int main(){
	
	return 0;
}

