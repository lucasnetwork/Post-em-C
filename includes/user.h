int getRegister(){
	int moreAddUsers;
	char nullPassword[1] = ""; 
	moreAddUsers = 0;
	while(moreAddUsers == 0){
		moreAddUsers = 0;
		FILE *usersFile;
		usersFile = fopen("users.txt","a+");
		struct USER userLog;
		printf("digite seu email:");
		scanf("%s",userLog.email);
		printf("digite sua senha:");
		scanf("%s",userLog.password);
		if(userExist(userLog.email,nullPassword)==0){
			printf("email já existe\n");
			system("pause");
		}else{
			fwrite(&userLog,sizeof(userLog),1,usersFile);
			printf("Cadastro feito com sucesso\n");
			system("pause");
		}
		fclose(usersFile);
		system("cls");
		printf("deseja criar outro contato?\nSim(0)\nNao(1)\n");
		scanf("%i",&moreAddUsers);
	}
	return 0;
}
int getLogin(char* emailLog, char* passwordLog){
	if(userExist(emailLog,passwordLog)==0){
		return 0;
	}
	system("cls");
	return 1;
}
int deleteUser(char* email){
	struct USER user;
	FILE *usersFile;
	FILE *usersFileAux;
	usersFile = fopen("users.txt","a+");
	usersFileAux = fopen("usersaux.txt","a+");
	while(fread(&user,sizeof(user),1,usersFile)!=0){
            if(strcmp(email,user.email)!= 0){
				fwrite(&user,sizeof(user),1,usersFileAux);
            }
	}	
	fclose(usersFile);
	fclose(usersFileAux);
	remove("users.txt");
	rename("usersaux.txt","users.txt");
	return 0;
}
int editUser(char* email){
	struct USER user;
	struct USER userAux;
	FILE *usersFile; 
	FILE *usersFileAux;
	usersFile = fopen("users.txt","a+");
	usersFileAux = fopen("usersaux.txt","a+");
	while(fread(&user,sizeof(user),1,usersFile)!=0){
		printf("%i",strcmp(email,user.email));
		getch();
		if(strcmp(email,user.email)==0){
			printf("Digite o novo email:");
			scanf("%s",&user.email);
			printf("Digite a nova senha:");
			scanf("%s",&user.password);
			system("cls");
			if(userExist(user.email,"")==0){
				printf("email ja existe");
				fwrite(&user,sizeof(user),1,usersFileAux);
				getch();
			}else{
				fwrite(&user,sizeof(user),1,usersFileAux);
			}
		}else{
			fwrite(&user,sizeof(user),1,usersFileAux);
		}
	}
	fclose(usersFile);
	fclose(usersFileAux);
	remove("users.txt");
	rename("usersaux.txt","users.txt");
}