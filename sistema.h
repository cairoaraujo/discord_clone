#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

// Sistema deve concentrar todas as operações do Concordo
class Sistema {
  private:
    //precisa guardar uma coleção de servidores;
    //precisa guardar uma coleção de usuários;
    int usuarioLogadoId; // se 0: não logado, caso contrário guarda o id do usuário logado
    string nomeServidorConectado;
    string nomeCanalConectado;

  public:

  string quit();
  string create_user (const string email, const string senha, const string nome);
  string login(const string email, const string senha);
  string disconnect();
  string create_server(const string nome);
  string set_server_desc(const string nome, const string descricao);
  string set_server_invite_code(const string nome, const string codigo);
  string list_servers();
  string remove_server(const string nome);
  string enter_server(const string nome, const string codigo);
  string leave_server();
  string list_participants();
  string list_channels();
  string create_channel(const string nome, const string tipo);
  string enter_channel(const string nome);
  string leave_channel();
  string send_message(const string mensagem);
  string list_messages();
};

#endif