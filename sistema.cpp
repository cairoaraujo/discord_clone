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
      cout << vectorUsuarios[u]->getEmail()<<" - ID: ";
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
          cout<<"Usuario '"<<vectorUsuarios[u]->getEmail()<<"' logado com sucesso!"<<endl;
          estaLogado = true;
          usuarioLogadoId = vectorUsuarios[u]->idUsuario;
          nomeUsuarioLogado = vectorUsuarios[u]->getUsuario();
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
    //há a criação do objeto novoServidor de forma dinâmica
    Servidor  *novoServidor = new Servidor(nome);
    //o atributo idServidor do objeto novoServidor recebe o valor da variável servidorID
    novoServidor->idServidor = servidorID;
    //adiciono o objeto no final do vectorServidores
    vectorServidores.push_back(novoServidor);
    //armazeno o ID do usuário dono do server a partir da ID do usuario logado
    novoServidor->setUsuarioDonoID(usuarioLogadoId);
    cout<<"ID do usuario que criou o servidor '"<<novoServidor->getNomeServidor()<<"': "<<novoServidor->getUsuarioDonoID()<<endl;
    cout<<"ID do servidor:"<<novoServidor->idServidor<<endl;

    //armazeno o nome do usuario que entrou no servidor
    vectorServidores[novoServidor->idServidor - 1]->vectorNomeParticipantesServidor.push_back(nomeUsuarioLogado);

    //armazeno o id do usuario que entrou no servidor
    //vectorServidores[novoServidor->idServidor]->vectorParticipantesIDs.push_back(usuarioLogadoId);

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

    //cout<<"DEBUG: ENTROU "<< u << " VEZES"<<endl;

    if(vectorServidores[u]->getNomeServidor() == nome){

      vectorServidores[u]->setDescricaoServidor(descricao);
    }
  }

  cout<<"IMPRIMINDO DESCRICOES DOS SERVIDORES: "<<endl;
  for(int u = 0; u < vectorServidores.size(); u++){
    //cout<<"DEBUG: entrou no laço "<<u<<" vezes"<<endl;
    cout<<vectorServidores[u]->getNomeServidor()<<endl;
    cout<<vectorServidores[u]->getDescricaoServidor()<<endl;
  }
  return " ";
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
    cout <<"Foi criado um codigo para o servidor: "<< vectorServidores[aux]->getCodigoConviteServidor();
    return "Codigo-convite criado com sucesso!";
  }
  else{
    return "erro!";
  }
}

string Sistema::list_servers() {
  cout<<"Imprimindo lista de servidores..."<<endl;
  for(int u = 0; u < vectorServidores.size(); u++){
    cout<<vectorServidores[u]->getNomeServidor()<<" - descricao: "<<vectorServidores[u]->getDescricaoServidor()<<endl;
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
  return "REMOVE-SERVER NAO IMPLEMENTADO 100% (HA BUGS!)";
}

string Sistema::enter_server(const string nome, const string codigo) {
  //O laço percorrerá o vector e irá verificar se o nome do servidor existe. Se existir, verificará se o código informado pelo usuário é o código-convite do servidor. Se sim, o usuário logado será adicionado ao vectorParticipantesIDs.
  for (int u = 0; u < vectorServidores.size();u++){

    if(vectorServidores[u]->getNomeServidor() == nome){

      if (codigo == vectorServidores[u]->getCodigoConviteServidor()){
        //armazeno o nome do usuario que entrou no servidor
        vectorServidores[u]->vectorNomeParticipantesServidor.push_back(nomeUsuarioLogado);

        //armazeno o id do usuario que entrou no servidor
        vectorServidores[u]->vectorParticipantesIDs.push_back(usuarioLogadoId);

        //armazena o nome do servidor que o usuário está conectado atualmente
        nomeServidorConectado = vectorServidores[u]->getNomeServidor();

        return "Usuario entrou no servidor";
      }
      else{
        cout <<"Codigo errado. Tente novamente."<<endl;
      }
    }
    /*else{
      cout <<"Nenhum servidor encontrado."<<endl;
    }*/
  }
  return " ";
}

string Sistema::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants() {
  int aux;
  for(int u = 0; u < vectorServidores.size(); u++){
    if (nomeServidorConectado == vectorServidores[u]->getNomeServidor()){
      aux = u;
    }
    /*else{
      return "erro ao imprimir participantes do servidor.";
    }*/
  }
  for (int i = 0; i < vectorServidores[aux]->vectorParticipantesIDs.size(); i++){
    cout << vectorServidores[aux]->vectorNomeParticipantesServidor[i]<<endl;
  }
  return " ";
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