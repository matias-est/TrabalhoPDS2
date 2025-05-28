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
* BancoDeDados (para buscar e armazenar)

---
## Classe: Avaliacao
- **Responsabilidades:**
    
- **Colaboradores:**
    
---
## Classe: BancoDeDados
- **Responsabilidades:**
    
- **Colaboradores:**
    
---
## Classe: Main
- **Responsabilidades:**
    
- **Colaboradores:**


---
