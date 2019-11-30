#include "./includes/index.h"

void initializeFiles(){
    int data = 0;
    users = (struct USER *)calloc(SIZE_USER,sizeof(struct USER));
    posts = (struct POST *)malloc(SIZE_POST*sizeof(struct POST));
    FILE *userFile;
    FILE *postFile;
    userFile = fopen("users.txt","a+");
    postFile = fopen("posts.txt","a+");
    while(fread(&posts[data],sizeof(posts[data]),1,postFile)){
        if(data >=SIZE_POST-1){
            SIZE_POST = SIZE_POST*2;
            posts = (struct POST *)realloc(posts,SIZE_POST*sizeof(struct POST));
            
        }
        POSITION_POST++;
        data++;
    }
    data =0;
    while(fread(&users[data],sizeof(users[data]),1,userFile)){
        if(data >=-1){
            SIZE_USER = SIZE_USER+2;
            users = (struct USER *)realloc(users,SIZE_USER*sizeof(struct USER));
        }
        POSITION++;
        data++;
    }
    fclose(userFile);
    fclose(postFile);
}

int login(struct USER *user){
    int task,data;
    char emailLog[50];
	char passwordLog[16];
    task = 0;
    printf(" Digite seu email:");
    scanf("%s",&emailLog);
    printf(" Digite sua senha:");
    scanf("%s",&passwordLog);
    system("cls");
    if(userExist(emailLog,passwordLog,user)==0){
        while(task !=3){
            system("cls");
            printf(" Criar ou visualizar posts?\n\nCriar(0)\nVisualizar(1)\nEditar Usuario(2)\nDeletar usuario(3)\nExit(4)\n");
            scanf("%i",&task);
            switch (task){
                case 0:
                    system("cls");
                    createPost(emailLog);
                    break;
                case 1:
                    system("cls");
                    getPostsUser(emailLog);
                    break;
                case 2:
                    system("cls");
                    editUser(emailLog);
                    task = 3;
                    break;
                case 3:
                    deleteUser(emailLog);
                    task = 3;
                    break;
                case 4:
                    system("cls");
                    
                    task = 3;
                    break;
            }
                    
        }
        
    }else{
        printf("%s",LOGIN_ERROR);
        getch();
    }
    return 0;
}

int main(){
    initializeFiles();
    int password,Login,data;
    //0 para login em email, e 1 para se registrar;
        FILE *userFile;
        FILE *postFile;
    for(;;){
        system("cls");
        getPosts(posts);
        printf(" Ja possui login?\nSim(0)\nNao(1)\nexit(2)\n");
        scanf("%i",&Login);
        system("cls");
        //login of user
        switch (Login){
            case 0:
                login(users);
                break;
            case 1:
                getRegister();
                break;
            case 2:
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
                return 0;
            
        }
    }
}