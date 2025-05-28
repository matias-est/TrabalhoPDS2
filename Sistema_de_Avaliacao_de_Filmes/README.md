# 🎬 Sistema de Avaliação de Filmes 🎬
## Apresentação do Problema: 
  Atualmente a indústria cinematográfica foi tomada por sistemas de avaliações de filmes focados na caracterização do avaliador. Ou seja, as pessoas têm avaliado os filmes pensando não só no filme mas também no que as outras pessoas vão pensar sobre a avaliação dela. Por isso, desenvolvemos um sistema que busca preservar o anonimato e a sinceridade, mas ao mesmo tempo permitindo com que cada usuário tenha seu próprio perfil dentro da plataforma. \
  \
  Nosso sistema permitirá que cada usuário possa criar contas (seguindo os padrões de semi anonimato), cadastrar filmes, realizar avaliações (de 1 a 5) e comentar sobre os filmes registrados.
  
---

## Visão Geral da Solução:
O sistema foi desenvolvido em C++ e funciona via terminal. Ele permite que os usuários criem contas utilizando **nome completo e data de nascimento**, dados que são mantidos em **sigilo absoluto**. O nome de usuário visível na plataforma segue o padrão:

> **(Personagem de Filme) + (Sobrenome do Usuário)**

Exemplos:
- `BatmanSilva`
- `YodaPereira`
- `HermioneSantos`

Após a autenticação, os usuários podem:
- Cadastrar filmes.
- Avaliar filmes (notas de 1 a 5).
- Adicionar comentários.
- Visualizar informações detalhadas dos filmes, como média das avaliações e comentários.

---
