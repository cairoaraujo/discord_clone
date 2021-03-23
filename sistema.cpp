#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
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
  int servidorID = 0;

  //Variavel booleana que retorna true se logado e false se não logado
  bool estaLogado;
  //Variavel que controla se usuario ja foi criado

  

/* COMANDOS */

string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {//se não há usuarios criados, não precisa verificar se os dados já foram cadastrados.
    bool emailJaUsado;//variavel de controle para verificar se email ja foi usado ou nao. Retorna true se sim.

    if(!vectorUsuarios.empty()){//se  ja existem elementos no vetor...
      for (int u=0; u < vectorUsuarios.size(); u++){
        if (email == vectorUsuarios[u]->getEmail()){
          cout<<"O email ja foi cadastrado!"<<endl;
          emailJaUsado = true;
          break;
        }  
      }

      if(!emailJaUsado){//se o email nao foi utilizado ainda, ha a criacao de um novo usuario
        usuarioID++;
        Usuario  *novoUsuario = new Usuario (email, senha, nome);
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
    if(vectorUsuarios.empty()){
      //cout<<"debug: é vazio"<<endl;
      usuarioID++;
      Usuario  *novoUsuario = new Usuario (email, senha, nome);
      novoUsuario->idUsuario = usuarioID;
      vectorUsuarios.push_back(novoUsuario);
    }
    /*  cout <<"QUANTIDADE DE USUARIOS ATIVOS: "<<vectorUsuarios.size()<<endl;
      //cout <<"IMPRIMINDO OS USUARIOS ATIVOS:"<<endl;
    for (int u=0; u<vectorUsuarios.size();u++){
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
          usuarioLogadoId = vectorUsuarios[u]->idUsuario;
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
  if (estaLogado == true){ //só poderá criar servidor se houver usuário logado
    servidorID++;
    Servidor  *novoServidor = new Servidor(nome);
    novoServidor->idServidor = servidorID;
    vectorServidores.push_back(novoServidor);
    novoServidor->setUsuarioDonoID(usuarioLogadoId);
    cout<<"ID do usuario que criou o servidor '"<<novoServidor->getNomeServidor()<<"': "<<novoServidor->getUsuarioDonoID()<<endl;
    cout<<"ID do servidor:"<<novoServidor->idServidor<<endl;
    return "Servidor criado com sucesso!";
  }
  else{
    return "Para criar um servidor, é preciso estar logado!";
  }
}

string Sistema::set_server_desc(const string nome, const string descricao) {
  bool encontrouServidor;
  int aux;
  for (int u=0; u < vectorServidores.size();u++){

    cout<<"DEBUG: ENTROU "<< u << " VEZES"<<endl;

    if(vectorServidores[u]->getNomeServidor() == nome){

      vectorServidores[u]->setDescricaoServidor(descricao);
    }
  }

  cout<<"IMPRIMINDO DESCRICOES DOS SERVIDORES: "<<endl;
  for(int u = 0; u < vectorServidores.size(); u++){
    cout<<"DEBUG: entrou no laço "<<u<<" vezes"<<endl;
    cout<<vectorServidores[u]->getNomeServidor()<<endl;
    cout<<vectorServidores[u]->getDescricaoServidor()<<endl;
  }
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {
  bool encontrouServidor;
  int aux;

  for(int u = 0; u < vectorServidores.size();u++){//ao percorrer o vector, será verificado se o nome do servidor informado pelo usuário realmente existe. Se sim, há a verificação se o usuário logado é o dono do servidor. Caso ambas as condições sejam verdadeiras, o código informado pelo usuário será o código-convite do servidor.

    if(nome == vectorServidores[u]->getNomeServidor()){
      if(usuarioLogadoId == vectorServidores[u]->getUsuarioDonoID()){
          encontrouServidor = true;
          aux = u;
      }
      else{
        cout<<"usuario logado nao eh o dono do servidor."<<endl;
      }

      break;
    }
  }
  if(encontrouServidor == true){
    vectorServidores[aux]->setCodigoConviteServidor(codigo);
    cout << vectorServidores[aux]->getCodigoConviteServidor();
    return "CODIGO CRIADO!";
  }
  else{
    return "erro!";
  }
}

string Sistema::list_servers() {
  cout<<"Imprimindo lista de servidores..."<<endl;
  for(int u = 0; u < vectorServidores.size(); u++){
    cout<<vectorServidores[u]->getNomeServidor()<<endl;
    cout<<"'"<<vectorServidores[u]->getDescricaoServidor()<<"'"<<endl;
  }

  return "";
}

string Sistema::remove_server(const string nome) {

  for (int u=0; u < vectorServidores.size();u++){

    if(nome == vectorServidores[u]->getNomeServidor()){
      vectorServidores.erase (vectorServidores.begin()+ vectorServidores[u]->idServidor - 1);
    }//adicionar ID para cada server
  }
  cout<<nome<<" removido com sucesso."<<endl;
  return "";
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