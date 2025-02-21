#include <stdio.h>
#include <stdlib.h>

int passing(){
	//locals
	int realm;
	printf("Rentrez le nombre N maximum du coefficient binomial:\n");
	while(scanf("%d",&realm)!=1 || realm<0){
	};
	return realm;
}

int** phanuel(int realm, int trial){
	//checking
	if(realm==0 || trial==0 || realm<trial){
		printf("ROT\n");
		exit(2);
	}
	//locals
	int** b_c;
	int size=0;
	//process
		//allocation
	for(int i=1; i<=realm ;i++){
		 size=+i;
	}
	b_c=malloc(size*sizeof(int));
	if(b_c==NULL){
		printf("NIGHTMARE\n");
		exit(1);
	}
		//filling
	size=realm;
	for (int i=0; i<realm;i++){
		for (int j=size; j>0; j-- ){
			b_c[i][j]=1;
		}
		size-=1;
	}
}
	

int main(){
	printf("%p\n",phanuel(passing(),passing()));
	return 0;
}
