#include "servidor.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

Servidor::Servidor(string nomeServidor){
      this->nomeServidor = nomeServidor;
}

string Servidor::getNomeServidor(){
    return nomeServidor;
}

void Servidor::setUsuarioDonoID(int idLogada){
    this->usuarioDonoID = idLogada;
}

int Servidor::getUsuarioDonoID(){
    return usuarioDonoID;
}

string Servidor::getDescricaoServidor(){
    return this->descricaoServidor;
}

void Servidor::setDescricaoServidor(string descricaoServidor){
    this->descricaoServidor = descricaoServidor;
}

string Servidor::getCodigoConviteServidor(){
    return codigoConviteServidor;
}

void Servidor::setCodigoConviteServidor(string codigoServidor){
    codigoConviteServidor = codigoServidor;
}