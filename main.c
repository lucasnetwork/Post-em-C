#include "./includes/index.h"
int main(){
    setlocale(LC_ALL,"");
    int password,Login,task;
    char emailLog[SIZE];
	char passwordLog[SIZE];
    //0 para login em email, e 1 para se registrar;
    for(;;){
        system("cls");
        task = 0;
        getPosts();
        printf(" Ja possui login?\nSim(0)\nNao(1)\nexit(2)\n");
        while(!scanf("%i",&Login)){
            if(isNumber(Login)==0){
                system("cls");
                printf("Por favor, digite um numero");
            }
        };
        system("cls");
        //login do usuario
        switch (Login){
            case 0:
                printf(" Digite seu email:");
                scanf("%s",&emailLog);
                printf(" Digite sua senha:");
                scanf("%s",&passwordLog);
                system("cls");
                if(getLogin(emailLog,passwordLog)==0){
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
                    printf("Email ou senha incorretos,tente novamente\n");
                    getch();
                }
                break;
            case 1:
                getRegister();
                break;
            case 2:
                return 0;
            
        }
    }
}
