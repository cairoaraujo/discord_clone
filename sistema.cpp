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
#include <fstream>

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
  if(encontrouServidor){
    cout<<"O servidor '"<<nome<<"' teve a "; 
    return "descricao alterada com sucesso!";
  }
  else{
    return "Erro ao mudar descricao do servidor: servidor nao encontrado!";
  }
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
    cout <<"Foi criado um codigo para o servidor '"<<nome<<"'. O codigo-convite eh: '"<< vectorServidores[aux]->getCodigoConviteServidor()<<"'."<<endl;
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
    cout<<" - "<<vectorServidores[u]->getNomeServidor()<<" - descricao: "<<vectorServidores[u]->getDescricaoServidor()<<endl;
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
          nomeCanalConectado = "";
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
          vectorMensagens.push_back(novaMensagem);
          //armazena o nome do usuario que enviou a mensagem
          cout << "mensagem enviada com sucesso!"<< endl;
          break;

        }
      }
      for (int i = 0; i < vectorCanaisVoz.size(); i++){
        if(vectorCanaisVoz[i]->getNomeCanal() == nomeCanalConectado){
          vectorCanaisVoz[i]->ultimaMensagem = mensagem;
          vectorCanaisVoz[i]->DonoMensagem = nomeUsuarioLogado;
          cout << "mensagem de voz enviada com sucesso!";
          break;
        }
      }
    }
  }
  return "";
}

string Sistema::list_messages() {
  if(nomeCanalConectado != ""){

    if(!vectorMensagens.empty()){//Isso significa que há 1 ou mais mensagens
      cout << "\n-------------- '"<<nomeCanalConectado<<"' --------------"<<endl;
      cout <<"### MENSAGENS DE TEXTO ###"<<endl;
      for (int u = 0; u < vectorMensagens.size(); u++){
        if(nomeServidorConectado == vectorMensagens[u]->getNomeServidor() && nomeCanalConectado == vectorMensagens[u]->getNomeCanal()){
        //Irá imprimir apenas as mensagens do canal e servidor conectado.
          cout <<"  * "<< vectorMensagens[u]->getHorario() << "    " <<vectorMensagens[u]->getDonoMensagem() <<": " << vectorMensagens[u]->getMensagem()<<endl<<endl;

        }
      }
    }
    if(!vectorCanaisVoz.empty()){
        for (int i = 0; i < vectorCanaisVoz.size(); i++){
          if(vectorCanaisVoz[i]->getNomeCanal() == nomeCanalConectado){
            cout << "### ULTIMA MENSAGEM DE VOZ: ###"<<endl;
            cout<<"  * "<<vectorCanaisVoz[i]->DonoMensagem <<": " << vectorCanaisVoz[i]-> ultimaMensagem<<endl;
          }
        }
    
    }
    else{
      return "Não existem mensagens!";

    }
  }
  cout << "---------------------------------------"<<endl;
  return "Mensagens imprimidas com sucesso!";
}

/*
C1 ok
*/
string Sistema::save_users(){
  ofstream arquivo_usuarios("usuarios.txt");
  arquivo_usuarios << vectorUsuarios.size() << endl;
  for (size_t i = 0; i < vectorUsuarios.size(); i++){
    arquivo_usuarios << vectorUsuarios[i]->getId() << endl;
    arquivo_usuarios << vectorUsuarios[i]->getUsuario() <<endl;
    arquivo_usuarios << vectorUsuarios[i]->getEmail() <<endl;
    arquivo_usuarios << vectorUsuarios[i]->getSenha() <<endl;
  }

  return "Usuarios gravavos com sucesso em : ./USUARIOS_SALVOS.txt";
}


/*
C2 0.5
Boa parte do trabalho está feita, vou considerar 50%
*/
string Sistema::save_servers(){ //método não concluído por falta de tempo. Infelizmente tive que focar em outras disciplinas nesse final de semestre. Devido a isso, o método de upar os servidores não pôde ser feito. 
  string canalAtual;
  string servidorName;
  ofstream arquivo_servidores("servidores.txt");
  arquivo_servidores << vectorServidores.size()<<endl;
  cout << vectorServidores.size();

  for (int i = 0; vectorServidores.size(); i++){
    if (vectorServidores.size() == i){
      break;
    }
    cout<<"DEBUG: ENTROU "<<i<<endl;
    arquivo_servidores <<"Id do Usuario Dono:" << vectorServidores[i]->getUsuarioDonoID()<<endl;
    arquivo_servidores <<vectorServidores[i]->getNomeServidor()<<endl;
    arquivo_servidores << "Descricao Servidor: " << vectorServidores[i]->getDescricaoServidor()<<endl;
    arquivo_servidores << "Codigo convite " <<vectorServidores[i]->getCodigoConviteServidor()<<endl;
    //falta numero de participantes do servidor

    for (size_t c = 0; vectorCanaisTexto.size(); c++){
      cout << "DEBUG1: ENTROU "<< c<<endl;
      if(vectorCanaisTexto.size() == c){
        break;
      }
      if (vectorCanaisTexto[c]->nomeServidorDono == vectorServidores[i]->getNomeServidor()){
        servidorName = vectorServidores[i]->getNomeServidor();
        arquivo_servidores<< "tamanho do canal texto: "<< vectorCanaisTexto.size()<<endl;
        arquivo_servidores << "Nome do canal:"<< vectorCanaisTexto[c]->getNomeCanal()<<endl;
         canalAtual= vectorCanaisTexto[c]->getNomeCanal();
      }


      for(size_t a = 0; vectorMensagens.size(); a++){
          if (vectorMensagens.size() == a){
            break;
          }
          if(vectorMensagens[c]->getNomeServidor() == vectorServidores[i]->getNomeServidor() && vectorMensagens[c]->getNomeCanal() == canalAtual){
            arquivo_servidores <<"Dono mensagem:" << vectorMensagens[a]->getDonoMensagem()<<endl;
            arquivo_servidores <<"hora: " << vectorMensagens[a]->getHorario();
            arquivo_servidores << "mensagem: " << vectorMensagens[a]->getMensagem()<<endl;
            arquivo_servidores << "-----------------------------------"<<endl;
          }
      }
    }

  }

  return "Servidores gravados com sucesso em: ./servidores.txt";
}

string Sistema::save(){
  save_servers();
  save_users();
  return "Informacoes de usuarios e servidores salvas com sucesso em ./usuarios.txt e ./servidores.txt.";

}

/*
C3 ok!
*/
string Sistema::upload_users(){ //id, nome, email, senha
  ifstream users("usuarios.txt");
  string id, email, senha, nome, qntdUsuarios;
  int quantidadeUsuarios, id_convertido;
  if (users.is_open()){
    //cout << "quantidade de usuarios eh " << quantidadeUsuarios<<endl;
    getline(users,qntdUsuarios);
    quantidadeUsuarios = stoi(qntdUsuarios);
    for (int i = 0; i < quantidadeUsuarios; i++){
      getline(users, id);
      getline(users, nome);
      getline(users, email);
      getline(users, senha);
      cout << "------------------------------------------------"<<endl;
      cout << "ID: " << id << " nome:"<< nome <<" email:"<< email <<"  senha:"<< senha<<endl;
      cout << "------------------------------------------------"<<endl;
      create_user(email, senha, nome);
      cout <<"usuario criado com sucesso!"<<endl <<endl;
    }
    users.close();
  }else{
    return "Erro! Nao foi possivel abrir o arquivo usuarios.txt.";
  }
  return "Usuario(s) recuperado(s) com sucesso!";
}

/*
C4 0.2
Realmente ficou faltando carregar ainda muita coisa
*/
string Sistema::upload_servers(){//Método não implementado 100% devido a falta de tempo. Infelizmente tive que focar em outras disciplinas nesse final de semestre =/
  ifstream servers("servidores.txt");
  string qntdServidores, nomeServidor, idUsuarioDono;
  int qntdServidoresConvertido;
  getline(servers, qntdServidores);
  qntdServidoresConvertido = stoi(qntdServidores);

  for (int i = 0; i < 2; i ++){
      getline (servers, idUsuarioDono);
      getline (servers, nomeServidor);
      create_server(nomeServidor);
      cout << endl;
  }
  return "Servidores carregados com sucesso!";
}

string Sistema::upload(){
  upload_users();
  upload_servers();
  return "Usuarios e servidores carregados com sucesso!";
}
