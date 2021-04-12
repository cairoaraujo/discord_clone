#include "canal.h"
#include "servidor.h"
#include "mensagem.h"
#include "sistema.h"
#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

    Mensagem::Mensagem(std::string donoMensagem, std::string conteudoMensagem, std::string nomeServidor, std::string nomeCanal){
        this -> donoMensagem = donoMensagem;
        this -> conteudoMensagem = conteudoMensagem;
        this -> nomeServidor = nomeServidor;
        this -> nomeCanal = nomeCanal;
        this -> horario = setHora();
    };
    string Mensagem::getMensagem(){
        return conteudoMensagem;
    }

string Mensagem::getDonoMensagem(){
        return donoMensagem;
    }

void Mensagem::setDonoMensagem(string usuario){
    donoMensagem = usuario;
    }

string Mensagem::getNomeServidor(){
        return nomeServidor;
    }

string Mensagem::getNomeCanal(){
        return nomeCanal;
    }

string Mensagem::setHora(){
    time_t timer;
    time(&timer);
        return ctime(&timer);
    }

string Mensagem::getHorario(){
        return horario;
    }