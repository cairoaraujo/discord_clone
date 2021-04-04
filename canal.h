#ifndef CANAL_H
#define CANAL_H
#include <vector>
#include <string>
#include <iostream>

class Canal{

    private:
        std::string nomeCanal;

    public:
        //construtor
        Canal();

        std::string getNomeCanal(){
            return nomeCanal;
        }


};

class CanalTexto : public Canal{

};

class CanalVoz : public Canal{

};

#endif