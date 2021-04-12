#ifndef MENSAGEM_H
#define MENSAGEM_H
#include <vector>
#include <string>
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;



class Mensagem{
    private:
        std::string tempo;
        std::string donoMensagem;
        std::string conteudoMensagem;
        std::string nomeServidor;
        std::string nomeCanal;
        std::string horario;
    public:
        Mensagem(std::string donoMensagem, std::string conteudoMensagem, std::string nomeServidor, std::string nomeCanal){
            this -> donoMensagem = donoMensagem;
            this -> conteudoMensagem = conteudoMensagem;
            this -> nomeServidor = nomeServidor;
            this -> nomeCanal = nomeCanal;
            this -> horario = setHora();
        };

        std::string getMensagem(){
            return conteudoMensagem;
        }

        std::string getDonoMensagem(){
            return donoMensagem;
        }

        void setDonoMensagem(std::string usuario){
            donoMensagem = usuario;
        }

        std::string getNomeServidor(){
            return nomeServidor;
        }

        std::string getNomeCanal(){
            return nomeCanal;
        }

        std::string setHora(){
            time_t timer;
            time(&timer);
            return ctime(&timer);
        }

        std::string getHorario(){
            return horario;
        }

};

#endif