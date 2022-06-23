/*
Classe GerenciaBD:
--------------------------------------------------------------------------------------------------
Essa classe refere-se a todos os contatos que há entre o Banco de Dados e o respectivo programa.
Essa classe é responsável pelas seguintes questões:
-> Adicionar um novo funcionário (de qualquer Classe);
-> Remover um funcionário (de qualquer Classe);
-> Listar todos os funcionários;
-> Listar todos os funcionários de um determinado cargo (de qualquer Classe);
-> Editar os dados de qualquer funcionário diretamente no banco de dados.
-> Retornar, dado um atributo, o tipo do funcionário.
--------------------------------------------------------------------------------------------------
Ap.1.
Essa classe irá considerar, para organização, a seguinte numeração para as designações:
-> 1 - Operador
-> 2 - Gerente
-> 3 - Diretor
-> 4 - Presidente
-> 0 - NULO

Ap.2.
Essa classe irá organizar os dados da seguinte forma:

->  designação,codigo,nome,endereco,telefone,dataIngresso,salario,areaSupervisao,areaFormacao,formacaoMax'!'

Isto é, irá considerar na leitura do arquivo, que todos os campos possuem local fixo no arquivo,
bem como irá considerar que estes serão dividos por ','. Todos os dados que estiverem entre uma vírgula 
e outra, ou entre a última vírgula e o caractere '!', serão considerados. Por fim, para determinar o final de linha,
está sendo considerado que esta acaba com o caractere '!'.

Ap.3.
A organização presente irá considerar o tipo do funcionário em vários momentos, principalmente para uma consulta.
Dado o objetivo de receber, durante a execução do programa, o objeto respectivo ao funcionário, seja qual for sua classe,
fora criado a função 'retornaTipo'. Para exemplificação, caso você deseje fazer uma consulta de um objeto qualquer,
você deverá chamar a função 'retornaTipo' com o código do funcionário (ou qualquer atributo deste, com cuidado à duplicidade);
após, basta utilizá-lo na consulta.


*/





#include "aumentoSalario.h"


#include <fstream>
class GerenciaBD : public c3Presidente, ofstream{

    public:
        GerenciaBD();
        virtual ~GerenciaBD();
        
        void listarFuncionarios();
        void listarFuncionarios(int filtroCargo, string qualquerAtributo);

        void cadastrarFuncionario(int tipo);
        void cadastrarOperario(mFuncionario novo);
        void cadastrarGerente(c1Gerente novo);
        void cadastrarDiretor(c2Diretor novo);
        void cadastrarPresidente(c3Presidente novo);
        void removerFuncionario(string codigo1);
        void editaFuncionario(string codigo1, int tipo);

        void atualizaOperario(mFuncionario operario);
        void atualizaGerente(c1Gerente gerente);
        void atualizaDiretor(c2Diretor diretor);
        void atualizaPresidente(c3Presidente presidente);

        void aumentaSalarios();
        void aumentaSalarioEspecifico(string codigo);
        void aleatorizaHD();
        mFuncionario consultaOperario(string codigo);
        c1Gerente consultaGerente(string codigo);
        c2Diretor consultaDiretor(string codigo);
        c3Presidente consultaPresidente(string codigo);
        int retornaTipo(string codigo);

        void tirarFotografia(int designacao, string codigo);
        
    protected:
        ofstream arq;
        mFuncionario tempOperario;
        c1Gerente tempGerente;
        c2Diretor tempDiretor;
        c3Presidente tempPresidente;
        

};