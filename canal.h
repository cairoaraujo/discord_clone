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
        }


};

class CanalTexto : public Canal{
    public:
      CanalTexto(std::string nomeCanal);
      std::vector<std::string> vectorMensagens;
};

class CanalVoz : public Canal{
    public:
      CanalVoz(std::string nomeCanal);
      std::string ultimaMensagem;
};

#endif