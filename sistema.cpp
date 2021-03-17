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
  //bool emailJaUsado;
  //Variavel que controla qual ID está logado
  int idLogada;

/* COMANDOS */

string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {//se não há usuarios criados, não precisa verificar se os dados já foram cadastrados.
    bool emailJaUsado;

    if(vectorUsuarios.empty() == false){//se  ja existem elementos no vetor...
      for (int u=0; u < vectorUsuarios.size(); u++){
        if (email == vectorUsuarios[u]->getEmail()){
          cout<<"O email ja foi cadastrado!"<<endl;
          emailJaUsado = true;
          break;
        }  
      }

      if(emailJaUsado != true){//se o email nao foi utilizado ainda, ha a criacao de um novo usuario
        Usuario  *novoUsuario = new Usuario (email, senha, nome);
        usuarioID++;
        novoUsuario->idUsuario = usuarioID;
        vectorUsuarios.push_back(novoUsuario);
        //cout<<"CADASTRO REALIZADO COM SUCESSO!"<<endl;
        emailJaUsado = false;
            for (int u=0; u<vectorUsuarios.size();u++){
      cout << vectorUsuarios[u]->getEmail()<<endl;
      cout << vectorUsuarios[u]->idUsuario<<endl;
    }
        return "Cadastro realizado com sucesso!";

      }
      else{
        return "Erro na criacao de usuario!";
      }
          
    }
    if(vectorUsuarios.empty() == true){
      //cout<<"debug: é vazio"<<endl;
      Usuario  *novoUsuario = new Usuario (email, senha, nome);
      vectorUsuarios.push_back(novoUsuario);
    }
      cout <<"QUANTIDADE DE USUARIOS ATIVOS: "<<vectorUsuarios.size()<<endl;
      //cout <<"IMPRIMINDO OS USUARIOS ATIVOS:"<<endl;
    /*for (int u=0; u<vectorUsuarios.size();u++){
      cout << vectorUsuarios[u]->getEmail()<<endl;
      cout << vectorUsuarios[u]->idUsuario<<endl;
    }*/

    return "Usuario cadastrado com sucesso";
}


string Sistema::login(const string email, const string senha) {
  if(estaLogado == false){//verifica se ja existe algum usuario logado no sistema. Se sim, impede de fazer um novo login

    for (int u=0; u< vectorUsuarios.size();u++){

      if (vectorUsuarios[u]->getEmail() == email){

        if (vectorUsuarios[u]->getSenha()== senha){
          cout<<"Usuario logado com sucesso!"<<endl;
          estaLogado = true;
          idLogada = vectorUsuarios[u]->idUsuario;
          break;
        }
        else{
          cout<<"senha invalida!"<<endl;
        }

      } 
      /*else{
        cout << "dados invalidos!"<<endl;
      }*/
    }
  }
  else{
    cout <<"ja existe um usuario logado! Desconecte do usuario atual e tente novamente!"<<endl;
  }
  return "";
}

string Sistema::disconnect() {
  if (estaLogado == true){
    estaLogado = false;
    return "Usuario desconectado com sucesso!";
  }
  else{
    return "não existe usuario logado! Faça o login antes!";
  }
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