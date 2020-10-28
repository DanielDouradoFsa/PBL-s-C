/*
Autor: Daniel Cavalcante Dourado
Componente Curricular: MI - Algoritmos
Concluido em: 19/07/2018
Declaro que este c�digo foi elaborado por mim de forma individual e n�o cont�m nenhum
trecho de c�digo de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e p�ginas ou documentos eletr�nicos da Internet. Qualquer trecho de c�digo
de outra autoria que n�o a minha est� destacado com uma cita��o para o autor e a fonte
do c�digo, e estou ciente que estes trechos n�o ser�o considerados para fins de avalia��o.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <time.h>
typedef struct cad{
	int seFoiSorteado;
	char nomeJogador[30];
	int ano;
	char pais[15];
	int numero;
	char posicao[11];
	struct cad *prox;
}Celula;
Celula* cadJogador(Celula *primeiroNo,int cont);//FUN��O PARA CADASTRAR
void showJogadores(Celula *primeiroNo);//FUN��O PARA MOSTRAR JOGADORES CADASTRADOS
Celula* alteraCamisa(Celula *primeiroNo);//FUN��O PARA ALTERAR CAMISA
Celula* removeJogador(Celula *primeiroNo);//FUN��O PARA REMOVER
int sairDoPrograma(int k,FILE *Entrada);//FUN��O PARA SAIR DO PROGRAMA
Celula* sorteiajogador(int cont,Celula* primeiroNo,int numeroDoSorteio,int *vetorSorteados);////FUN��O PARA SORTEAR JOGADORES
int descobreaquantidade(Celula* primeiroNo);//FUN��O PARA DESCOBRIR A QUANTIDADE DE C�LULAS DA LISTA
void showJogadoresSorteados(Celula *primeiroNo,int numeroDoSorteio);//FUN��O PARA MOSTRAR JOGADORES SORTEADOS
void filtraJogadores(Celula* primeiroNo);//FUN��O PARA PRINTAR JOGADORES SORTEADOS

int main() {
	srand(time(NULL));
	int cont;//QUANTIDADE DE N�S
	Celula *primeiroNo=NULL;//PONTEIRO USADO COMO "CABE�A" DA LISTA
	int pararcodigo;
	int numeroDoSorteio=0;
	int *vetorSorteados;
	FILE *Entrada,*Saida; /*Ponteiro usado para localizar o arquivo*/
	Entrada=freopen("entrada.txt","r",stdin);
	Saida=freopen("SAIDAA.txt","w",stdout);
	//Fun��o para abrir e para criar o arquivo
	while(pararcodigo==0){
		int i;
		fscanf(stdin,"%d\n",&i);
		switch(i){
			case 1:primeiroNo=cadJogador(primeiroNo,cont);/*Essa igualdade serve para "atualizar" os dados da lista*/
				break;
			case 2:primeiroNo=alteraCamisa(primeiroNo);
				break;
			case 6:showJogadores(primeiroNo);
				break;
			case 8:sairDoPrograma(pararcodigo,Entrada);
				break;
			case 3:primeiroNo=removeJogador(primeiroNo);
				break;
			case 4:cont=descobreaquantidade(primeiroNo);
				numeroDoSorteio++;
				primeiroNo=sorteiajogador(cont,primeiroNo,numeroDoSorteio,vetorSorteados);
				break;
			case 7:showJogadoresSorteados(primeiroNo,numeroDoSorteio);
				break;
			case 5:filtraJogadores(primeiroNo);
				break;
			default:
				return 0;
		}
	}
}
Celula* cadJogador(Celula *primeiroNo,int i){
	//Armazena dados do novo jogador
	Celula *p = (Celula *)malloc(sizeof (Celula));//ALOCA��O DE CADA N�
	fgets(p->nomeJogador,30,stdin);
	p->nomeJogador[strcspn(p->nomeJogador, "\n")] = 0;/*Retira o "\n" que � lido pelo fgets*/
	fscanf(stdin,"%d\n",&p->ano);
	fgets(p->pais,30,stdin);
	p->pais[strcspn(p->pais, "\n")] = 0;
	fscanf(stdin,"%d\n",&p->numero);
	fgets(p->posicao,30,stdin);
	p->posicao[strcspn(p->posicao, "\n")] = 0;
	p->seFoiSorteado=0;
	p->prox = NULL;
	//adciona jogador no final da lista
	if(primeiroNo == NULL){ //vazio
		primeiroNo = p;
	}else{
		//encontra ultimo
		Celula *ultimo = primeiroNo;
		while(ultimo->prox != NULL){ //se nao for o ultimo, avan�a
			ultimo = ultimo->prox;
		}

		ultimo->prox = p;
	}
	return primeiroNo;//RETORNAR "CABE�A" DA LISTA
}
Celula* alteraCamisa(Celula *primeiroNo){
	int numeroparamudar;//NUMERO QUE SER� ALTERADO
	char nomeparamudar[30];//NOME QUE SER� BUSCADO PARA TER SUA CAMSISA ALTERADA
	fgets(nomeparamudar,30,stdin);
	nomeparamudar[strcspn(nomeparamudar, "\n")] = 0;
	fscanf(stdin,"%d",&numeroparamudar);
	Celula *p= primeiroNo;	
	while(p!=NULL){
		if(strcmp(p->nomeJogador,nomeparamudar)==0){
			p->numero=numeroparamudar;
			break;
		}
		else
			p=p->prox;
	}
	return primeiroNo;
}

void showJogadores(Celula *primeiroNo){
	Celula *p= primeiroNo;
	printf("\nEXIBICAO DE TODOS OS JOGADORES\n");
	while(p!=NULL){
		printf("|%s",p->nomeJogador);
		printf("|	%d",p->ano);
		printf("|	%s",p->pais);
		printf("|	%d",p->numero);
		printf("|	%s",p->posicao);
		printf("\n");
		p = p->prox;
	}
printf("\n");
}
int sairDoPrograma(int k,FILE *Entrada){
	fclose(Entrada);//FECHA O ARQUIVO
	return k--;
}
Celula* removeJogador(Celula *primeiroNo){
	Celula *atual= primeiroNo;
	Celula *anterior=NULL;//PONTEIRO AUXILIAR
	char nomeParaSerRetirado[30];
	fgets(nomeParaSerRetirado,29,stdin);
	nomeParaSerRetirado[strcspn(nomeParaSerRetirado, "\n")] = 0;
	while(atual!=NULL){
		if(strcmp(atual->nomeJogador,nomeParaSerRetirado)!=0){
			anterior=atual;//Armazena o valor do cadastro atual antes que ele avance
			atual=atual->prox;
		}
		else{
			if(anterior!=NULL){
				anterior->prox=atual->prox;
			}
			else//Caso seja o primeiro elemento da lista
				primeiroNo=atual->prox;
			free(atual);
			break;
		}
	}
	return primeiroNo;
}
int descobreaquantidade(Celula* primeiroNo){
	Celula* quantidade= primeiroNo;
	int contador=0;//VARIAVEL PARA ARMAZENAR O TAMANHO DA LISTA
	while(quantidade!=NULL){
		contador++;
		quantidade=quantidade->prox;
	}
	return contador;
}
Celula* sorteiajogador(int cont,Celula* primeiroNo,int numeroDoSorteio,int *vetorSorteados){
	int quantidadeDeSorteios,valorDoSorteio,condicaoDeRepeticao=0;
	Celula* aux=primeiroNo;
	fscanf(stdin,"%d",&quantidadeDeSorteios);
	vetorSorteados=(int*)malloc(quantidadeDeSorteios * sizeof(int));//ALOCA��O DINAMICA DE UM VETOR PARA RECEBER VALORES
	int i,j,contador=1;
	for(i=0;i<quantidadeDeSorteios;i++){
		do{
			valorDoSorteio=1+(rand()%cont);
			vetorSorteados[i]=valorDoSorteio;
			condicaoDeRepeticao=0;
			for(j=0;j<i;j++){
				if(vetorSorteados[j]==vetorSorteados[i])
				condicaoDeRepeticao=1;
			}
		}while(condicaoDeRepeticao==1);
		while(aux!=NULL){
			if(valorDoSorteio==contador && aux->seFoiSorteado==0){
				aux->seFoiSorteado=numeroDoSorteio;
			}
			contador++;
			aux=aux->prox;
		}
		aux=primeiroNo;
		contador=1;
	}

	return primeiroNo;
}
void showJogadoresSorteados(Celula *primeiroNo,int numeroDoSorteio){
	Celula* atual=primeiroNo;
	printf("\nEXIBICAO DE JOGADORES SORTEADOS NO SORTEIO %d\n",numeroDoSorteio);
	while(atual!=NULL){
		if(atual->seFoiSorteado==numeroDoSorteio)
			printf("%s	%s\n",atual->nomeJogador,atual->pais);
		atual=atual->prox;
	}
}
void filtraJogadores(Celula* primeiroNo){
	Celula* atual=primeiroNo;
	int naoFoiSorteado=0;//VARI�VEL PARA IDENTIFICAR SE HOUVE OU N�O JOGADORES NA POSI��O LIDA
	char auxiliar[15];
	fgets(auxiliar,14,stdin);
	auxiliar[strcspn(auxiliar, "\n")] = 0;
	printf("\n\nFILTRO PELA POSICAO DE: %s\n",auxiliar);
	while(atual!=NULL){
		if(strcmp(atual->posicao,auxiliar)==0 && atual->seFoiSorteado!=0){
			printf("%s\t",atual->nomeJogador);
			printf("%s\n",atual->pais);
			naoFoiSorteado++;
		}
		atual=atual->prox;
	}
	printf("\n");
	if(naoFoiSorteado==0)
		printf("NAO EXISTE A POSICAO INSERIDA:%s\n",auxiliar);
	}
