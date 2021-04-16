#ifndef CANAL_H
#define CANAL_H
#include <vector>
#include <string>
#include <iostream>


/**
 * @author Cairo Araujo
*/
/**
* @brief Classe que contempla os métodos dos canais, tanto de voz quanto de texto. Possui atributos e métodos (construtores, getters e setters).
*/

/*
0.8
vou tirar 20% pela desorganização das classes derivadas
*/

class Canal{

    protected:
        /**
        * @brief atributo que armazena o nome do canal.
        */
        std::string nomeCanal;
        /**
        * @brief atributo que armazena o tipo do canal.
        */
        std::string tipoCanal;

    public:
        /**
        * @brief Construtor padrão
        */        
        Canal(){

        };
        /**
        * @brief Construtor parametrizado. Recebe 2 parâmetros:
        * @param nomeCanal
        * @param tipoCanal
        */
        Canal(std::string nomeCanal, std::string tipoCanal){
            this->nomeCanal = nomeCanal;
            this->tipoCanal = tipoCanal;
        };

        /**
        * @brief Método get que retorna o nome do canal.
        */
        std::string getNomeCanal(){
            return nomeCanal;
        };

        /**
        * @brief variável que armazena em qual Servidor está o Canal
        */
        std::string nomeServidorDono;




};

/**
* @brief Classe derivada da Classe Canal. É responsável por atributos e métodos dos canais de texto.
*/
/*
0.8
ok
*/
class CanalTexto : public Canal{
    public:
      //std::vector<std::string> vectorCanalTexto;
      std::vector<std::string> vectorParticipantesCanalTexto;
      CanalTexto(std::string nomeCanal);
};

/**
* @brief Classe derivada da Classe Canal. É responsável por atributos e métodos dos canais de voz.
*/
/*
0.9
ok
*/
class CanalVoz : public Canal{
    public:
      //std::vector<std::string> vectorCanalVoz;
      std::vector<std::string> vectorParticipantesCanalVoz;
      CanalVoz(std::string nomeCanal);
      std::string ultimaMensagem;
      std::string DonoMensagem;

};

#endif
