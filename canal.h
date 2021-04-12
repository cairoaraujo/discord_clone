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

class Canal{

    protected:
        std::string nomeCanal;
        std::string tipoCanal;

    public:
        //construtor
        Canal(){

        };
        //construtor parametrizado
        Canal(std::string nomeCanal, std::string tipoCanal){
            this->nomeCanal = nomeCanal;
            this->tipoCanal = tipoCanal;
        };


        std::string getNomeCanal(){
            return nomeCanal;
        };


        std::string nomeServidorDono;




};

class CanalTexto : public Canal{
    public:
      //std::vector<std::string> vectorCanalTexto;
      std::vector<std::string> vectorParticipantesCanalTexto;
      CanalTexto(std::string nomeCanal);
};

class CanalVoz : public Canal{
    public:
      //std::vector<std::string> vectorCanalVoz;
      std::vector<std::string> vectorParticipantesCanalVoz;
      CanalVoz(std::string nomeCanal);
      std::string ultimaMensagem;
      std::string DonoMensagem;

};

#endif