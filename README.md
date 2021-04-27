# Concordo - Um elegante clone do Discord. - Versão 1.0

Disciplina: Linguagem de Programação I<br>
Discente: Cairo Bezerra Cortez de Araújo - <a href="https://github.com/cairoaraujo"><b>Github</b></a><br> 
Docente: Júlio Cesar Paulino de Melo<br>

#### OBS: Para acessar a Documentação completa do Concordo, acesse a pasta 'Documentacao' e procure pelo formato rtf(documento Word), html (abrir o arquivo index.html por algum navegador) ou LaTeX.

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

### Funções de Canal

- **Create-channel:** Função que cria um novo Canal, que pode ser de voz ou de texto. O usuário deve informar o **nome** para o canal e o seu tipo: **"texto"** ou **"voz"**, respectivamente. Podem existir Canais de tipos diferentes com o mesmo nome, porém não podem existir sendo do mesmo tipo.

- **enter-channel:** Função que permite o acesso do canal pelo atual usuário. Essa função armazenará o nome do usuário logado e após isso permitirá as demais funções de Canal para o usuário que entrou. Recebe o **nome do canal** como parâmetro. **Se existirem canais de voz e texto com nomes iguais**, o usuário entrará nos dois simultaneamente.

- **leave-channel:** Função que fará a saída do usuário do Canal atual.

- **list-channels:** Função que imprimirá todos os canais do Servidor conectado.

- **send-message:** Função que enviará uma mensagem para o Canal conectado. Caso o canal seja do tipo **texto**, essa função armazenará a **mensagem**, o **nome do usuário** que enviou, junto com a **data e hora**, podendo ser vista através da função **lista-messages**. Se o canal for de **voz**, apenas armazenará a **última mensagem** enviada no canal.

- **list-messages:** função que listará todas as mensagens do Canal onde o usuário está conectado. Se for um canal de **texto**, mostrará todas as mensagens de texto. Caso o Canal seja de **voz**, mostrará apenas a última mensagem do Canal. E caso exista um canal de mesmo nome para **voz e texto**, imprimirá tanto as mensagens de texto quanto a última mensagem como voz.

## Implementações

### A1.1 - Sair do sistema
- O quesito A1.1 é implementado na classe Sistema, no método **quit()** (linha 14 em sistema.cpp);
### A1.2 - Criar usuário
- O quesito A1.1 é implementado na classe Sistema, no método **create-user()** (linha 18 em sistema.cpp);
### A1.3 - Entrar no sistema
- O quesito A1.3 é implementado na classe Sistema, no método **login()** (linha 59 em sistema.cpp);

### A2.1 - Desconectar do Concordo
- O quesito A2.1 é implementado na classe Sistema, no método **disconnect()** (linha 89 em sistema.cpp);
### A2.2 - Criar servidores (nome)
- O quesito A2.2 é implementado na classe Sistema, no método **create-server()** (linha 99 em sistema.cpp);
### A2.3 - Mudar a descrição do servidor
- O quesito A2.3 é implementado na classe Sistema, no método **set-server-desc()** (linha 120 em sistema.cpp);
### A2.4 - Setar código de convite para o servidor
- O quesito A2.4 é implementado na classe Sistema, no método **set-server-desc()** (linha 136 em sistema.cpp);
### A2.5 - Listar servidores
- O quesito A2.5 é implementado na classe Sistema, no método **list-servers()** (linha 166 em sistema.cpp);
### A2.6 - Remover servidor
- O quesito A2.6 é implementado na classe Sistema, no método **remove-server()** (linha 177 em sistema.cpp);
### A2.7 - Entrar em um servidor
- O quesito A2.7 é implementado na classe Sistema, no método **enter-server()** (linha 204 em sistema.cpp);
### A2.8 - Sair do servidor
- O quesito A2.8 é implementado na classe Sistema, no método **leave-server()** (linha 249 em sistema.cpp);
### A2.9 - Listar pessoas no servidor
- O quesito A2.9 é implementado na classe Sistema, no método **list-participants()** (linha 259 em sistema.cpp);

### B1.1 - Listar canais do servidor (de áudio ou texto)
- O quesito B1.1 é implementado na classe Sistema, no método **list-channels()** (linha 340 em sistema.cpp);
### B1.2 - Criar um canal do servidor 
- O quesito B1.2 é implementado na classe Sistema, no método **create-channel()** (linha 362 em sistema.cpp);
## B1.3 - Entrar em um canal
- O quesito B1.3 é implementado na classe Sistema, no método **enter-channel()** (linha 417 em sistema.cpp);
## B1.4 - Sair do canal:
- O quesito B1.4 é implementado na classe Sistema, no método **leave-channel()** (linha 450 em sistema.cpp);
## B2.1 - Enviar mensagem para o canal
- O quesito B2.1 é implementado na classe Sistema, no método **send-message()** (linha 476 em sistema.cpp);
## B2.2 - Visualizar mensagens do canal:
- O quesito B2.2 é implementado na classe Sistema, no método **list-messages()** (linha 502 em sistema.cpp);

<br>

## C1 - Implementar Persistência dos dados em disco
- O quesito C1.1 é implementado na classe Sistema, nos métodos **save-users(), save-servers() e save()** (linha 495 em sistema.cpp);

## C2 - Implementar restauração dos dados do disco na inicialização do sistema
- O quesito C1.1 é implementado na classe Sistema, no método **upload-users(), upload-servers() e upload()** (linha 566 em sistema.cpp);


<br>

## Exemplos de uso

#### 1 - Criando 2 usuários, depois logando no usuário 1 e criando um servidor. Em seguida, acessando o servidor e criando uma descrição e um código convite. Após isso, desconectar do usuário 1 e logar com o usuário 2, entrar no servidor usando o código convite e listar participantes e servidores.

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


