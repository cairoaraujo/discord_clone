# Concordo - Um elegante clone do Discord. - Versão 1.0

Disciplina: Linguagem de Programação I<br>
Discente: Cairo Bezerra Cortez de Araújo<br>
Docente: Júlio Cesar Paulino de Melo<br>


## Para compilar

O projeto do concordo possui Makefile, o que facilita  o processo de compilação. Para compilar, basta usar a seguinte linha de comando:

```console
make concordo
```

## Para executar
Você pode rodar o sistema e em logo depois digitar os comandos seguidos de ENTER
```console
./concordo
```

Ou pode criar um arquivo de texto com uma lista de comandos (um por linha) e executar o sistema redirecionando esse arquivo como entrada padrão:
```console
./concordo < script_comandos.txt
```
## Usando o Concordo
O Concordo possui as seguintes funções:

### Funções de Usuário:

- **create-user:** a função espera os parâmetros "Email" "Senha" e "Nome", respectivamente. O email e senha não devem possuir espaços, porém o Nome pode conter. Caso o usuário não informe algum dos parâmetros, o mesmo ficará vazio, porém o cadastro ainda funcionará.

- **login:** Espera-se que o usuário informe o "Email" e "Senha", respectivamente. Caso o usuário não exista, o login retornará erro. Caso contrário, o usuário entrará no Concordo. O sistema aceita somente 1 usuário por vez, então caso haja o comando **login** já com algum usuário logado, a função retornará erro. 

- **disconnect:** Irá desconectar o usuário logado. Caso não haja usuário logado, a função retornará erro.

- **quit:** Sairá imediatamente do Concordo.

### Funções de Servidor:

- **Create-server:** Função que cria um novo servidor, cujo recebe como parâmetro apenas o nome do servidor fornecido pelo usuário. É necessário que haja algum usuário logado, caso contrário, retornará um erro.

- **Enter-server:** Função que fará o usuário logado entrar em determinado servidor já criado. Para usar a função, o usuário deve informar o **nome do servidor** e o **código convite**, respectivamente. Caso o servidor específico não possua código convite, não é necessário informar esse parâmetro.

- **Leave-server:** a função leave-server irá remover o usuário logado do servidor atual. Assim, caso o usuário deseje acessar o servidor novamente, será preciso usar a função enter-server.

- **Remove-server:** Remove o servidor informado. Recebe como parâmetro o **nome do servidor** que deseja-se remover. Retornará mensagem de erro caso o servidor informado não exista.

- **List-participants:** Essa função imprimirá a lista de participantes do servidor atual onde o usuário está conectado.

- **List-servers:**: Imprime todos os servidores já criados, com suas respectivas descrições. Caso a descrição esteja vazia, não imprimirá a descrição.

- **Set-server-desc:** Com o usuário logado, essa função poderá adicionar uma descrição para o servidor informado pelo usuário. O parâmetro da funação receberá do usuário respectivamente o **nome do servidor** e a **descrição**. A descrição pode ser alterada por qualquer usuário e, por default, a descrição de um servidor é vazia.

- **Set-server-invite-code:** Com usuário dono do servidor logado, essa função criará um código-convite de determinado servidor. Assim, a única forma de acessar o servidor é informando esse código. O usuário deve informar, respectivamente, o **nome do servidor** e o **código convite desejado.

## Exemplos de uso

#### 1 - Criando 2 usuários e 1 servidor. Em seguida, os 2 usuários acessam o servidor, onde se altera a sua descrição e adiciona um código-convite.

```console
create-user usuario@email.com senha Fulano de Tal
create-user usuario2@email.com senha2 Ciclano de Tal
login usuario@email.com senha
create-server Servidor1
enter-server Servidor1
set-server-desc Um servidor do Concordo
set-server-invite-code Servidor1 codigoParaServidor1
disconnect
login usuario2@email.com senha2
enter-server Servidor1 codigoParaServidor1
list-participants
list-servers
```


