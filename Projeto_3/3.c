#include <stdio.h>
#include <string.h> //usado pro strtok
#include <stdlib.h> //usado pro atoi

int main(){
    int n, i, j, ini, fin, menor, h, k, vaux, l, sum=0, uh=0, ui=0, lv;
    char v[512],t[512];
    char* token;

//ler a quantidade de cidades
    scanf("%d",&n);
    getchar(); //getchar para nao bugar o fgets

//definir a matriz para o grafo
    int m[n][n];

//ler uma string para cada linha da matriz, e, usando strtok, dividí-la para que os elementos da string vão para cada endereço da matriz

    for(i=0;i<n;i++){
        fgets(t,512,stdin);
        token=strtok(t, " ");
        m[i][0]=atoi(token); //usei o atoi pra converter elementos char da string em elementos int da matriz
            for(j=1;j<n;j++){
                token=strtok(NULL, " ");
                m[i][j]=atoi(token);
            }
    }

//definir a cidade inicial
    scanf("%d",&ini);
    v[0]=ini;

//definir cidade final
    scanf("%d",&fin);

//encontrar o menor custo a partir da proxima cidade, ate chegar na cidade destino

    k = ini;
    h = k;

    for(l=1;h!=fin;l++,h=k){
        menor = 99999999; //defini um numero bem grande pra ser o maior, assim, qualquer numero diferente de zero se tornaria o marior, e seria substituido assim que aparecer um menor ainda
        for(i=0;i<n;i++){
            if((m[h][i]<menor)&&(m[h][i]!=0)&&(m[h][i]!=m[uh][ui])){ //o elemento tem que ser menor que o antigo menor, diferente de zero, e diferente da cidade anterior
                if(l>1){
                    for(lv=l-2;(lv>=0)&&(i!=v[lv]);lv--){ //loop que verifica se a cidade já foi visitada anteriormente, sem ser a cidade passada
                        menor=m[h][i];
                        uh=h;
                        ui=i;
                        v[l]=i;
                        k=i;
                    }
                }
                else{
                    menor=m[h][i];
                    uh=h;
                    ui=i;
                    v[l]=i;
                    k=i;
                }
            }
        }
    sum+=menor; //acrescenta na soma o valor de percorrer o caminho com menor custo
    }

    printf("Menor distancia gulosa entre os nos %d e %d:: %d\n",ini ,fin , sum);
    printf("Caminho:: ");

    for(i=0;i<512;i++) //loop que pega o indice do ultimo elemento do vetor dos caminhos
        if(v[i]==fin)
            break; //o loop para quando encontrar o destino

    vaux = i; //define vaux como o valor i, pois i eh usado como um indice no prox loop

    for(i=0;i<vaux;i++) //loop para printar os caminhos, o destino fica separado por é o ultimo, portanto, também carrega o '\n'
        printf("%d->",v[i]);
    printf("%d\n",fin);


    return 0;
}

