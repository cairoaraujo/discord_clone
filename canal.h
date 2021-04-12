#ifndef CANAL_H
#define CANAL_H
#include <vector>
#include <string>
#include <iostream>

class Canal{

    protected:
        std::string nomeCanal;
        std::string tipoCanal;

    public:
        //construtor
        Canal(){

        };
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
      std::vector<std::string> vectorMensagens;
};

class CanalVoz : public Canal{
    public:
      //std::vector<std::string> vectorCanalVoz;
      std::vector<std::string> vectorParticipantesCanalVoz;
      CanalVoz(std::string nomeCanal);
      std::string ultimaMensagem;

};

#endif