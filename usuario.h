#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Usuario{
    private:

        string nomeUsuario;
        string emailUsuario;
        string senhaUsuario;

    public:
    
        int idUsuario;

        //CONSTRUTOR
        Usuario(string emailUsuario, string senhaUsuario, string nomeUsuario){
            this->nomeUsuario = nomeUsuario;
            this->emailUsuario = emailUsuario;
            this->senhaUsuario = senhaUsuario;
        }

        string getUsuario(){
          return nomeUsuario;
        }
        string getEmail(){
          return emailUsuario;
        }
        string getSenha(){
          return senhaUsuario;
        }

        int getId(){
          return idUsuario;
        }

        
};
#endif