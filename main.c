#include "./includes/index.h"

int login(){
    int task;
    task = 0;
    char emailLog[50];
	char passwordLog[16];
    printf(" Digite seu email:");
    scanf("%s",&emailLog);
    printf(" Digite sua senha:");
    scanf("%s",&passwordLog);
    system("cls");
    if(userExist(emailLog,passwordLog)==0){
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
}

int main(){
    setlocale(LC_ALL,"");
    int password,Login;
    //0 para login em email, e 1 para se registrar;
    for(;;){
        system("cls");
        getPosts();
        printf(" Ja possui login?\nSim(0)\nNao(1)\nexit(2)\n");
        scanf("%i",&Login);
        system("cls");
        //login of user
        switch (Login){
            case 0:
                login();
                break;
            case 1:
                getRegister();
                break;
            case 2:
                return 0;
            
        }
    }
}
