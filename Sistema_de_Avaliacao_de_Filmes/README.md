# 🎬 Sistema de Avaliação de Filmes 🎬

## 🎞️ Apresentação do Problema 🎞️

Atualmente, a indústria cinematográfica foi tomada por sistemas de avaliações de filmes focados na caracterização do avaliador. Ou seja, as pessoas têm avaliado os filmes pensando não só no filme mas também no que as outras pessoas vão pensar sobre a avaliação dela. Por isso, desenvolvemos um sistema que busca preservar o anonimato e a sinceridade, mas ao mesmo tempo permitindo com que cada usuário tenha seu próprio perfil dentro da plataforma.

Este projeto visa desenvolver um sistema de avaliação de filmes que busca resgatar a sinceridade e preservar o semi-anonimato do usuário, ao mesmo tempo em que permite a personalização de perfis.

---

## 🚀 Visão Geral da Solução

O nosso Sistema de Avaliação de Filmes foi desenvolvido em C++ e é operado via interface de terminal. Ele permite que os usuários criem contas fornecendo nome completo e data de nascimento; esses dados pessoais são mantidos em sigilo. Para interação pública, o nome de usuário segue o padrão (personagem de filme) (sobrenome do usuário), buscando um equilíbrio entre personalização e anonimato, garantindo a liberdade para os usuários efetuarem comentários honestos.

---

## 🛠️ Funcionalidades Implementadas

- Cadastro e Login de Usuários: Criação de contas seguras e sistema de autenticação.
- Geração de Nomes de Usuário Criativos: Nome público (Personagem Sobrenome) gerado automaticamente.
- Cadastro de Filmes: Título, Gênero e Data de Lançamento. Evita duplicidade de títulos similares.
- Avaliação de Filmes: Notas de 1 a 5. Impede múltiplas avaliações por usuário.
- Comentários: Comentários textuais por filme.
- Consulta de Filmes:
  - Busca por título (ignora caixa e espaços).
  - Listagem por gênero.
  - Visualização de média de notas, avaliações e comentários.
- Sistema de Recomendação: Sugere filmes com as melhores médias não avaliados ainda.
- Persistência de Dados: Informações salvas em arquivos `.txt` entre sessões.

---

## 🗂️ Estrutura do Projeto

🗂️ SistemaAvaliacaoFilmes \
┣ 📄 README.md \
┣ 📄 user_stories.md \
┣ 📄 crc_cards.md \
┣ 📄 makefile \
┣ 📁 src/ \
┃ ┣ 📄 main.cpp \
┃ ┣ 📄 usuario.h \
┃ ┣ 📄 usuario.cpp \
┃ ┣ 📄 banco_de_dados.h \
┃ ┣ 📄 banco_de_dados.cpp \
┃ ┣ 📄 erros.h \
┃ ┣ 📄 filme.h \
┃ ┣ 📄 filme.cpp \
┃ ┣ 📄 avaliacao.h \
┃ ┗ 📄 avaliacao.cpp \

---

## 🔧 Instruções de Instalação

### ✔️ Pré-requisitos

- C++11 ou superior.
- Compilador g++ (ou outro compatível com C++11).
- Makefile.

## ⚙️ Passos para Instalação

1. **Clone o repositório:**

```bash
git clone https://github.com/matias-est/TrabalhoPDS2.git
cd TrabalhoPDS2
cd Sistema_de_Avaliacao_de_Filmes
```

2. **Compile o projeto:**

```bash
make
```

3. **Execute o programa:**

```bash
./avaliador
```

---

## 🤝 Como Contribuir

Se desejar contribuir ou reportar problemas:

1. Para bugs ou sugestões de funcionalidades, crie uma "Issue" no repositório GitHub.
2. Para contribuir com código:
   - Faça um "Fork" do repositório.
   - Crie uma nova "Branch" (`git checkout -b minha-funcionalidade`).
   - Faça seus "Commits" com mensagens claras.
   - Envie um "Pull Request" para a branch principal.

---

## Desenvolvedores

- Matias Machado de Faria
- Evandro Eurico Morais Penido
- Arthur de Almeida Souza
- Gustavo Marques Mendes
- Bernardo Marques Nascimento
