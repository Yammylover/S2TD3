#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void crowmask(char** list, int N){
	if(list==NULL|| N<=0){
		return;
	}
	for (int i=0;i<N;i++){
		printf("[%s] \n",list[i]);
	}
}
	
int main(){
	char** nikoli=NULL;
	int a;
	printf("Combien de prénoms souhaitez-vous stocker?\n");
	if(scanf("%d",&a)!=1){
		printf("erreur nb prénoms\n");
		exit(6);
	}
	//allocation de mémoire
	nikoli=malloc(a*sizeof(char*));
	if(nikoli==NULL){
		printf("erreur malloc\n");
		exit(1);
	}
	//pour chaque prénom
	for(int i=0; i<a; i++){
		//définir aléatoirement la taille du prénom (8-16 car.)	
		int L;
		printf("Rentrez la taille du prénom: ");
		scanf("%d",&L);
		nikoli[i]=malloc((L+1)*sizeof(char));
		if(nikoli[i]==NULL){
			printf("Erreur malloc prénom\n");
			exit(2);
		}
		//*
		//scanf
		printf("entrez un prénom de %d lettres: ",L);
		if(scanf("%s",nikoli[i])!=1){
			printf("erreur scanf\n");
			exit(3);
		}
		if(nikoli[i][0]<='z'&& nikoli[i][0]>='a'){
			nikoli[i][0]-=32;
		}
		//*/
		/*
		//remplissage aléatoire du mot(simulation du scanf)
		for(int j=0;j<L;j++){
			nikoli[i][j];=rand()%26+'a';
		}
		nikoli[i][L]='\0';
		//*/
	}
	crowmask(nikoli, a);
	free(nikoli);
	return 0;
}
