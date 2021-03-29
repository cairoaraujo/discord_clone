#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "usuario.h"
#include "servidor.h"

using namespace std;

/**
 *  @brief Classe onde se concentra todas as operações do Concordo
*/
class Sistema {
  private:
    /**
     * @brief vector que armazena todos os Usuarios do Concordo.
    */
    vector<Usuario*> vectorUsuarios;
    /**
     * @brief vector que armazena todos os Servidores do Concordo.
    */
    vector<Servidor*> vectorServidores;
    /**
     * @brief Variável que armazena o nome do Usuario logado atualmente.
    */
    string nomeUsuarioLogado;
    /**
     * @brief se 0: não logado, caso contrário guarda o id do usuário logado
    */
    int usuarioLogadoId;
    /**
     * @brief Variável que armazena o nome do servidor atualmente conectado pelo usuário.
    */
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
   * @brief Método para criação de um novo usuário. Caso o usuário não informe algum dos parâmetros, o mesmo ficará vazio, porém o cadastro ainda funcionará.
   * @param email Email do usuário, sem espaços.
   * @param senha Senha do usuário. Aceita letras, símbolos e números, mas sem espaços.
   * @param Nome Nome do usuário. Aceita espaços.
  */
  string create_user (const string email, const string senha, const string nome);
  /**
   * @brief Método que realiza o login de usuário no Concordo.
   * @param email Email do usuário, sem espaços.
   * @param senha Senha do usuário. Aceita letras, símbolos e números, mas sem espaços. 
   * @return Caso o usuário não exista, o login retornará erro. Caso contrário, o usuário entrará no Concordo. 
  */
  string login(const string email, const string senha);
  /**
   * @brief Método que realiza a desconexão do atual usuário.
   * @return Caso exista usuário logado, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro.
  */
  string disconnect();
  /**
   * @brief Método que realiza a criação de um novo servidor. É preciso estar logado com algum usuário antes.
   * @param nome Nome do servidor, sem espaços.
   * @return Caso haja usuário logado, retornará mensagem de sucesso, caso contrário, mensagem de erro. 
  */
  string create_server(const string nome);
  /**
   * @brief Método que realiza a criação de uma descrição para o servidor informado. Aceita espaços.
   * @param nome Nome do Servidor que deseja adicionar a descrição, sem espaços.
   * @param descricao Descrição desejada para o Servidor. 
   * @return Caso encontre o Servidor informado, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro. 
  */
  string set_server_desc(const string nome, const string descricao);
  /**
   * @brief Método que realiza a criação de um código convite para o servidor informado. Para isso, **o usuário logado deve ser o dono do servidor**. Não aceita espaços.
   * @param nome Nome do Servidor que deseja adicionar o código convite, sem espaços.
   * @param codigo Código convite que deseja adicionar ao servidor. 
   * @return Caso encontre o Servidor informado, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro. 
  */
  string set_server_invite_code(const string nome, const string codigo);
  /**
   * @brief Método que realiza a impressão de todos os servidores existentes no Concordo
  */
  string list_servers();
  /**
   * @brief Método que realiza a remoção de um servidor.
   * @param nome Nome do Servidor que deseja-se excluir.
   * @return Caso encontre o Servidor informado, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro. 
  */
  string remove_server(const string nome);
  /**
   * @brief Método que realiza a entrada do usuário logado ao servidor informado.
   * @param nome Nome do Servidor que deseja entrar.
   * @param codigo Código convite do servidor. Caso não haja, deixar em branco. 
   * @return Caso encontre o Servidor informado e o código informado esteja correto, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro. 
  */
  string enter_server(const string nome, const string codigo);
  /**
   * @brief Método que realiza a remoção do usuário logado ao servidor informado.
   * @return Caso o usuário esteja em algum servidor, retornará mensagem de sucesso. Caso contrário, retornará mensagem de erro.
  */
  string leave_server();
  /**
   *@brief Método que imprimirá a lista de participantes do servidor atual onde o usuário está conectado.
   *@return Lista de participantes do servidor. Se não houver participantes, imprimirá vazio.
  */
  string list_participants();
  /**
   * @brief Função ainda não implementada.
  */
  string list_channels();
  /**
   * @brief Função ainda não implementada.
  */
  string create_channel(const string nome, const string tipo);
  /**
   * @brief Função ainda não implementada.
  */
  string enter_channel(const string nome);
  /**
   * @brief Função ainda não implementada.
  */
  string leave_channel();
  /**
   * @brief Função ainda não implementada.
  */
  string send_message(const string mensagem);
  /**
   * @brief Função ainda não implementada.
  */
  string list_messages();
};

#endif