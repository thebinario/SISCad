//ENZO RAMON RODRIGUES ALMEIDA CUNHA		MATRICULA: 03242255
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

typedef struct Data{
	int dia,mes,ano;
}DATA;

struct Pessoa{
	char nome[10];
	int salario;
	DATA dtnasc;
	bool sts;
}pessoa[5];

void linha();
void addPessoa();
int contarPessoas();
void mostrarPessoas();
void excluir();
void alterar();
void menu();

int main(){
	
	menu();

	return 0;
}
void menu(){	
	int opc;
	do{
		printf("CADASTRO DE PESSOAS\n");
		printf("\n[1] - Cadastrar Pessoa\n");
	    printf("[2] - Alterar Pessoa\n");
	    printf("[3] - Contar quantatidades de Pessoas Armazendas\n");
	    printf("[4] - Remover uma Pessoa\n");
	    printf("[5] - Mostrar numeros armazenadas\n");
		printf("[6] - SAIR\n\n");			
	    printf("Digite a opcao desejada: ");
	    scanf("%i",&opc);
		switch(opc){
			case 1:			
				if(contarPessoas()<5){
					addPessoa();
				}
				linha();		
				break;				
			case 2:
				mostrarPessoas();
				alterar();
				linha();
				break;
			case 3:
				printf("\nNumero de pessoas cadastradas igual a: %d",contarPessoas());
				linha();	
				break;
			case 4:				
				excluir();
				linha();				
				break;
			case 5:			
				mostrarPessoas();
				linha();				
				break;
			case 6:
				break;				
			default:
				printf("Valor Invalido!");
				linha();	
		}
	}while(opc!=6);
}
void addPessoa(){
	int cont=0;
	for(int i=0;i<5;i++){
		if(pessoa[i].sts==0 || pessoa[i].sts==NULL){
			printf("Nome: ");
			scanf("%s",&pessoa[i].nome);
			printf("salario: ");
			scanf("%d",&pessoa[i].salario);
			printf("Digite o dia de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.dia);
			printf("Digite o mes de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.mes);
			printf("Digite o ano de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.ano);
			pessoa[i].sts=true;
			cont++;
			printf("Pessoa Cadastrada com Sucesso!");
			break;
		}
	}
}
int contarPessoas(){
	int cont=0;
	for(int i=0;i<5;i++){
		if(pessoa[i].sts==true){
			cont++;				
		}				
	}
	return cont;
}
void mostrarPessoas(){
	for(int i=0;i<5;i++){
		if(pessoa[i].sts==1){			
			printf("[%d]-Nome: %s 		Salario: %d		Data de nascimento: %d/%d/%d\n",i,pessoa[i].nome,pessoa[i].salario,pessoa[i].dtnasc.dia,pessoa[i].dtnasc.mes,pessoa[i].dtnasc.ano);				
		}	
	}
}
void linha(){
	printf("\n");
	system("pause");
	system("cls");	
}
void excluir(){
	char delNome[10];
	bool status=false;		
	printf("Digite o nome da Pessoa a ser excluido: ");
	scanf("%s",&delNome);	
	for(int i=0;i<5;i++){
		if(strcmp(delNome, pessoa[i].nome)==0){		
			pessoa[i].sts=false;					
			printf("\nPessoa apagada!\n\n");
			break;									
		}
	}	
}
void alterar(){
	char alteraNome[10];	
	printf("\n\nDigite o nome da pessoa a ser alterada\n");
	scanf("%s",&alteraNome);
	for(int i=0;i<5;i++){
		if(strcmp(alteraNome,pessoa[i].nome)==0){
			printf("Novo Nome: ");
			scanf("%s",&pessoa[i].nome);		
			printf("Novo Salario: \n");
			scanf("%d",&pessoa[i].salario);
			printf("Digite o dia de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.dia);
			printf("Digite o mes de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.mes);
			printf("Digite o ano de Nascimento: ");
			scanf("%d",&pessoa[i].dtnasc.ano);	
			printf("\nCadastro alterado com sucesso!\n");
		}
	}
}