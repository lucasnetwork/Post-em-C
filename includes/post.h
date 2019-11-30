int createPost(char* email){
	struct POST postLog;
	int moreAddPosts;
	moreAddPosts = 0;

	strcat(postLog.email,email);
	while(moreAddPosts ==0){
		system("cls");
		memmove(postLog.postContent,addValues(POST_LENGHT_ERROR,"","Escreva seu post: ",1000,0),sizeof(postLog.postContent));
		postLog.id = checkPostId(email);
		if(POSITION_POST >= SIZE_POST-1){
			SIZE_POST = SIZE_POST*2;
			posts = (struct POST *)realloc(posts,SIZE_POST*sizeof(struct POST));
		}
			posts[POSITION_POST] = postLog;
			printf("%s",REGISTER_POST_SUCCESS);
			system("pause");
			POSITION_POST++;
		system("cls");
		printf("Deseja criar mais um post?\nSim(0)\nNao(1)\n");
		scanf("%i",&moreAddPosts);
	}
	return 0;
}
int deletePost(char* email, int id){
	int i,j;
	j=0;
	if(postUserExists(email,id)==0){
		struct POST *newPosts;
		newPosts = (struct POST *)malloc(POSITION_POST*sizeof(struct POST));
		system("cls");
		for(i=0;i<=POSITION_POST;i++){
			if(strcmp(email,posts[i].email)!=0){
				newPosts[j] = posts[i];
				j++;
			}
			if(strcmp(email,posts[i].email)== 0 && id != posts[i].id){
				newPosts[j] = posts[i];
				j++;
			}
		}
		posts = newPosts;
		return 0;
	}else{
		printf("%s",GET_POST_ERROR);
		getch();
		return 1;
	}
}
int editPost(char* email,int id){
	int i;
	if(postUserExists(email,id)==0){
		int lenghtOverflow = 1;
		struct POST *newPosts;
		newPosts = (struct POST *)malloc((POSITION_POST+1)*sizeof(struct POST));
		for(i=0;i<=POSITION_POST;i++){
			if(strcmp(email,posts[i].email)== 0 && id==posts[i].id){
				memmove(newPosts[i].postContent,addValues(POST_LENGHT_ERROR,"","Digite o novo conteudo: ",1000,0),sizeof(newPosts[i].postContent));
			}else{
				newPosts[i] = posts[i];
			}
		}

		posts = newPosts;
	}else{
		printf("%s",GET_POST_ERROR);
		getch();
		return 1;
	}
}
int getPostsUser(char* email){
	int id,action,i;
	printf("Posts do usuario %s\n",email);
	for(i=0;i<=POSITION_POST;i++){
            if(strcmp(email,posts[i].email)== 0){
				printf("\n  email:%s\n",posts[i].email);
				printf("  id:%i\n",posts[i].id);
				printf("  %s\n\n",posts[i].postContent);
            }
	}
	printf("\n Deseja fazer alguma acao?\nDeletar(0)\nEditar(1)\nSair(3)");
	scanf("%i",&action);
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
int getPosts(struct POST *post){
	int data;
	printf("           Timeline\n-----------------------------\n");
	for(data=0; data<POSITION_POST;data++){
		if(strlen(post[data].email)!=0){
			printf("  %s@gmail.com:\n",post[data].email);
			printf("     %s\n\n",post[data].postContent);
		}
	}	
	return 0;
}
int deletePostsUser(char* email){
	struct POST *newPost;
	system("cls");
	int i;
	int j=0;
	newPost = (struct POST *)malloc((POSITION_POST+1)*sizeof(struct POST));
	for(i=0;i<SIZE_POST;i++){
		if(strcmp(email,posts[i].email)!=0){
			newPost[j] = posts[i];
			j++;
		}
	}
	posts = newPost;
	return 0;
}