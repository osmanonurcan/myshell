#include <stdio.h>
#include <stdlib.h>
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

int main(int argc, char *argv[],char ** envp){
	
	int cikis = 0;
	while(cikis==0)
	{
		
		//char s[100];
		//scanf("%s",s);
		//char** newString; 
		//newString = sepString(s);
		
		char *buffer;
    		size_t bufsize = 32;
    		size_t characters;

   		buffer = (char *)malloc(bufsize * sizeof(char));
    		if( buffer == NULL)
    		{
      			perror("Unable to allocate buffer");
      			exit(1);
   		}
   		
   		printf("myshell>>");

   
    		characters = getline(&buffer,&bufsize,stdin);
    		
    	
		
		char newString[10][10]; 
    		int x,y,z;
       
 		char newSentence[100][100];
 		int a,b,c;
 		b=0; c=0;
   		for(a=0;a<=(strlen(buffer));a++) //satırdaki harfleri dön
  		{
  			if(buffer[a]=='|' || buffer[a]=='\0')
       		{
       			newSentence[c][b]='\0'; //cümlenin sonuna NULL ekle
       			y=0; z=0;
		  	  	for(x=0;x<=(strlen(newSentence[c]));x++) //cümledeki harfleri dön
		  		{
		     			
		      			if(newSentence[c][x]==' ' || newSentence[c][x]=='\0')
		       		{
		       			newString[z][y]='\0';
		       			z++;  //yeni kelime
		      		      		y=0;    //yeni kelimenin ilk indisi
		     		        }
		     		   	else
		     		   	{
		     		       	newString[z][y]=newSentence[c][x]; //cümleden kelimeye harf ekle
		     		       	y++; //kelimenin indisi arttır
		     		   	}
			 	}
			  
		   		
		   			
				if(stringcompare(newString[0],"bash")==0)
				{
					
					int i,j,status;
					i = fork();
					if(i>0)
					{
						j = wait(&status);
					}
					else
					{
						
						
						int i;
						
						i = execve("/bin/bash", NULL, envp);
					}
				}
				
				else if(stringcompare(newString[0],"exit")==0)
				{
					cikis = 1;
				}
				
				else if(stringcompare(newString[0],"tekrar")==0)
				{
					int i;
					i = fork();
					if(i==0)
					{
						char *newargv[3];
						newargv[0] = newString[1];
						newargv[1] = newString[2];
						newargv[2] = NULL;
						int i;
						i = execve("tekrar", newargv, envp);
					}
					else
					{
						
					}
				}
				
				else if(stringcompare(newString[0],"islem")==0)
				{
					
					int i,j,status;
					i = fork();
					if(i>0)
					{
						j = wait(&status);
						printf("%s = %d\n",newString[1],WEXITSTATUS(status));
					}
					else
					{
						char *newargv[4];
						newargv[0] = newString[1];
						newargv[1] = newString[2];
						newargv[2] = newString[3];
						newargv[3] = NULL;
						
						printf("%s", newString[3]);
						int i;
						
						i = execve("islem", newargv, envp);
					}
				}
				
				else if(stringcompare(newString[0],"clear")==0)
				{
					
					system("clear");
				}
				
				else if(stringcompare(newString[0],"ls")==0)
				{
					
					system("ls");
				}
		   			
				else if(stringcompare(newString[0],"cat")==0)
				{
					int i,j,status;
					i = fork();
					if(i==0)
					{
						int i;
						printf("cat:");
						for(i=3;i<strlen(newSentence[c]);i++)
						{
							printf("%c",newSentence[c][i]);
						}
						printf("\n");
					}
					else
					{
						j = wait(&status);
					}
				}
				else
				{
					printf("Yanlis komut\n");
				}
		       			
		       			
		       			
		       			
		       			
       			c++;  //yeni cümle
      		      		b=0;  //yeni cümlenin ilk indisi  
	        	}
     		   	else
     		   	{
     		       	newSentence[c][b]=buffer[a]; //cümleye satırdan harf ekle
     		       	b++; //cümleniin indisi arttır
     		   	}
  		}
				
 
   		
   		
   		
	 		
	 		
 		
	
	}
		
		
	
    return 0;
}
