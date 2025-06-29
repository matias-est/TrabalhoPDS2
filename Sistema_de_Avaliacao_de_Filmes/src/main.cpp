#include "banco_de_dados.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

void limparBufferEntrada() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void pauseSistema() {
    cout << "\nPressione Enter para continuar...";
    string dummy;
    getline(cin, dummy);
}

int lerOpcaoSegura() {
    int opcao;
    while (!(cin >> opcao)) {
        cout << "Entrada inválida. Por favor, digite um número: ";
        cin.clear();
        limparBufferEntrada();
    }
    limparBufferEntrada();
    return opcao;
}

int main() {
    BancoDeDados bd;

    // ---------- CARREGAR DADOS AQUI --------------
    if (bd.carregarDados()) {
        cout << "Dados carregados com sucesso.\n";
    } else {
        cout << "Nenhum dado anterior encontrado.\n";
    }
    // ---------------------------------------------

    string nomePublicoLogado;
    int opcao;
    bool logado = false;
    bool terminarPrograma = false;

    srand(static_cast<unsigned int>(time(NULL)));

    cout << "🎬 Bem-vindo ao Sistema de Avaliação de Filmes 🎬\n";

    do {
        cout << "\n1. Criar Conta\n2. Login\n3. Sair\nEscolha: ";
        opcao = lerOpcaoSegura();

        if (opcao == 1) {
            string nomeCompleto, dataNascimento, senha;
            cout << "Nome completo: ";
            getline(cin, nomeCompleto);
            cout << "Data de nascimento (DD/MM/AAAA): ";
            getline(cin, dataNascimento);
            cout << "Senha: ";
            getline(cin, senha);

            string nomePublicoGerado;
            if (bd.criarConta(nomeCompleto, dataNascimento, senha, nomePublicoGerado)) {
                cout << "Conta criada! Seu nome de usuário é: " << nomePublicoGerado << "\n";
            } else {
                cout << "Já existe uma conta com esse nome de usuário.\n";
            }
        }
        else if (opcao == 2) {
            string senha;
            cout << "Nome de usuário: ";
            getline(cin, nomePublicoLogado);
            cout << "Senha: ";
            getline(cin, senha);

            if (bd.autenticar(nomePublicoLogado, senha)) {
                cout << "Login bem-sucedido! Bem-vindo(a), " << nomePublicoLogado << "!\n";
                logado = true;
                break;
            } else {
                cout << "Falha no login. Nome de usuário ou senha incorretos.\n";
            }
        }
        else if (opcao == 3) {
            terminarPrograma = true;
        }
        else {
            cout << "Opção inválida. Tente novamente.\n";
        }

        if (!terminarPrograma && !logado) {
            pauseSistema();
        }
    } while (opcao != 3 && !terminarPrograma);

    if (logado && !terminarPrograma) {
        do {
            cout << "\nMenu:\n"
                 << "1. Cadastrar Filme\n"
                 << "2. Avaliar Filme\n"
                 << "3. Comentar Filme\n"
                 << "4. Ver Informações do Filme\n"
                 << "5. Listar Filmes por Categoria\n"
                 << "6. Ver Recomendações\n"
                 << "7. Logout\n"
                 << "Escolha: ";
            opcao = lerOpcaoSegura();

            if (opcao == 1) {
                string titulo, genero, dataLancamento;
                cout << "Título: ";
                getline(cin, titulo);
                cout << "Gênero: ";
                getline(cin, genero);
                cout << "Data de lançamento (DD/MM/AAAA): ";
                getline(cin, dataLancamento);
                bd.adicionarFilme(new Filme(titulo, genero, dataLancamento));
                cout << "Filme cadastrado.\n";
                pauseSistema();
            }
            else if (opcao == 2) {
                string titulo;
                int nota;
                cout << "Título do filme para avaliar: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo);
                if (filme) {
                    if (bd.usuarioJaAvaliou(nomePublicoLogado, filme->getTituloNormalizado())) {
                        cout << "Você já avaliou este filme.\n";
                    } else {
                        cout << "Nota (1 a 5): ";
                        nota = lerOpcaoSegura();
                        if (nota >= 1 && nota <= 5) {
                            bd.registrarAvaliacaoUsuario(nomePublicoLogado, filme->getTituloNormalizado(), nota);

                            cout << "Avaliação adicionada.\n";
                        } else {
                            cout << "Nota inválida. Deve estar entre 1 e 5.\n";
                        }
                    }
                } else {
                    cout << "Filme não encontrado.\n";
                }
                pauseSistema();
            }
            else if (opcao == 3) {
                string titulo, comentario;
                cout << "Título do filme para comentar: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo);
                if (filme) {
                    cout << "Comentário: ";
                    getline(cin, comentario);
                    filme->adicionarComentario(nomePublicoLogado + ": " + comentario);
                    cout << "Comentário adicionado.\n";
                } else {
                    cout << "Filme não encontrado.\n";
                }
                pauseSistema();
            }
            else if (opcao == 4) {
                string titulo;
                cout << "Título do filme para ver informações: ";
                getline(cin, titulo);
                Filme *filme = bd.buscarFilme(titulo);
                if (filme) {
                    filme->exibirInformacoes();
                } else {
                    cout << "Filme não encontrado.\n";
                }
                pauseSistema();
            }
            else if (opcao == 5) {
                string genero;
                cout << "Digite o gênero para listar: ";
                getline(cin, genero);
                bd.listarFilmesPorCategoria(genero);
                pauseSistema();
            }
            else if (opcao == 6) {
                auto recomendados = bd.recomendarFilmes(nomePublicoLogado);
                cout << "\n🎯 Recomendações de filmes para você:\n";
                if (recomendados.empty()) {
                    cout << "Nenhuma recomendação disponível.\n";
                } else {
                    for (auto filme : recomendados) {
                        cout << "- " << filme->getTitulo()
                             << " | Gênero: " << filme->getGenero()
                             << " | Média: " << filme->calcularMedia() << "\n";
                    }
                }
                pauseSistema();
            }
            else if (opcao == 7) {
                cout << "Você saiu da sua conta.\n";
                logado = false;
                nomePublicoLogado.clear();
                break;
            }
            else {
                cout << "Opção inválida. Tente novamente.\n";
                pauseSistema();
            }
        } while (!terminarPrograma && logado);
    }

    cout << "Encerrando programa.\n";

    // ----------- SALVAR DADOS AQUI ----------------
    if (bd.salvarDados()) {
        cout << "Dados salvos com sucesso.\n";
    } else {
        cout << "Erro ao salvar dados.\n";
    }
    // ----------------------------------------------

    pauseSistema();
    return 0;
}
