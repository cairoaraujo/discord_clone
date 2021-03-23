#ifndef SERVIDOR_H
#define SERVIDOR_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Servidor{
  private:
    int usuarioDonoID;
    string nomeServidor;
    string descricaoServidor;
    string codigoConviteServidor;
    //vector<Canal> canais;
    vector<int> participantesIDs;
  public:
    int idServidor;
  //CONSTRUTOR SEM PARAMETROS:
    Servidor(string nomeServidor){
      this->nomeServidor = nomeServidor;
    }
  
    string getNomeServidor(){
      return nomeServidor;
    }

    void setUsuarioDonoID(int idLogada){
      this->usuarioDonoID = idLogada;
    }
    int getUsuarioDonoID(){
      return usuarioDonoID;
    }
    string getDescricaoServidor(){
      return this->descricaoServidor;
    }
    void setDescricaoServidor(string descricaoServidor){
      this->descricaoServidor = descricaoServidor;
    }

    string getCodigoConviteServidor(){
      return codigoConviteServidor;
    }
    void setCodigoConviteServidor(string codigoServidor){
      codigoConviteServidor = codigoServidor;
    }
};

#endif
