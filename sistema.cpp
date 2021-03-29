#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;


/* COMANDOS */

string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
    bool emailJaUsado; //variável de controle para verificar se email ja foi usado ou não. Retorna true se sim.

    if(!vectorUsuarios.empty()){ //se  já existem usuários criados...
      for (int u=0; u < vectorUsuarios.size(); u++){
        if (email == vectorUsuarios[u]->getEmail()){
          cout<<"O email ja foi cadastrado!"<<endl;
          emailJaUsado = true;
          break;
        }  
      }

      if(!emailJaUsado){ //se o email nao foi utilizado ainda, há a criação de um novo usuário
        usuarioID++;
        Usuario  *novoUsuario = new Usuario (email, senha, nome);
        novoUsuario->idUsuario = usuarioID;
        vectorUsuarios.push_back(novoUsuario);
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
    if(vectorUsuarios.empty()){ //se ainda não há usuários criados...
      usuarioID++;
      Usuario  *novoUsuario = new Usuario (email, senha, nome);
      novoUsuario->idUsuario = usuarioID;
      vectorUsuarios.push_back(novoUsuario);
    }

    return "Usuario cadastrado com sucesso";
}


string Sistema::login(const string email, const string senha) {
  if(estaLogado == false){//verifica se já existe algum usuário logado no sistema. Se sim, impede de fazer um novo login

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
    cout <<"Já existe um usuario logado! Desconecte do usuario atual e tente novamente!"<<endl;
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
    Servidor  *novoServidor = new Servidor(nome); //há a criação do objeto novoServidor de forma dinâmica
    novoServidor->idServidor = servidorID;
    vectorServidores.push_back(novoServidor);
    novoServidor->setUsuarioDonoID(usuarioLogadoId);

    /*armazeno o nome do usuario que entrou no servidor
    vectorServidores[novoServidor->idServidor - 1]->vectorNomeParticipantesServidor.push_back(nomeUsuarioLogado);*/
    //armazeno o id do usuario que entrou no servidor
    //vectorServidores[novoServidor->idServidor]->vectorParticipantesIDs.push_back(usuarioLogadoId);

    cout <<"O servidor '"<<novoServidor->getNomeServidor() << "'(ID = " << novoServidor->idServidor << ")";
    return " foi criado com sucesso!";
  }
  else{
    return "Para criar um servidor, é preciso estar logado!";
  }
}

string Sistema::set_server_desc(const string nome, const string descricao) {
  bool encontrouServidor = false;
  int aux;
  for (int u=0; u < vectorServidores.size();u++){//Percorre o vector e verifica se existe o servidor informado.
    if(vectorServidores[u]->getNomeServidor() == nome){

      vectorServidores[u]->setDescricaoServidor(descricao);
      encontrouServidor = true;
    }
  }
  if(encontrouServidor)
    return "Descricao alterada com sucesso!";
  else
    return "Erro ao mudar descricao do servidor: servidor nao encontrado!";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {
  bool encontrouServidor;
  int aux;
  //Ao percorrer o vector, será verificado se o nome do servidor informado pelo usuário realmente existe. 
  //Se sim, há a verificação se o usuário logado é o dono do servidor. 
  //Caso ambas as condições sejam verdadeiras, o código informado pelo usuário será o código-convite do servidor.
  for(int u = 0; u < vectorServidores.size();u++){

    if(nome == vectorServidores[u]->getNomeServidor()){
      if(usuarioLogadoId == vectorServidores[u]->getUsuarioDonoID()){
          encontrouServidor = true;
          aux = u;
      }
      else{
        cout<<"Usuario logado nao eh o dono do servidor."<<endl;
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
    return "Erro!";
  }
}

string Sistema::list_servers() {
  cout<<"Imprimindo lista de servidores..."<<endl;
  cout<<"\n";
  for(int u = 0; u < vectorServidores.size(); u++){
    cout<<vectorServidores[u]->getNomeServidor()<<" - descricao: "<<vectorServidores[u]->getDescricaoServidor()<<endl;
    cout<<"\n";
  }

  return "";
}

string Sistema::remove_server(const string nome) {
  bool removeuServidor = false;
  //percorrerá o vectorServidores e irá verificar se o nome do servidor informado pelo usuário existe. Se sim, irá remover e em seguida ajustar o index dos servidores à direita do removido.
  if(estaLogado == true){
    for (int u=0; u < vectorServidores.size();u++){
      if(nome == vectorServidores[u]->getNomeServidor()){
        vectorServidores.erase (vectorServidores.begin() + u);
        removeuServidor = true;
        if(nome == nomeServidorConectado){
          nomeServidorConectado = "";
        }
      }
    }
    if(removeuServidor){
      cout <<nomeServidorConectado;
      cout<<nome;
      return " removido com sucesso!";
    }
    else{
      return "Não foi possivel remover o servidor informado.";
    }
  }
  else{
    return "Nao eh possivel remover servidor estando desconectado.";
  }
}

string Sistema::enter_server(const string nome, const string codigo= "vazio") {

  //O laço percorrerá o vector e irá verificar se o nome do servidor existe. Se existir, verificará se o código informado pelo usuário é o código-convite do servidor. Se sim, o usuário logado será adicionado ao vectorParticipantesIDs.
  bool encontrouServidor = false;
  bool usuarioRepetido = false;
  for (int u = 0; u < vectorServidores.size();u++){
    if(vectorServidores[u]->getNomeServidor() == nome){
      if (codigo == vectorServidores[u]->getCodigoConviteServidor()){

        for (int i = 0; i < vectorServidores[u]->vectorNomeParticipantesServidor.size(); i ++){//laço que verificará se o usuário já está nesse servidor
          if(vectorServidores[u]->vectorNomeParticipantesServidor[i] == nomeUsuarioLogado){
            usuarioRepetido = true;
          }
        }
        if(!usuarioRepetido){
          //armazeno o nome do usuario que entrou no servidor
          vectorServidores[u]->vectorNomeParticipantesServidor.push_back(nomeUsuarioLogado);

          //armazeno o id do usuario que entrou no servidor
          vectorServidores[u]->vectorParticipantesIDs.push_back(usuarioLogadoId);

          //armazena o nome do servidor que o usuário está conectado atualmente
          nomeServidorConectado = vectorServidores[u]->getNomeServidor();
          encontrouServidor = true;
          estaConectado = true;
          return "Usuario entrou no servidor.";
        }
        else{
          return "O usuario ja esta no servidor!";
        }

      }
      else{
        return "Codigo errado. Tente novamente.";
      }
    }
  }
  if(encontrouServidor){
    return "deu certo!";
  }
  else{
    return "ERRO!";
  }
}

string Sistema::leave_server() {
  if(nomeServidorConectado != ""){//Isso significa que o usuário está conectado a algum servidor, pois o nome != de vazio
    nomeServidorConectado = "";
    return "Sucesso ao sair do servidor!";
  }
  else{ //Se o nome do server conectado for vazio, isso quer dizer que o usuário não está conectado a nenhum server.
    return "Erro ao sair de servidor! Voce não esta conectado a nenhum!";
  }
}

string Sistema::list_participants() {
  int aux;
  if(nomeServidorConectado != ""){
    for(int u = 0; u < vectorServidores.size(); u++){
      if (nomeServidorConectado == vectorServidores[u]->getNomeServidor()){
        aux = u;
      }
      else{
        if(u == vectorServidores.size()){
          return "erro ao imprimir participantes do servidor.";
        }
      }
    }
  }
  else{
    return "ERRO AO IMPRIMIR";
  }
  cout <<"Imprimindo participantes...\n";
  for (int i = 0; i < vectorServidores[aux]->vectorParticipantesIDs.size(); i++){
    cout << vectorServidores[aux]->vectorNomeParticipantesServidor[i]<<endl;
  }
  
  if(estaConectado)
    return "\nLista de participantes imprimida com sucesso!";
  else
    return "Erro ao imprimir!";
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