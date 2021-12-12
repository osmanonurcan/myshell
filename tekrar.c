#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[],char ** envp)
{
	
   	int count = atoi(argv[1]);
   	
   	int i;
   	printf("\n");
   	for(i = 0; i<count; i++)
   	{
   		printf("%s\n", argv[0]);
   		
   		
   	}

	return 0;
}
