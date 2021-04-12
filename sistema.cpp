#include "sistema.h"
#include "usuario.h"
#include "servidor.h"
#include "canal.h"
#include "mensagem.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;


/* COMANDOS */

/*
A1.1 ok
Bem, aqui era um bom ponto para vc destruir os elementos que estão nos vetores onde vc usou new.
*/

string Sistema::quit() {
  return "Saindo...";
}

/*
A1.2 ok, 0.8
Vou tirar pontos pelos erros de indentação!
*/
string Sistema::create_user (const string email, const string senha, const string nome) {
    bool emailJaUsado; //variável de controle para verificar se email ja foi usado ou não. Retorna true se sim.

    if(!vectorUsuarios.empty()){ //se  já existem usuários criados...
      for (int u=0; u < vectorUsuarios.size(); u++){
        if (email == vectorUsuarios[u]->getEmail()){
          cout<<"O email "<<email<<" ja foi cadastrado!"<<endl;
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
    cout << "Usuario "<<nome<<" <"<<email<<"> ";
    return "cadastrado com sucesso!";
}


/*
A1.3 ok
Acho que vc entendeu depois, mas a ideia era o comando retornar alguma coisa para o executor imprimir.
*/

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


/*
A2.1 Ok
*/
string Sistema::disconnect() {
  if (estaLogado == true){
    estaLogado = false;
    return "Usuario desconectado com sucesso!";
  }
  else{
    return "não existe usuario logado! Faça o login antes!";
  }
}

/*
A2.2 Ok!
*/
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

/*
A2.3 Ok
aqui é um bom ponto pra vc usar lambda
*/
string Sistema::set_server_desc(const string nome, const string descricao) {
  bool encontrouServidor = false;
  int aux;
  for (int u=0; u < vectorServidores.size();u++){//Percorre o vector e verifica se existe o servidor informado.
    if(vectorServidores[u]->getNomeServidor() == nome){

      vectorServidores[u]->setDescricaoServidor(descricao);
      encontrouServidor = true;
    }
  }
  if(encontrouServidor){
    cout<<"O servidor '"<<nome<<"' teve a "; 
    return "descricao alterada com sucesso!";
  }
  else{
    return "Erro ao mudar descricao do servidor: servidor nao encontrado!";
  }
}

/*
A2.4 ok,
outro bom lugar pra usar lambda
*/

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
    cout <<"Foi criado um codigo para o servidor '"<<nome<<"'. O codigo-convite eh: '"<< vectorServidores[aux]->getCodigoConviteServidor()<<"'."<<endl;
    return "Codigo-convite criado com sucesso!";
  }
  else{
    return "Erro!";
  }
}


/*
A2.5 ok
*/
string Sistema::list_servers() {
  cout<<"Imprimindo lista de servidores..."<<endl;
  cout<<"\n";
  for(int u = 0; u < vectorServidores.size(); u++){
    cout<<" - "<<vectorServidores[u]->getNomeServidor()<<" - descricao: "<<vectorServidores[u]->getDescricaoServidor()<<endl;
    cout<<"\n";
  }

  return "";
}

/*
A2.6 0.5
Acho que vc entendeu errado, o usuário só pode remover o servidor se ele for o dono, vc não testou isso. Vou considerar 50%
*/
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


/*
A2.6 ok
*/
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
          estaConectado = true; //já deveria estar true nesse ponto
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

/*
A2.8 ok
*/
string Sistema::leave_server() {
  if(nomeServidorConectado != ""){//Isso significa que o usuário está conectado a algum servidor, pois o nome != de vazio
    nomeServidorConectado = "";
    return "Sucesso ao sair do servidor!";
  }
  else{ //Se o nome do server conectado for vazio, isso quer dizer que o usuário não está conectado a nenhum server.
    return "Erro ao sair de servidor! Voce não esta conectado a nenhum!";
  }
}

/*
A2.9 ok
*/
string Sistema::list_participants() {
  int aux;
  if(nomeServidorConectado != ""){
    for(int u = 0; u < vectorServidores.size(); u++){
      if (nomeServidorConectado == vectorServidores[u]->getNomeServidor()){
        aux = u;
      }
      else{
        if(u == vectorServidores.size()){ //essa condição nunca vai acontecert rsrsrs...
          return "erro ao imprimir participantes do servidor.";
        }
      }
    }
  }
  else{
    return "Erro ao imprimir participantes do Servidor.";
  }
  cout <<"Imprimindo participantes...\n";
  for (int i = 0; i < vectorServidores[aux]->vectorParticipantesIDs.size(); i++){
    cout <<" - "<< vectorServidores[aux]->vectorNomeParticipantesServidor[i]<<endl;
  }
  
  if(estaConectado)
    return "\nLista de participantes imprimida com sucesso!";
  else
    return "Erro ao imprimir!";
}

string Sistema::list_channels() {
  cout << "----------- IMPRIMINDO CANAIS DE VOZ: -----------"<<endl;
  for (int u = 0; u < vectorCanaisVoz.size(); u++){
    if(vectorCanaisVoz[u]->nomeServidorDono == nomeServidorConectado){
      cout <<"  *"<<vectorCanaisVoz[u]->getNomeCanal()<<endl;
      cout << "SERVIDOR DONO: "<< vectorCanaisVoz[u]->nomeServidorDono<<endl;
      cout << endl;
    }

  }
  cout << "---------- IMPRIMINDO CANAIS DE TEXTO: ----------"<<endl;
  for (int u = 0; u < vectorCanaisTexto.size(); u++){
    if(vectorCanaisTexto[u]->nomeServidorDono == nomeServidorConectado){
      cout <<"  *"<<vectorCanaisTexto[u]->getNomeCanal()<<endl;
      cout << "SERVIDOR DONO: "<< vectorCanaisTexto[u]->nomeServidorDono<<endl;
      cout << endl;
    }
  }

  return "Canais impressos com sucesso!";
}

string Sistema::create_channel(const string nome, const string tipo) {
  bool canalExiste;
  if(estaLogado){
      if(nomeServidorConectado != ""){//Isso significa que o usuário está conectado a algum servidor, pois o nome != de vazio
        if(tipo == "texto"){
          for (int u = 0; u < vectorCanaisTexto.size(); u ++){//verificar se o nome do canal ja existe no servidor conectado
            if(nome == vectorCanaisTexto[u]->getNomeCanal() && nomeServidorConectado == vectorCanaisTexto[u]->nomeServidorDono){
              canalExiste = true;
            }
          }
          if(!canalExiste){
            CanalTexto *novoCanal = new CanalTexto(nome);
            vectorCanaisTexto.push_back(novoCanal);
            novoCanal -> nomeServidorDono = nomeServidorConectado;
            return "CANAL DE TEXTO CRIADO COM SUCESSO!";
          }
          else if(canalExiste){
            return "Erro! o Servidor ja possui um canal de texto com esse nome!";
          }

        }
        else if(tipo == "voz"){
          for (int u = 0; u < vectorCanaisVoz.size(); u ++){//verificar se o nome do canal ja existe no servidor conectado
            if(nome == vectorCanaisVoz[u]->getNomeCanal() && nomeServidorConectado == vectorCanaisVoz[u]->nomeServidorDono){
              canalExiste = true;
            }
          }
          if(!canalExiste){
            CanalVoz *novoCanal = new CanalVoz(nome);
            vectorCanaisVoz.push_back(novoCanal);
            novoCanal -> nomeServidorDono = nomeServidorConectado;
            return "CANAL DE VOZ CRIADO COM SUCESSO!";
          }
          else if(canalExiste){
            return "Erro! o Servidor ja possui um canal de voz com esse nome!";
          }

        }
        else{
          return "Erro na criacao do canal. Voce precisa informar o tipo! (texto ou voz)";
        }

      }

      else{ //Se o nome do server conectado for vazio, isso quer dizer que o usuário não está conectado a nenhum server.
        return "Erro ao criar um canal! Voce não esta conectado a nenhum Servidor!";
      }
  }
  else{
    return "Erro ao criar canal!";
  }
  
  return " ";
}

/*string Sistema::enter_channel(const string nome) {
  bool usuarioRepetido;
  int aux;

  if(nomeServidorConectado != ""){//significa que está conectado a algum servidor

    //Percorrer no vector de Canal de voz
    for (int u = 0; u < vectorCanaisVoz.size(); u++){
      if(vectorCanaisVoz[u]->nomeServidorDono == nomeServidorConectado){

        if (nome == vectorCanaisVoz[u]->getNomeCanal()){
          for (int i = 0; i < vectorCanaisVoz[u]->vectorParticipantesCanalVoz.size()+1; i++){
            cout<<"DEBUG: ENTROU NESSE FOR" <<endl;
            if(nomeUsuarioLogado == vectorCanaisVoz[u]->vectorParticipantesCanalVoz[i]){
              cout<<"ENTROU NESSE IF"<<endl;
              usuarioRepetido = true;
              aux = u;
            }
            else{
              usuarioRepetido = false;
            }
          }
        }
      }
    }
    if(!usuarioRepetido){
      vectorCanaisVoz[aux]->vectorParticipantesCanalVoz.push_back(nomeUsuarioLogado);
      nomeCanalConectado = nome;
      //cout << "DEBUG: " << vectorCanaisVoz[u]->vectorParticipantesCanalVoz[0]<<endl;
      cout << "Usuario entrou no canal de voz com sucesso!" << endl;
    }
    else{
      return "Usuario ja existe no canal de voz!";
    }
    //Percorrer no vector de Canal de Texto
    for (int u = 0; u < vectorCanaisTexto.size(); u++){
      if(vectorCanaisTexto[u]->nomeServidorDono == nomeServidorConectado){
        if (nome == vectorCanaisTexto[u]->getNomeCanal()){
          vectorCanaisTexto[u]->vectorParticipantesCanalTexto.push_back(nomeUsuarioLogado);
          aux = u;
          nomeCanalConectado = nome;
          //cout << "DEBUG: " << vectorCanaisTexto[u]->vectorParticipantesCanalTexto[0]<<endl;
          cout << "Usuario entrou no canal de texto com sucesso!"<<endl;
        }
      }
    }
  }
  else{
    return "voce nao esta conectado a nenhum servidor!";
  }



  return " ";
}*/
string Sistema::enter_channel(const string nome) {
  int aux;
  if(nomeServidorConectado != ""){//significa que está conectado a algum servidor
    //Percorrer no vector de Canal de voz
    for (int u = 0; u < vectorCanaisVoz.size(); u++){
      if (nome == vectorCanaisVoz[u]->getNomeCanal()){
        vectorCanaisVoz[u]->vectorParticipantesCanalVoz.push_back(nomeUsuarioLogado);
        aux = u;
        nomeCanalConectado = nome;
        cout << "DEBUG: " << vectorCanaisVoz[u]->vectorParticipantesCanalVoz[0]<<endl;
        cout << "Usuario entrou no canal de voz com sucesso!" << endl;
      }
    }
    //Percorrer no vector de Canal de Texto
    for (int u = 0; u < vectorCanaisTexto.size(); u++){
      if (nome == vectorCanaisTexto[u]->getNomeCanal()){
        vectorCanaisTexto[u]->vectorParticipantesCanalTexto.push_back(nomeUsuarioLogado);
        aux = u;
        nomeCanalConectado = nome;
        cout << "DEBUG: " << vectorCanaisTexto[u]->vectorParticipantesCanalTexto[0]<<endl;
        cout << "Usuario entrou no canal de texto com sucesso!"<<endl;
      }
    }
  }
  else{
    return "voce nao esta conectado a nenhum servidor!";
  }



  return " ";
}

string Sistema::leave_channel() {
  bool saiuCanal;

  if(nomeServidorConectado != ""){//verifica se o usuário está conectado a algum servidor.
    cout<< "DEBUG: ENTROU NO 1 IF"<<endl;
    for (int u=0; u < vectorCanaisVoz.size();u++){//Percorro o vector de canal de voz e confiro se o nome do usuario conectado está em algum canal de voz do servidor atual.
      for (int i = 0; i < vectorCanaisVoz[u]->vectorParticipantesCanalVoz.size(); i ++){
        if(nomeUsuarioLogado == vectorCanaisVoz[u]->vectorParticipantesCanalVoz[i] && nomeServidorConectado == vectorCanaisVoz[u]->nomeServidorDono){
          vectorCanaisVoz.erase (vectorCanaisVoz.begin() + u);
          saiuCanal = true;
          cout << "DEBUG: USUARIO SAIU DO CANAL!"<< endl;
          cout <<nomeServidorConectado<<endl;
          cout << vectorCanaisVoz[u]->vectorParticipantesCanalVoz[i]<<endl;
        }
      }
    }
  }
  else{
    return "Nao eh possivel remover servidor estando desconectado.";
  }

  return "Usuario saiu do canal com sucesso!";

}

string Sistema::send_message(const string mensagem) {
  if(nomeServidorConectado != ""){//reforçando verificações...
    if(nomeCanalConectado != ""){
      for (int u = 0; u < vectorCanaisTexto.size(); u ++){
        if(vectorCanaisTexto[u]->nomeServidorDono == nomeServidorConectado){
          Mensagem  *novaMensagem = new Mensagem(nomeUsuarioLogado, mensagem, nomeServidorConectado, nomeCanalConectado);
          //vectorMensagens[u]->getTempo();
          vectorMensagens.push_back(novaMensagem);

          //armazena o nome do usuario que enviou a mensagem


          return "mensagem enviada com sucesso!";
        }
      }
    }
  }
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
  if(nomeCanalConectado != ""){
    if(!vectorMensagens.empty()){//Isso significa que há 1 ou mais mensagens
      cout << "----- IMPRIMINDO MENSAGENS DO CANAL '"<<nomeCanalConectado<<"' : -----"<<endl;
      for (int u = 0; u < vectorMensagens.size(); u++){
        if(nomeServidorConectado == vectorMensagens[u]->getNomeServidor() && nomeCanalConectado == vectorMensagens[u]->getNomeCanal()){
        //Irá imprimir apenas as mensagens do canal e servidor conectado.
          cout <<"  * "<< vectorMensagens[u]->getHorario() << "    " <<vectorMensagens[u]->getDonoMensagem() <<": " << vectorMensagens[u]->getMensagem()<<endl<<endl;

        }
      }
    }
    else{
      return "Não existem mensagens!";

    }
  }
  cout << "-----------------------------------------------------"<<endl;
  return "Mensagens imprimidas com sucesso!";
}


/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */
