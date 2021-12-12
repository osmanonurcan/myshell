#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[],char ** envp)
{
	
	char charA[100];
	char charB[100];
	
	read(3,charA,100);
	read(3,charB,100);
	
	
	
	int a = atoi(charA);
	int b = atoi(charB);
	
	int sonuc = a+b;
	//printf("%d\n",toplam);
	char charSonuc[100];
	sprintf(charSonuc,"%d",sonuc);
	//toplam = atoi(charToplam);
	//printf("%d\n",toplam);
	write(4,charSonuc,100);
	
	return 0;
}
