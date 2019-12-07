#include "./includes/index.h"

int switchs(int(*(*functions))(),int maxlengh,char *email){
    int i;
	int task;
    scanf("%i",&i);
    if(i < maxlengh){
        system("cls");
        (**(functions+i))(email);
        return 0;
    }else if(i==maxlengh){
        task=3;
        return task;
    }else{
        printf("Acao nao existe");
        system("pause");
        return 0;
    }
    
}

void initializeFiles(){
    /*
        Essa função inicializará todos os dados de um arquivo, se existirem,
        para um vetor, alocando mais memoria ao vetor se precisar;
    */
    users = (struct USER *)calloc(SIZE_USER,sizeof(struct USER));
    posts = (struct POST *)malloc(SIZE_POST*sizeof(struct POST));
    FILE *userFile;
    FILE *postFile;
    userFile = fopen("users.txt","rb");
    postFile = fopen("posts.txt","rb");
    if(postFile != NULL){
        while(fread(&posts[POSITION_POST],sizeof(posts[POSITION_POST]),1,postFile)){
            if(POSITION_POST >=SIZE_POST-1){
                SIZE_POST = SIZE_POST*2;
                posts = (struct POST *)realloc(posts,SIZE_POST*sizeof(struct POST));
            }
            POSITION_POST++;
        }
        fclose(postFile);
    }
    if(userFile !=NULL){
        while(fread(&users[POSITION],sizeof(users[POSITION]),1,userFile)){
            if(POSITION >=SIZE_USER-1){
                SIZE_USER = SIZE_USER*2;
                users = (struct USER *)realloc(users,SIZE_USER*sizeof(struct USER));
            }
            POSITION++;
        }
        fclose(userFile);
    }
    
}

int login(){
    int task,data;
    char emailLog[50];
	char passwordLog[16];
    printf(" Digite seu email:");
    scanf("%s",&emailLog);
    printf(" Digite sua senha:");
    scanf("%s",&passwordLog);
    system("cls");
    if(userExist(emailLog,passwordLog,users)==0){
        while(task !=3){
            printf(" Criar ou visualizar posts?\n\nCriar(0)\nVisualizar(1)\nEditar Usuario(2)\nDeletar usuario(3)\nExit(4)\n");
            int (*functions[4])() = {createPost,getPostsUser,editUser,deleteUser};
            task = switchs(functions,4,emailLog);
            system("cls"); 
        }
        
    }else{
        printf("%s",LOGIN_ERROR);
        getch();
    }
    return 0;
}

int main(){
    initializeFiles();
    int data;
    //0 para login em email, e 1 para se registrar;
    FILE *userFile;
    FILE *postFile;
    int (*functions[2])() = {login,getRegister};
    int task;
    system("cls");
    //login of user
    while(task !=3){
        system("cls");
        getPosts(posts);
        printf(" Ja possui login?\nSim(0)\nNao(1)\nexit(2)\n");
        task = switchs(functions,2,"");
    }
    system("cls");
    userFile = fopen(USERS_FILE,"wb");
    for(data=0;data<SIZE_USER;data++){
        fwrite(&users[data],sizeof(users[data]),1,userFile);
    }
    fclose(userFile);
    postFile = fopen(POSTS_FILE,"wb");
    for(data=0;data<SIZE_POST;data++){
        fwrite(&posts[data],sizeof(posts[data]),1,postFile);
    }
    fclose(postFile);
    free(users);
    free(posts);
    return 0;
}
