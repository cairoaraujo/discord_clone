#include "usuario.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

//CONSTRUTOR
Usuario::Usuario(string emailUsuario, string senhaUsuario, string nomeUsuario){
    this->emailUsuario = emailUsuario;
    this->nomeUsuario = nomeUsuario;
    this->senhaUsuario = senhaUsuario;
}

//DESTRUTOR
/*Usuario::~Usuario(){
    delete //novoUsuario;    
}*/

string Usuario::getUsuario(){
    return nomeUsuario;
}
string Usuario::getEmail(){
    return emailUsuario;
}
string Usuario::getSenha(){
    return senhaUsuario;
}

int Usuario::getId(){
    return idUsuario;
}
