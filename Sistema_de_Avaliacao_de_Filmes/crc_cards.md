# 🗂️ Cartões CRC 🗂️

## Classe: Usuário
- **Responsabilidades:**
* Gerenciar dados privados de cadastro (nome completo, data de nascimento, senha).
* Gerar e fornecer o nome de usuário público (Personagem de Filme + Sobrenome).
* Autenticar a senha fornecida para login.

- **Colaboradores:**
* BancoDeDados (para armazenamento e recuperação de dados de usuário).

---

## Classe: Filme
- **Responsabilidades:**
* Armazenar informações do filme (título, gênero, data de lançamento).
* Armazenar as avaliações recebidas.
* Armazenar os comentários recebidos.
* Calcular e fornecer a média das notas de avaliação.
* Permitir a adição de novas avaliações.
* Permitir a adição de novos comentários.
* Fornecer uma versão normalizada do título para comparações.

- **Colaboradores:**
* Avaliacao (para receber objetos de avaliação).
* BancoDeDados (para ser armazenado e buscado).

---

## Classe: Avaliacao
- **Responsabilidades:**
* Armazenar a nota (1 a 5).
* Armazenar o nome público do usuário que realizou a avaliação.

- **Colaboradores:**
* Filme (que utiliza o objeto Avaliacao).
* Usuario (que fornece o nome público).

---

## Classe: BancoDeDados
- **Responsabilidades:**
* Gerenciar o armazenamento de todos os usuários cadastrados.
* Gerenciar o armazenamento de todos os filmes cadastrados.
* Fornecer funcionalidades de busca de filmes por título (com tolerância a variações) e por gênero.
* Garantir a unicidade de filmes com títulos similares.
* Processar a criação de contas de usuário e o login.
* Gerenciar a memória dos objetos Usuario e Filme alocados dinamicamente.

- **Colaboradores:**
* Usuario (para criar e autenticar usuários).
* Filme (para adicionar e buscar filmes).
