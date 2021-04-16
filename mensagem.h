#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;


/*
* ok, 0.8 
* vou tirar pontos de indentação do Mensagem.cpp
*/
class Mensagem{
    private:
        /**
        * @brief atributo que armazena o nome do remetente da mensagem
        */
        std::string donoMensagem;
        /**
        * @brief atributo que armazena o o texto que existe na mensagem
        */
        std::string conteudoMensagem;
        /**
        * @brief atributo que armazena o nome do Servidor que o canal existe
        */
        std::string nomeServidor;
        /**
        * @brief atributo que armazena o nome do Canal para onde a mensagem será enviada
        */
        std::string nomeCanal;
        /**
        * @brief atributo que armazena o horário da mensagem
        */
        std::string horario;
    public:
        /**
        * @brief Método construtor parametrizado, cujo recebe 4 parâmetros:
        * @param donoMensagem Remetente da mensagem.
        * @param conteúdoMensagem Conteúdo da mensagem de texto.
        * @param nomeServidor Nome do servidor onde o Canal existe.
        * @param nomeCanal Nome do Canal para onde a mensagem será enviada.
        */
        Mensagem(std::string donoMensagem, std::string conteudoMensagem, std::string nomeServidor, std::string nomeCanal);
        /**
        * @brief Método get que retorna o conteúdo da mensagem
        */
        std::string getMensagem();

        /**
        * @brief Método get que retorna o nome do remetente da mensagem
        */
        std::string getDonoMensagem();

        /**
        * @brief Método set que atribui o nome do remetente da mensagem
        */
        void setDonoMensagem(std::string usuario);

        /**
        * @brief Método get que retorna o nome do Servidor onde o Canal está criado
        */
        std::string getNomeServidor();

        /**
        * @brief Método get que retorna o nome do Canal para qual a mensagem será enviada
        */
        std::string getNomeCanal();
        /**
        * @brief Método set que irá captar a data e hora do sistema do usuário para registrar na mensagem
        */
        std::string setHora();
        /**
        * @brief Método que retorna a data e hora do envio da mensagem
        */
        std::string getHorario();


};

#endif
