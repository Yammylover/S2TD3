#include <stdio.h>
#include<stdlib.h>

int main(int argc, char** argv){
	/*//printf("%c+%c=%d\n",*argv[1],*argv[2],*argv[1]-48+*argv[2]-48);
	int Lulu,Lucifer,Lucelia;
	Lulu=atoi(argv[1]);
	Lucifer=atoi(argv[3]);*/
	/*Lulu=*argv[1]-48;
	Lucifer=*argv[3]-48;	*/
	float Lulu,Lucifer,Lucelia;
	Lulu=atof(argv[1]);
	Lucifer=atof(argv[3]);
	switch (*argv[2]){
		case '+' :
			Lucelia=Lulu+Lucifer;
		break;
		case 'x' :
			Lucelia=Lulu*Lucifer;
		break;
		case '-' :
			Lucelia=Lulu-Lucifer;
		break;
		case '/' :
			Lucelia=Lulu/Lucifer;
		break;
	}
	//printf("%d %c %d = %d\n",Lulu,*argv[2],Lucifer,Lucelia);
	printf("%f %c %f = %f\n",Lulu,*argv[2],Lucifer,Lucelia);
	return 0;
}
