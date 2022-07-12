#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "componentes.hpp"

using namespace std;

/* --------------- */ 
/*    Componente   */ 
/* --------------- */ 

// Constructors

Componente::Componente()
{
    quantidade=0;
    preco=0.0;
}

Componente::Componente(string c_id, string c_nome, int c_quantidade, float c_preco, string c_categoria)
{
    id=c_id;
    nome=c_nome;
    quantidade=c_quantidade;
    preco=c_preco;
    categoria=c_categoria;
    
}

// Get Methods

string Componente::getId() const
{
    return id;
}

string Componente::getNome() const
{
    return nome;
}

string Componente::getCategoria() const
{
    return categoria;
}

float Componente::getPreco() const
{
    return preco;
}

int Componente::getQuantidade() const
{
    return quantidade;
}

// Set Methods

void Componente::setId(string c_id)
{    
    id=c_id;
}

void Componente::setNome(string c_nome)
{
    nome=c_nome;
}

void Componente::setQuantidade(int c_quantidade)
{
    if(c_quantidade < 0)
        quantidade=0;

    quantidade = c_quantidade;
}

void Componente::setPreco(float c_preco)
{
    if(c_preco < 0)
        preco=0;

    preco=c_preco;
}

void Componente::setCategoria(string c_categoria)
{
    categoria=c_categoria;
}

// Friend Fucntion

bool comparaComponentes(const Componente *c1, const Componente *c2)
{
    if(c1==NULL || c2==NULL || (c1->getPreco() < 0) || (c2->getPreco() < 0))
        return 0;

    if(c1->preco < c2->preco) return 1;
    if(c1->preco > c2->preco) return 0;
    if(c1->preco == c2->preco){
        if(c1->id.compare(c2->id) < 0) return 1;        
        if(c1->id.compare(c2->id) > 0) return 0;      
    }
    return 0;
}

/* --------------- */ 
/*     Armazém     */ 
/* --------------- */

// Constructor

Armazem::Armazem()
{
    componentes.clear();
}

// Destructor

Armazem::~Armazem()
{
    for(vector<Componente*>::iterator it = componentes.begin(); it != componentes.end(); it++)
    {
        delete *it;
    }
}

// Get Methods

vector<Componente*> Armazem::getComponentes() const
{
    return componentes;
}

size_t Armazem::getTamanho() const
{
    return componentes.size();
}

// Other Methods

int Armazem::componenteInsere(Componente *c)
{
    if(c==NULL)
        return -1;

    // verifica se já existe o componente c    
    for(size_t i=0; i<componentes.size(); i++){
        if(componentes[i]->getId().compare(c->getId()) == 0){
            componentes[i]->setPreco(c->getPreco());
            componentes[i]->setQuantidade(c->getQuantidade()+componentes[i]->getQuantidade());
            delete c;
            return 1;
        }
    }
    componentes.push_back(c);
    return 0;

}

Componente* Armazem::componenteRemove(const string nome)
{ 
    if(nome.empty())
        return NULL;

    Componente *C = NULL;

    int componente_existe=0, foundAt=0;
    for(size_t i=0; i<componentes.size(); i++){
        if((componentes[i]->getNome().compare(nome)) == 0){
            foundAt=i;
            componente_existe++;
            break;
        }
    }
    if(componente_existe == 0)
    {
        delete C;
        return NULL;
    }

    C = componentes[foundAt];
    componentes.erase(componentes.begin()+foundAt);
    return C;
}

int Armazem::importa(const string nome_ficheiro)
{  
    string linha;
    int quantidade_;
    float preco_;    
    string substr;

    ifstream MyReadFile(nome_ficheiro);
    if(!MyReadFile)
        return -1;

    while (getline (MyReadFile, linha)) // Lê linha por linha 
    {
        Componente *C = NULL;
        C = new Componente;
        stringstream linha_ss(linha, ios_base::in);

        getline(linha_ss, substr, ','); // copia a primeira palavra da linha para substring (ID)
        C->setId(substr);
        getline(linha_ss, substr, ','); // copia a segunda palavra da linha para substring (Nome)
        C->setNome(substr);
        getline(linha_ss, substr, ','); // copia a terceira palavra da linha para substring (Categoria)
        C->setCategoria(substr);
        getline(linha_ss, substr, ','); // copia a quarta palavra da linha para substring (Quantidade)
        quantidade_ = stoi(substr);
        C->setQuantidade(quantidade_);
        getline(linha_ss, substr, ','); // copia a quinta palavra da linha para substring (Preço)
        preco_ = std::stof(substr);
        C->setPreco(preco_);
       
        if(componenteInsere(C) == -1)
        {
            delete C;
            return -1;
        }
        
    }
    MyReadFile.close();
    return 0;
}

vector<int> Armazem::pesquisaCategoria(const string categoria)
{
    vector<int> foundAt;  
    for(size_t i=0; i<componentes.size(); i++){
        if((componentes[i]->getCategoria().compare(categoria)) == 0){
            foundAt.push_back(i);
        }
    }
    return foundAt;
}

void Armazem::ordena()
{
    if (componentes[0] == NULL || componentes[1] == NULL ) // não precisa ordenar se o Armazem estiver vazio ou só existir um componente
        return;

    sort(componentes.begin(), componentes.begin() + componentes.size(), comparaComponentes);  

}