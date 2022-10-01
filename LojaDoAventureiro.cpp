#include <iostream>
#include <locale.h>
#include <vector>
#include <algorithm>
#include <atomic>
#include <stdio.h>
#include <cmath>

static std::atomic<std::uint32_t> idAtual;
static std::atomic<std::uint32_t> idAtualVenda;

class Itens{
private:
    int id, qtdEstoque;
    std::string nome, tipo;
    float custo;
    
public:  //metodos get e set
    int& getId(){
        return id;
    }

    void setId(const int id){
        this->id = id;
    }

    std::string& getNome(){
        return nome;
    }
    void setNome(std::string nome){
        this->nome = nome;
    }

    std::string& getTipo(){
        return tipo;
    }
    void setTipo(std::string tipo){
        this->tipo = tipo;
    }

    float& getCusto(){
        return custo;
    }
    void setCusto(float custo){
        this->custo = custo;
    }

    int& getQtdEstoque(){
        return qtdEstoque;
    }
    void setQtdEstoque(int qtdEstoque){
        this->qtdEstoque = qtdEstoque;
    }
};

class Armamentos: public Itens{
private:
    float dano;
public:
    float& getDano(){
        return dano;
    }
    void setDano(float dano){
        this->dano = dano;
    }

    Armamentos(std::string nome, std::string tipo, float custo, float dano){
        this->setId(idAtual++);
        this->setNome(nome);
        this->setTipo(tipo);
        this->setCusto(custo);
        this->setDano(dano);
        this->setQtdEstoque(0);
        system("clear||cls");
        std::cout << "Armamento criado com sucesso!\n\n";
    }
};

std::vector <Armamentos> listaArmamentos;
std::vector <Armamentos>::iterator armamento;

class Armaduras: public Itens{
private:
    float durabilidade;
public:
    float& getDurabilidade(){
        return durabilidade;
    }
    void setDurabilidade(float durabilidade){
        this->durabilidade = durabilidade;
    }

    Armaduras(std::string nome, std::string tipo, float custo, float durabilidade){
        this->setId(idAtual++);
        this->setNome(nome);
        this->setTipo(tipo);
        this->setCusto(custo);
        this->setDurabilidade(durabilidade);
        this->setQtdEstoque(0);
        // system("clear||cls");
        std::cout << "Armadura criada com sucesso!\n\n";
    }
};

std::vector <Armaduras> listaArmaduras;
std::vector <Armaduras>::iterator armadura;

class Consumiveis: public Itens{
private:
    int usos;
public:
    int& getUsos(){
        return usos;
    }
    void setUsos(int usos){
        this->usos = usos;
    }

    Consumiveis(std::string nome, std::string tipo, float custo, int usos){
        this->setId(idAtual++);
        this->setNome(nome);
        this->setTipo(tipo);
        this->setCusto(custo);
        this->setUsos(usos);
        this->setQtdEstoque(0);
        // system("clear||cls");
        std::cout << "Consumivel criado com sucesso!\n\n";
    }
};

std::vector <Consumiveis> listaConsumiveis;
std::vector <Consumiveis>::iterator consumivel;

class LogVendas {
private:
    int idVenda, idItem, qtdItens;
    std::string nomeItem;
    float custoInicial, custoFinal;

public:
    LogVendas(){}

    int& getIdVenda() {
        return idVenda;
    }

    void setIdVenda(int idVenda) {
        this->idVenda = idVenda;
    }

    int& getIdItem() {
        return idItem;
    }

    void setIdItem(int idItem) {
        this->idItem = idItem;
    }

    int& getQtdItens() {
        return qtdItens;
    }

    void setQtdItens(int qtdItens) {
        this->qtdItens = qtdItens;
    }

    std::string& getNomeItem() {
        return nomeItem;
    }

    void setNomeItem(std::string nomeItem) {
        this->nomeItem = nomeItem;
    }

    float& getCustoInicial() {
        return custoInicial;
    }

    void setCustoInicial(float custoInicial) {
        this->custoInicial = custoInicial;
    }

    float& getCustoFinal() {
        return custoFinal;
    }

    void setCustoFinal(float custoFinal) {
        this->custoFinal = custoFinal;
    }

    LogVendas(int idItem, int qtdItens, std::string nomeItem, float custoInicial, float custoFinal) {
        this->idVenda = idAtualVenda++;
        this->idItem = idItem;
        this->qtdItens = qtdItens;
        this->nomeItem = nomeItem;
        this->custoInicial = custoInicial;
        this->custoFinal = custoFinal;
    }

};

std::vector <LogVendas> listaLogVendas;
std::vector <LogVendas>::iterator logVenda;

class Estoque{
public:
    void menuEstoque(){
        int escolhaEstoque;
        do {
            std::cout << "\nESTOQUE\nEscolha um numero:\n(1) Cadastro de itens\n(2) Remocao de itens\n(3) Adicao de unidades\n(4) Listagem de estoque\n(5) Exportacao de estoque\n(6) Importacao de estoque\n(0) Voltar ao menu anterior\nEscolha:";
            std::cin>>escolhaEstoque;
            switch (escolhaEstoque){ 
                case 1:
                    cadastrarItem();
                    break;
                    
                case 2:
                    removerItem();
                    break;

                case 3:
                    adicionarUnidade();
                    break;

                case 4:
                    listarEstoque();
                    break;

                case 5:
                    exportarEstoque();
                    break;

                case 6:
                    importarEstoque();
                    break;
                                        
                case 0: //voltar ao menu principal
                    break;
                    
                default:  //codigo errado
                    std::cout << "São aceitos apenas os números (0) (1) (2) (3) (4) (5) (6)\n";
                    break;
                }

        } while(escolhaEstoque != 0);
    }

    void cadastrarItem(){
        int itemCadastrar, usos;
        std::string nome, tipo;
        float custo, dano, durabilidade;
        // system("clear||cls");
        std::cout << "CADASTRAR ITENS\nEscolha um item para cadastrar\n(1) Armamento\n(2) Armadura\n(3) Consumivel\n(0) Voltar ao menu anterior\nEscolha:";
        std::cin >> itemCadastrar;
        switch(itemCadastrar){
            case 1:
                // system("clear||cls");
                std::cout << "Cadastrar armamento:\n";//Nome, Tipo, Custo, Dano
                std::cout << "Digite o nome:";
                std::cin >> nome;
                std::cout << "Digite o tipo:";
                std::cin >> tipo;
                std::cout << "Digite o custo:";
                std::cin >> custo;
                std::cout << "Digite o dano:";
                std::cin >> dano;

                listaArmamentos.push_back(Armamentos(nome, tipo, custo, dano));
                
                break;

            case 2:
                // system("clear||cls");
                std::cout << "Cadastrar armadura:\n";
                std::cout << "Digite o nome:";
                std::cin >> nome;
                std::cout << "\nDigite o tipo:";
                std::cin >> tipo;
                std::cout << "\nDigite o custo:";
                std::cin >> custo;
                std::cout << "\nDigite a durabilidade:";
                std::cin >> durabilidade;

                listaArmaduras.push_back(Armaduras(nome, tipo, custo, durabilidade));

                break;

            case 3:
                // system("clear||cls");
                std::cout << "Cadastrar consumivel:";

                std::cout << "\nDigite o nome:";
                std::cin >> nome;
                std::cout << "\nDigite o tipo:";
                std::cin >> tipo;
                std::cout << "\nDigite o custo:";
                std::cin >> custo;
                std::cout << "\nDigite a quantidade de usos:";
                std::cin >> usos;

                listaConsumiveis.push_back(Consumiveis(nome, tipo, custo, usos));

                break;

            case 0:                 //VOLTAR AO MENU ANTERIOR
                // system("clear||cls");
                break;

            default:
                // system("clear||cls");
                std::cout << "Opcao invalida!";
                break;
        }
    }

    void removerItem(){
        int escolhaRemoveItem = -1;
        do
        {
            std::cout << "Voce quer remover qual tipo de item?\n";
            std::cout << "1 - Armamento\n2 - Armadura\n3 - Consumivel\nEscolha?" ;
            std::cin >> escolhaRemoveItem;
            switch (escolhaRemoveItem)
            {
            case 1:
                if(removeArmamento()){
                    escolhaRemoveItem = 0;
                }
                break;

            case 2:
                if(removeArmadura()){
                    escolhaRemoveItem = 0;
                }
                break;

            case 3:
                if(removeConsumivel()){
                    escolhaRemoveItem = 0;
                }
                break;

            case 0:
                break;

            default:
                std::cout << "Escolha inválida!";
                break;
            }
        } while(escolhaRemoveItem != 0);
    }

    bool removeArmamento(){   //funcao que retorna verdadeiro se o armamento for removido
        int idEscolhido;     
        listarArmamentos();
        std::cout << "Escolha o ID do armamento que deseja remover: ";
        std::cin >> idEscolhido;
        //funcao que percorre a lista de armamentos até achar o id escolhido pelo usuario
        for(armamento = listaArmamentos.begin(); armamento != listaArmamentos.end(); armamento++){
            if (armamento->getId() == idEscolhido){  //se o armamento for encontrado 
                listaArmamentos.erase(armamento);   //ele sera removido
                std::cout << "Armamento removido com sucesso!\n";
                return true;                       // e retornara verdadeiro
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    bool removeArmadura(){ 
        int idEscolhido;
        listarArmaduras();
        std::cout << "Escolha o ID da armadura que deseja remover: ";
        std::cin >> idEscolhido;

        for(armadura = listaArmaduras.begin(); armadura != listaArmaduras.end(); armadura++){
            if (consumivel->getId() == idEscolhido){
                listaArmaduras.erase(armadura);
                std::cout << "Armadura removida com sucesso!\n";
                return true;
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    bool removeConsumivel(){
        int idEscolhido;
        listarConsumiveis();
        std::cout << "Escolha o ID do consumivel que deseja remover: ";
        std::cin >> idEscolhido;

        for(consumivel = listaConsumiveis.begin(); consumivel != listaConsumiveis.end(); consumivel++){
            if (consumivel->getId() == idEscolhido){
                listaConsumiveis.erase(consumivel);
                std::cout << "Consumivel removido com sucesso!\n";
                return true;
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    void adicionarUnidade(){
        int escolhaAdicionaItem = -1;
        do{           
            std::cout << "Voce quer adicionar qual tipo de item?\n";
            std::cout << "1 - Armamento\n2 - Armadura\n3 - Consumivel\n0 - Voltar\nEscolha?" ;
            std::cin >> escolhaAdicionaItem;
            switch (escolhaAdicionaItem)
            {
            case 1:
                if(adicionaArmamento()){
                    escolhaAdicionaItem = 0;
                }
                break;

            case 2:
                if(adicionaArmadura()){
                    escolhaAdicionaItem = 0;
                }
                break;

            case 3:
                if(adicionaConsumivel()){
                    escolhaAdicionaItem = 0;
                }
                break;

            case 0:
                break;

            default:
                std::cout << "Escolha inválida!";
                break;
            }
        } while(escolhaAdicionaItem != 0);
    }

    bool adicionaArmamento(){
        int idEscolhido, unidades;
        listarArmamentos();
        std::cout << "Escolha o ID do armamento para adicionar unidades:\n";
        std::cin >> idEscolhido;
        
        for(armamento = listaArmamentos.begin(); armamento != listaArmamentos.end(); armamento++){
            if (armamento->getId() == idEscolhido){
                std::cout << "Qual a quantidade de unidades para serem adicionadas?\n" ;
                std::cin >> unidades;
                armamento->setQtdEstoque(armamento->getQtdEstoque() + unidades);
                std::cout << unidades << " unidades adicionadas com sucesso!\n";
                return true;
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    bool adicionaArmadura(){
        int idEscolhido, unidades;
        listarArmaduras();
        std::cout << "Escolha o ID da armadura para adicionar unidades:\n";
        std::cin >> idEscolhido;
        
        for(armadura = listaArmaduras.begin(); armadura != listaArmaduras.end(); armadura++){
            if (armadura->getId() == idEscolhido){
                std::cout << "Qual a quantidade de unidades para serem adicionadas?\n" ;
                std::cin >> unidades;
                armadura->setQtdEstoque(armadura->getQtdEstoque() + unidades);
                std::cout << unidades << " unidades adicionadas com sucesso!\n";
                return true;
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    bool adicionaConsumivel(){
        int idEscolhido, unidades;
        listarConsumiveis();
        std::cout << "Escolha o ID do consumivel para adicionar unidades:\n";
        std::cin >> idEscolhido;
        
        for(consumivel = listaConsumiveis.begin(); consumivel != listaConsumiveis.end(); consumivel++){
            if (consumivel->getId() == idEscolhido){
                std::cout << "Qual a quantidade de unidades para serem adicionadas?\n" ;
                std::cin >> unidades;
                consumivel->setQtdEstoque(consumivel->getQtdEstoque() + unidades);
                std::cout << unidades << " unidades adicionadas com sucesso!\n";
                return true;
            }
        }
        std::cout << "ID nao encontrado!";
        return false;
    }

    void listarArmamentos(){    // lista todos armamentos ja feitos
        std::cout << "\nLista de armamentos: " << '\n';
        for(armamento = listaArmamentos.begin(); armamento != listaArmamentos.end(); armamento++){
            std::cout << "ID: " << armamento->getId() << '\n';
            std::cout << "Nome: " << armamento->getNome() << '\n';
            std::cout << "Tipo: " << armamento->getTipo() << '\n';
            std::cout << "Custo: " << armamento->getCusto() << " PO\n";
            std::cout << "Dano: " << armamento->getDano() << '\n';
            std::cout << "Unidades em estoque: " << armamento->getQtdEstoque() << "\n\n";
        }
    }

    void listarArmaduras(){
        std::cout << "\nLista de armaduras: " << '\n';
        for(armadura = listaArmaduras.begin(); armadura != listaArmaduras.end(); armadura++){
            std::cout << "ID: " << armadura->getId() << '\n';
            std::cout << "Nome: " << armadura->getNome() << '\n';
            std::cout << "Tipo: " << armadura->getTipo() << '\n';
            std::cout << "Custo: " << armadura->getCusto() << " PO\n";
            std::cout << "Durabilidade: " << armadura->getDurabilidade() << '\n';
            std::cout << "Unidades em estoque: " << armadura->getQtdEstoque() << "\n\n";
        }
    }

    void listarConsumiveis(){
        std::cout << "\nLista de consumiveis: " << '\n';
        for(consumivel = listaConsumiveis.begin(); consumivel != listaConsumiveis.end(); consumivel++){
            std::cout << "ID: " << consumivel->getId() << '\n';
            std::cout << "Nome: " << consumivel->getNome() << '\n';
            std::cout << "Tipo: " << consumivel->getTipo() << '\n';
            std::cout << "Custo: " << consumivel->getCusto() << " PO\n";
            std::cout << "Usos: " << consumivel->getUsos() << '\n';
            std::cout << "Unidades em estoque: " << consumivel->getQtdEstoque() << "\n\n";
        }
    }

    void listarEstoque(){   //lista todos os itens do estoque
        // system("clear||cls");
        std::cout << "Lista de itens:\n";
        listarArmaduras();
        listarArmamentos();
        listarConsumiveis();
    }

    void exportarEstoque(){   //cria um arquvo .txt com todo o estoque atual
        exportarArmamentos(); 
        exportarArmaduras();
        exportarConsumiveis();
        std::cout << "Exportacao concluida!";
    }

    void exportarArmamentos(){
        int resultado;
        FILE *arquivo;
        arquivo = fopen("Estoque.txt", "a");// cria um arquivo chamado Estoque.txt
        if (arquivo == NULL) // Se nao conseguiu criar
        {
            printf("Falha ao criar arquivo!\n");
            exit(0); //se falar encerra o programa
        }   //percorre a lista de armamentos e vai escrevendo no arquivo Estoque.txt todos os armamentos
        for (armamento = listaArmamentos.begin(); armamento != listaArmamentos.end(); armamento++){
            resultado = fprintf(arquivo,"ID -> %d; Nome -> %s; Tipo -> %s; Custo -> %.2f PO; Dano -> %.2f; Unidades em estoque -> %d\n\n",
                                armamento->getId(), armamento->getNome().c_str(), armamento->getTipo().c_str(), 
                                armamento->getCusto(), armamento->getDano(), armamento->getQtdEstoque()
                                );  					  
            if (resultado == EOF)		    
                printf("Erro na Gravacao\n");
                fclose(arquivo);
                break;
        }
        fclose(arquivo);
    }

    void exportarArmaduras(){
        int resultado;
        FILE *arquivo;
        arquivo = fopen("Estoque.txt", "a");
        if (arquivo == NULL) // Se nao conseguiu criar
        {
            printf("Falha ao criar arquivo!\n");
            exit(0); //chama devolta a funcao
        }
        for (armadura = listaArmaduras.begin(); armadura != listaArmaduras.end(); armadura++){

            resultado = fprintf(arquivo,"ID -> %d; Nome-> %s; Tipo -> %s; Custo -> %.2f PO; Durabilidade -> %.2f; Unidades em estoque -> %d\n\n",
                            armadura->getId(), armadura->getNome().c_str(), armadura->getTipo().c_str(), 
                            armadura->getCusto(), armadura->getDurabilidade(), armadura->getQtdEstoque()
                            );  					  
            if (resultado == EOF)		    
                printf("Erro na Gravacao\n");
                fclose(arquivo);
                break;
        }
        fclose(arquivo);
    }

    void exportarConsumiveis(){
        int resultado;
        FILE *arquivo;
        arquivo = fopen("Estoque.txt", "a");
        if (arquivo == NULL) // Se nao conseguiu criar
        {
            printf("Falha ao criar arquivo!\n");
            exit(0); //chama devolta a funcao
        }
        for (consumivel = listaConsumiveis.begin(); consumivel != listaConsumiveis.end(); consumivel++){

            resultado = fprintf(arquivo,"ID -> %d; Nome -> %s; Tipo -> %s; Custo -> %.2f PO; Usos -> %d; Unidades em estoque -> %d\n\n",
                            consumivel->getId(), consumivel->getNome().c_str(), consumivel->getTipo().c_str(), 
                            consumivel->getCusto(), consumivel->getUsos(), consumivel->getQtdEstoque()
                            );  					  
            if (resultado == EOF)		    
                printf("Erro na Gravacao\n");
                fclose(arquivo);
                break;
        }
        fclose(arquivo);
    }

    void importarEstoque(){

    }

};

class Vendas:public Estoque, public LogVendas{
private:
    int idVenda;
public:
    Vendas(){}

    void menuVendas(){
        int escolhaMenuVendas;
        do{
            std::cout << "MENU DE VENDAS \nEscolha uma opcao:\n1 - Venda de itens\n2 - Log de vendas\n3 - Exportacao de log de vendas\n0 - Voltar ao menu anterior\n";
            switch (escolhaMenuVendas){
            case 1:
                venderItens();
                break;

            case 2:
                chamaLogVendas();
                break;

            case 3:
                exportarLogVendas();
                break;

            case 0:
                break;
            
            default:
                std::cout << "Opcao invalida!";
                break;
            }
        } while(escolhaMenuVendas);
    }

    void venderItens(){
        int escolhaVendaItem = -1;
        do{
            std::cout << "Voce quer vender qual tipo de item?\n";
            std::cout << "1 - Armamento\n2 - Armadura\n3 - Consumivel\nEscolha?" ;
            std::cin >> escolhaVendaItem;
            switch (escolhaVendaItem)
            {
            case 1:
                if(venderArmamentos())
                break;

            case 2:
                if(venderArmaduras())
                break;

            case 3:
                if(venderConsumiveis())
                break;

            case 0:
                break;

            default:
                std::cout << "Escolha inválida!";
                break;
            }
        } while(escolhaVendaItem != 0);
    }

    bool venderArmamentos(){
        int idEscolhido, unidades, desconto;
        float valorUnitario;
        listarArmamentos();
        std::cout << "Escolha o ID do armamento para vender unidades:\n";
        std::cin >> idEscolhido;
        
        for(armamento = listaArmamentos.begin(); armamento != listaArmamentos.end(); armamento++){
            if (armamento->getId() == idEscolhido){
                int prossegue, escolhe;
                valorUnitario = armamento->getCusto();
                do{
                    std::cout << "Quantas unidades deseja vender?\n" ;
                    std::cin >> unidades;
                    if(armamento->getQtdEstoque() >= unidades){ 
                        desconto = 2 * qtdPrimos(unidades);
                        std::cout << "Tela de confirmacao:\nCusto da unidade: " << valorUnitario << " PO\nValor sem desconto: " << unidades * valorUnitario << " PO\nDesconto: " << desconto << "%\nDesconto total: " << desconto * valorUnitario * 0.01 <<" PO\nValor com desconto: " << (1 - (desconto * valorUnitario * 0.0001)) * valorUnitario << " PO\nTem certeza que dejesa prosseguir?\n1 - Sim\n2 - Nao\n";
                        std::cin >> prossegue;
                        switch (prossegue){
                        case 1:
                            armamento->setQtdEstoque(armamento->getQtdEstoque() - unidades); //VENDIDO AQUI!!
                            listaLogVendas.push_back(LogVendas(idEscolhido, unidades, armamento->getNome(), unidades * valorUnitario, (1 - (desconto * valorUnitario * 0.0001)) * valorUnitario));
                            if(unidades == 1){
                                std::cout <<"Uma unidade vendida com sucesso!\n";
                                return true;
                            }else{
                                std::cout << unidades << " unidades vendidas com sucesso!\n";
                                return true;
                            }
                            escolhe = 0;
                            break;

                        case 2:
                            escolhe = 0;
                            break;

                        default:
                            std::cout << "Escolha invalida!\n";
                            break;
                        }
                    }else{
                        std::cout << "Só tem " << armamento->getQtdEstoque() << " deste item no estoque! Escolha outra quantia!\n";
                    }
                } while (escolhe != 0);
            }
        }
        return false;
    }

    bool venderArmaduras(){
        int idEscolhido, unidades, desconto;
        float valorUnitario;
        listarArmaduras();
        std::cout << "Escolha o ID da armadura para vender unidades:\n";
        std::cin >> idEscolhido;
        
        for(armadura = listaArmaduras.begin(); armadura != listaArmaduras.end(); armadura++){
            if (armadura->getId() == idEscolhido){
                int prossegue, escolhe;
                valorUnitario = armadura->getCusto();
                do{
                    std::cout << "Quantas unidades deseja vender?\n" ;
                    std::cin >> unidades;
                    if(armadura->getQtdEstoque() >= unidades){ 
                        desconto = 2 * qtdPrimos(unidades);
                        std::cout << "Tela de confirmacao:\nCusto da unidade: " << valorUnitario << " PO\nValor sem desconto: " << unidades * valorUnitario << " PO\nDesconto: " << desconto << "%\nDesconto total: " << desconto * valorUnitario * 0.01 <<" PO\nValor com desconto: " << 1 - desconto * valorUnitario * 0.0001 << " PO\nTem certeza que dejesa prosseguir?\n1 - Sim\n2 - Nao\n";
                        std::cin >> prossegue;
                        switch (prossegue){
                        case 1:
                            armadura->setQtdEstoque(armadura->getQtdEstoque() - unidades); //VENDIDO AQUI!!
                            listaLogVendas.push_back(LogVendas(idEscolhido, unidades, armadura->getNome(), unidades * valorUnitario, (1 - (desconto * valorUnitario * 0.0001)) * valorUnitario));
                            if(unidades == 1){
                                std::cout <<"Uma unidade vendida com sucesso!\n";
                                return true;
                            }else{
                                std::cout << unidades << " unidades vendidas com sucesso!\n";
                                return true;
                            }
                            escolhe = 0;
                            break;
                        case 2:
                            escolhe = 0;
                            break;

                        default:
                            std::cout << "Escolha invalida!\n";
                            break;
                        }
                    }else{
                        std::cout << "Só tem " << armadura->getQtdEstoque() << " deste item no estoque! Escolha outra quantia!\n";
                    }
                } while (escolhe != 0);
            }
        }
        return false;
    }

    bool venderConsumiveis(){
        int idEscolhido, unidades, desconto;
        float valorUnitario;
        listarConsumiveis();
        std::cout << "Escolha o ID do consumivel para vender unidades:\n";
        std::cin >> idEscolhido;
        
        for(consumivel = listaConsumiveis.begin(); consumivel != listaConsumiveis.end(); consumivel++){
            if (consumivel->getId() == idEscolhido){
                int prossegue, escolhe;
                valorUnitario = consumivel->getCusto();
                do{
                    std::cout << "Quantas unidades deseja vender?\n" ;
                    std::cin >> unidades;
                    if(consumivel->getQtdEstoque() >= unidades){ 
                        desconto = 2 * qtdPrimos(unidades);
                        std::cout << "Tela de confirmacao:\nCusto da unidade: " << valorUnitario << " PO\nValor sem desconto: " << unidades * valorUnitario << " PO\nDesconto: " << desconto << "%\nDesconto total: " << desconto * valorUnitario * 0.01 <<" PO\nValor com desconto: " << 1 - desconto * valorUnitario * 0.0001 << " PO\nTem certeza que dejesa prosseguir?\n1 - Sim\n2 - Nao\n";
                        std::cin >> prossegue;
                        switch (prossegue){
                        case 1:  //SIM
                            consumivel->setQtdEstoque(consumivel->getQtdEstoque() - unidades); //VENDIDO AQUI!!
                            listaLogVendas.push_back(LogVendas(idEscolhido, unidades, consumivel->getNome(), unidades * valorUnitario, (1 - (desconto * valorUnitario * 0.0001)) * valorUnitario));
                            if(unidades == 1){
                                std::cout <<"Uma unidade vendida com sucesso!\n";
                                return true;
                            }else{
                                std::cout << unidades << " unidades vendidas com sucesso!\n";
                                return true;
                            }
                            escolhe = 0;
                            break;

                        case 2:  //NAO
                            escolhe = 0;
                            break;

                        default:
                            std::cout << "Escolha invalida!\n";
                            break;
                        }
                    }else{
                        std::cout << "Só tem " << consumivel->getQtdEstoque() << " deste item no estoque! Escolha outra quantia!\n";
                    }
                } while (escolhe != 0);
            }
        }
        return false;
    }

    bool ehPrimo(int numero){
        int divisores = 0;
        for (int i = 2; i <= sqrt(numero); i++){
            if (numero % i == 0){
                divisores++;
            }
        }
        if (divisores == 1){
            return true;
        }
        return false;
    }

    int qtdPrimos(int numero){ //10
        int cont = 0;
        for (int i = 0; i <= numero; i++){
            if (ehPrimo(i)){
                cont++;
            }
        }
        return cont;
    }

    void chamaLogVendas(){   //lista todos os log de vendas ja feitos
        std::cout << "\nLogs de vendas: " << '\n';
        for(logVenda = listaLogVendas.begin(); logVenda != listaLogVendas.end(); logVenda++){
            std::cout << "ID da venda: " << logVenda->getIdVenda() << '\n';
            std::cout << "ID do item vendido: " << logVenda->getIdItem() << '\n';
            std::cout << "Quantidade de itens vendidos: " << logVenda->getQtdItens() << '\n';
            std::cout << "Nome do item vendido: " << logVenda->getNomeItem() << " PO\n";
            std::cout << "Valor sem desconto: " << logVenda->getCustoInicial() << '\n';
            std::cout << "Valor com desconto: " << logVenda->getCustoFinal() << "\n\n";
        }
    }

    void exportarLogVendas(){
        int resultadoLog;
        FILE *arquivoLog;
        arquivoLog = fopen("LogVendas.txt", "a"); //w, r, a, 
        if (arquivoLog == NULL) // Se nao conseguiu criar
        {
            printf("Falha ao criar arquivo!\n");
            exit(0); //chama devolta a funcao
        }
        for (logVenda = listaLogVendas.begin(); logVenda != listaLogVendas.end(); logVenda++){
            resultadoLog = fprintf(arquivoLog,"ID da venda -> %d;ID do item -> %d;  Nome do item -> %s; Quantidade de itens vendidos -> %d; Valor sem desconto -> %.2f PO; Valor com desconto -> %.2f PO\n\n",
                                logVenda->getIdVenda(), logVenda->getIdItem(), logVenda->getNomeItem().c_str(), 
                                logVenda->getQtdItens(), logVenda->getCustoInicial(), logVenda->getCustoFinal()
                                );
            if (resultadoLog == EOF)		    
                printf("Erro na Gravacao\n");
                fclose(arquivoLog);
                break;
        }
        fclose(arquivoLog);
    }
};

class Menu: public Vendas{
public:
    void menuPrincipal(){
        int escolha = -1;
        Estoque estoque;
        Vendas vendas;
        do {
            std::cout << "********************\n** MENU PRINCIPAL **\n********************\n1 - Menu de estoque\n2 - Menu de vendas\n0 - Sair\nEscolha:";
            std::cin>>escolha;
            switch (escolha) { 
                case 1:
                    estoque.menuEstoque();
                    break;
                    
                case 2:
                    vendas.menuVendas();
                    break;
                    
                case 0: //sair
                    std::cout << "Obrigado por utilizar a nossa Loja do Aventureiro! s2\n";
                    break;
                    
                default:  //codigo errado
                    std::cout << "São aceitos apenas os números (0) (1) (2)\n";
                    break;
                }
        } while(escolha != 0);
    }
};

int main(){
    setlocale(LC_ALL, "Portuguese");
    Menu menu;
    menu.menuPrincipal();
   
    return 0;
}
