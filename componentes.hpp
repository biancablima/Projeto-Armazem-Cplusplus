#ifndef COMPONENTES_HPP
#define COMPONENTES_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Componente {
private:
    /* ATRIBUTOS
     *   id           - identificação única do componente
     *   nome         - nome do componente
     *   categoria    - categoria do componente
     *   quantidade   - quantidade do componente em armazém
     *   preco        - preço do componente
     */
    string id, nome, categoria;
    int quantidade; 
    float preco;
public:
    /* MÉTODOS */
    
    // Constructors

    /* 
     * Construtor default
     *   Inicializa 'quantidade' e 'preco' a zero.
     */
    Componente();

    /* 
     * Constructor (parametrizado)
     *   Inicializa os atributos com o correspondente argumento.
     */
    Componente(string c_id, string c_nome, int c_quantidade, float c_preco, string c_categoria);
    
    // Get Methods

    /* 
     * Obter identificação do componente.
     *   @return 'id' do componente
     */
    string getId() const;

    /* 
     * Obter nome do componente.
     *   @return 'nome' do componente
     */
    string getNome() const;

    /* 
     * Obter quantidade armazenada do componente.
     *   @return 'quantidade' do componente
     */
    int getQuantidade() const;

    /* 
     * Obter preço do componente.
     *   @return 'preco' do componente
     */
    float getPreco() const;

    /* 
     * Obter categoria do componente.
     *   @return 'categoria' do componente
     */
    string getCategoria() const;

    // Set Methods

    /* 
     * Definir identificação do componente.
     *   @param c_id 'id' do componente
     */
    void setId(string c_id);

    /* 
     * Definir nome do componente.
     *   @param c_nome 'nome' do componente
     */
    void setNome(string c_nome);

    /* 
     * Definir quantidade armazenada do componente.
     *   @param c_quantidade 'quantidade' do componente
     */
    void setQuantidade(int c_quantidade);
    
    /* 
     * Definir preço do componente.
     *   @param c_preco 'preco' do componente
     */
    void setPreco(float c_preco);
    
    /* 
     * Definir categoria do componente.
     *   @param c_categoria 'categoria' do componente
     */
    void setCategoria(string c_categoria);

    // Friend Function

    /*
     * Compara dois objetos da classe Componente:
     *      - um objeto é menor que outro se 'preco' é inferior,
     *      - no caso de preços iguais, o objeto menor é o que tem 'id' mais baixo.
     *   @param c1 apontador para Componente
     *   @param c2 apontador para Componente
     *   @returns 1 (true) se (*c1 < *c2) | 0 (false) se (*c1 > *c2)
     */
    friend bool comparaComponentes(const Componente *c1, const Componente *c2);
};

class Armazem {
private:
    /* ATRIBUTOS 
     *   componentes  - vetor de apontadores para os componentes armazenados (apontadores para objetos da classe Componente)
     */
    vector <Componente*> componentes;
public:
    /* MÉTODOS */

    // Constructor e Destructor 

    /* 
     * Construtor default
     *   Garante que o vetor 'componentes' está vazio.
     */
    Armazem();

    /* 
     * Destrutor
     *   Apaga em memória os elementos de 'componentes'.
     */
    ~Armazem();

    // Get Methods

    /* 
     * Obter componentes em armazém.
     *   @return 'componentes'
     */
    vector<Componente*> getComponentes() const;

    /* 
     * Obter tamanho do vetor de componentes.
     *   @return 'tamanho' correspondente ao número de componentes em armazém
     */
    size_t getTamanho() const;

    // Other Methods

    /*
     * Insere um componente no armazém, na última posição.
     * Observações: Caso o componente já exista (tenha o mesmo 'id'), adicionar o número de componentes ao que já existe e atualizar o preço.
     *   @param c componente a inserir
     *   @returns 0 se o componente não existia e foi inserido com sucesso | 1 se o componente já existia e apenas foi atualizado | -1 se ocorrer um erro
     */
    int componenteInsere(Componente *c);

    /*
     * Remove do armazém o componente com nome dado por 'nome'.
     * Observações: Remove apenas o primeiro componente que encontrar com o nome dado (tem que ser o nome completo).
     *   @param nome nome do componente a remover
     *   @returns Apontador para o componente removido | NULL se ocorrer um erro ou o componente não exisitir no armazém
     */
    Componente* componenteRemove(const string nome);

    /*
     * Preenche o armazém lendo o conteúdo do ficheiro de texto 'nome_ficheiro'.
     * Observações: Cada linha do ficheiro corresponde a um componente e tem o seguinte formato: ID,nome,categoria,quantidade,preco.
     *   @param nome_ficheiro nome do ficheiro de texto contendo o armazém a importar
     *   @returns 0 em caso de sucesso | -1 se ocorrer um erro
     */
    int importa(const string nome_ficheiro);

    /*
     * Pesquisa todos os componentes que tenham categoria correspondente a 'categoria'.
     *   @param categoria categoria a procurar
     *   @returns Vetor de índices/posições dos componentes encontrados
     */
    vector<int> pesquisaCategoria(const string categoria);

    /*
     * Ordena o armazém por ordem crescente.
     *   Ou seja, ordena os componentes armazenados.
     */
    void ordena();
};

#endif