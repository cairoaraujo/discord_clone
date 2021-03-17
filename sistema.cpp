#include "sistema.h"
#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

//DECLARACOES:

  //Vector que armazena todos os usuários criados no Concordo:


//VARIAVEIS:

  //Contador para os IDs do usuario:
  int usuarioID = 0;

  //Variavel booleana que retorna true se logado e false se não logado
  bool estaLogado;
  //Variavel que controla se usuario ja foi criado
  bool foiCriado;
  //Variavel que controla qual ID está logado
  int idLogada;

/* COMANDOS */

string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {//se não há usuarios criados, não precisa verificar se os dados já foram cadastrados. 

  if (vectorUsuarios.empty()== true ){//se não há usuarios criados, não precisa verificar se os dados já foram cadastrados. 
  
    Usuario  *novoUsuario = new Usuario (email, senha, nome);//cria um novo usuario a partir do construtor da classe usuario:
    vectorUsuarios.push_back(novoUsuario);//adiciono no final do vetor o ultimo usuario criado.

  } else{//se já existem usuarios cadastrados, irá percorrer o vector pra ver se já foi usado o email em outra conta.

    for (int u=0; u< vectorUsuarios.size();u++){
      if (vectorUsuarios[u]->getEmail() == email){
        cout<<"EMAIL JÁ CADASTRADO!"<<endl;
        foiCriado = true;
        break;
      }
      else{
        Usuario  *novoUsuario = new Usuario (email, senha, nome);
        vectorUsuarios.push_back(novoUsuario);
      }
      //imprimindo os usuarios (testando)
      cout <<"QUANTIDADE DE USUARIOS ATIVOS: "<<vectorUsuarios.size()<<endl;
      cout <<"IMPRIMINDO OS USUARIOS ATIVOS:"<<endl;
      cout << vectorUsuarios[u]->getEmail()<<endl;
      //cout << vectorUsuarios[u]->getSenha()<<endl;
      //cout << vectorUsuarios[u]->getUsuario()<<endl;   
    }
  }
  if (foiCriado==true)
  return "Usuário ja cadastrado!";
  else{
    return "Usuario cadastrado com sucesso";
  }
}


string Sistema::login(const string email, const string senha) {
  for (int u=0; u< vectorUsuarios.size();u++){

    if (vectorUsuarios[u]->getEmail() == email){

      if (vectorUsuarios[u]->getSenha()== senha){
        cout<<"Usuario logado com sucesso!"<<endl;
      }
      else{
        cout<<"senha invalida!"<<endl;
      }

    } 
    else{
      cout << "dados invalidos!"<<endl;
    }
  }
  return "";
}

string Sistema::disconnect() {
  if (estaLogado){
    
  }
  return "disconnect NÃO IMPLEMENTADO";
}

string Sistema::create_server(const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(const string nome, const string descricao) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers() {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants() {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */