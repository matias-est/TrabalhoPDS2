# 🗂️ Cartões CRC 🗂️

## Classe: Usuário
- *Responsabilidades:*

* Gerenciar dados privados (nome completo, data de nascimento, senha).
* Gerar e fornecer o nome de usuário público (Personagem de Filme + Sobrenome).
* Autenticar a senha fornecida para login.**
* Registrar um mapa das avaliações que o próprio usuário fez (título do filme -> nota).

* Fornecer o nome completo e a senha para persistência em arquivo.

- *Colaboradores*
* BancoDeDados (que cria, armazena e gerencia os objetos Usuario).

---

## Classe: Filme
- *Responsabilidades:*
* Armazenar informações do filme (título, gênero, data de lançamento).
* Armazenar uma coleção de objetos Avaliacao.
* Armazenar uma coleção de comentários (strings).
* Calcular e fornecer a média das notas de avaliação.
* Adicionar novas avaliações à sua coleção.
* Adicionar novos comentários à sua coleção.
* Fornecer uma versão normalizada do título para buscas e comparações

- *Colaboradores:*
* Avaliacao (para compor sua lista de avaliações).
* BancoDeDados (que armazena, busca e gerencia os objetos Filme).

---

## Classe: Avaliacao
- *Responsabilidades:*
* Armazenar a nota (1 a 5).
* Armazenar o nome público do usuário que realizou a avaliação.

- *Colaboradores:*
* Filme (que cria e contém os objetos Avaliacao).

---

## Classe: BancoDeDados
- *Responsabilidades:*
* Gerenciar coleções de todos os objetos Usuario e Filme.
* Processar a criação de contas de usuário e a autenticação (login).
* Adicionar novos filmes, garantindo a unicidade de títulos similares.
* Buscar filmes por título (com normalização) e listar por gênero.
* Controlar se um usuário já avaliou um determinado filme para evitar duplicidade.
* Orquestrar o processo de salvar e carregar todos os dados (filmes, usuários, avaliações) de/para arquivos de texto.
* Gerar recomendações de filmes para um usuário com base nas melhores médias.
* Gerenciar o ciclo de vida e a memória dos objetos Usuario e Filme alocados dinamicamente.

- *Colaboradores:*
* Usuario (para criar e autenticar usuários).
* Filme (para adicionar e buscar filmes).
