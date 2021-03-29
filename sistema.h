#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "usuario.h"
#include "servidor.h"

using namespace std;

// Sistema deve concentrar todas as operações do Concordo
class Sistema {
  private:
    //vector que armazena usuarios
    vector<Usuario*> vectorUsuarios;

    //vector que armazena servidores
    vector<Servidor*> vectorServidores;
    string nomeUsuarioLogado;
    int usuarioLogadoId; // se 0: não logado, caso contrário guarda o id do usuário logado
    string nomeServidorConectado;
    string nomeCanalConectado;

  public:
  
  int usuarioID = 0;
  int servidorID = 0;
  bool estaConectado;
  bool estaLogado;
  /**
   * Sairá imediatamente do Concordo.
  */
  string quit();
  /**
   * A função espera os parâmetros "Email" "Senha" e "Nome", respectivamente. 
   O email e senha não devem possuir espaços, porém o Nome pode conter. 
   Caso o usuário não informe algum dos parâmetros, o mesmo ficará vazio, porém o cadastro ainda funcionará.
  */
  string create_user (const string email, const string senha, const string nome);
  /**
   * Espera-se que o usuário informe o **email** e **Senha**, respectivamente. 
   Caso o usuário não exista, o login retornará erro. 
   Caso contrário, o usuário entrará no Concordo. 
   O sistema aceita somente 1 usuário por vez, então caso haja o comando **login** já com algum usuário logado,
   a função retornará erro.
  */
  string login(const string email, const string senha);
  /**
   * Irá desconectar o usuário logado. Caso não haja usuário logado, a função retornará erro.
  */
  string disconnect();
  /**
   * Função que cria um novo servidor, cujo recebe como parâmetro apenas o nome do servidor fornecido pelo usuário. 
   É necessário que haja algum usuário logado, caso contrário, retornará um erro.
  */
  string create_server(const string nome);
  /**
   * Com o usuário logado, essa função poderá adicionar uma descrição para o servidor informado pelo usuário.
   O parâmetro da funação receberá do usuário respectivamente o **nome do servidor** e a **descrição**. 
   A descrição pode ser alterada por qualquer usuário e, por default, a descrição de um servidor é vazia.
  */
  string set_server_desc(const string nome, const string descricao);
  /**
   * Com usuário dono do servidor logado, essa função criará um código-convite de determinado servidor. 
   Assim, a única forma de acessar o servidor é informando esse código. 
   O usuário deve informar, respectivamente, o **nome do servidor** e o **código convite desejado**.
   */
  string set_server_invite_code(const string nome, const string codigo);
  /**
   * Imprime todos os servidores já criados, com suas respectivas descrições. 
   Caso a descrição esteja vazia, não imprimirá a descrição.
   */
  string list_servers();
  /**
   * Remove o servidor informado. Recebe como parâmetro o **nome do servidor** que deseja-se remover. 
   Retornará mensagem de erro caso o servidor informado não exista.
  */
  string remove_server(const string nome);
  /**
   * Função que fará o usuário logado entrar em determinado servidor já criado. 
   Para usar a função, o usuário deve informar o **nome do servidor** e o **código convite**, respectivamente. 
   Caso o servidor específico não possua código convite, não é necessário informar esse parâmetro.
  */
  string enter_server(const string nome, const string codigo);
  /**
   * A função leave-server irá remover o usuário logado do servidor atual.
    Assim, caso o usuário deseje acessar o servidor novamente, será preciso usar a função enter-server.
  */
  string leave_server();
  /**
   * Essa função imprimirá a lista de participantes do servidor atual onde o usuário está conectado.
  */
  string list_participants();
  /**
   * Função ainda não implementada.
  */
  string list_channels();
  /**
   * Função ainda não implementada.
  */
  string create_channel(const string nome, const string tipo);
  /**
   * Função ainda não implementada.
  */
  string enter_channel(const string nome);
  /**
   * Função ainda não implementada.
  */
  string leave_channel();
  /**
   * Função ainda não implementada.
  */
  string send_message(const string mensagem);
  /**
   * Função ainda não implementada.
  */
  string list_messages();
};

#endif