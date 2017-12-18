/* Somador binário feito por Thalyssa de Almeida Monteiro
Comando de compilação: gcc Somador.c -o somador */

//Bibliotecas padrão do C
#include <stdio.h>
#include <stdlib.h>

//Função para calcular o valor da porta AND
int portaAND (int bitA, int bitB){
	if((bitA == 1) && (bitB == 1)){
		return 1;
	}else{
		return 0;
	}
}

//Função para calcular o valor da porta XOR
int portaXOR (int bitA, int bitB){
	if((bitA == 1) ^ (bitB == 1)){
		return 1;
	}else{
		return 0;
	}
}

//Função para calcular o valor do carry
int calcCarry (int bitNum1, int bitNum2, int carryIn){
	int aux;
	if((bitNum1 == 1)^(bitNum2 == 1)){
		aux = 1;
	}else{
		aux = 0;
	}

	if(((bitNum1 == 1)&&(bitNum2 == 1)) || ((aux == 1) && (carryIn == 1))){
		return 1;
	}else{
		return 0;
	}
}

//Função para executar todos os cálculos do circuito representado, retornando o valor da soma dos bits
int circuito (int bit1, int bit2, int carryIn){
	int and1 = portaAND(bit1, bit2);
	int xor1 = portaXOR(bit1, bit2);
	int and2 = portaAND(xor1, carryIn);
	int xor2 = portaXOR(xor1, carryIn);
	return xor2;
}

int main (int argc, char *argv[]){//Recebe duas strings como argumento

	int numb1 = atoi(argv[1]); //Ambas as strings de entrada são convertidas em números inteiros por meio da função atoi
	int numb2 = atoi(argv[2]);
	int bit1, bit2, bit3, bit4, bit5, bit6, bit7, bit8; //Variáveis que armazenarão o valor individual de cada bit
	int carryOut = 0; //O carry, com valor inicial 0, já que ainda não foi feita nenhuma operação
	int sum1, sum2, sum3, sum4, sum5=0; //Variáveis que armazenarão o valor da soma bit-a-bit

	/*Aqui acontecerá a "separação" dos bits de cada número inserido, pegando o resto da divisão do inteiro por 10
	(Que é, na prática, o último algarismo do número)
	e depois dividindo por 10 para retirar o algarismo que já está armazenado na variável.
	Fazendo isso sucessivamente, obtém-se todos os bits dos dois números de entrada*/

	bit1 = numb1%10;
	numb1 /= 10;
	
	bit2 = numb1%10;
	numb1 /= 10;
	
	bit3 = numb1%10;
	numb1 /= 10;

	bit4 = numb1%10;
	numb1 /= 10;

	bit5 = numb2%10;
	numb2 /= 10;

	bit6 = numb2%10;
	numb2 /= 10;

	bit7 = numb2%10;
	numb2 /= 10;

	bit8 = numb2%10;
	numb2 /= 10;

	/*Após isso, os bits estão armazenados em variáveis separadas*/

	/*Chamada da função circuito(), que calcula o valor da soma dos bits.
	Os parâmetros passados são: O primeiro bit do primeiro número, o primeiro bit do segundo número e o carry*/
	sum1 = circuito(bit1, bit5, carryOut);
	carryOut = calcCarry(bit1, bit5, carryOut); //Cálculo do valor do carry depois dessa operação
	
	/*Mesma coisa que a situação de cima só que desta vez com o segundo bit de cada número.
	Assim sucessivamente nas funções seguintes*/
	
	sum2 = circuito(bit2, bit6, carryOut);
	carryOut = calcCarry(bit2, bit6, carryOut);

	sum3 = circuito(bit3, bit7, carryOut);
	carryOut = calcCarry(bit3, bit7, carryOut);

	/*No último cálculo, o carry fica armazenado na variável sum5 pois, caso seja diferente de 0, será parte do resultado*/

	sum4 = circuito(bit4, bit8, carryOut);
	
	sum5 = calcCarry(bit4, bit8, carryOut);

	if(sum5!=0){
		printf("%d%d%d%d%d\n", sum5, sum4, sum3, sum2, sum1);
	}else{
		printf("%d%d%d%d\n", sum4, sum3, sum2, sum1);
	}

	return 0;
}
