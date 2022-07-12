#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <algorithm>
#include "componentes.hpp"

using namespace std;

int verifica_componente_construtor(Componente **c1)
{
    int er = 0;
    *c1 = new Componente("con007290", "800UF/250V GIGA 85 50X100MM MALLORY", 5, 1.34, "condensador eletrolitico");
    
    /*Teste 1*/
    if ((*c1) == NULL)
    {
        cout << "...verifica_componente_construtor: componente e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_componente_construtor: componente nao e' NULL (ok)" << endl;

    /*Teste 2*/
    if (((*c1)->getId().compare("con007290")) != 0)
    {
        cout << "...verifica_componente_construtor: ID do componente (= " << (*c1)->getId() << ") e' diferente do esperado (= con007290) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_construtor: ID coincide com o esperado (= con007290) (ok)" << endl;

    /*Teste 3*/
    if ((*c1)->getNome().compare("800UF/250V GIGA 85 50X100MM MALLORY") != 0)
    {
        cout << "...verifica_componente_construtor: Nome do componente (= " << (*c1)->getNome() << ") e' diferente do esperado (= 800UF/250V GIGA 85 50X100MM MALLORY) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_construtor: Nome do componente coincide com o esperado (= 800UF/250V GIGA 85 50X100MM MALLORY) (ok)" << endl;
    
    /*Teste 4*/
    if ((*c1)->getCategoria().compare("condensador eletrolitico") != 0)
    {
        cout << "...verifica_componente_construtor: Categoria do componente (= " << (*c1)->getCategoria() <<") e' diferente do esperado (= condensador eletrolitico) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_componente_construtor: Categoria do componente coincide com o esperado (= condensador eletrolitico) (ok)" <<endl;    
    
    /*Teste 5*/
    if ((*c1)->getQuantidade() != 5)
    {
        cout << "...verifica_componente_construtor: Quantidade do componente (= "<< (*c1)->getQuantidade() <<") e' diferente do esperado (=5) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_construtor: Quantidade do componente coincide com o esperado (= 5) (ok)" << endl;

    /*Teste 6*/
    if (abs((*c1)->getPreco() - 1.34) > 0.00001)
    {
        cout << "...verifica_componente_construtor: Preco do componente (= " << (*c1)->getPreco() <<") e' diferente do esperado (= 1.34) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_construtor: Preco do componente coincide com o esperado (= 1.34) (ok)" << endl;

    return er;
}

int verifica_armazem_construtor(Armazem **a)
{
    int er = 0;

    *a = new Armazem(); 

    if (!(*a))
    {
        cout << "...verifica_armazem_construtor: armazem e' NULL (ERRO)" << endl;
        return 1;
    }
    else
        cout << "...verifica_armazem_construtor: armazem nao e' NULL (ok)" << endl;

    return er;
}

int verifica_componente_setters(Componente **c1)
{
    int er = 0; 
    if (!(*c1)) {
        cout << "...verifica_componente_setters: componente e' NULL (ERRO)" << endl;
        return 1;
    }

    (*c1)->setId("con007293");
    (*c1)->setNome("800UF/250V"); 
    (*c1)->setCategoria("transistor");
    (*c1)->setPreco(3.2); 
    (*c1)->setQuantidade(10);

    /*Teste 2*/
    if (((*c1)->getId().compare("con007293")) != 0)
    {
        cout << "...verifica_componente_setters: ID do componente (= " << (*c1)->getId() << ") e' diferente do esperado (= con007293) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_setters: ID coincide com o esperado (= con007293) (ok)" << endl;

    /*Teste 3*/
    if ((*c1)->getNome().compare("800UF/250V") != 0)
    {
        cout << "...verifica_componente_setters: Nome do componente (= " << (*c1)->getNome() << ") e' diferente do esperado (= 800UF/250V) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_setters: Nome do componente coincide com o esperado (= 800UF/250V) (ok)" << endl;
    
    /*Teste 4*/
    if ((*c1)->getCategoria().compare("transistor") != 0)
    {
        cout << "...verifica_componente_setters: Categoria do componente (= " << (*c1)->getCategoria() <<") e' diferente do esperado (= transistor) (ERRO)" <<endl;
        er++;
    }
    else
        cout << "...verifica_componente_setters: Categoria do componente coincide com o esperado (= transistor) (ok)" <<endl;    
    
    /*Teste 5*/
    if ((*c1)->getQuantidade() != 10)
    {
        cout << "...verifica_componente_setters: Quantidade do componente (= "<< (*c1)->getQuantidade() <<") e' diferente do esperado (= 10) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_setters: Quantidade do componente coincide com o esperado (= 10) (ok)" << endl;

    /*Teste 6*/
    if (abs((*c1)->getPreco() - 3.2) > 0.00001)
    {
        cout << "...verifica_componente_setters: Preco do componente (= " << (*c1)->getPreco() <<") e' diferente do esperado (= 3.2) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_setters: Preco do componente coincide com o esperado (= 3.24) (ok)" << endl;
    
    
    return er;
}

int verifica_compara_componentes()
{
    int er = 0, result;

    Componente *c1 = new Componente("con007290", "800UF/250V GIGA 85 50X100MM MALLORY", 5, 1.34, "condensador eletrolitico");
    Componente *c2 = new Componente("con007350", "1000UF/400V GIGA 105 65X70MM NICHICON", 10, 3.12,"condensador eletrolitico");
    Componente *c3 = new Componente("con007110", "220UF/450V SNAP-IN 85 25X50MM SAMWHA", 240, 2.14,"condensador eletrolitico");
    Componente *c4 = new Componente("Var016830", "S10K250V", 440, 2.14,"Varistor");

    result = comparaComponentes(c1, c2);
    if (result)
        cout << "...verifica_compara_componentes (teste de precos diferentes): comparacao correta - " << c1->getId() << " < " << c2->getId() << " (ok)" << endl;
    else {
        cout << "...verifica_compara_componentes (teste de precos diferentes): comparacao incorreta (ERRO)" << endl;
        er++;
    }

    result = comparaComponentes(c4, c3);
    if (result)
        cout << "...verifica_compara_componentes (teste de precos iguais): comparacao correta - " << c4->getId() << " < " << c3->getId() << " (ok)" << endl;
    else {
        cout << "...verifica_compara_componentes (teste de precos iguais): comparacao incorreta (ERRO)" << endl;
        er++;
    }

    delete c1;
    delete c2;
    delete c3;
    delete c4;

    return er;
}

int verifica_componente_insere(Armazem **a)
{
    int er = 0, erro = 0;

    Componente *c1 = new Componente("con007290", "800UF/250V GIGA 85 50X100MM MALLORY", 5, 1.34, "condensador eletrolitico");
    Componente *c2 = new Componente("con007350", "1000UF/400V GIGA 105 65X70MM NICHICON", 10, 3.12,"condensador eletrolitico");
    Componente *c3 = new Componente("tra012720", "MJ900 MOTOROLA", 0, 1.20,"transistor");
    Componente *c4 = new Componente("con007350", "1000UF/400V GIGA 105 65X70MM NICHICON", 20, 3.12,"condensador eletrolitico");

    /* Inserir Componente 1 */
    erro = (*a)->componenteInsere(c1);
    if (erro == -1)
    {
        cout << "...verifica_componente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Componente 2 */
    erro = (*a)->componenteInsere(c2);
    if (erro == -1)
    {
        cout << "...verifica_componente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Componente 3 */
    erro = (*a)->componenteInsere(c3);
    if (erro == -1)
    {
        cout << "...verifica_componente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Inserir Componente 4 */
    erro = (*a)->componenteInsere(c4);
    if (erro == -1)
    {
        cout << "...verifica_componente_insere: nao conseguiu inserir (ERRO)" << endl;
        return 1;
    }

    /* Testes de Posições */
    if ((*a)->getComponentes()[0]->getId().compare("con007290") != 0 || (*a)->getComponentes()[2]->getId().compare("tra012720") != 0)
    {
        cout << "...verifica_componente_insere: nao inseriu correctamente o 1º e 3º componentes, nao estao na posicao correta (ERRO)" << endl;
        er++;
        return er;
    }
    else
        cout << "...verifica_componente_insere: inseriu o 1º e 3º componentes nas posicoes corretas (ok)" << endl;

    
    if ((*a)->getComponentes()[1]->getQuantidade() != 30)
    {
        cout << "...verifica_componente_insere: quantidade do 2º componente (= "<< (*a)->getComponentes()[1]->getQuantidade() << ") 'e diferente do esperado (= 30) (ERRO)" << endl;
        er++;
    }
    else
        cout <<"...verifica_componente_insere: quantidade do 2º componente coincide com o esperado (= 30) (ok)" << endl;

    if (abs((*a)->getComponentes()[1]->getPreco() - 3.12) > 0.000001)
    {
        cout << "...verifica_componente_insere: preco do 2º componente (= " << (*a)->getComponentes()[1]->getPreco() << ") 'e diferente do esperado (= 3.14) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_insere: preco do 2º componente coincide com o esperado (= 3.12) (ok)" << endl;

    return er;
}

int verifica_importa(Armazem **a)
{
    int er = 0;
    cout << "A importar armazem..." << endl;

    (*a)->importa("db_small.txt");

    if (*a == NULL)
    {
        cout << "...verifica_importa: falhou importacao do armazem (ERRO)" << endl;
        return 1;
    }
    else
    {
        int tam =(*a)->getTamanho();
        if (tam != 565)
        {
            cout << "...verifica_importa: tamanho do armazem "<< tam << " e' diferente do esperado (= 565) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_importa: tamanho do armazem coincide com o esperado (= 565) (ok)" << endl;
    
        if ((*a)->getComponentes()[0]->getId().compare("cir000030") != 0 || (*a)->getComponentes()[tam - 1]->getId().compare("Cap016950") != 0)
        {
            cout << "...verifica_importa: IDs da 1ª (= " << (*a)->getComponentes()[0]->getId() << ") e 'ultima (= " << (*a)->getComponentes()[tam - 1]->getId() << ") posicoes do armazem diferem do esperado (cir000030 e Cap016950) (ERRO)" << endl;
            er++;
        }
        else
            cout << "...verifica_importa: IDs da 1ª e 'ultima posicoes do armazem coincidem com o esperado (cir000030 e Cap016950) (ok)" << endl;
    }
    return er; 
}

int verifica_componente_remove(Armazem *a)
{
    int er = 0;

    Componente *c;
    /*Remoção de componente inexistente*/
    c = a->componenteRemove("inexistente");
    if (c)
    {
        cout << "...verifica_componente_remove (teste de componente inexistente): removeu um componente inexistente (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_componente_remove (teste de componente inexistente): nao removeu nenhum componente (ok)" << endl;

    c = a->componenteRemove("800UF/250V GIGA 85 50X100MM MALLORY");
    if (!c)
    {
        cout << "...verifica_componente_remove (teste de componente valido): nao removeu (ERRO)" << endl;
        er++;
    }
    else if (c->getId().compare("con007290") != 0)
    {
        cout <<"...verifica_componente_remove (teste de componente valido): removeu um componente errado" << c->getId() <<  "(ERRO)" << endl;
        er++;
    }
    else
    {
        cout << "...verifica_componente_remove (teste de componente valido): removeu com sucesso (ok)" << endl;
    }

    delete c;
    return er;
}

int verifica_pesquisa_categoria(Armazem *a)
{
    int er = 0;
    vector<int> idxs;

    idxs = a->pesquisaCategoria("Rosae");

    if (idxs.size())
    {
        cout << "...verifica_pesquisa_categoria (teste de uma categoria que nao existe): tamanho do vetor nao 'e 0 (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_pesquisa_categoria (teste de uma categoria que nao existe): tamanho do vector 'e 0 (ok)" << endl;

    idxs = a->pesquisaCategoria("resistencia smd");
    if (idxs.size() == 0)
    {
        cout << "...verifica_pesquisa_categoria (teste de uma categoria que existe): categoria nao foi encontrada (ERRO)" << endl;
        er++;
    }
    else if (idxs.size() != 18)
    {
        cout << "...verifica_pesquisa_categoria (teste de uma categoria que existe): numero de indices encontrados " << idxs.size() << " nao coincide com o esperado (= 18) (ERRO)" << endl;
        er++;
    }
    else
        cout << "...verifica_pesquisa_categoria (teste de uma categoria que existe): numero de indices encontrados coincide com o esperado (= 18) (ok)" << endl;

    if (idxs.size())
    {
        idxs.clear();
    }
    return er;
}

int verifica_ordena(Armazem **a)
{    
    (*a)->ordena();

    if ((*a)->getComponentes()[0]->getId().compare("cir002670") != 0 || (*a)->getComponentes()[(*a)->getTamanho()-1]->getId().compare("res015000") != 0)
    {
        cout << "...verifica_ordena: 1º (= " << (*a)->getComponentes()[0]->getId() << ") e 'ultimo (= " << (*a)->getComponentes()[(*a)->getTamanho()-1]->getId()<< ") componentes do vetor sao diferentes do esperado (= cir002670 e res015000) (ERRO)" << endl;
        return 1;
    }
    else
    {
        cout <<"...verifica_ordena: 1º e 'ultimo componentes do vetor coincidem com o esperado (= cir002670 e res015000) (ok)" << endl;
    }
    return 0;

}


int main()
{
    int errorCount = 0, error;

    cout << "INICIO DOS TESTES\n\n" << endl;

    cout << "TESTES DE CONSTRUTORES, SETTERS E GETTERS\n" << endl;
    
    /* Verifica construtor do componente */
    Componente *c1;
    error = verifica_componente_construtor(&c1);
    if (error)
    {
        cout << "ERRO: "<< error << " erros encontrados em verifica_componente_construtor\n\n" <<  endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_componente_construtor passou\n\n" << endl;
    }

    /* Verifica construtor do armazem */
    Armazem *a;
    error = verifica_armazem_construtor(&a);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_armazem_construtor\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_armazem_construtor passou\n\n" << endl;
    }

    /* Verifica setters de componente */
    error = verifica_componente_setters(&c1);
    if (error)
    {
        cout << "ERRO: " << error << "erros encontrados em verifica_componente_setters\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_componente_setters passou\n\n" << endl;
    }

    cout << "TESTES DE METODOS\n" << endl;

    /* Verifica compara */
    error = verifica_compara_componentes();
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_compara_componentes\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_compara_componentes passou\n\n" << endl;
    }

    /* Verifica componente insere */
    error = verifica_componente_insere(&a);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_componente_insere\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_componente_insere passou\n\n" << endl;
    }

    /* Verifica importa */
    Armazem *a1 = new Armazem;
    error = verifica_importa(&a1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_importa\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout<< "OK: verifica_importa passou\n\n" << endl;
    }

    /* Verifica componente remove */
    error = verifica_componente_remove(a1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_componente_remove\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_componente_remove passou\n\n" << endl;
    }

    /* Verifica pesquisa categoria */
    error = verifica_pesquisa_categoria(a1);
    if (error)
    {
        cout << "ERRO: "<< error <<" erros encontrados em verifica_pesquisa_categoria\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_pesquisa_categoria passou\n\n" << endl;
    }

    /* Verifica ordena */
    error = verifica_ordena(&a1);
    if (error)
    {
        cout << "ERRO: " << error << " erros encontrados em verifica_ordena\n\n" << endl;
        errorCount += error;
    }
    else
    {
        cout << "OK: verifica_ordena passou\n\n" << endl;
    }

    /* Fim dos testes */
    if (errorCount == 0)
        cout << "FIM DOS TESTES: Todos os testes passaram\n" << endl;
    else
        cout << "FIM DOS TESTES: Foram encontrados "<< errorCount << " ERROS no total\n" << endl;

    delete c1;
    delete a;
    delete a1;

    return 0;
}