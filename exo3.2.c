#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

//en cas de problème, renvoyer l'adresse nulle.
void displayArray(int tab[], int size){
	if(tab!=NULL && size>0){
		for(int i=0; i<size;i++){
			printf("[%d]",tab[i]);
		}
	} else {
		printf("erreur");
	}
	printf("\n\n");
}

int* randTab(int n, int x, int y){
	//locals
	int* p=NULL;
	//check params
	if(n<=0|| x>y ){
		return NULL;
	}
	//process
	//memory allocation
	p= malloc(n * sizeof (int));
	if(p==NULL){
		return NULL;
	}
	//set random values
	for(int i=0; i<n; i++){
		p[i]=rand()%(y-x+1)+x;
	}
	//return array
	return p;
}

int* tabPair(int* p, int n, int* pN2){
	//locals
	int* p2=NULL;
	int count=0;
	int j=0;
	//check params
	if(p==NULL||n<=0||pN2==NULL){
		return NULL;
	}
	//process
	//count even values
	for(int i=0; i<n;i++){
		if(p[i]%2==0){
			count++;
		}
	}
	//memory alloc output array
	p2=malloc( count * sizeof(int));
	if(p2==NULL){
		return NULL;
	}
	//copy even values
	for(int i=0; i<n; i++){
		if(p[i]%2==0){
			p2[j]=p[i];
			j++;
		}
	}
	//END
	*pN2=count;
	return p2;
}

int* noDouble(int* p1, int N1, int* pN3){
	//locals
	int* p3=NULL;
	int count=1;
	int j=1;
	//check params
	if(p1==NULL||N1<=0||pN3==NULL){
		return NULL;
	}
	//loop p1
	for(int i=1;i<N1;i++){
		if(p1[i]!=p1[i-1]){
			count++;
		}
	}
	//process
	//malloc
	p3=malloc(count * sizeof(int));
	if(NULL==p3){
		return NULL;
	}
	//copy
	//copy first[0]
	p3[0]=p1[0];
	for(int i=1; i<N1; i++){
		if(p1[i]!=p1[i-1]){
			p3[j]=p1[i];
			j++;
		}
	}
	//end
	*pN3=count;
	return p3;
}
	

int main (){
	int* tab=NULL;
	int* tab2=NULL;
	int* tab3=NULL;
	int N,M,m;
	int N2,N3;
	printf("Rentrez la taille du tableau voulue:\n");
	scanf("%d",&N);
	printf("Rentrez la valeur maximale voulue:\n");
	scanf("%d",&M);
	printf("Rentrez la valeur minimale voulue:\n");
	scanf("%d",&m);
	
	srand(time(NULL));
	tab=randTab(N, m, M);
	if(tab==NULL){
		printf("randTab failed!\n");
		return 1;
	}
	displayArray(tab, N);
	
	tab2=tabPair(tab, N, &N2);
	if(tab2==NULL){
		printf("tabPAir failed!\n");
	}
	displayArray(tab2, N2);
	
	tab3=noDouble(tab,N,&N3);
	if(tab3==NULL){
		printf("noDouble failed!\n");
	}
	displayArray(tab3, N3);
			
	free(tab);
	free(tab2);
	free(tab3);
	tab=NULL;
	tab2=NULL;
	tab3=NULL;
	return 0;
}
