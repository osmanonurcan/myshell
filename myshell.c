#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int strtoint( char* charnums)
{
 int number=0;
 int index=0;
 while(charnums[index])
 {
    if(('0'<=charnums[index]) && (charnums[index]<='9'))
    {

    if(!number)
        number= ( (int) charnums[index]) - 48;
    else
    {
        number = (number *= 10) + ((int) charnums[index] - 48);
    }
    index++;
         }
         else
         {
            number=-1;
            printf("\nGecersiz islem");
            break;
         }
 }
 return number;
}

char** sepString(char* str1)
{
    //char str1[100];
    char newString[10][10]; 
    int i,j,ctr;
       
 
    //fgets(str1, sizeof str1, stdin);	
 
    j=0; ctr=0;
    for(i=0;i<=(strlen(str1));i++)
    {
        // if space or NULL found, assign NULL into newString[ctr]
        if(str1[i]==' ' || str1[i]=='\0')
        {
            newString[ctr][j]='\0';
            ctr++;  //for next word
            j=0;    //for next word, init index to 0
        }
        else
        {
            newString[ctr][j]=str1[i];
            j++;
        }
    }
	  
    for(i=0;i < ctr;i++)
        printf(" %s\n",newString[i]);
    return newString;
}

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

	while(1)
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
    		
    		//fgets(buffer, sizeof buffer, stdin);
		
		//printf("%s", buffer);
		
		char newString[10][10]; 
    		int i,j,ctr;
       
 
   			
 
   		j=0; ctr=0;
  	  	for(i=0;i<=(strlen(buffer));i++)
  		{
     			// if space or NULL found, assign NULL into newString[ctr]
      			if(buffer[i]==' ' || buffer[i]=='\0')
       		{
       			newString[ctr][j]='\0';
       			ctr++;  //for next word
      		      		j=0;    //for next word, init index to 0
     		        }
     		   	else
     		   	{
     		       	newString[ctr][j]=buffer[i];
     		       	j++;
     		   	}
	 	}
	  
   		for(i=0;i < ctr;i++)
   		{
   			printf("%s\n",newString[i]);
   			
   			if(newString[i])
   			
   			//int compare=stringcompare(str1,str2);
   		
   		}
	 		
	 		
 		
	
	}
		
		
	
    return 0;
}
