#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include <iostream>

using namespace std;
/**
* @brief Classe que contempla os métodos do usuário, como construtores, getters e setters.
*/
class Usuario{
    private:
        /**
        * @brief atributo que armazena o nome do usuário.
        */
        string nomeUsuario;
        /**
        * @brief atributo que armazena o email do usuário.
        */
        string emailUsuario;
        /**
        * @brief atributo que armazena a senha do usuário.
        */
        string senhaUsuario;

    public:
        /**
        * @brief armazena o ID de usuário. Começa a partir do número 1.
        */
        int idUsuario;

        /**
        * @brief Método construtor da classe.
        * @param emailUsuario Email do usuário.
        * @param senhaUsuario Senha do usuário.
        * @param nomeUsuario Nome do usuário.
        */
        Usuario(string emailUsuario, string senhaUsuario, string nomeUsuario){
            this->emailUsuario = emailUsuario;
            this->nomeUsuario = nomeUsuario;
            this->senhaUsuario = senhaUsuario;
        }
        /*/DESTRUTOR
        ~Usuario(){
          delete novoUsuario;
        }*/
        /**
        * @brief método get que retorna o nome do usuário.
        */
        string getUsuario(){
          return nomeUsuario;
        }
        /**
        * @brief método get que retorna o email do usuário.
        */
        string getEmail(){
          return emailUsuario;
        }
        /**
        * @brief método get que retorna a senha do usuário.
        */
        string getSenha(){
          return senhaUsuario;
        }
        /**
        * @brief método get que retorna o ID do usuário.
        */
        int getId(){
          return idUsuario;
        }

        
};
#endif