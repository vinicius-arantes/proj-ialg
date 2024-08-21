// Projeto prático de Introdução a Algoritmos
//
// Sistema de Cadastro de Personagens de Desenho Animado
//
// Intergrantes do grupo:
// Mariana Laura Gonçalves Campos Rufo
// Vínicius Souza Arantes
// Mattheus Jordany Vicente Rodrigues 


#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

void telaInicial(){
cout << ".---------------------------------------------------------------------------------------------------------------." << endl;
cout << "|             ____                   Projeto de Sistema de Cadastro de                  _                        |" << endl;
cout << "|            |  _ '. ___  _ __  ___   ___   _ __    __ _   __ _   ___  _ __   ___    __| |  ___                  |" << endl;
cout << "|            | |_) |/ _ '| '__|/ __| / _ '.| '_ '. / _` | / _` | / _ '| '_ './ __|  / _` | / _ '                 |" << endl;
cout << "|            |  __/|  __/| |   '__ '| (_) || | | || (_| || (_| ||  __/| | | |'__ ' | (_| ||  __/                 |" << endl;
cout << "|            |_|   '.___||_|   |___/'.___/ |_| |_|'.__,_|'.__, |'.___||_| |_||___/ '.__,_|'.___|                 |" << endl;
cout << "|                                                  |___/                                                         |" << endl;
cout << "|        ____                           _                 _                                     _                |" << endl;
cout << "|       |  _ '.  ___  ___   ___  _ __  | |__   ____      / '    _ __  (_) _ __ ___    __ _   __| |  ___          |" << endl;
cout << "|       | | | | / _ '/ __| / _ '| '_ '.| '_ './  _ '.   / _ '  | '_ '.| || '_ ` _ '. / _` | / _` | / _ '.        |" << endl;
cout << "|       | |_| ||  __/'__ '|  __/| | | || | | || (_) |  / ___ ' | | | || || | | | | || (_| || (_| || (_) |        |" << endl;
cout << "|       |____/ '.___||___/'.___||_| |_||_| |_|'.___/  /_/   '_'|_| |_||_||_| |_| |_|'.__,_|'.__,_|'.___/         |" << endl;
cout << "|                                                                                                                |" << endl;
cout << "|                                                                                                                |" << endl;
cout << "|        .--..--..--..--..--..--.    .-----------------------------------------------------------------------.   |" << endl;
cout << "|      .' '. (`._   (_)     _   '.   |      ___  _        __                       .'                     _  |   |" << endl;
cout << "|    .'    |  '._)         (_)  |    |     / _ '(_)__ _(_) /____    ___     ___  __ ____ _  ___ ____ __  (_) |   |" << endl;
cout << "|    '. _.')'.     .----..--.   /    |    / // / / _ `/ / __/ -_)  / _ '   / _ '/ // /  ' '/ -_) __/ _ ' _   |   |" << endl;
cout << "|    |(_.'  |    /    .-'-.  '. |    |   /____/_/'_, /_/'__/'__/   '___/  /_//_/'_,_/_/_/_/'__/_/  '___/(_)  |   |" << endl;
cout << "|   '.     0|    |   ( O| O) | o|    |          /___/                                                        |   |" << endl;
cout << "|     |  _  |  .--.____.'._.-.  |    |                                                                       |   |" << endl;
cout << "|    '. (_) | o         -` .-`  |    |           1 - Se quiser listar os personagens;                        |   |" << endl;
cout << "|      |    '.  |`-._ _ _ _ _'. /    |           2 - Se quiser adicionar um personagem;                      |   |" << endl;
cout << "|     '.    |   |  `. |_||_|   |     |           3 - Se quiser colocar um personagem na lixeira;             |   |" << endl;
cout << "|      | o  |   '._     '.     |     -.   .-.    4 - Se quiser esvaziar a lixeira;                           |   |" << endl;
cout << "|      |.-. '.     `--..-'   O |     `.`-' .'    5 - Se quiser ordenar a lista por ID;                       |   |" << endl;
cout << "|    _.'  .' |     `-.-'      /-.__   ' .-'      6 - Se quiser ordenar a lista por ordem alfabetica;         |   |" << endl;
cout << "|  .' `-.` '.|='=.='=.='=.='=|._/_ `-'.'         7 - Se quiser salvar os dados em outro arquivo .csv;        |   |" << endl;
cout << "|  `-._  `.  |_______/'._____|   `-.'|           8 - Se quiser editar os dados de um personagem;             |   |" << endl;
cout << "|     .'   ).|'=' '=''./ '=' |       |           9 - Se quiser mostrar um personagem de acordo com o nome;   |   |" << endl;
cout << "|     `._.`  '---------------'       |           10 - Salvar as alteracoes no arquivo data.csv;              |   |" << endl;
cout << "|             //___'.  //___'.       |           11 - Se quiser fechar o programa.                           |   |" << endl;
cout << "|               ||       ||          |                                                                       |   |" << endl;
cout << "|               ||_.-.   ||_.-.      '-----------------------------------------------------------------------'   |" << endl;
cout << "|              (_.--__) (_.--__)           Mariana Laura Goncalves Campos Rufo | Vinicius Souza Arantes          |" << endl;
cout << "|                                                      Mattheus Jordany Vicente Rodrigues                        |" << endl;
cout << "|                                                                                                                |" << endl;
cout << "'---------------------------------------------------------------------------------------------------------------'" << endl << endl;
}

struct personagem
{
  int id;
  char nomePersona[30];
  char nomeCriador[30];
  char nomeTitulo[50];
  char descricao[200];
};

void adicionarPersona(personagem *&lista, int &tamanho, int limite){
	
  if (limite == tamanho or limite < tamanho){
	personagem* novo = new personagem[limite + 10];
	copy(lista, lista + tamanho, novo);
	delete[] lista;
	lista = novo;
	limite += 10;
	} 

	personagem novaPersona;
	novaPersona.id = tamanho + 1;
	cin.ignore();
	cout << "Qual o nome da sua personagem? " << endl;
	cin.getline(novaPersona.nomePersona, 30);
	cout << "Qual o nome do criador da personagem? " << endl;
	cin.getline(novaPersona.nomeCriador, 30);
	cout << "De qual desenho sua personagem faz parte? " << endl;
	cin.getline(novaPersona.nomeTitulo, 50);
	cout << "Faca uma breve descricao da sua personagem: " << endl;
	cin.getline(novaPersona.descricao, 200);
	cout << ".====================================." << endl;
	cout << "| Personagem adicionada com sucesso! |" << endl;
	cout << "'===================================='" << endl;
	
	lista[tamanho] = novaPersona;
	tamanho++;
}

void shellSortId(personagem lista[], int tamanho)
{
  int gaps[6] = {1, 4, 10, 23, 57, 132};
  int posGap = 5;

  while (gaps[posGap] > tamanho)
  {
    posGap--;
  }

  personagem aux;
  int j;

  while (posGap >= 0)
  {
    int gap = gaps[posGap];

    for (int i = gap; i < tamanho; i++)
    {
      aux = lista[i];
      j = i;
      while ((j >= gap) and (aux.id < lista[j - gap].id))
      {
        lista[j] = lista[j - gap];
        j = j - gap;
      }
      lista[j] = aux;
    }
    posGap--;
  }
}

void shellSortNome(personagem lista[], int tamanho)
{
  int gaps[6] = {1, 4, 10, 23, 57, 132};
  int posGap = 5;

  while (gaps[posGap] > tamanho)
  {
    posGap--;
  }

  personagem aux;
  int j;

  while (posGap >= 0)
  {
    int gap = gaps[posGap];

    for (int i = gap; i < tamanho; i++)
    {
      aux = lista[i];
      j = i;
      while ((j >= gap) and strcmp(lista[j - gap].nomePersona, aux.nomePersona) > 0)
      {
        lista[j] = lista[j - gap];
        j = j - gap;
      }
      lista[j] = aux;
    }
    posGap--;
  }
}

void atualizaPersona(personagem lista[], int tamanho)
{
  char serAtualizado[30];
  bool achou = false;
  cout << "Qual o nome da personagem que deseja atualizar? ";
  cout << endl;
  cin.ignore();
  cin.getline(serAtualizado, 30);

  for (int i = 0; i < tamanho; i++){
    if (lista[i].id != -1){
      if (strcmp(lista[i].nomePersona, serAtualizado) == 0){
        achou = true;
        cout << endl;
        cout << "ID: " << lista[i].id;
        cout << endl;
        cout << "Qual o nome da personagem? " << endl;
        cin.getline(lista[i].nomePersona,30);
        cout << "Quem criou sua personagem? " << endl;
        cin.getline(lista[i].nomeCriador,30);
        cout << "De qual desenho ela fazia parte? " << endl;
        cin.getline(lista[i].nomeTitulo,50);
        cout << "Faca uam breve descricao da sua personagem: " << endl;
        cin.getline(lista[i].descricao,200);
        
        cout << ".====================================." << endl;
        cout << "| Personagem atualizada com sucesso! |" << endl;
        cout << "'===================================='" << endl;
      }
    }
  }
  if (!achou)
  {
	cout << endl;
    cout << "Personagem nao encontrado!" << endl;
    cout << "==========================" << endl;
    cout << "  ======================" << endl;
    cout << endl;
  }
}

void busca(personagem lista[], int tamanho)
{
  char pesquisa[30];
  bool achou = false;
  cout << "Digite o nome do personagem para a busca: ";
  cout << endl;
  cin.ignore();
  cin.getline(pesquisa, 30);

  for (int i = 0; i < tamanho; i++){
    if (lista[i].id != -1){
      if (strcmp(lista[i].nomePersona, pesquisa) == 0){
        achou = true;
        cout << endl;
        cout << "========================================================================================" << endl;
        cout << "ID: " << lista[i].id;
        cout << endl;
        cout << "Nome do Personagem: " << lista[i].nomePersona << endl;
        cout << "Criador: " << lista[i].nomeCriador << endl;
        cout << "Titulo do Desenho: " << lista[i].nomeTitulo << endl;
        cout << "Descricao: " << lista[i].descricao << endl;
        cout << "========================================================================================";
        cout << endl;
      }
    }
  }
  if (!achou)
  {
    cout << endl;
    cout << "Personagem nao encontrado!" << endl;
    cout << "==========================" << endl;
    cout << "  ======================" << endl;
    cout << endl;
  }
}

void apagar(personagem lista[], int tamanho)
{
  char pesquisa[30];
  bool achou = false;
  cout << "Digite o nome do personagem que deseja apagar: ";
  cout << endl;
  cin.ignore();
  cin.getline(pesquisa, 30);

  for (int i = 0; i < tamanho; i++)
  {
    if (lista[i].id != -1)
    {
      if (strcmp(lista[i].nomePersona, pesquisa) == 0)
      {
        achou = true;
        lista[i].id = -1;
        cout << endl;
        cout << ".=================================." << endl;
        cout << "| Personagem apagada com sucesso! |" << endl;
        cout << "'================================='" << endl;
        cout << endl;
      }
    }
  }
  if (!achou)
  {
    cout << endl;
    cout << "Personagem nao encontrado!" << endl;
    cout << "==========================" << endl;
    cout << "  ======================" << endl;
    cout << endl;
  }
}

void deletar(personagem lista[], int &tamanho)
{
  int resposta;
  cout << "Tem certeza que deseja deletar todos os personagens da lixeira?";
  cout << endl;
  cout << "Digite 1 para sim e qualquer outro numero para nao:";
  cout << endl;
  cin >> resposta;

  if (resposta == 1){

    int novoTamanho = 0;

    personagem *novaLista = new personagem[tamanho];

    for (int i = 0; i < tamanho; i++){
      if (lista[i].id != -1){
        novaLista[novoTamanho] = lista[i];
        novoTamanho++;
      }
    }

    delete[] lista;
    tamanho = novoTamanho;
    lista = novaLista;
    cout << endl;
    cout << ".====================================." << endl;
    cout << "| Personagens deletadas com sucesso! |" << endl;
    cout << "'===================================='" << endl;
    cout << endl;
  } else {
    cout << endl;
    cout << ".=========================================." << endl;
    cout << "| Certo! Personagens nao serao deletados. |" << endl;
    cout << "'========================================='" << endl;
    cout << endl;
  }
}

void arqBinario(personagem lista[], int tamanho)
{
  ofstream arquivo("personagens.dat", ios::binary);
  arquivo.write((char *)(lista), sizeof(personagem) * tamanho);
  arquivo.close();
}

void atualizarCsv(personagem lista[], int tamanho)
{
  ofstream saida("data.csv");
  if (saida){
    saida << tamanho << endl;
    for (int i=0; i < tamanho; i++) {
				if (lista[i].id == -1) {
				  lista[i].id = -1;
				} else {
				  lista[i].id = i+1;
				  saida << lista[i].id << ";" << lista[i].nomePersona << ";" << lista[i].nomeCriador << ";" << lista[i].nomeTitulo << ";" << lista[i].descricao << ";" << endl;	
				}  	
			}
		saida.close();
  } else {
    cout << endl;
    cout << "Não foi possível acessar o arquivo!" << endl;
    cout << "==================================" << endl;
    cout << "  ==============================" << endl;
    cout << endl;
  }
}

void outroCsv(personagem lista[], int tamanho, string nomeArq){
	
  ofstream saida(nomeArq);
  if (saida){
    saida << tamanho << "\n";
    for (int i = 0; i < tamanho; i++){
      saida << lista[i].id << ";" << lista[i].nomePersona << ";" << lista[i].nomeCriador << ";" << lista[i].nomeTitulo << ";" << lista[i].descricao << ";" << endl;
    }
    saida.close();
    cout << endl;
        cout << ".====================." << endl;
        cout << "| Salvo com sucesso! |" << endl;
        cout << "'===================='" << endl;
        cout << endl;
  } else {
    cout << endl;
    cout << "Não foi possível acessar o arquivo!" << endl;
    cout << "==================================" << endl;
    cout << "  ==============================" << endl;
    cout << endl;
  }
}

int main(){


  bool recomecar = true;
  int tamanho;
  int limite = 100;

  ifstream entrada("data.csv");
  if(entrada){
    entrada >> tamanho;
    entrada.ignore();
  }

  personagem *lista = new personagem[tamanho];

  if(entrada){
    char pontoVirgula;
    for (int i = 0; i < tamanho; i++){
      entrada >> lista[i].id;
      entrada >> pontoVirgula;
      entrada.getline(lista[i].nomePersona, 30, ';');
      entrada.getline(lista[i].nomeCriador, 30, ';');
      entrada.getline(lista[i].nomeTitulo, 50, ';');
      entrada.getline(lista[i].descricao, 200, ';');
    }
  }
  
  arqBinario(lista,tamanho);
  
  fstream arq("personagens.dat", ios::binary | ios::in | ios::out);
    if (arq.is_open()){
      arq.seekg(0, arq.end);
      streampos tamBinario = arq.tellg();
      arq.seekg(0, arq.beg);

      int numReg = tamBinario / sizeof(personagem);

      personagem *personagens = new personagem[numReg];
      arq.read((char*)(personagens), tamBinario);
    }

  while(recomecar){
	telaInicial();
    int requisicao;
    cin >> requisicao;

    // Mostra a lista de personagens registrados:
    if (requisicao == 1){
      cout << "Caso queira ver toda a lista digite 1, caso queira delimitar o inicio e o fim da sua busca digite 2: " << endl;
      int escolha;
      cin >> escolha;
      if(escolha == 1){
        for (int i = 0; i < tamanho; i++){
        if (lista[i].id != -1){
          cout << "ID: " << lista[i].id << endl
               << "Nome da personagem: " << lista[i].nomePersona << endl
               << "Nome do criador: " << lista[i].nomeCriador << endl
               << "Titulo do desenho: " << lista[i].nomeTitulo << endl
               << "Descricao: " << lista[i].descricao << endl
               << "===============================================================================================================" << endl;
          }
        }
      } else if(escolha == 2){
		  cout << "Digite o primeiro elemento que queira ver: " << endl;
		  
		  int posInicio;
		  cin >> posInicio;
		  if(posInicio <= 0 or posInicio > tamanho){
		    cout << "A posicao inicial nao esta entre as disponiveis, escolha entre 1 e " << tamanho << "!" << endl;
		    cin >> posInicio;	  	  
		  }
		  
		  int posFinal;
		  cin >> posFinal;
		  if(posFinal <= 0 or posFinal < posInicio or posFinal > tamanho){
		    cout << "A posicao final nao esta entre as disponiveis, escolha uma diferente da posicao inicial e entre 1 e " << tamanho << "!" << endl;
		    cin >> posFinal;	  	  
		  }
		  
		  for (int i = posInicio - 1; i < posFinal; i++){
            if (lista[i].id != -1){
            cout << "ID: " << lista[i].id << endl
              << "Nome da personagem: " << lista[i].nomePersona << endl
              << "Nome do criador: " << lista[i].nomeCriador << endl
              << "Titulo do desenho: " << lista[i].nomeTitulo << endl
              << "Descricao: " << lista[i].descricao << endl
              << "===============================================================================================================" << endl;
            }
          }
	  } else {
		cout << endl;
        cout << "Opção inválida!" << endl;
        cout << "===============" << endl;
        cout << "  ===========" << endl;
        cout << endl; 
	  }
    }

    // Adiciona um novo personagem:
    if (requisicao == 2){
	  adicionarPersona(lista, tamanho, limite);
	  atualizarCsv(lista, tamanho);
	  
	  arq.seekg(0, ios::beg);
      arq.write((char*)(lista), sizeof(personagem) * tamanho);
    }

    // Coloca um personagem na lixeira:
    if (requisicao == 3){
		apagar(lista, tamanho);
    }

    // Esvaziar a lixeira:
    if (requisicao == 4){
		deletar(lista, tamanho);
		atualizarCsv(lista, tamanho);
    }

    // Ordena a lista de personagens por ID:
    if (requisicao == 5){
	  shellSortId(lista, tamanho);
	    cout << endl;
        cout << ".======================================." << endl;
        cout << "| Toda a lista foi ordenada com exito! |" << endl;
        cout << "'======================================'" << endl;
        cout << endl;
    }

    // Ordena a lista de personagens por ordem alfabética:
    if (requisicao == 6){
	  shellSortNome(lista, tamanho);
	    cout << endl;
        cout << ".======================================." << endl;
        cout << "| Toda a lista foi ordenada com exito! |" << endl;
        cout << "'======================================'" << endl;
        cout << endl;
    }

    // Salvar os dados em outro arquivo .csv:
    if (requisicao == 7){
		string nomeArq;
		cout << "Digite o nome do novo arquivo .csv: " << endl;
		cin >> nomeArq;
		nomeArq = nomeArq + ".csv";
        
		outroCsv(lista, tamanho, nomeArq);
    }

    // Reescrever os dados de um personagem:
    if (requisicao == 8){
	  atualizaPersona(lista, tamanho);
    }

    // Mostra um personagem de acordo com o nome:
    if (requisicao == 9){
	  busca(lista, tamanho);
    }
     
    // Salvar todas as alterações feitas no arquivo .csv:
    if (requisicao == 10){
	  atualizarCsv(lista, tamanho);
	  cout << endl;
        cout << ".==================================." << endl;
        cout << "| Atualizações feitas com sucesso! |" << endl;
        cout << "'=================================='" << endl;
        cout << endl;
    }
     
    // Finaliza o programa:
    if (requisicao == 11){
		recomecar = false;
    }

    if (requisicao < 1 or requisicao > 11){
      cout << "                         ________" << endl;
	  cout << " _________        ___.---''''''''---.___" << endl;
      cout << ":______.-':      :  .----------------.  :" << endl;
      cout << "| ______  |      | :                  : |" << endl;
      cout << "|:______B:|      | |       Erro:      | |" << endl;
      cout << "|:______B:|      | |                  | |" << endl;
      cout << "|:______B:|      | | Nao foi possivel | |" << endl;
      cout << "|         |      | |    realizar a    | |" << endl;
      cout << "|:_____:  |      | |   requisicao!!   | |" << endl;
      cout << "|    ==   |      | :                  : |" << endl;
      cout << "|       O |      :  '----------------'  :" << endl;
      cout << "|       o |      :'---...________...---'" << endl;
      cout << "|       o |-._.-i___|'             |._  " << endl;
      cout << "|'-.____o_|   '-.   '-...________...-'  `-._" << endl;
      cout << ":_________:      `.____________________   `-.___.-." << endl;
      cout << "                 .'.eeeeeeeeeeeeeeeeee.'.      :___:" << endl;
      cout << "               .'.eeeeeeeeeeeeeeeeeeeeee.'." << endl;
      cout << "              :____________________________:" << endl;
    }

    cout << ".---------------------------------." << endl <<"| Deseja voltar a pagina inicial? |" << endl << "'---------------------------------'--------------------------------------------------." << endl
         << "| Digite 1 para sim ou qualquer outro numero para caso deseja finalizar a aplicacao: |" << endl << "'------------------------------------------------------------------------------------'" << endl;

    int resposta;
    cin >> resposta;

    if (resposta != 1){
      recomecar = false;
    } else {
      recomecar = true;
      cout << endl;
    }
  }
  
cout << "                         _____                                                                               " << endl;
cout << "                     .d88888888bo.                      _______________________________________________      " << endl;
cout << "                   .d8888888888888b.                  .'           _    __                   _     _   '.    " << endl;
cout << "                   8888888888888888b                .'        /'  | |  /_/                  (_)   | |    |   " << endl;
cout << "                   888888888888888888               |        /  ' | |_ __    _ __ ___   __ _ _ ___| |     |  " << endl;
cout << "                   888888888888888888          .    |       / /' '| __/ _'. | '_ ` _ './ _` | / __| |     |  " << endl;
cout << "                    Y8888888888888888   '           |      / ____ ' ||  __/ | | | | | | (_| | ,__'._|     |  " << endl;
cout << "              ,od888888888888888888P                 |    /_/    '_'_ .___| |_| |_| |_|.__,_|_|___(_)    |   " << endl;
cout << "           .'`Y8P'```'Y8888888888P'         *         '.    ___________________________________________.'    " << endl;
cout << "         .'_   `  _     'Y88888888b                    /   /                                                 " << endl;
cout << "       /  _`    _ `      Y88888888b   ____           .'   /     .      '      .                             *" << endl;
cout << "    _  | /  '  /  '      8888888888.d888888b.      /.,. .'   _|_                   *        |         '      " << endl;
cout << "   d8b | | /|  | /|      8888888888d8888888888b               |             ,             --|--              " << endl;
cout << "  8888_' '_|/  '_|/      d888888888888888888888b     .                  '.  :  /            |                " << endl;
cout << "   TY8P  `'-.            d88888888888888888888888          *    '     `. __/'.__ .'                 .        " << endl;
cout << "  /          `          `      `Y8888888888888888                     _ '.     /_ _       '                  " << endl;
cout << "  |                        __    888888888888888P          '             /_   _'.              *             " << endl;
cout << "  '.                       / `   dPY8888888888P'                .      .' '. /  `.      |                    " << endl;
cout << "    '._                  .'     .'  `Y888888P`                           /  :  '.       |                    " << endl;
cout << "       `''-..__    ___.-'     .-'                     *           '         '        ___|___        *        " << endl;
cout << "           `-._````____..--'`                  '                                        |                    " << endl;
cout << "                                                                .         *             |                    " << endl;
cout << "                                                                                        |                    " << endl;

  delete[] lista;
  return 0;
}
