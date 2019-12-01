int postUserExists(char* email,int id){
	system("cls");
    int i;
	for(i=0;i<POSITION_POST;i++){
		if(strcmp(email,posts[i].email)==0 && id == posts[i].id){
            return 0;
		}
	}
	return 1;
}
int userExist(char* email, char* password,struct USER *user){
    int i;
    for(i=0;i< SIZE_USER;i++){
        if(strcmp(password,"")==0){
            if(strcmp(email,user[i].email)== 0){
                return 0;
            }
        }else{
            if(strcmp(email,user[i].email)== 0 && strcmp(password,user[i].password) == 0){
                return 0;
            }
        }
    }
   
    return 2;
}
int checkPostId(char* email){
	int id,i;
	id = 0;
	struct POST post;
	for(i=0;i<=POSITION_POST;i++){
            if(strcmp(email,posts[i].email)== 0 && id == posts[i].id){
                id++;
            }
	}	
	return id;
}
char * addValues(char *textMaxError,char *textMinError,char *showText,int maxLenght,int minLenght){
	/*
		A função será usada para adicionar uma string a uma variavel,
		verificando se tamanho da string condiz com o desejavel,
		no final, a função retornará uma string;
	*/
	char value[maxLenght];
	int lenghtOverFlow = 1;
	while(lenghtOverFlow== 1){
		system("cls");
		printf("%s",showText);
        setbuf(stdin,NULL);
		scanf("%[^\n]s",&value);
        setbuf(stdin,NULL);
		if(strlen(value)>maxLenght){
			printf("%s",textMaxError);
			lenghtOverFlow= 1;
		}else if(strlen(value) < minLenght){
			printf("%s",textMinError);
		}else{
			lenghtOverFlow=0;
		}
	}
	return value;
}
