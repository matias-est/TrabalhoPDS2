# Sistema de Avaliação de Filmes 
## Apresentação do Problema 
Atualmente, a indústria cinematográfica foi tomada por sistemas de avaliações de filmes focados na caracterização do avaliador. Ou seja, as pessoas têm avaliado os filmes pensando não só no filme mas também no que as outras pessoas vão pensar sobre a avaliação dela. Por isso, desenvolvemos um sistema que busca preservar o anonimato e a sinceridade, mas ao mesmo tempo permitindo com que cada usuário tenha seu próprio perfil dentro da plataforma.

Este projeto visa desenvolver um sistema de avaliação de filmes que busca resgatar a sinceridade e preservar o semi-anonimato do usuário, ao mesmo tempo em que permite a personalização de perfis.

## Visão Geral da Solução
O nosso Sistema de Avaliação de Filmes foi desenvolvido em C++ e é operado via interface de terminal. Ele permite que os usuários criem contas fornecendo nome completo e data de nascimento; esses dados pessoais são mantidos em sigilo. Para interação pública, o nome de usuário segue o padrão (personagem de filme) (sobrenome do usuário), buscando um equilíbrio entre personalização e anonimato, garantindo a liberdade para os usuários efetuarem comentários honestos.

## Funcionalidades Implementadas
Cadastro e Login de Usuários: Criação de contas seguras e sistema de autenticação.

Geração de Nomes de Usuário Criativos: Geração automática de um nome público (Personagem Sobrenome) para preservar a identidade do usuário.

Cadastro de Filmes: Permite adicionar filmes com Título, Gênero e Data de Lançamento. O sistema evita a duplicidade de filmes com títulos similares.

Avaliação de Filmes: Permite dar notas de 1 a 5. O sistema impede que um usuário avalie o mesmo filme mais de uma vez.

Comentários: Usuários podem adicionar comentários textuais em cada filme.

Consulta de Filmes:

Busca de filmes por título (com tratamento para ignorar maiúsculas/minúsculas e espaços).

Listagem de filmes por gênero.

Visualização de informações detalhadas, incluindo média de notas e todas as avaliações e comentários.

Sistema de Recomendação: Sugere filmes ao usuário com base nas melhores médias de avaliação entre os filmes que ele ainda não avaliou.

Persistência de Dados: Todas as informações (usuários, filmes, avaliações) são salvas em arquivos .txt ao fechar o programa e recarregadas ao iniciar, garantindo que os dados não sejam perdidos entre as sessões.

## Estrutura do Projeto

A estrutura de diretórios planejada para o projeto é:

🗂️ SistemaAvaliacaoFilmes \
┣ 📄 README.md \
┣ 📄 user_stories.md \
┣ 📄 crc_cards.md \
┣ 📄 makefile \
┣ 📁 src/ \
┃ ┣ 📄 main.cpp \
┃ ┣ 📄 usuario.h \
┃ ┣ 📄 usuario.cpp \
┃ ┣ 📄 filme.h \
┃ ┣ 📄 filme.cpp \
┃ ┣ 📄 avaliacao.h \
┃ ┗ 📄 avaliacao.cpp \
┗ 

---
## Instruções de Instalação

###  Pré-requisitos

* C++11 ou superior.
* Compilador g++ (ou outro compatível com C++11).
* Makefile.

##  Passos para Instalação

1.  **Clone o repositório:**
    * Abra o seu terminal ou prompt de comando.
    * Use o comando `git clone` para baixar uma cópia do projeto do GitHub para o seu computador.
      
        ```bash
        git clone [https://github.com/matias-est/TrabalhoPDS2.git](https://github.com/matias-est/TrabalhoPDS2.git)
        ```
    * Após o download ser concluído, entre na pasta do projeto que foi criada:
      
        ```bash
        cd TrabalhoPDS2
        ```
    * Depois na pasta principal :
      
        ```bash
        cd Sistema_de_Avaliacao_de_Filmes
        ```

2.  **Compile o projeto:**
    * Dentro da pasta do projeto (`TrabalhoPDS2`), utilize o comando `make` para compilar o código-fonte.
      
        ```bash
        make
        ```
    
3.  **Execute o programa:**
    * Após a compilação bem-sucedida, um arquivo executável chamado avaliador será criado.
    * Para rodar o programa, execute o seguinte comando no terminal, ainda dentro da pasta do projeto:
      
        ```bash
        ./avaliador
        ```

## Como Contribuir

Se desejar contribuir ou reportar problemas:
1.  Para bugs ou sugestões de funcionalidades, crie uma "Issue" no repositório GitHub.
2.  Se desejar contribuir com código:
    * Faça um "Fork" do repositório.
    * Crie uma nova "Branch" para sua funcionalidade ou correção (git checkout -b minha-funcionalidade).
    * Faça seus "Commits" seguindo um padrão claro de mensagens.
    * Envie um "Pull Request" para a branch principal.

---

Desenvolvedores:

* Matias Machado de Faria
* Evandro Eurico Morais Penido
* Arthur de Almeida Souza
* Gustavo Marques Mendes
* Bernardo Marques Mendes
