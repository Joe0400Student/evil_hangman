#include "vector.h"
#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include "filereader.h"
#include "dictionary.h"
#include "Boolean.h"
#include <ctype.h>

void flush(void){while(fgetc(stdin)!='\n');}

boolean wannaplay(void){
	char c = 0;
	do{
		printf("wanna play:(y or n): ");
		scanf("%c",&c);
		flush();
		if(c == 'y' || c == 'Y' || c == 'n' || c == 'N')
			return c=='y' || c=='Y';
		printf("invalid response, please try again\n");
	}while(true);
}

int getsize(vector v){
	int ret = -2;
	do{
		printf("enter a word size for evil(mwahahah) hangman: ");
		scanf("%d",&ret);
		flush();
		if(vcontains(v,ret))
			return ret;
		printf("silly, %d sized words dont exist\n",ret);
	}while(true);
}

int getgeusscount(void){
	int ret = -1;
	do{
		printf("enter a guess count: ");
		scanf("%d",&ret);
		flush();
		if(ret>0)
			return ret;
		else
			printf("silly, you cant have %d geusses\n",ret);
	}while(true);
}

boolean runningtotal(void){
	char c = 0;
        do{
                printf("Do you want a running total of geusses?(y or n): ");
           	scanf("%c",&c);
		flush();
                if(c=='y'||c=='Y'||c=='n'||c=='N')
			return c=='y'||c=='Y';
                printf("invalid response, please try again\n");
        }while(true);
}

char getchr(void){
	char c = 0;
	do{
                printf("Enter a characcter: ");
                scanf("%c",&c);
              	flush();
		printf("%c\n",c);
		c = tolower(c);
		if(c<='z'&&c>='a')
			return c;
                printf("invalid response, please try again\n");
        }while(true);
}

int main(int argc, char* argv){
        vector v = vectorIterGenerator();
	for(;;){
		//break point
		if(!wannaplay()){ break; }
		
		vector v2 = vectorSplitterSize(v);
 	     	
		int size = getsize(v2);
		vector chosen = chooseWordGroup(&v2,size);
		
		int geussn = getgeusscount();
		
		MY_STRING stack = my_string_init_c_string("");
		
		boolean rt = runningtotal();
		
		while(geussn){
			char s[2] = {0,0};
			s[0] = getchr();
			printf("got here with %c \n",s[0]);
			MY_STRING clone = my_string_init_c_string(s);
			my_string_concat(stack,clone);
			my_string_destroy(&clone);
			
			dict d = makeDict(&chosen, stack);
			chosen = getLargest(&d);
			
			if(!contains(get(chosen,0),s[0]))
				geussn--;
			
			
			if(rt)
				printf("%d is the size\n",vsize(chosen));
			MY_STRING tmp = replace(get(chosen,0),stack,'-');
			printf(" %d guesses left\n",geussn);
			printf(" %s characters geussed\n",my_string_c_str(stack));
			printf(" %s is the word\n",my_string_c_str(tmp));
			if(vsize(chosen)==1 && !compareTo(get(chosen,0),tmp)){
				my_string_destroy(&tmp);
				break;
			}
			my_string_destroy(&tmp);
		}
		printf(" %s \n",my_string_c_str(get(chosen,0)));
		my_string_destroy(&stack);
		__del__vector(&chosen);
	}

	while(vsize(v)){
		MY_STRING s= get(v,0);
//		printf("%s",my_string_c_str(s));
		my_string_destroy(&s);
		rem(v,0);
	}
	__del__vector(&v);

        return 0;
}


