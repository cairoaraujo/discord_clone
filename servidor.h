#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <iostream>

/*
Ok,
Muito boa documentação!
*/
/**
 * @author Cairo Araujo
*/
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
    std::string nomeServidor;
    /**
    * @brief Atributo que armazena o nome do Servidor.
    */
    std::string descricaoServidor;
    /**
    * @brief Atributo que armazena o código convite do Servidor.
    */
    std::string codigoConviteServidor;

  public:
    /**
    * @brief Estrutura de dados Vector que armazena os IDs dos participantes de determinado Servidor.
    */
    std::vector<int> vectorParticipantesIDs;
    /**
    * @brief Estrutura de dados Vector que armazena os nomes dos participantes de determinado Servidor.
    */
    std::vector<std::string> vectorNomeParticipantesServidor;
    /**
    * @brief Estrutura de dados Vector que armazena os canais de voz de determinado Servidor.
    */
    std::vector<std::string> vectorCanalVoz;
    /**
    * @brief Estrutura de dados Vector que armazena os canais de texto de determinado Servidor.
    */
    std::vector<std::string> vectorCanalTexto;

    /**
    * @brief Atributo que guarda o ID do servidor.
    */
    int idServidor;


    /**
    * @brief Método construtor do Servidor
    * @param nomeServidor O nome do Servidor a ser criado, sem espaços.
    */
    Servidor(std::string nomeServidor);
    /**
    * @brief Método get responsável pelo nome do servidor.
    * @return Nome do Servidor
    */
    std::string getNomeServidor();
    /**
    * @brief Método set que armazena a ID logada como sendo o ID do usuário dono do Servidor.
    */
    void setUsuarioDonoID(int idLogada);
    /**
    * @brief Método get responsável pelo ID do dono do Servidor.
    * @return ID do dono do servidor.
    */
    int getUsuarioDonoID();
    /**
    * @brief Método get responsável pela descrição do Servidor.
    * @return ID do dono do servidor.
    */
    std::string getDescricaoServidor();
    /**
    * @brief Método set que armazena a descrição do Servidor informado.
    */
    void setDescricaoServidor(std::string descricaoServidor);
    /**
    * @brief Método get responsável pelo Código convite do Servidor.
    * @return Código convite do Servidor.
    */
    std::string getCodigoConviteServidor();
    /**
    * @brief Método set que armazena o código convite informado pelo usuário do Servidor.
    */
    void setCodigoConviteServidor(std::string codigoServidor);
};

#endif
