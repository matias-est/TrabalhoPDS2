#include "banco_de_dados.h"
#include <iostream>
#include <limits> 

using namespace std;


void limparBufferEntrada()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseSistema()
{
    cout << "\nPressione Enter para continuar...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main()
{
    BancoDeDados bd;          
    string nomePublicoLogado; 
    int opcao;
    bool logado = false;

    cout << "🎬 Bem-vindo ao Sistema de Avaliação de Filmes 🎬\n";

    
    do
    {
        cout << "\n1. Criar Conta\n2. Login\n3. Sair\nEscolha: ";
        cin >> opcao;
        limparBufferEntrada(); 

        if (opcao == 1)
        {
            string nomeCompleto, dataNascimento, senha;
            cout << "Nome completo: ";
            getline(cin, nomeCompleto);
            cout << "Data de nascimento (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            cout << "Senha: ";
            getline(cin, senha);

            string nomePublicoGerado; 
            if (bd.criarConta(nomeCompleto, dataNascimento, senha, nomePublicoGerado))
            {
                cout << "Conta criada! Seu nome de usuário é: " << nomePublicoGerado << "\n";
            }
            else
            {
                cout << "Já existe uma conta com esse nome de usuário.\n";
            }
        }
        else if (opcao == 2)
        {
            string senha;
            cout << "Nome de usuário: ";
            getline(cin, nomePublicoLogado); 
            cout << "Senha: ";
            getline(cin, senha);

            if (bd.autenticar(nomePublicoLogado, senha))
            {
                cout << "Login bem-sucedido! Bem-vindo(a), " << nomePublicoLogado << "!\n";
                logado = true;
                break; 
            }
            else
            {
                cout << "Falha no login. Nome de usuário ou senha incorretos.\n";
            }
        }
        else if (opcao != 3)
        { 
            cout << "Opção inválida. Tente novamente.\n";
        }
        pauseSistema(); 
    } while (opcao != 3);

    
    if (logado)
    {
        do
        {
            cout << "\nMenu:\n1. Cadastrar Filme\n2. Avaliar Filme\n3. Comentar Filme\n4. Ver Informações do Filme\n5. Listar Filmes por Categoria\n6. Logout\nEscolha: ";
            cin >> opcao;
            limparBufferEntrada(); 
            if (opcao == 1)
            {
                string titulo, genero, dataLancamento; 
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Gênero: ";
                getline(cin, genero);
                cout << "Data de lançamento (DD/MM/AAAA): "; 
                getline(cin, dataLancamento);
                bd.adicionarFilme(Filme(titulo, genero, dataLancamento));
            }
            else if (opcao == 2)
            {
                string titulo;
                int nota;
                cout << "Título do filme para avaliar: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo); 
                if (filme)
                {
                    cout << "Nota (1 a 5): ";
                    cin >> nota;
                    limparBufferEntrada(); 
                    filme->adicionarAvaliacao(nomePublicoLogado, nota);
                    cout << "Avaliação adicionada.\n";
                }
                else
                {
                    cout << "Filme não encontrado.\n";
                }
            }
            else if (opcao == 3)
            {
                string titulo, comentario;
                cout << "Título do filme para comentar: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo); 
                if (filme)
                {
                    cout << "Comentário: ";
                    getline(cin, comentario);
                    filme->adicionarComentario(nomePublicoLogado + ": " + comentario);
                    cout << "Comentário adicionado.\n";
                }
                else
                {
                    cout << "Filme não encontrado.\n";
                }
            }
            else if (opcao == 4)
            {
                string titulo;
                cout << "Título do filme para ver informações: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo); 
                if (filme)
                {
                    filme->exibirInformacoes();
                }
                else
                {
                    cout << "Filme não encontrado.\n";
                }
            }
            else if (opcao == 5)
            {
                string genero;
                cout << "Digite o gênero para listar: ";
                getline(cin, genero);
                bd.listarFilmesPorCategoria(genero);
            }
            else if (opcao != 6)
            { 
                cout << "Opção inválida. Tente novamente.\n";
            }
            if (opcao != 6 && opcao != 3)
            { 
                pauseSistema();
            }
        } while (opcao != 6); 
    }

    cout << "Encerrando programa.\n";
    return 0;
}
