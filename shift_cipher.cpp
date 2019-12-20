#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *Process(char *text,int key,int method){
	char *temp = new char[1000];
	strcpy(temp,text);
	for(int i = 0;i<strlen(text);i++){
		int x = (int)temp[i];        	
		int y = (method==0)?(x+key%26):(x-key%26); //0:Encryption & 1:Decryption
		int space; 								
		if(x>64 && x<91){	//ABC...XYZ
			space = 0;
		}
		else if(x>96 && x<123){	//abc...xyz
			space = 32;
		}
		else continue;
		if(y>90+space) y-=26;
		else if(y<65+space) y+=26;
		temp[i] = char(y);
	}
	return temp;
}

char *Decryption(char *text,int key){
	system("cls");	//clear screen
	printf("The ciphertext is decoded as: %s ",Process(text,key,1));
}

char *Encryption(char *text,int key){
	system("cls");
	printf("The plaintext is encoded as: %s",Process(text,key,0));
}

main(){
	int choise;
	char text[1000];
	do{
		int key;
		printf("Input text: ");
		fgets(text,sizeof(text),stdin);
		rkey: printf("Input key: ");
		scanf("%d",&key);
		if(key>26 || key<0){
			printf("The key is in the range of 0 - 26!!!\a\n");
			goto rkey;		//reenter key
		}
		printf("---OPTION---");
		printf("\n1. Encryption");
		printf("\n2. Decryption");
		printf("\n3. END");
		rchoise: printf("\nChoise option: ");
		scanf("%d",&choise);
		if(choise>3 || choise<=0){
			printf("\aThe wrong choice. Please choose again!!!");
			goto rchoise;	//reenter choise
		}
		switch(choise){
			case 1: Encryption(text, key);
					break;
			case 2: Decryption(text, key);
					break;
			case 3: break;
		}
	}while(choise==0);
}
