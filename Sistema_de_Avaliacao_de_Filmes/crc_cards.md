# 🗂️ Cartões CRC 🗂️

## Classe: Usuário
- **Responsabilidades:**
* Gerenciar dados de cadastro (nome completo, data de nascimento, senha) – dados privados.
* Gerar e armazenar nome do usuário público (Personagem de Filme + Sobrenome).
* Efetuar login.
* Registrar uma avaliação para um filme.
* Escrever um comentário para um filme.
     
- **Colaboradores:**
* Filme (para associar avaliações e comentários)
* Avaliacao (para criar métodos de avaliação)
* Comentario (para criar comentário - se for uma classe separada)
* BancoDeDados 
  
---
## Classe: Filme
- **Responsabilidades:**
* Armazenar informações do filme (título, gênero).
* Armazenar avaliações recebidas.
* Armazenar comentários recebidos.
* Calcular e fornecer a média das notas de avaliação.
* Permitir a adição de novas avaliações.
* Permitir a adição de novos comentários.
    
- **Colaboradores:**
* Avaliacao 
* Comentario 
* Usuario (para identificar quem fez as avaliações e os comentários)
* BancoDeDados 

---
## Classe: Avaliacao

- **Responsabilidades:**
* Armazenar a nota (1 a 5).
* Armazenar a data da avaliação (opcional).
* Manter referência ao usuário que fez a avaliação.
* Manter referência ao filme que foi avaliado.

- **Colaboradores:**
* Usuario (para identificar o autor)
* Filme (para identificar o objeto da avaliação)
* BancoDeDados

---
## Classe: Comentario (Considerar se será uma classe distinta ou atributo de Avaliacao/Filme)
- **Responsabilidades:**
* Armazenar o texto do comentário.
* Armazenar a data do comentário (opcional).
* Manter referência ao usuário que fez o comentário.
* Manter referência ao filme que foi comentado.

---
- **Colaboradores:**
* Usuario (para identificar o autor)
* Filme (para identificar o objeto do comentário)
---
## Classe: BancoDeDados
- **Responsabilidades:**
* Gerenciar os dados de todos os usuários cadastrados. 
* Gerenciar os dados de todos os filmes cadastrados. 
* Fornecer funcionalidades de busca de filmes (por título, gênero).
* Garantir que não existirão filmes duplicados. 
* Processar o login de usuários. 
* Carregar/Salvar dados. 
    
- **Colaboradores:**
* Usuario 
* Filme 

