/***************************
Autor: Daniel Cavalcante Dourado
Componente Curricular: MI Algoritmos
Concluido em: 11/06/2018
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
******************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	struct CadastroAluno{/*Tipo especial de vari�vel que cont�m outras vari�veis*/
		char Categoria[20];/*Vetor respons�vel por armazenar a categoria das equipes*/
		char NomeEquipe[20];/*Vetor respons�vel por armazenar o nome de cada equipe*/
	 };
	 void EntradaArquivo(struct CadastroAluno cad[],int numEquipe[], char jurados[],char criterios[],char nome[],char inicial[],float matriz[][25],int i, int j);
	 //Fun��o para o cadastro via arquivo .txt
	 void Manual(struct CadastroAluno cad[],float matriz[10][25], int i, int j, int k,int numEquipe[]);
	 //funcao para o cadastro manual
	 void Medias(float matriz[][25],float matrizR[][6],int i,int j,struct CadastroAluno cad[],int indice[],float vetorponderada[]);
	 //fun��o para calcular as medias
	 void Ordenar(int i,int j,float vetorponderada[],int indice[]);	
	 //fun��o para ordenar as notas
	 void Exibir(int i,int j,struct CadastroAluno cad[],float matrizR[][6],int indice[10],float vetorponderada[]);
	//Fun��o para criar o arquivo de saida
int main(){
	char nome[100],inicial[12];
	int escolha;//Variavel que armazena a escola do usuario entre entrada manula ou por arquivo
	int i,j,k;//Variaveis utilizadas nos la�os for
	int numEquipe[10];//matriz dos numeros das equipes
	float matrizR[10][6];//matriz com as notas medias de cada criterio e com a media ponderada das 10 equipes
	char jurados[100],criterios[100];//matrizes responsaveis por armazenar dados dos jurados e criterios, do arquivo de entrada
	struct CadastroAluno cad[10];//struct utilizado no cadastro das equipes
	float matriz[10][25];//matriz de notas
	int indice[10]={0,1,2,3,4,5,6,7,8,9};//variavel auxiliar utilizada pra ordenar
	float vetorponderada[10];//vetor com as notas ponderadas usada pra ordenar
	
	
	printf("Como deseja realizar o cadastro das equipes?\n"); 
	printf("[1] para cadastro por arquivo.txt\n [2] para entrada manual\n");
	scanf("%d",&escolha);
	system("cls"); 
	if (escolha==1){
		EntradaArquivo(cad,numEquipe,jurados,criterios,nome,inicial,matriz,i, j);
	}
	else{
		Manual(cad,matriz,i, j, k,numEquipe);
	}
	//Escolha do usuario a respeito de como sera feito o cadastro das equipes
	Medias(matriz,matrizR,i,j,cad,indice,vetorponderada);
	Ordenar(i,j,vetorponderada,indice);
	Exibir(i,j,cad,matrizR,indice,vetorponderada);
	//Chamada das fun��es
	return 0;	
}                                                     
 void EntradaArquivo(struct CadastroAluno cad[],int numEquipe[], char jurados[],char criterios[],char nome[],char inicial[],float matriz[][25],int i, int j){
 	char resposta1[20];//Nome do arquivo que ser� lido
 	printf("Digite o nome do arquivo de texto que sera utilizado(nao esquecer de por .txt)");/*Caso utilzar o arquivo disponibilizado, escrever "EntradaDeDados.txt" */
 	fflush (stdin);/*Fun��o respons�vel por limpar o buffer do teclado*/
	gets(resposta1);
	FILE *Entrada; /*Ponteiro usado para localizar o arquivo*/
	Entrada=fopen(resposta1,"r");/*Fun��o para abrir o arquivo escolhido*/
	//Caso o arquivo de texto n�o esteja no mesmo lugar da memoria do diretorio do codigo, digitar local na mem�ria em que est� contido o arquivo de texto//
	for(i=0;i<10;i++){
		fscanf(Entrada,"%d\n",&numEquipe[i]);/*Leitura do numero da equipe*/
		fscanf(Entrada,"%s\n",&cad[i].Categoria);/*Leitura da categoria da equipe*/
		fscanf(Entrada,"%s\n",&cad[i].NomeEquipe);/*Leitura do nome da equipe*/
	}
	printf("\n");
	fgets(jurados,100,Entrada);
	fgets(criterios,100,Entrada);
	//leitura e armazenamento de dados do arquivo//
		
	for(i=0;i<10;i++)
		{
			fscanf(Entrada,"%*s  %*c   ",nome[i],inicial[i]);/* comando "%*" utilizado para n�o armazenar valores na matriz*/
			for(j=0;j<25;j++)
			{
				fscanf(Entrada,"%f ",&matriz[i][j]);/*armazenamento das notas do arquivo em uma matriz*/
			}
		}
	 }
	void Manual(struct CadastroAluno cad[],float matriz[][25], int i, int j, int k,int numEquipe[]){
		int pause=0;
		int numeros[25]={1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5,1,2,3,4,5};/* vetor criado para auxiliar o usuario quando for digitar as notas*/
		for(i=0;i<10;i++){
			printf("-------------CADASTRO MANUAL-------------\n");			
		do{	
			printf("\nDigite o numero da sua equipe:\n");
			scanf("%d",&numEquipe[i]);/*Leitura do numero da equipe*/
				for(j=0;j<i;j++){
					if(j!=i && numEquipe[i]==numEquipe[j]){
					printf("Numero ja foi utilizado, digite outro");
					scanf("%d",&numEquipe[i]);
					}
					else 
						pause++;
				}
			}while(pause==0);
			//Estrutura responsavel por impedir que codigos iguais sejam escritos
			printf("\nDigite o nome da equipe:\n");
			scanf("%s",cad[i].Categoria);
			printf("\nDigite a categoria da equipe(Escrevendo as palavras juntas):\n");
			scanf("%s",cad[i].NomeEquipe);
			for(j=0;j<25;j++){
					do{
						printf("\nDigite a nota do criterio C%d:\n",numeros[j]);
						scanf("%f",&matriz[i][j]);
						if(matriz[i][j]<0 || matriz[i][j]>10)
						printf("Nota invalida, por favor digite uma nota entre 1 e 10");
					}while(matriz[i][j]<0 || matriz[i][j]>10);						
					system("cls");
			}
		}	
	}
void Medias(float matriz[][25],float matrizR[][6],int i,int j,struct CadastroAluno cad[],int indice[],float vetorponderada[]){
		for(i=0;i<10;i++){
		for(j=0;j<25;j++){
				if (j==0 || j==5 || j==10 || j==15 || j==20)
					matrizR[i][0]=(matriz[i][0]+matriz[i][5]+matriz[i][10]+matriz[i][15]+matriz[i][20])/5;
				if(j==1 || j==6 || j==11 || j==16 || j==21)
					matrizR[i][1]=(matriz[i][1]+matriz[i][6]+matriz[i][11]+matriz[i][16]+matriz[i][21])/5;
				if(j==2 || j==7 || j==12 || j==17 || j==22)
					matrizR[i][2]=(matriz[i][2]+matriz[i][7]+matriz[i][12]+matriz[i][17]+matriz[i][22])/5;
				if(j==3 || j==8 || j==13 || j==18 || j==23)
					matrizR[i][3]=(matriz[i][3]+matriz[i][8]+matriz[i][13]+matriz[i][18]+matriz[i][23])/5;		
				if(j==4 || j==9 || j==14 || j==19 || j==24)
					matrizR[i][4]=(matriz[i][4]+matriz[i][9]+matriz[i][14]+matriz[i][19]+matriz[i][24])/5;	
			}
		}
	//C�lculo das medias de cada crit�rio
		for(i=0;i<10;i++){
			matrizR[i][5]=(matrizR[i][0]*1 + matrizR[i][1]*1 + matrizR[i][2]*2 + matrizR[i][3]*3 + matrizR[i][4]*3)/10;
			vetorponderada[i]=matrizR[i][5];
		}
	//C�lculo das medias ponderdas de cada equipe
	}

	void Exibir(int i,int j,struct CadastroAluno cad[],float matrizR[][6],int indice[10],float vetorponderada[]){
		int k=0;
		char resposta[20];
		printf("Qual nome deseja dar ao arquivo de saida?(escreva no final)");/*Escolha feita pelo ususario para o nome do arquivo de saida*/
		fflush (stdin);/*Fun��o respons�vel por limpar o buffer do teclado*/
		gets(resposta);
		FILE* Saida;
		Saida = fopen(resposta,"w");/*Fun��o que cria um arquivo e escreve dados requisitados nele*/
		fprintf(Saida,"RANKING\n");
		fprintf(Saida,"\nEducacao:          C1  C2  C3  C4  C5  M\n");/*Palavras escritas para a formata��o do arquivo*/
		for(i=0;i<10;i++){
			if(cad[indice[i]].Categoria[0]=='E' || cad[indice[i]].Categoria[0]=='e'){/*	Verifica��o da categoria das notas*/
				fprintf(Saida, "%s            ",cad[indice[i]].NomeEquipe);
				for(j=0;j<6;j++){
				fprintf(Saida, "%2.1f ",matrizR[indice[i]][j]);
				}
				fprintf(Saida, "\n");
			}
		}
		//Divisao das notas por categoria e exibi��o das mesmas em ordem decrescente
		fprintf(Saida,"\nProjeto Social:    C1  C2  C3  C4  C5  M\n");
		for(i=0;i<10;i++){
			if(cad[indice[i]].Categoria[0]=='P'|| cad[indice[i]].Categoria[0]=='p'){
				fprintf(Saida, "%s            ",cad[indice[i]].NomeEquipe);
				for(j=0;j<6;j++){
					fprintf(Saida, "%2.1f ",matrizR[indice[i]][j]);
				}
			fprintf(Saida,"\n");
			}
		}
		//Divisao das notas por categoria e exibi��o das mesmas em ordem decrescente
		fprintf(Saida, "\n\nGestao:            C1  C2  C3  C4  C5  M\n");
		for(i=0;i<10;i++){
			if(cad[indice[i]].Categoria[0]=='G' || cad[indice[i]].Categoria[0]=='g'){
				fprintf(Saida, "%s            ",cad[indice[i]].NomeEquipe);
				for(j=0;j<6;j++){
					fprintf(Saida, "%2.1f ",matrizR[indice[i]][j]);
				}
				fprintf(Saida, "\n");
			}
		}
		//Divisao das notas por categoria e exibi��o das mesmas em ordem decrescente
		fprintf(Saida,"\n\n\nRESULTADO FINAL\n");
			for(i=0;i<10;i++){
				if(cad[indice[i]].Categoria[0]=='E' || cad[indice[i]].Categoria[0]=='e'){				
					fprintf(Saida,"\nEducacao: %s",cad[indice[i]].NomeEquipe);
				break;	
				}	
			}
		//Exibi��o da equipe com maior nota da categoria eduaca��o
		for(i=0;i<10;i++){
			if(cad[indice[i]].Categoria[0]=='P' || cad[indice[i]].Categoria[0]=='p'){
				fprintf(Saida, "\nProjeto Social: %s",cad[indice[i]].NomeEquipe);
			break;
			}
		}
		//Exibi��o da equipe com maior nota da categoria Projeto Social
		for(i=0;i<10;i++){
			if(cad[indice[i]].Categoria[0]=='G' || cad[indice[i]].Categoria[0]=='g'){
				fprintf(Saida, "\nGestao: %s\n",cad[indice[i]].NomeEquipe);
			break;
			}
		}
		//Exibi��o da equipe com maior nota da categoria Gestao
		fprintf(Saida,"\nEQUIPES DESCLASSIFICADAS: ");
		for(i=0;i<10;i++){
			if(vetorponderada[i]<7){
				fprintf(Saida,"%s",cad[indice[i]].NomeEquipe);
			}
		}
		//Exibi��o das equipes com media ponderada menor que 7, ou seja, desclassificadas		
}
	void Ordenar(int i,int j,float vetorponderada[],int indice[]){
		float aux;
		int aux1;
		//auxiliares que tambem ajudam na ordena��p
		for(i=0;i<10;i++){
			for(j=0;j<10;j++){
			if(vetorponderada[j]<vetorponderada[j+1]){
				aux=vetorponderada[j];
				vetorponderada[j]=vetorponderada[j+1];
				vetorponderada[j+1]=aux;
				aux1=indice[j];
				indice[j]=indice[j+1];
				indice[j+1]=aux1;
				}
			}
		}	
	}

