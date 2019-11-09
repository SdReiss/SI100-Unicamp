//Breno Souza dos Reis RA:232246
//Trabalho 02: Contando Números
#include <stdio.h>

int main(){
	int N, spn = 0, sin = 0, sp = 0, pn, in, p, n, vp; //N é o numero a ser inserido, spn é a soma dos pares não primos, sin dos impares não primos, e sp dos primos, o restante são variáves das respectivas somas pra realizar as operações
	scanf("%d", &N);

//(1) Soma dos números pares não primos, já que 2 é o unico par primo, então ao invés de começar por pn>1, coloquei pn>2 para já ter uma resposta direta
	for(pn=3;pn<N;pn++){
		if(pn%2==0){
			spn+=pn;
		}
	}
	printf("%d ", spn);

//(2) Soma dos números ímpares não primos, comecei com in=9 pois é o primeiro impar não primo diferente de 1, tambem usei n=3 pois é o primeiro impar diferente de um
	for(in=9;in<N;in++){
		if(in%2!=0){
			for(n=3;n<in;n++){
				if(in%n==0){
					sin+=in;
					break;
				}
			}
		}
		else{
			continue;
		}
	}
	printf("%d ", sin);

//(3) Soma dos primos, simplesmente peguei os numeros impares não primos e somei com 2, 3, 5 e 7 (totalizando 17), que são os primeiros numeros primos, ou seja, a soma de todos os numeros primos depois de 7, somados com 17
	for(p=9;p<N;p++){
		vp=0;
		n=3;
		while(n<p){
			if(p%n==0){
				vp++;
			}
			n++;
		}
		if(vp==0)
			sp+=p;	
	}
	sp+=17;
	printf("%d\n", sp);
	return 0;
}
