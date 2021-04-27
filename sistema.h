#ifndef SISTEMA_H
#define SISTEMA_H
#include <vector>
#include <string>
#include <iostream>
#include "usuario.h"
#include "servidor.h"
#include "canal.h"
#include "mensagem.h"
#include <chrono>
#include <ctime>
#include <time.h>

using namespace std;


/**
 * @author Cairo Araujo
*/
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
     * @brief vector que armazena todos os CANAIS do Concordo.
    */
    vector<CanalTexto*> vectorCanaisTexto;
    /**
     * @brief vector que armazena todos os CANAIS do Concordo.
    */
    vector<CanalVoz*> vectorCanaisVoz;
    /**
     * @brief vector que armazena todas as MENSAGENS DE TEXTO do Concordo.
    */
    vector<Mensagem*> vectorMensagens;
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
    bool estaLogado = false;
    string getHora();
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
     * @brief Função que imprime todos os Canais do servidor onde o usuário está conectado no momento.
    */
    string list_channels();
    /**
     * @brief Função ainda não implementada.
    */
    /**
     * @brief Função que cria um novo Canal, que pode ser de voz ou de texto. O usuário deve informar o **nome** para o canal e o seu tipo: **"texto"** ou **"voz"**, respectivamente. Podem existir Canais de tipos diferentes com o mesmo nome, porém não podem existir sendo do mesmo tipo.
    */
    string create_channel(const string nome, const string tipo);
    /**
     * @brief Função que permite o acesso do canal pelo atual usuário. Essa função armazenará o nome do usuário logado e após isso permitirá as demais funções de Canal para o usuário que entrou. Recebe o **nome do canal** como parâmetro. **Se existirem canais de voz e texto com nomes iguais**, o usuário entrará nos dois simultaneamente.
    */
    string enter_channel(const string nome);
    /**
     * @brief Função que fará a saída do usuário do Canal atual.
    */
    string leave_channel();
    /**
     * @brief Função que enviará uma mensagem para o Canal conectado. Caso o canal seja do tipo **texto**, essa função armazenará a **mensagem**, o **nome do usuário** que enviou, junto com a **data e hora**, podendo ser vista através da função **lista-messages**. Se o canal for de **voz**, apenas armazenará a **última mensagem** enviada no canal.
    */
    string send_message(const string mensagem);
    /**
     * @brief função que listará todas as mensagens do Canal onde o usuário está conectado. Se for um canal de **texto**, mostrará todas as mensagens de texto. Caso o Canal seja de **voz**, mostrará apenas a última mensagem do Canal. E caso exista um canal de mesmo nome para **voz e texto**, imprimirá tanto as mensagens de texto quanto a última mensagem como voz.
    */
    string list_messages();
    /**
     * @brief Função que salva todos os usuários criados durante a execução do Concordo. As informações são exportadas para o arquivo "usuarios.txt" 
    */

    string save_users();
    /**
     * @brief Função que salva todos os servidores criados durante a execução do Concordo. As informações são exportadas para o arquivo "servidores.txt" 
    */
    string save_servers();
    /**
     * @brief Função que salva todos os usuários e servidores criados durante a execução do Concordo. As informações são exportadas para o arquivo "usuarios.txt" e "servidores.txt", respectivamente.
    */
    string save();
    /**
     * @brief Função que fará o carregamento dos usuários previamente salvos em outra sessão do Concordo. Ele carregará a partir do arquivo "usuarios.txt" e recuperará todos os usuários criados anteriormente, automaticamente. 
    */
    string upload_users();
    /**
     * @brief Função que fará o carregamento dos servidores previamente salvos em outra sessão do Concordo. Ele carregará a partir do arquivo "servidores.txt" e recuperará todos os servidores criados anteriormente, automaticamente. 
    */
    string upload_servers();
    /**
     * @brief Função que fará o carregamento tanto dos usuários quanto dos servidores previamente salvos em outra sessão do Concordo. Ele carregará a partir do arquivo "usuarios.txt" e "servidores.txt" e recuperará todos os usuários e servidores criados anteriormente, automaticamente. 
    */
    string upload();
  };

  #endif