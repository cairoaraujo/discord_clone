#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include <iostream>

/**
* @brief Classe que contempla os métodos do usuário, como construtores, getters e setters.
*/
class Usuario{
    private:
        /**
        * @brief atributo que armazena o nome do usuário.
        */
        std::string nomeUsuario;
        /**
        * @brief atributo que armazena o email do usuário.
        */
        std::string emailUsuario;
        /**
        * @brief atributo que armazena a senha do usuário.
        */
        std::string senhaUsuario;

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
        Usuario(std::string emailUsuario, std::string senhaUsuario, std::string nomeUsuario);
        /**
         * @brief Método destrutor da classe. 
        */
        ~Usuario();
        /**
        * @brief método get que retorna o nome do usuário.
        */
        std::string getUsuario();
        /**
        * @brief método get que retorna o email do usuário.
        */
        std::string getEmail();
        /**
        * @brief método get que retorna a senha do usuário.
        */
        std::string getSenha();
        /**
        * @brief método get que retorna o ID do usuário.
        */
        int getId();   
};
#endif