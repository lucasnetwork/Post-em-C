int createPost(char* email){
	struct POST post;
	int continuar,a;
	a= 1;
	strcat(post.email,email);
	continuar = 0;
	FILE *postFile;
	while(continuar ==0){
		postFile = fopen("posts.txt","a+");
		a=1;
		printf("Escreva seu post: ");
		while(a== 1){
			scanf("%s",&post.postContent);
			if(strlen(post.postContent)>1000){
				printf("post muito grande\n");
				a= 1;
			}else{
				a=0;
			}
		}
		post.id = checkPostId(email);
		fwrite(&post,1,sizeof(post),postFile);	
		printf("post cadastrado com sucesso");
		getch();
		fclose(postFile);
		system("cls");
		printf("Deseja continuar?\n");
		scanf("%i",&continuar);
	}
	return 0;
}
int deletePost(char* email, int id){
	struct POST post;
	FILE *postFile;
	FILE *postFileAux;
	postFile = fopen("posts.txt","a+");
	postFileAux = fopen("postsaux.txt","a+");
	system("cls");
	while(fread(&post,sizeof(post),1,postFile)){
		if(strcmp(email,post.email)!=0){
			fwrite(&post,sizeof(post),1,postFileAux);
		}
		if(strcmp(email,post.email)== 0 && id != post.id){
			fwrite(&post,sizeof(post),1,postFileAux);
		}
	}
	fclose(postFile);
	fclose(postFileAux);
	remove("posts.txt");
	rename("postsaux.txt","posts.txt");
	return 0;
}
int editPost(char* email,int id){
	if(postUserExists(email,id)==0){
		struct POST post;
		struct POST postAux;
		FILE *postFile;
		FILE * postFileAux;
		postFile = fopen("posts.txt","a+");
		postFileAux = fopen("postsaux.txt","a+");
		while(fread(&post,sizeof(post),1,postFile)!=0){
			if(strcmp(email,post.email)== 0 && id==post.id){
				printf("Digite o novo conteudo:\n");
				scanf("%s",&post.postContent);
				fwrite(&post,sizeof(post),1,postFileAux);
			}else{
				fwrite(&post,sizeof(post),1,postFileAux);
			}
		}
		fclose(postFile);
		fclose(postFileAux);
		remove("posts.txt");
		rename("postsaux.txt","posts.txt");
	}else{
		printf("post nao existe");
		getch();
	}
}
int getPostsUser(char* email){
	int id,action;
	struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	printf("Posts do usuario %s\n",post.email);
	while(fread(&post,sizeof(post),1,postFile)!=0){
            if(strcmp(email,post.email)== 0){
				printf("\n  email:%s\n",post.email);
				printf("  id:%i\n",post.id);
				printf("  %s\n\n",post.postContent);
            }
	}
	printf("\n Deseja fazer alguma ação?\nDeletar(0)\nEditar(1)\nSair(3)");
	scanf("%i",&action);
	fclose(postFile);
	switch (action){
	case 0:
		printf(" Id do post:");
		scanf(" %i",&id);
		deletePost(email,id);
		break;
	case 1:
		printf(" Id do post:");
		scanf(" %i",&id);
		editPost(email,id);
		break;
	default:
		break;
	}
	return 0;
}
int getPosts(){
	struct POST post;
	FILE *postFile;
	postFile = fopen("posts.txt","a+");
	printf("           Timeline\n");
	printf("-----------------------------\n");
	while(fread(&post,sizeof(post),1,postFile)!=0){
		printf("  %s@gmail.com:\n",post.email);
		printf("     %s\n\n",post.postContent);
	}	
	fclose(postFile);
	return 0;
}
