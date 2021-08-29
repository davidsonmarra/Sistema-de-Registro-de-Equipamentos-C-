#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <fstream>
#define N 25
using namespace std;

/* 
? Uma empresa deseja controlar seus equipamentos industriais e de informatica. 
? Existem diversos equipamentos, como: notebooks, impressoras, modem, roteadores, etc.
? Cada equipamento deve estar fisicamente em um departamento da empresa.
? Somente o empregado responsável pelo departamento, o chefe, pode solicitar a compra de um novo equipamento.
*/

class TipoEquipamentos{
    private:
        string codigo;
        string descricao;
    public:
        string getCodigo(){
            return codigo;
        }
        void setCodigo(string cod){
            codigo = cod;
        }
        string getDescricao(){
            return descricao;
        }
        void setDescricao(string desc){
            descricao = desc;
        }
        TipoEquipamentos(){ // construtor para zerar o objeto quando criado
            codigo = "";
            descricao = "";
        }
        void inserirEquipamento(string cod, string desc){
            int i;
            for (i = 0; i < N; i++){ // garante que sera registrado na ultima posicao
                if (this[i].codigo == ""){
                    this[i].codigo = cod;
                    this[i].descricao = desc;
                    i = N;
                    break;
                }
            }
        }
        int pesquisaEquipamentos(string cod){
            int i;
            for(i = 0; i < N; i++){
                if (this[i].codigo == cod)
                    return i;
            }
            return N;
        }
        void atualizaEquipamentos(string cod, string desc, int i){
            this[i].codigo = cod;
            this[i].descricao = desc;
        }
        void apagaEquipamentos(int i){
            this[i].codigo = "";
            this[i].descricao = "";
        }
} vetTipoEquipamentos[N];
// tambem poderiamos declarar com: Tipo Equipamentos vetTipoEquipamentos

class Departamento : public TipoEquipamentos{
    private:
        string nome;
        string localizacao;
    public:
        Departamento() : TipoEquipamentos(){
            nome = "";
            localizacao = "";
        }
        void inserirEquipamento(string cod, string name, string desc, string local){
            int i;
            for (i = 0; i < N; i++){ // garante que sera registrado na ultima posicao
                if (this[i].getCodigo() == ""){
                    this[i].setCodigo(cod);
                    this[i].nome = name;
                    this[i].setDescricao(desc);
                    this[i].localizacao = local;
                    i = N;
                    break;
                }
            }
        }
        void atualizaEquipamentos(string cod, string name, string desc, string local, int i){
            this[i].setCodigo(cod);
            this[i].nome = name;
            this[i].setDescricao(desc);
            this[i].localizacao = local;
        }
        void apagaEquipamentos(int i){
            this[i].setCodigo("");
            this[i].nome = "";
            this[i].setDescricao("");
            this[i].localizacao = "";
        }
        string getNome(){
            return nome;
        }
        void setNome(string name){
            nome = name;
        }
        string getLocalizacao(){
            return localizacao;
        }
        int pesquisaEquipamentos(string cod){
            int i;
            for(i = 0; i < N; i++){
                if (this[i].getCodigo() == cod)
                    return i;
            }
            return N;
        }
} vetDepartamentos[N];

class Equipamentos : public Departamento{
    private:
        float preco;
        TipoEquipamentos tipo;
        Departamento departamento;
    public:
        Equipamentos() : Departamento(){
            preco = 0;
            tipo: {};
            departamento: {}; 
        }
        void setTipo(int index){
            tipo = vetTipoEquipamentos[index];
        }
        TipoEquipamentos getTipo(){
            return tipo;
        }
        void setDepartamento(int index){
            departamento = vetDepartamentos[index];
        }
        Departamento getDepartamento(){
            return departamento; 
        }
        float getPreco(){
            return preco;
        }
        void atualizaEquipamentos(string cod, string name, float prec, int i){
            this[i].setCodigo(cod);
            this[i].setNome(name);
            this[i].preco = prec;
        }
        void inserirEquipamento(string cod, string name, float prec){
            int i;
            for (i = 0; i < N; i++){ // garante que sera registrado na ultima posicao
                if (this[i].getCodigo() == ""){
                    this[i].setCodigo(cod);
                    this[i].setNome(name);
                    this[i].preco = prec;
                    i = N;
                    break;
                }
            }
        }
        int pesquisaEquipamentos(string cod){
            int i;
            for(i = 0; i < N; i++){
                if (this[i].getCodigo() == cod)
                    return i;
            }
            return N;
        }
        void apagaEquipamentos(int i){
            this[i].setCodigo("");
            this[i].setNome("");
            preco = 0;
            this[i].tipo = {};
            this[i].departamento = {};
        }
} vetEquipamentos[N];

/* Descricao: mostra na tela o menu do CRUD
Entrada: nada
Saida: o menu preenchido e o caractere que o usuario digitou
*/
char menuCRUD(){
    char flag;
    cout << "CRUD:" << endl;
    cout << "a) Insecao (Create)" << endl;
    cout << "b) Pesquisa (Read)" << endl;
    cout << "c) Atualizacao (Update)" << endl;
    cout << "d) Exclusao (Delete)" << endl;
    cout << "e) Sair" << endl;
    cout << "Entre com a opcao desejada:\t";
    do{
        cin >> flag; fflush(stdin);
        flag = tolower(flag);
        if(flag < 97 || flag > 101)
            cout << "Essa opcao nao existe. Tente novamente:\t";
    }while(flag < 97 || flag > 101);
    return flag;
}

void opcaoA(){
    char CRUD;
    string codigo;
    string descricao;
    int index, aux;
    CRUD = menuCRUD();
    switch (CRUD){
    case 'a':
        cout << "Voce selecinou inserir um tipo de equipamento." << endl;
        cout << "Entre com o codigo:\t";
        cin.ignore(256,'\n');
        getline(cin, codigo); fflush(stdin);
        cout << "Entre com a descricao:\t";
        getline(cin, descricao); fflush(stdin);
        vetTipoEquipamentos->inserirEquipamento(codigo, descricao);
        // cout << vetEquipamentos[0].getCodigo();
        break;
    case 'b':
        cout << "Voce selecinou pesquisar um tipo de equipamento." << endl;
        cout << "Entre com o codigo:\t";
        cin.ignore(256,'\n');
        getline(cin, codigo); fflush(stdin);
        index = vetTipoEquipamentos->pesquisaEquipamentos(codigo);
        if(index != N){
            cout << "Encontramos um equipamento com o codigo digitado!" << endl;
            cout << "Codigo: " << vetTipoEquipamentos[index].getCodigo() << endl;
            cout << "Descricao: " << vetTipoEquipamentos[index].getDescricao() << endl;
        }
        else
            cout << "Nao encontramos nenhum equipamento correspondente em nossa base." << endl;        
        break;
    case 'c':
        cout << "Voce selecinou atualizar um tipo de equipamento." << endl;
        cout << "Digite o codigo do equipamento que voce quer atualizar:\t";
        cin.ignore(256,'\n');
        getline(cin, codigo); fflush(stdin);
        index = vetTipoEquipamentos->pesquisaEquipamentos(codigo);
        if(index != N){
            cout << "Encontramos um equipamento com o codigo digitado!" << endl;
            cout << "Digite o novo codigo:\t";
            getline(cin, codigo); fflush(stdin);
            cout << "Digite a nova descricao:\t";
            getline(cin, descricao); fflush(stdin);
            vetTipoEquipamentos->atualizaEquipamentos(codigo, descricao, index);
        }
        else
            cout << "Nao encontramos nenhum tipo de equipamento correspondente em nossa base." << endl;
        break;
    case 'd':
        cout << "Voce selecinou excluir um tipo de equipamento." << endl;
        cout << "Digite o codigo de um tipo equipamento que voce quer apagar:\t";
        cin.ignore(256,'\n');
        getline(cin, codigo); fflush(stdin);
        index = vetTipoEquipamentos->pesquisaEquipamentos(codigo);
        if(index != N){
            cout << "Encontramos um tipo de equipamento com o codigo digitado! Podemos apagar?" << endl;
            cout << "0) Sim" << endl << "1) Nao" << endl;
            do{
                cin >> aux;
                if(aux != 1 && aux != 0)
                    cout << "Voce digitou um valor invalido. Digite 0 para sim e 1 para nao." << endl;    
            } while(aux != 1 && aux != 0);
            if(aux == 0){
                vetTipoEquipamentos->apagaEquipamentos(index);
                cout << "Apagamos esse equipamento." << endl;
            }
            else
                cout << "Voce optou por nao apagar esse tipo de equipamento." << endl;
        }
        else
            cout << "Nao encontramos nenhum tipo de equipamento correspondente em nossa base." << endl;
        break;
    case 'e':
        cout << "Voce selecinou sair." << endl;
        break;
    default:
        break;
    }
}

void opcaoB(){
    char CRUD;
    string codigo, nome;
    string descricao, localizacao;
    int index, aux;
    CRUD = menuCRUD();
    switch (CRUD){
        case 'a':
            cout << "Voce selecinou inserir um departamento." << endl;
            cout << "Entre com o codigo:\t";
            getline(cin, codigo); fflush(stdin);
            cout << "Entre com a nome:\t";
            getline(cin, nome); fflush(stdin);
            cout << "Entre com a descricao:\t";
            getline(cin, descricao); fflush(stdin);
            cout << "Entre com a localizacao:\t";
            getline(cin, localizacao); fflush(stdin);
            vetDepartamentos->inserirEquipamento(codigo, nome, descricao, localizacao);
            break;
        case 'b':
            cout << "Voce selecinou pesquisar um departamento." << endl;
            cout << "Entre com o codigo:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetDepartamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um departamento com o codigo digitado!" << endl;
                cout << "Codigo: " << vetDepartamentos[index].getCodigo() << endl;
                cout << "Nome: " << vetDepartamentos[index].getNome() << endl;
                cout << "Descricao: " << vetDepartamentos[index].getDescricao() << endl;
                cout << "Localizacao: " << vetDepartamentos[index].getLocalizacao() << endl;
            }
            else
                cout << "Nao encontramos nenhum departamento correspondente em nossa base." << endl;        
            break;
        case 'c':
            cout << "Voce selecinou atualizar um departamento." << endl;
            cout << "Digite o codigo do departamento que voce quer atualizar:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetDepartamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um departamento com o codigo digitado!" << endl;
                cout << "Digite o novo codigo:\t";
                getline(cin, codigo); fflush(stdin);
                cout << "Digite o novo nome:\t";
                getline(cin, nome); fflush(stdin);
                cout << "Digite a nova descricao:\t";
                getline(cin, descricao); fflush(stdin);
                cout << "Digite o novo localizacao:\t";
                getline(cin, localizacao); fflush(stdin);
                vetDepartamentos->atualizaEquipamentos(codigo, nome, descricao,localizacao, index);
            }
            else
                cout << "Nao encontramos nenhum departamento correspondente em nossa base." << endl;
            break;
        case 'd':
            cout << "Voce selecinou excluir um tipo departamento." << endl;
            cout << "Digite o codigo do departamento que voce quer apagar:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetDepartamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um departamento com o codigo digitado! Podemos apagar?" << endl;
                cout << "0) Sim" << endl << "1) Nao" << endl;
                do{
                    cin >> aux;
                    if(aux != 1 && aux != 0)
                        cout << "Voce digitou um valor invalido. Digite 0 para sim e 1 para nao." << endl;    
                } while(aux != 1 && aux != 0);
                if(aux == 0){
                    vetDepartamentos->apagaEquipamentos(index);
                    cout << "Apagamos esse departamento." << endl;
                }
                else
                    cout << "Voce optou por nao apagar esse departamento." << endl;
            }
            else
                cout << "Nao encontramos nenhum departamento correspondente em nossa base." << endl;
            break;
        case 'e':
            cout << "Voce selecinou sair." << endl;
            break;
        default:
            break;
    }
}

int preencheTipo(){
    string tipo;
    int i, j;
    cout << "Entre com o codigo do tipo:\t";
    getline(cin, tipo); fflush(stdin);
    for(i = 0; i < N; i++){
        if(tipo == vetTipoEquipamentos[i].getCodigo()){
            for(j = 0; j < N; j++){ // garante que sera usado uma posicao vazia
                if(vetEquipamentos[j].getCodigo() == ""){
                    vetEquipamentos[j].setTipo(i);
                    return j;
                }
            }
        }
    }
    return N;
}

int preecheDepartamento(int index){
    string departamento;
    int i;
    cout << "Entre com o codigo do departamento:\t";
    getline(cin, departamento); fflush(stdin);
    for(i = 0; i < N; i++){
        if(departamento == vetDepartamentos[i].getCodigo()){
            vetEquipamentos[i].setDepartamento(i);
            return i;
        }
    }
    return N;
}

int attTipo(int index){
    int i;
    string tipo;
    cout << "Entre com o codigo do tipo:\t";
    getline(cin, tipo); fflush(stdin);
    for(i = 0; i < N; i++){
        if(tipo == vetTipoEquipamentos[i].getCodigo()){ // garante que o código existe 
            vetEquipamentos[index].setTipo(i);
            return 0;
        }
    }
    return N;
}

int attDepartamento(int index){
    int i;
    string departamento;
    cout << "Entre com o codigo do departamento:\t";
    getline(cin, departamento); fflush(stdin);
    for(i = 0; i < N; i++){
        if(departamento == vetDepartamentos[i].getCodigo()){ // garante que o código existe 
            vetEquipamentos[index].setDepartamento(i);
            return 0;
        }
    }
    return N;
}

void attTipo_Dep(int index){
    int i, j, aux1, aux2;
    aux1 = attTipo(index);
    aux2 = attDepartamento(index);
    if(aux1 == N || aux2 == N){
        cout << "Tipo ou departamento nao existe. Eh possivel que haja um erro. Recomendamos apagar esse quipamento por completo" << endl;
    }
}

void opcaoC(){
    char CRUD;
    string codigo, nome;
    float preco;
    int index, aux, aux1, aux2;
    CRUD = menuCRUD();
    switch (CRUD){
        case 'a':
            cout << "Voce selecinou inserir um equipamento." << endl;
            cout << "Entre com o codigo:\t";
            getline(cin, codigo); fflush(stdin);
            cout << "Entre com a nome:\t";
            getline(cin, nome); fflush(stdin);
            cout << "Entre com o preco:\t";
            cin >> preco; fflush(stdin);
            aux1 = preencheTipo();
            aux2 = preecheDepartamento(aux1);
            if(aux1 == N || aux2 == N)
                cout << "O codigo do departamento ou do tipo nao existe." << endl;
            else
                vetEquipamentos->inserirEquipamento(codigo, nome, preco);
            break;
        case 'b':
            cout << "Voce selecinou pesquisar um equipamento." << endl;
            cout << "Entre com o codigo:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetEquipamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um equipamento com o codigo digitado!" << endl;
                cout << "Codigo: " << vetEquipamentos[index].getCodigo() << endl;
                cout << "Nome: " << vetEquipamentos[index].getNome() << endl;
                cout << "Preco: " << vetEquipamentos[index].getPreco() << endl;
                cout << "Tipo (Descricao): " << vetEquipamentos[index].getTipo().getDescricao() << endl;
                cout << "Departameto (nome): " << vetEquipamentos[index].getDepartamento().getNome() << endl;
                cout << "Departameto (localidade): " << vetEquipamentos[index].getDepartamento().getLocalizacao() << endl;
            }
            else
                cout << "Nao encontramos nenhum equipamento correspondente em nossa base." << endl;        
            break;
        case 'c':
            cout << "Voce selecinou atualizar um equipamento." << endl;
            cout << "Digite o codigo do equipamento que voce quer atualizar:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetEquipamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um equipamento com o codigo digitado!" << endl;
                cout << "Digite o novo codigo:\t";
                getline(cin, codigo); fflush(stdin);
                cout << "Digite o novo nome:\t";
                getline(cin, nome); fflush(stdin);
                cout << "Digite o novo preco:\t";
                cin >> preco; fflush(stdin);
                attTipo_Dep(index);
                vetEquipamentos->atualizaEquipamentos(codigo, nome, preco, index);
            }
            else
                cout << "Nao encontramos nenhum equipamento correspondente em nossa base." << endl;
            break;
        case 'd':
            cout << "Voce selecinou excluir um equipamento." << endl;
            cout << "Digite o codigo do equipamento que voce quer apagar:\t";
            getline(cin, codigo); fflush(stdin);
            index = vetEquipamentos->pesquisaEquipamentos(codigo);
            if(index != N){
                cout << "Encontramos um equipamento com o codigo digitado! Podemos apagar?" << endl;
                cout << "0) Sim" << endl << "1) Nao" << endl;
                do{
                    cin >> aux;
                    if(aux != 1 && aux != 0)
                        cout << "Voce digitou um valor invalido. Digite 0 para sim e 1 para nao." << endl;    
                } while(aux != 1 && aux != 0);
                if(aux == 0){
                    vetEquipamentos->apagaEquipamentos(index);
                    cout << "Apagamos esse equipamento." << endl;
                }
                else
                    cout << "Voce optou por nao apagar esse equipamento." << endl;
            }
            else
                cout << "Nao encontramos nenhum equipamento correspondente em nossa base." << endl;
            break;
        case 'e':
            cout << "Voce selecinou sair." << endl;
            break;
        default:
            break;
    }
}

void opcaoD(){
    int i;
    cout << "Os tipos sao:" << endl;
    for(i = 0; i < N; i++){
        if(vetTipoEquipamentos[i].getCodigo() != ""){
            cout << "Codigo: " << vetTipoEquipamentos[i].getCodigo() << endl;
            cout << "Descricao: " << vetTipoEquipamentos[i].getDescricao() << endl;
            cout << endl;
        }
    }
}

void opcaoE(){
    int i, aux;
    cout << "Voce deseja listar os departamentos: \n" << "(0) Apenas pelo codigo e nome \n" << "(1) Todos os atributos? " << endl;
    do{
        cin >> aux; fflush(stdin);
        if(aux != 0 && aux != 1)
            cout << "Valor digitado eh invalido. Tente novamente:" << endl; 
    } while(aux != 0 && aux != 1);
    for(i = 0; i < N; i++){
        if(vetDepartamentos[i].getCodigo() != ""){
            if(aux == 0){
                cout << "Codigo: " << vetDepartamentos[i].getCodigo() << endl;
                cout << "Nome: " << vetDepartamentos[i].getNome() << endl;
                cout << endl;
            }
            else{
                cout << "Codigo: " << vetDepartamentos[i].getCodigo() << endl;
                cout << "Nome: " << vetDepartamentos[i].getNome() << endl;
                cout << "Descricao: " << vetDepartamentos[i].getDescricao() << endl;
                cout << "Localizacao: " << vetDepartamentos[i].getLocalizacao() << endl;
                cout << endl;
            }
        }
    }
}

void opcaoF(){
    int i, aux;
    cout << "Voce deseja equipamentos os departamentos: \n" << "(0) Apenas pelo codigo e nome \n" << "(1) Departamento (nome) e tipo (descricao) \n" << "(2) Todos os atributos? " << endl;
    do{
        cin >> aux; fflush(stdin);
        if(aux != 0 && aux != 1 && aux != 2)
            cout << "Valor digitado eh invalido. Tente novamente:" << endl; 
    } while(aux != 0 && aux != 1 && aux != 2);
    for(i = 0; i < N; i++){
        if(vetDepartamentos[i].getCodigo() != ""){
            if(aux == 0){
                cout << "Codigo: " << vetEquipamentos[i].getCodigo() << endl;
                cout << "Nome: " << vetEquipamentos[i].getNome() << endl;
                cout << endl;
            }
            else if(aux == 1){
                cout << "Codigo: " << vetEquipamentos[i].getCodigo() << endl;
                cout << "Nome: " << vetEquipamentos[i].getNome() << endl;
                cout << "Departamento (nome): " << vetEquipamentos[i].getDepartamento().getNome() << endl;
                cout << "Descricao (tipo): " << vetEquipamentos[i].getTipo().getDescricao() << endl;
                cout << endl;
            }
            else{
                cout << "Codigo: " << vetEquipamentos[i].getCodigo() << endl;
                cout << "Nome: " << vetEquipamentos[i].getNome() << endl;
                cout << "Preco: " << vetEquipamentos[i].getPreco() << endl;
                cout << "Departamento (codigo): " << vetEquipamentos[i].getDepartamento().getCodigo() << endl;
                cout << "Departamento (nome): " << vetEquipamentos[i].getDepartamento().getNome() << endl;
                cout << "Departamento (descricao): " << vetEquipamentos[i].getDepartamento().getDescricao() << endl;
                cout << "Departamento (localizacao): " << vetEquipamentos[i].getDepartamento().getLocalizacao() << endl;
                cout << "Tipo (codigo): " << vetEquipamentos[i].getTipo().getCodigo() << endl;
                cout << "Tipo (descricao): " << vetEquipamentos[i].getTipo().getDescricao() << endl;
                cout << endl;
            }
        }
    }
}

void opcaoG(){
    string nome;
    int i;
    cout << "Aqui iremos salvar os dados em um arquivo .txt." << endl;
    cout << "Salvaremos os tipos de quipamentos, departamentos e equipamentos." << endl;
    cout << "Digite o nome do aqruivo em que deseja salvar (com a extensao):\t";
    getline(cin, nome); fflush(stdin);
    ofstream out(nome);
    out << "TIPOS DE EQUIPAMENTOS:" << endl;
    for(i = 0; i < N; i++){
        if(vetTipoEquipamentos[i].getCodigo() != ""){
            out << "Codigo: " << vetTipoEquipamentos[i].getCodigo() << endl;
            out << "Descricao: " << vetTipoEquipamentos[i].getDescricao() << endl;
            out << endl;
        }
    }
    out << "DEPARTAMENTOS:" << endl;
    for(i = 0; i < N; i++){
        if(vetDepartamentos[i].getCodigo() != ""){
            out << "Codigo: " << vetDepartamentos[i].getCodigo() << endl;
            out << "Nome: " << vetDepartamentos[i].getNome() << endl;
            out << "Descricao: " << vetDepartamentos[i].getDescricao() << endl;
            out << "Localizacao: " << vetDepartamentos[i].getLocalizacao() << endl;
            out << endl;
        }
    }
    out << "EQUIPAMENTOS:" << endl;
    for(i = 0; i < N; i++){
        if(vetEquipamentos[i].getCodigo() != ""){
            out << "Codigo: " << vetEquipamentos[i].getCodigo() << endl;
            out << "Nome: " << vetEquipamentos[i].getNome() << endl;
            out << "Preco: " << vetEquipamentos[i].getPreco() << endl;
            out << "Tipo (codigo): " << vetEquipamentos[i].getTipo().getCodigo() << endl;            
            out << "Tipo (descricao): " << vetEquipamentos[i].getTipo().getDescricao() << endl;  
            out << "Departamento (codigo): " << vetEquipamentos[i].getDepartamento().getCodigo() << endl;
            out << "Departamento (nome): " << vetEquipamentos[i].getDepartamento().getNome() << endl;
            out << "Departamento (descricao): " << vetEquipamentos[i].getDepartamento().getDescricao() << endl;
            out << "Departamento (localizacao): " << vetEquipamentos[i].getDepartamento().getLocalizacao() << endl;
            out << endl;
        }
    }
    out.close();
}

void opcaoH(){
    string leitura;
    int i;
    cout << "Aqui iremos mostrar os dados em um arquivo .txt." << endl;
    cout << "Digite o nome do aqruivo em que deseja mostrar os dados (com a extensao):\t";
    getline(cin, leitura); fflush(stdin);
    ifstream in(leitura);
    if(in.is_open()){
        while(!in.eof()){
            getline(in, leitura);
            cout << leitura << endl;
        }
    }
    else
        cout << "Erro ao abrir o arquivo.";
    in.close();
}

/* Descricao: procedimento que chama o procedimento correspondente a opcao digitada pelo usuario
Entrada: char flag => opcao que o usuario digitou
Saida: nada */
void executaMenu(char flag){
    switch(flag){
        case 'a':
            opcaoA();
            break;
        case 'b':
            opcaoB();
            break;
        case 'c':
            opcaoC();
            break;
        case 'd':
            opcaoD();
            break;
        case 'e':
            opcaoE();
            break;
        case 'f':
            opcaoF();
            break;
        case 'g':
            opcaoG();
            break;
        case 'h':
            opcaoH();
            break;
        default:
            break;
    }
}

/* Descricao: funcao booleana que seleciona a opcao do menu 
Entrada: nenhuma 
Saida: um booleano para saber se o programa deve ser encerrado */
bool menu(){
    char flag, aux;
    cout << "\nSISTEMA DE CADASTRO DE EQUIPAMENTOS" << endl;
    cout << "Envie qualquer caractere para que possamos mostrar o menu" << endl;
    cin >> aux; fflush(stdin);
    cout << "Seja em vindo! Selecione uma opcao do menu:" << endl;
    cout << "a) CRUD de tipo de equipamento (codigo e descricao)" << endl;
    cout << "b) CRUD de departamento (codigo, nome, descricao e localizacao/predio)" << endl;
    cout << "c) CRUD de equipamento (codigo, nome e preco)" << endl;
    cout << "d) Listagem de Tipos" << endl;
    cout << "e) Listagem de Departamentos" << endl;
    cout << "f) Listagem de Equipamentos" << endl;
    cout << "g) Salva dados em arquivo" << endl;
    cout << "h) Lista os dados dos equipamentos armazenados em arquivo" << endl;
    cout << "i) Sair" << endl;
    cout << "Entre com a opcao desejada:\t";
    do{
        cin.ignore(256,'\n');
        cin >> flag; fflush(stdin);
        flag = tolower(flag);
        if(flag < 97 || flag > 105)
            cout << "Essa opcao nao existe. Tente novamente:\t";
    }while(flag < 97 || flag > 105);
    if (flag == 'i')
        return false;
    else { 
        executaMenu(flag);
        return true;
    }   
}

int main(){
    while(menu()); // enquanto a saida for true o menu continuara a aparecer
    cout << "Programa finalizado. Obrigado por usar!" << endl << "Volte sempre!!!" << endl;
    return 0;
}