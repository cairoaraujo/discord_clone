#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
* @brief Classe que contempla atributos e métodos dos Servidores do Concordo.
*/
class Servidor{
  private:
    /**
    * @brief Atributo que armazena o ID do usuário dono do Servidor.
    */
    int usuarioDonoID;
    /**
    * @brief Atributo que armazena o nome do Servidor.
    */
    string nomeServidor;
    /**
    * @brief Atributo que armazena o nome do Servidor.
    */
    string descricaoServidor;
    /**
    * @brief Atributo que armazena o código convite do Servidor.
    */
    string codigoConviteServidor;

  public:
    /**
    * @brief Estrutura de dados Vector que armazena os IDs dos participantes de determinado Servidor.
    */
    vector<int> vectorParticipantesIDs;
    /**
    * @brief Estrutura de dados Vector que armazena os nomes dos participantes de determinado Servidor.
    */
    vector<string> vectorNomeParticipantesServidor;
    /**
    * @brief Atributo que guarda o ID do servidor.
    */
    int idServidor;
    /**
    * @brief Método construtor do Servidor
    * @param nomeServidor O nome do Servidor a ser criado, sem espaços.
    */
    Servidor(string nomeServidor){
      this->nomeServidor = nomeServidor;
    }
    /**
    * @brief Método get responsável pelo nome do servidor.
    * @return Nome do Servidor
    */
    string getNomeServidor(){
      return nomeServidor;
    }
    /**
    * @brief Método set que armazena a ID logada como sendo o ID do usuário dono do Servidor.
    */
    void setUsuarioDonoID(int idLogada){
      this->usuarioDonoID = idLogada;
    }
    /**
    * @brief Método get responsável pelo ID do dono do Servidor.
    * @return ID do dono do servidor.
    */
    int getUsuarioDonoID(){
      return usuarioDonoID;
    }
    /**
    * @brief Método get responsável pela descrição do Servidor.
    * @return ID do dono do servidor.
    */
    string getDescricaoServidor(){
      return this->descricaoServidor;
    }
    /**
    * @brief Método set que armazena a descrição do Servidor informado.
    */
    void setDescricaoServidor(string descricaoServidor){
      this->descricaoServidor = descricaoServidor;
    }
    /**
    * @brief Método get responsável pelo Código convite do Servidor.
    * @return Código convite do Servidor.
    */
    string getCodigoConviteServidor(){
      return codigoConviteServidor;
    }
    /**
    * @brief Método set que armazena o código convite informado pelo usuário do Servidor.
    */
    void setCodigoConviteServidor(string codigoServidor){
      codigoConviteServidor = codigoServidor;
    }
};

#endif
