/***************************
Autor: Daniel Cavalcante Dourado
Componente Curricular: MI Algoritmos
Concluido em: 29/04/2018
Declaro que este código foi elaborado por mim de forma individual e não contém nenhum
trecho de código de outro colega ou de outro autor, tais como provindos de livros e
apostilas, e páginas ou documentos eletrônicos da Internet. Qualquer trecho de código
de outra autoria que não a minha está destacado com uma citação para o autor e a fonte
do código, e estou ciente que estes trechos não serão considerados para fins de avaliação.
******************************/
#include <stdio.h>
#include <stdlib.h>

int main() {
	int num_eleitor;
	int voto1,P_maeli=0,P_antonio=0,P_lissandro=0,artificio1=2,VotoPresidente=0;/*"ints" relacionada ao voto a presidencia*/
	int voto2,G_Maia=0,G_Gentil=0,G_DonaSelma=0,artificio2=2,VotoGovernador=0;/*"ints" relacionados ao voto ao cargo de governador*/
	int voto3,S_Gutemberg=0,S_Fernando=0,artificio3=2,VotoSenador=0;/*"ints" relacionados ao voto a deputado federal */
	int voto4,DF_AnaVitoria=0,DF_PauloGuilherme=0,artificio4=2,VotoDepFederal=0;/* "ints"relacionados ao voto a deputado federal*/
	int voto5,DE_AnaRita=0,DE_AnaGuilherme=0,DE_AdalbertoCampos=0,artificio5=2,VotoDepEstadual=0;/*"INTS" relacionados ao voto do deputado federal*/
	int VotoBranco=0,VotoNulo=0;/* contador dos votos nulos e brancos*/
	int senha;/*variavel responsavel por repetir ou dar por finalizada a votacao*/
	int VotosTotais=0;/*contador do numero total de votos*/
	int votosmulher=0,votoshomens=0;
	float porcentmulher,porcenthomem,porcentbranco,porcentnulo;/*variaveis que serao responsaveis por conter as porcentagens de cada grupo*/
	float porcentMaeli,porcentAntonio,porcentLissandro;/* variaveis responsaveis pela porcentangem dos candidatos a presidente*/
	float porcentMaia,porcentGentil,porcentSelma;/* variaveis responsaveis pela porcentangem dos candidatos a governador*/
	float porcentGutemberg,porcentFernando;/* variaveis responsaveis pela porcentangem dos candidatos a senador*/
	float porcentAnaVitoria,porcentPaulo;/* variaveis responsaveis pela porcentangem dos candidatos a deputado federal*/
	float porcentAnaRita,porcentAnaGuilherme,porcentAdalberto;/* variaveis responsaveis pela porcentangem dos candidatos a deputado estadual*/
	/*P_,G_,DF_,DE_,foram prefixos dados aos cargos de cada candidato,presidente,governador,deputado federal e estadual,respectivamente*/
	printf("Prezado eleitor, a votacao sera iniciada. Identifique-se por meio do titulo de eleitor:");
	scanf("%d",&num_eleitor);
	do{/*Looping responsavel por possiblitar que o voto de inumeras pessoas sejam feitos*/
	    do/*Looping responsavel por permitir a correcao do voto*/
	    {   
		    printf("Insira o numero do seu candidato a presidencia\n 17 para a candidata sr. Maeli Gente Boa");
		    printf("\n 22 para o candidato sr. Antonio do Brasil\n 31 para o candidato dr. Lissandro\n 0 para voto em branco\n 1 para voto nulo\n");
		    //Apresentacao dos candidatos e seus respectivos numeros//
		    scanf("%d",&voto1);/*voto1=voto para presidente*/
			printf("tecle [1] para seguir a votacao e [2] para repetir o voto:");/*Pergunta para saber se o eleitor quer ou nao repetir o voto*/
		    scanf("%d",&artificio1);/*artificios, variaveis responsaveis pela repeticao ou seguimento do programa, escritas pelo eleitor e diferenciadas pelo numero a direita */
	   }
	   while(artificio1==2);/*Final do looping, onde sera lido uma resposta que,reiniciara o looping ou dara prosseguimento*/
	   		switch(voto1){/*Cadeia de decisoes a respeito sobre o voto*/
			    case 17:
					P_maeli++;
					votosmulher++;
					VotosTotais++;
					VotoPresidente++;
			    	break;
			    	//Os numeros nos cases representam um candidato, e os contaoores abaixo somam, em 1, a valor de cada varivel//
			    case 22:
					P_antonio++;
					votoshomens++;
					VotosTotais++;
					VotoPresidente++;
			    	break;
			    	//soma as variaveis antonio(CANDIDATO), votos em homens, votos totais e votos para o cargo de presidente//
			    case 31:
					P_lissandro++;
					votoshomens++;
					VotosTotais++;
					VotoPresidente++;
			    	break;
			    	//soma as variaveis Lissandro(CANDIDATO), votos em homens, votos totais e votos para o cargo de presidente//
			    case 0:
					VotoBranco++;
					VotosTotais++;
			    	break;
			    	//soma 1 nas variaveis voto branco e votos totais//
			    case 1:
					VotoNulo++;
					VotosTotais++;
		        	break;
		        	//soma 1 nas variaveis voto nulo e votos totais//
		        default:printf("voto nao contabilizado, digite [2] para repetir votacao]\n");}/*Caso seja escrito um valor desconhecido, o eleitor digitara e podera refazer a votacao*/
	    system("cls");/*Comando para "limpar" a tela do eleitor*/
    	do/*Looping responsavel por permitir a correcao do voto*/
	    {
		    printf("Insira o numero do seu candidato ao cargo de governador\n 38 para a candidata sr. Maia da Ana \n 40 para o candidato sr. Gentil");
		    printf("\n 18 para a candidato sra. Dona Selma Maria\n 0 para voto em branco\n 1 para voto nulo\n");
		    //Apresentacao dos candidatos e seus respectivos numeros//
		    scanf("%d",&voto2);/*Leitura do voto*/
		    printf("tecle [1] para seguir a votacao e [2] para repetir o voto:");/*Pergunta feita ao eleitor para saber se a interesse em refazr o voto*/
		    scanf("%d",&artificio2);/*Leitura da resposta*/
    	}while(artificio2==2);
    		switch(voto2){
				case 38:
					G_Maia++;
					votosmulher++;
					VotosTotais++;
					VotoGovernador++;
			    	break;
			    	//soma 1 as variaveis Maia da Ana(CANDIDATA), votos em mulheres, votos totais e votos para o cargo de governador//
				case 40:
					G_Gentil++;
					votoshomens++;
					VotosTotais++;
					VotoGovernador++;
			    	break;
			    	//soma 1 as variaveis Gentil(candidato), votos em homens, votos totais e votos para o cargo de governador//
		   		case 18:
					G_DonaSelma++;
					votosmulher++;
					VotosTotais++;
					VotoGovernador++;
		    		break;
		    		//soma 1 as variaveis Dona Selma(candidata), votos em mulheres, votos totais e votos para o cargo de governador//
				case 0:
					VotoBranco++;
					VotosTotais++;
			    	break;
			    	//soma 1 nas variaveis voto branco e votos totais//
				case 1:
					VotoNulo++;
					VotosTotais++;
		        	break;
		        	//soma 1 nas variaveis voto nulo e votos totais//
            default:printf("voto nao contabilizado, digite [2] para repetir votacao]\n");}/*Caso seja escrito um valor desconhecido, o eleitor digitara e podera refazer a votacao*/
    	 system("cls");
	    do /*Looping responsavel por permitir a correcao do voto*/
    	{
		    printf("Insira o numero do seu candidato ao cargo de senador\n 4 para o candidata sr. Gutemberg Silva");
		    printf(" \n 67 para o candidato sr.Fernando Fernandes\n 0 para voto em branco\n 1 para voto nulo\n");
		    //Apresentacao dos candidatos e seus respectivos numeros//
		    scanf("%d",&voto3);/*Leitura do voto*/
	    	printf("tecle [1] para seguir a votacao e [2] para repetir o voto:");
	    	scanf("%d",&artificio3);
    	}while(artificio3==2);
    		switch(voto3){
		    	case 4:
					S_Gutemberg++;
					votoshomens++;
					VotosTotais++;
					VotoSenador++;
		    		break;
		    		//soma 1 as variaveis Gutemberg(candidato), votos em homens, votos totais e votos para o cargo de senador//
	    		case 67:
					S_Fernando++;
					votoshomens++;
					VotosTotais++;
					VotoSenador++;
		    		break;
		    		//soma 1 as variaveis Fernando(candidato), votos em homens, votos totais e votos para o cargo de senador//
	    		case 0:
					VotoBranco++;
					VotosTotais++;
	    			break;
	    			//soma 1 nas variaveis voto branco e votos totais//
	    		case 1:
					VotoNulo++;
					VotosTotais++;
		        	break;
		        	//soma 1 nas variaveis voto nulo e votos totais//
		        default:printf("voto nao contabilizado, digite [2] para repetir votacao]\n");}/*Caso seja escrito um valor desconhecido, o eleitor digitara e podera refazer a votacao*/
    		system("cls");
        do/*Looping responsavel por permitir a correcao do voto*/
    	{
	    	printf("Insira o numero do seu candidato ao cargo de deputado Federal\n 56 para o candidata sra. Ana Vitoria");
	    	printf("\n 33 para o candidato sr. Paulo Guilherme \n 0 para voto em branco\n 1 para voto nulo\n");
	    	scanf("%d",&voto4);
	    	printf("tecle [1] para seguir a votacao e [2] para repetir o voto:");
	    	scanf("%d",&artificio4);
    	}while(artificio4==2);
    		switch(voto4){
		    	case 56:
					DF_AnaVitoria++;
					votosmulher++;
					VotosTotais++;
					VotoDepFederal++;
		    		break;
		    		//soma 1 as variaveis Ana Vitoria(candidata), votos em mulheres, votos totais e votos para o cargo de Deputado Federal//
		    	case 33:
					DF_PauloGuilherme++;
					votoshomens++;
					VotosTotais++;
					VotoDepFederal++;
		    		break;
		    		//soma 1 as variaveis Paulo Guilherme(candidato), votos em homens, votos totais e votos para o cargo de Deputado Federal//
		    	case 0:
					VotoBranco++;
					VotosTotais++;
		    		break;
		    		//soma 1 nas variaveis voto branco e votos totais//
		    	case 1:
					VotoNulo++;
					VotosTotais++;
		       		break;
		       		//soma 1 nas variaveis voto nulo e votos totais//
		         default:printf("voto nao contabilizado, digite [2] para repetir votacao]\n");}/*Caso seja escrito um valor desconhecido, o eleitor digitara e podera refazer a votacao*/
    		system("cls");
	    do/*Looping responsavel por permitir a correcao do voto*/
    	{
	    	printf("Insira o numero do seu candidato ao cargo de Deputado Estadural");
	    	printf("\n 51 para a candidata sra. Ana Rita Pacheco \n 34 para a candidata sra. Ana Gilherme\n 11 para o candidato sr. Adalberto Campos\n 0 para voto em branco\n 1 para voto nulo\n");
	    	scanf("%d",&voto5);
	    	printf("tecle [1] para seguir a votacao e [2] para repetir o voto:");
	    	scanf("%d",&artificio5);
	    	
	    	system("cls");
	    	
	    	printf("Eleitor, esses sao seus votos:\n");
	    	printf("PRESIDENTE:%d\n",voto1);
	    	printf("GOVERNADOR:%d\n",voto2);
	    	printf("SENADOR:%d\n",voto3);
	    	printf("DEPUTADO FEDERALL:%d\n",voto4);
	    	printf("DEPUTADO ESTADUAL:%d\n",voto5);
	    	//Espelho da votacao//
    	}
	    while(artificio5==2);
	    	switch(voto5){
	    		case 51:
					DE_AnaRita++;
					votosmulher++;
					VotosTotais++;
					VotoDepEstadual++;
	    			break;
	    			//soma 1 as variaveis Ana Rita(candidata), votos em mulhres, votos totais e votos para o cargo de Deputado Estadual//
	    		case 34:
					DE_AnaGuilherme++;
					votosmulher++;
					VotosTotais++;
					VotoDepEstadual++;
	    			break;
	    			//soma 1 as variaveis Ana Guilherme(candidata), votos em mulhres, votos totais e votos para o cargo de Deputado Estadual//
	    		case 11:
					DE_AdalbertoCampos++;
					votoshomens++;
					VotosTotais++;
					VotoDepEstadual++;
	    			break;
	    			//soma 1 as variaveis Adalberto(candidato), votos em homens, votos totais e votos para o cargo de Deputado Estadual//
	    		case 0:
					VotoBranco++;
					VotosTotais++;
	    			break;
	    			//soma 1 nas variaveis voto branco e votos totais//
	    		case 1:
					VotoNulo++;
					VotosTotais++;
		        	break;
		        	//soma 1 nas variaveis voto nulo e votos totais//
		        default:printf("voto nao contabilizado, digite [2] para repetir votacao]\n");}/*Caso seja escrito um valor desconhecido, o eleitor digitara e podera refazer a votacao*/
	    printf("ENCERRE A VOTACAO DIGITANDO ALGUM NUMERO:\n");/*Pede ao eleitor que digite um numero para reiniciar a votacao*/
    	scanf("%d",&senha);/*Leitura da resposta*/
	}while(senha!=3443);
	
	system("cls");
	if (senha==3443)/*Condicional para que o criador da urna, digitando um numero especifico, possa acessar os dados da votacao*/
	{
		printf("Dados dos candidatos a presidencia:\n");
		if(VotoPresidente!=0)/*Condicional responsavel por executar dados da eleicao somente quando houver votos validos*/
		{
	    	printf("\nTotal de votos na candidata Maeli:%d\n",P_maeli); 
			printf("Percentual de votos: %3.2f",porcentMaeli=P_maeli*100/VotoPresidente);
			//TOtal de percentual de votos em Malei//
	    	printf("\nTotal de votos no candidato Antonio:%d\n",P_antonio); 
			printf("Percentual de votos: %3.2f",porcentAntonio=P_antonio*100/VotoPresidente);
			//Total de percentual de votos em Antonio//
	    	printf("\nTotal de votos no candidato Lissandro:%d\n",P_lissandro);  
			printf("Percentual de votos: %3.2f\n",porcentLissandro=P_lissandro*100/VotoPresidente);
			//Total de percentual de votos em Lissandro//
		}
		else/*Caso nao exista votos validos, sera exibido uma mensagem*/
			printf("Nao houve votos validos para Presidente\n");
			
	    system("\npause");system("cls");
	    
	    printf("\nDados dos candidatos a governador:\n");
	    if(VotoGovernador!=0)/*Condicional responsavel por executar dados da eleicao somente quando houver votos validos*/
		{
	    	printf("\nTotal de votos na candidata Maia da Ana:%d\n",G_Maia); 
			printf("Percentual de votos: %3.2f",porcentMaia=G_Maia*100/VotoGovernador);
			//Total de percentual de votos em Maia da Ana//
	    	printf("\nTotal de votos no candidato Gentil:%d\n",G_Gentil);  
			printf("Percentual de votos: %3.2f",porcentGentil=G_Gentil*100/VotoGovernador);
			//Total de percentual de votos em Gentil//
	    	printf("\nTotal de votos na candidata Dona Selma:%d\n",G_DonaSelma); 
			printf("Percentual de votos: %3.2f\n",porcentSelma=G_DonaSelma*100/VotoGovernador);
			//Total de percentual de votos em Dona Selma//
		}
	    else
	    	printf("Nao houve votos validos para Governador\n");
	    	
	    system("\npause");system("cls");
	    
		if(VotoSenador!=0)/*Condicional responsavel por executar dados da eleicao somente quando houver votos validos*/
		{
	    	printf("\nDados dos candidatos a Senador:\n");
	    	printf("\nTotal de votos no canditado Gutemberg:%d\n",S_Gutemberg); 
			printf("Percentual de votos: %3.2f",porcentGutemberg=S_Gutemberg*100/VotoSenador);
			//Total de percentual de votos em Gutemberg//
	    	printf("\nTotal de votos no canditado Fernando:%d\n",S_Fernando); 
			printf("Percentual de votos: %3.2f\n",porcentFernando=S_Fernando*100/VotoSenador);
			//Total de percentual de votos em Fernando//
		}
		else
			printf("Nao houve votos validos para Senador\n");
			
	    system("\npause");system("cls");
	    
	    if(VotoDepFederal!=0)/*Condicional responsavel por executar dados da eleicao somente quando houver votos validos*/
		{
	    	printf("\nDados dos candidatos a Deputado Federal:\n");
	    	printf("\nTotal de votos na candidata Ana Vitoria:\n",DF_AnaVitoria); 
			printf("Percentual de votos: %3.2f",porcentAnaVitoria=DF_AnaVitoria*100/VotoDepFederal);
			//Total de percentual de votos em Ana Vitoria//
	    	printf("\nTotal de votos no candidato Paulo Guilherme:\n",DF_PauloGuilherme); 
			printf("Percentual de votos: %3.2f\n",porcentPaulo=DF_PauloGuilherme*100/VotoDepFederal);
			//Total de percentual de votos em Paulo Guilherme//
		}
		else
			printf("Nao houve votos validos para Deputado Federal\n");
			
	    system("\npause");system("cls");
	    
	    if(VotoDepEstadual!=0)/*Condicional responsavel por executar dados da eleicao somente quando houver votos validos*/
		{
	    	printf("\nDados dos candidatos a Deputado Estadual:\n");
	    	printf("\nTotal de votos na candidata Ana Rita Pacheco:\n",DE_AnaRita); 
			printf("Percentual de votos: %3.2f",porcentAnaRita=DE_AnaRita*100/VotoDepEstadual);
			//Total de percentual de votos em Ana Rita//
	    	printf("\nTotal de votos na candidata Ana Guilherme Pacheco:\n",DE_AnaRita); 
			printf("Percentual de votos: %3.2f",porcentAnaGuilherme=DE_AnaGuilherme*100/VotoDepEstadual);
			//Total de percentual de votos em Ana Guilherme//
	    	printf("\nTotal de votos no candidato Adalberto Campos:\n",DE_AdalbertoCampos); 
			printf("Percentual de votos: %3.2f\n",porcentAdalberto=DE_AdalbertoCampos*100/VotoDepEstadual);
		}
		else 
			printf("Nao houve votos validos para Deputado Estadual");
	    system("\npause");system("cls");
	        
	    printf("\nTotal de votos:%d\n",VotosTotais=votosmulher+votoshomens+VotoNulo+VotoBranco);/*TOtal de votos*/
	    printf("Total de votos brancos:%d\n",VotoBranco);
	    printf("Percentual de votos brancos:%3.2f\n",porcentbranco=VotoBranco*100/VotosTotais);
	    //Total de percentual de votos brancos//
	    
	    printf("\nTotal de votos Nulos:%d\n",VotoNulo);
	    printf("Percentual de votos Nulos:%3.2f\n",porcentnulo=VotoNulo*100/VotosTotais);
	    //Total de percentual de votos em nulos//
	    
	    printf("\nTotal de votos em candidatos do sexo feminino:%d\n",votosmulher);
		printf("Porcentagem de votos em mulheres:%3.2f\n",porcentmulher=votosmulher*100/VotosTotais);
		//Total de percentual de votos em mulheres//
		
	    printf("\nTotal de votos em candidatos do sexo masculino:%d\n",votoshomens);
		printf("Porcentagem de votos em homens:%3.2f\n",porcenthomem=votoshomens*100/VotosTotais);
		//Total de percentual de votos em homens//
	}
return 0;
}
