#include "./includes/index.h"
int main(){
    setlocale(LC_ALL,"portuguese");
    int password,Login,task;
    char emailLog[SIZE];
	char passwordLog[SIZE];
    //0 para login em email, e 1 para se registrar;
    for(;;){
        getPosts();
        printf("Ja possui login?\nSim(0)\nNao(1)\nexit()\n");
        while(!scanf("%i",&Login)){
            if(isNumber(Login)==0){
                system("cls");
                printf("Por favor, digite um numero");
            }
        };
        system("cls");
        switch (Login){
            case 0:
                printf("digite seu email:");
                scanf("%s",&emailLog);
                printf("digite sua senha:");
                scanf("%s",&passwordLog);
                if(getLogin(emailLog,passwordLog)==0){
                    printf("Criar ou visualizar posts?\nCriar(0)\nVisualizar(1)\nDeletar usuario(2)\nExit(3)\n");
                    scanf("%i",&task);
                    switch (task){
                    case 0:
                        createPost(emailLog);
                        break;
                    case 1:
                        getPostsUser(emailLog);
                        getch();
                        break;
                    case 2:
                        deleteUser(emailLog);
                        break;
                    case 3:
                        break;
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