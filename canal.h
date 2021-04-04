#ifndef CANAL_H
#define CANAL_H
#include <vector>
#include <string>
#include <iostream>

class Canal{

    private:
        std::string nomeCanal;
        std::string tipoCanal;

    public:
        //construtor
        Canal(std::string nomeCanal, std::string tipoCanal){
            this->nomeCanal = nomeCanal;
            this->tipoCanal = tipoCanal;
        };

        std::string getNomeCanal(){
            return nomeCanal;
        }


};

//class CanalTexto : public Canal{

//};

//class CanalVoz : public Canal{

//};

#endif