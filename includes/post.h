int createPost(char* email){
	struct POST post;
	int moreAddPosts,lenghtOverflow;
	lenghtOverflow= 1;
	strcat(post.email,email);
	moreAddPosts = 0;
	FILE *postFile;
	while(moreAddPosts ==0){
		postFile = fopen(POSTS_FILE,"a+");
		lenghtOverflow=1;
		while(lenghtOverflow== 1){
			printf("Escreva seu post: ");
			setbuf(stdin,NULL);
			scanf("%[^\n]s",&post.postContent);
			setbuf(stdin,NULL);
			if(strlen(post.postContent)>1000){
				printf("%s",POST_LENGHT_ERROR);
				lenghtOverflow= 1;
			}else{
				lenghtOverflow=0;
			}
		}
		post.id = checkPostId(email);
		fwrite(&post,1,sizeof(post),postFile);	
		printf("%s",REGISTER_POST_SUCCESS);
		getch();
		fclose(postFile);
		system("cls");
		printf("Deseja continuar?\n");
		scanf("%i",&moreAddPosts);
	}
	return 0;
}
int deletePost(char* email, int id){
	if(postUserExists(email,id)==0){
		struct POST post;
		FILE *postFile;
		FILE *postFileAux;
		postFile = fopen(POSTS_FILE,"a+");
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
		remove(POSTS_FILE);
		rename("postsaux.txt",POSTS_FILE);
		return 0;
	}else{
		printf("%s",GET_POST_ERROR);
		getch();
		return 1;
	}
}
int editPost(char* email,int id){
	if(postUserExists(email,id)==0){
		int lenghtOverflow = 1;
		struct POST post;
		struct POST postAux;
		FILE *postFile;
		FILE * postFileAux;
		postFile = fopen(POSTS_FILE,"a+");
		postFileAux = fopen("postsaux.txt","a+");
		while(fread(&post,sizeof(post),1,postFile)!=0){
			if(strcmp(email,post.email)== 0 && id==post.id){
				while(lenghtOverflow == 1){
					printf("Digite o novo conteudo:\n");
					setbuf(stdin,NULL);
					scanf("%[^\n]s",&post.postContent);
					setbuf(stdin,NULL);
					if(strlen(post.postContent)>1000){
						printf("%s",POST_LENGHT_ERROR);
						getch();
						lenghtOverflow = 1;
					}else{
						lenghtOverflow = 0;
					}
				}
					fwrite(&post,sizeof(post),1,postFileAux);
			}else{
				fwrite(&post,sizeof(post),1,postFileAux);
			}
		}
		fclose(postFile);
		fclose(postFileAux);
		remove(POSTS_FILE);
		rename("postsaux.txt",POSTS_FILE);
	}else{
		printf("%s",GET_POST_ERROR);
		getch();
		return 1;
	}
}
int getPostsUser(char* email){
	int id,action;
	struct POST post;
	FILE *postFile;
	postFile = fopen(POSTS_FILE,"a+");
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
	postFile = fopen(POSTS_FILE,"a+");
	printf("           Timeline\n-----------------------------\n");
	while(fread(&post,sizeof(post),1,postFile)!=0){
		printf("  %s@gmail.com:\n",post.email);
		printf("     %s\n\n",post.postContent);
	}	
	fclose(postFile);
	return 0;
}