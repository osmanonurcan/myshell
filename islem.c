#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int stringcompare(char *a,char *b)  
{  
	int flag=0;  
	while(*a!='\0' && *b!='\0')  // while loop  
    	{  
        	if(*a!=*b)  
        	{  
               	flag=1;  
        	}  
        a++;  
        b++;  
    	}  
      
    	if(flag==0)  
    	return 0;  
    	else  
    	return 1;  
} 

int main(int argc, char *argv[],char ** envp)
{
	
   	int fd[2];
   	
   	
   	if (pipe(fd) < 0) 
   	{
        	perror("pipe");
        	exit(1);
	}
	

	
	write(fd[1],argv[1],100);
	write(fd[1],argv[2],100);
	
	int i,j,status;
	
	if(stringcompare(argv[0],"topla")==0)
	{
		
		i = fork();
		if(i>0)
		{
			j = wait(&status);
			char charSonuc[100];
	
			read(fd[0],charSonuc,100);
			
			int sonuc = atoi(charSonuc);
			close(fd[0]);
			close(fd[1]);
			exit(sonuc);
		}
		else
		{
			
			int i;
				
			i = execve("topla", NULL, envp);
		}
	}
	
	else if(stringcompare(argv[0],"cikar")==0)
	{
		
		i = fork();
		if(i>0)
		{
			j = wait(&status);
			char charSonuc[100];
	
			read(fd[0],charSonuc,100);
			
			int sonuc = atoi(charSonuc);
			
			exit(sonuc);
		}
		else
		{
			
			int i;
				
			i = execve("cikar", NULL, envp);
		}
	}
	
	
	

	return 0;
}
