#include <stdio.h>
#include <string.h>

int I=0;
char busca[41],pesquisa[41], temp[41];

struct dados{ //estrutura basica para os dados das mensagens
    char nome[102]; //nome do agente
    char dep[62]; //departamento
    char mscrp[42]; //mensagem criptografada
    int ID; //numero de identificacao
} info[999]; //define 1000 mensagens para serem criptografadas

void criptografar(){ //usado na op1 pra criptrografar a mensagem sem que a original fique salva
    int i, tam;
    tam=strlen(info[I].mscrp);
    for(i=0;i<tam;i++){
        if((info[I].mscrp[i]<=85&&info[I].mscrp[i]>=65)||(info[I].mscrp[i]<=117&&info[I].mscrp[i]>=97)){
            info[I].mscrp[i]+=5;
            continue;
       }
        if((info[I].mscrp[i]>85&&info[I].mscrp[i]<=90)||(info[I].mscrp[i]>117&&info[I].mscrp[i]<=122)){
            info[I].mscrp[i]-=21;
       }
        info[I].mscrp[tam-1]='\0';
    }
}

void criptografar_busca(){ //recebe uma entrada e criptografa pra verificar se o padrão é existente nas mensagens criptografadas
    int i, tam;
    tam=strlen(busca);
    for(i=0;i<tam;i++){
        if((busca[i]<=85&&busca[i]>=65)||(busca[i]<=117&&busca[i]>=97)){
            busca[i]+=5;
            continue;
       }
        if((busca[i]>85&&busca[i]<=90)||(busca[i]>117&&busca[i]<=122)){
            busca[i]-=21;
       }
        busca[tam-1]='\0';
    }
}

void descriptografar_pesquisa(){ //descriptografa a mensagem inserida para mostrar na op3
    int i, tam;
    tam=strlen(temp);
    for(i=0;i<tam;i++){
        if((temp[i]<=90&&temp[i]>=70)||(temp[i]<=122&&temp[i]>=102)){
            temp[i]-=5;
            continue;
       }
        if((temp[i]>=65&&temp[i]<70)||(temp[i]>=97&&temp[i]<102)){
            temp[i]+=21;
       }
        temp[tam]='\0';
    }
}

void op1(){ //funcao pra quando a operacao 1 for escolhida
    printf("Digite o nome do agente: \n");
    getchar();
    fgets(info[I].nome,102,stdin);

    printf("Digite o departamento: \n");
    fgets(info[I].dep,62,stdin);

    printf("Digite a mensagem a ser criptografada: \n");
    fgets(info[I].mscrp,42,stdin);
    criptografar();

    printf("Digite o numero de identificacao do agente: \n");
    scanf("%d",&info[I].ID);

    I++;
}

void op2(){ //operacao 2
    int soma, i;

    printf("Digite o padrao a ser encontrado: \n");
    getchar();
    fgets(busca,41,stdin);

    criptografar_busca();

    for(i=0,soma=0;i<I;i++){
        if(strstr(info[i].mscrp,busca)!=NULL)
            soma++;
    }

    if(soma==0)
    printf("****Padrao nao encontrado!****\n");
    else
    printf("****Padrao encontrado em %d mensagens!****\n",soma);
}

void op3(){ //e assim por diante
    int i, tam, soma;

    printf("Digite a mensagem criptografada: \n");
    getchar();
    fgets(pesquisa,41,stdin);

    tam=strlen(pesquisa);
    pesquisa[tam-1]='\0';

    for(i=0, soma=0;i<I;i++){
        if(strcmp(info[i].mscrp,pesquisa)==0){
            printf("%s",info[i].nome);
            printf("%s",info[i].dep);
            strcpy(temp, pesquisa);
            descriptografar_pesquisa();
            printf("%s\n",temp);
            printf("%d\n",info[i].ID);
            soma++;
        }
    }
        if(soma==0)
            printf("****Mensagem nao encontrada!****\n");
}

void op4(){
    int i;
    if (I!=0){
        for(i=0;i<I;i++){
            printf("%s",info[i].nome);
            printf("%s",info[i].dep);
            printf("%s\n",info[i].mscrp);
            printf("%d\n",info[i].ID);
        }
    }
    else
        printf("****Sistema Vazio!****\n");
}

int main(){
    int num;

    for(;;){
    printf("****MENU DE CRIPTOGRAFIA****\n1: Criptografar mensagem\n2: Encontrar padroes\n3: Descriptografar mensagem\n4: Visualizar todas as mensagens\n0: Sair!\n"); //imprime o menu
    scanf("%d",&num); //recebe uma entrada para escolher a opчуo
        switch (num){//switch pra identificar a entrada
        case 1:
            printf("****ADICIONAR MENSAGEM****\n");
            op1();//chama a funcao 1
            break;
        case 2:
            printf("****ENCONTRAR PADROES****\n");
            op2();
            break;
        case 3:
            printf("****DESCRIPTOGRAFAR MENSAGEM****\n");
            op3();
            break;
        case 4:
            printf("****VISUALIZAR TODAS AS MENSAGENS****\n");
            op4();
            break;
        case 0:
            return 0;//se a entrada for 0, o programa щ encerrado
        default:
            printf("****Opcao Invalida, tentar novamente****\n");
            break;
        }
    }
}
