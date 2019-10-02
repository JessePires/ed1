#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char numero[16];
    char whatsapp[2] // S ou N;    
}Telefone;

typedef struct{
    char cep[11];
    int numero;
    char estado[3];
}Endereco;

typedef struct{
    char* nome;
    // char nome[40];
    int idade;
    char* email;
    Endereco endereco;
    Telefone* telefones[4];
    int qtdeContatos; // quantidade de contatos armazenados
}Pessoa;

typedef struct{
    char* descricao;
    Pessoa** pessoas;
    int tamVetor; // tamanho do vetor de pessoas
    int qtdePessoas; // quantidade de pessoas armazenadas
}Agenda;


Pessoa* pessoa_novo(char* nome, int idade, char* email){
    
    Pessoa* novo = (Pessoa*) malloc(sizeof(Pessoa));
    novo->nome = (char*) calloc(strlen(nome) + 1, sizeof(char) );
    strcpy(novo->nome, nome);
    novo->idade = idade;
    novo->email = (char*) calloc(strlen(email) + 1, sizeof(char) );
    strcpy(novo->email, email);
    novo->qtdeContatos = 0;

    return novo;
}

void pessoa_defineEndereco(Pessoa* p, char* cep, int num, char* estado){
    
    strcpy(p->endereco.cep, cep);
    p->endereco.numero = numero;
    strcpy(p->endereco.estado, estado);

}

void pessoa_cadastrarContato(Pessoa* p, char* numero, char* flagWhats){
    
    Telefone* contato = (Telefone*) malloc(sizeof(Telefone));
    strcpy(contato->numero, numero);
    strcpy(contato->whatsapp, flagWhats);

    p->telefones[p->qtdeContatos++] = contato;

}

// Reduzir o tamanho do vetor de pessoas pela metade quando a taxa de ocupação for inferior a 25%
void agenda_verificaReduzTamanho(Agenda* agenda){

    if(agenda->qtdeContatos < agenda->tamVetor * 0.25){

        Pessoa** newVetorPessoas = (Pessoa**) calloc(agenda->tamVetor / 2, sizeof(Pessoa*));
        
        for(int i = 0; i < agenda->qtdeContatos){

            newVetorPessoas[i] = agenda->pessoas[i];

        }

        free(agenda->pessoas);
        agenda->tamVetor /= 2;
        agenda->pessoas = newVetorPessoas;

    }


}

int agenda_consultaPorEstado(Agenda* agenda, char* estado, Telefone** referencia){

    int cont = 0;

    for(int i = 0; i < agenda->qtdeContatos; i++){

        if(strcmp(*(agenda->pessoas[i])->endereco->estado, estado)){
            
            cont++;

        }

    }

    return cont;

}

void agenda_inserirPessoa(Agenda* agenda, Pessoa* p){

    agenda->pessoas[agenda->qtdePessoas] = p;
    agenda->qtdePessoas++;

}

Pessoa* agenda_removerPessoa(Agenda* agenda, char* email){

    Pessoa* pessoaRemovida;

    for(int i = 0; i < agenda->qtdePessoas){

        if(strcmp(*(agenda->pessoas[i])->email, email)){

            pessoaRemovida = *(agenda->pessoas[i]);

        }

    }

    return pessoaRemovida;

}

void pessoa_desalocar(Pessoa* p){

    free(p->nome);
    free(p->email);
    free(p->telefones);
    free(p);

}




int main(){
    Agenda* a1 = agenda_novo("pessoal");

    Pessoa* p1 = pessoa_novo("Joao", 30, "joao@gmail.com");
    Pessoa* p2 = pessoa_novo("Maria", 20, "maria@gmail.com");

    pessoa_defineEndereco(p1, "88.888-88", 100, "PR");
    pessoa_defineEndereco(p2, "99.999-99", 200, "SP");
    

    pessoa_cadastrarContato(p1, "(44) 91111-1111", "S");
    pessoa_cadastrarContato(p1, "(41) 92222-2222", "S");
    pessoa_cadastrarContato(p1, "(44) 3033-1234", "N");

    pessoa_cadastrarContato(p2, "(44) 94444-4444", "S");
    pessoa_cadastrarContato(p2, "(44) 95555-5555", "S");

    Telefone vetPR[100], vetSP[100];
    int qtdeTelefones;
    qtdeTelefones = agenda_consultaPorEstado(a1, "PR", &vetPR);
    qtdeTelefones = agenda_consultaPorEstado(a1, "SP", &vetSP);

    agenda_inserirPessoa(a1, p1);
    agenda_inserirPessoa(a1, p2);

    Pessoa* removido = agenda_removerPessoa(a1, "joao@gmail.com");

    pessoa_desalocar(removido);

}