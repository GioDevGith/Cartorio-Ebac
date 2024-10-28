#include <stdio.h> //Biblioteca de comunica��o com Usu�rio 
#include <stdlib.h> //Biblioteca de Aloca��o de espa�o em Mem�ria
#include <locale.h> //Biblioteca de Aloca��o de texto por regi�o 
#include <string.h> //Bibliote respons�vel por cuidar das string

int registro() //Fun��o responsavel por cadastrar usuarios no sistema
{ 
        //inicio cria��o de vari�veis/string
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
        //inicio cria��o de vari�veis/string
        
    printf("Digite o CPF a ser cadastrado: "); //coletando info do usu�rio
        scanf("%s", cpf); //%s refere-se a string
    
    strcpy(arquivo, cpf); //Responsavel por copiar os valores das string
    
    FILE *file; //cria o arquivo
    file = fopen(arquivo, "w"); //cria o arquivo e o "w" significa escrever
        fprintf(file,cpf); //salvo valor da variavel
        fclose(file); //fecha arquivo
    
    file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
    printf("Digite o Nome a ser cadastrado: ");
        scanf("%s",nome);
        
    file = fopen(arquivo, "a");
        fprintf(file,nome);
        fclose(file);
        
    file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
    printf("Digite o Sobreome a ser cadastrado: ");
        scanf("%s",sobrenome);
        
    file = fopen(arquivo, "a");
        fprintf(file,sobrenome);
        fclose(file);
        
	file = fopen(arquivo, "a");
        fprintf(file,",");
        fclose(file);
        
    printf("Digite o cargo a ser cadastrado: ");
        scanf("%s",cargo);
    
    file = fopen(arquivo, "a");
        fprintf(file,cargo);
        fclose(file);
        
    system("pause");
 
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
    char cpf[40];
    char conteudo[200];
    
    printf("Digite o CPF a ser consultado: ");
        scanf("%s",cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    
    if(file == NULL)
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)
    {
    	printf("\nEssas s�o as informa��es do usu�rio: ");
    	printf("%s", conteudo);
    	printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	    scanf("%s",cpf);
	    
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
}

int main ()
{
	int opcao=0; //Definido Vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		
		system("cls");
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cart�rio da EBAC ### \n\n"); //Inicio do menu
	    printf("Escolha a op��o desejada do menu:\n\n");
	    printf("\t1 - Registrar nomes\n"); 
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n"); 
	    printf("\t4 - Sair do Sistema\n\n");
	    printf("Op��o: "); //Fim do menu
	
	    scanf("%d", &opcao); //Armazenando a escolha do usu�rio
	
	    system("cls"); //responsavel por limpar a tela
	    
	    switch(opcao) //inicio da sele��o do menu
	    {
	    	case 1:
	    	    registro(); //chamada de fun��es
		        break;
		        
		    case 2: 
		        consulta();
		        break;
		    
		    case 3:
		    	deletar();
		        break;
		        
		    case 4:
		    	printf("Obrigado por ultilizar esse sitema!\n");
		    	return 0;
		    	break; 
		        
		    default: 
		        printf("Essa opi��o n�o esta disponivel!\n");
		        system("pause"); 
		        break;
		} //fim da sele��o
    }
}
