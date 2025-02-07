/* Atividade Karatsuba */
/*
  Arquivo: CarolineGuimaraesCampos_Karatsuba.c
  Autor: Caroline Guimarães Campos
  Date: 17/11/24 09:08
  Descrição: Este programa implementa o algoritmo Karatsuba, por meio de recursão, 
  a fim de multiplicar dois números grandes (a, b). Este algoritmo tem como caso base (n = 1),
  ou seja, 'a' e 'b' precisam ter apenas um dígito.
*/

#include <stdio.h>
#include <math.h>

/* interface */
int contador = 0; 			// Contador está sendo usada para descobrir quantas vezes a função será chamada.
int karatsuba(int, int);	// Devolver valor da multiplicação de dois números grandes.

int main(){
	int a = 12345; 
	int b = 6789; 
	int A = 1234;
	int B = 987654;
	int c = karatsuba(a, b);
	
	printf("A = %d   B = %d   C = %d\n\nChamadas = %d",a,b,c,contador);
	contador = 0;	// contador reinicializado.
	c = karatsuba(A, B);
	printf("\n\nA = %d   B = %d   C = %d\n\nChamadas = %d",A,B,c,contador);
	
	return 0;
}

/* implementações */
int karatsuba(int a, int b){
	contador++;	// Adiciona 1 ao contador.

	int c;
	int n, metade;
	int altoA, baixoA, altoB, baixoB;
	int multAltos, multBaixos, multSoma;
	
	if(a < 10 && b < 10){	// Caso base: se os números A e B tiverem apenas um dígito, não há necessidade de utilizar o algoritmo Karatusba.
		c = a * b;
		
	}
	else{
		n = fmax(log10(a)+1, log10(b)+1);						// Encontra qual o maior numero de digitos entre A e B.
		if(n % 2 == 0){											// Se n for par:
			metade = n / 2;
		}else{													// Se n for ímpar:
			metade = n / 2 + 1;
		}
		
		// Dividindo 'a' e 'b' em partes altas e baixas.
		altoA = a / pow(10, metade);
		baixoA = a % (int)pow(10, metade);
		altoB = b / pow(10, metade);
		baixoB = b % (int)pow(10, metade);
		
		multAltos = karatsuba(altoA, altoB);					// Recursão das metades altas.
		multBaixos = karatsuba(baixoA, baixoB);					// Recursão das metades baixas.
		multSoma = karatsuba(altoA + baixoA, altoB + baixoB);	// Recursão das somas das partes.
		
		// Fórmula Karatsuba.
		c = multAltos * pow(10, 2 * metade) + (multSoma - multAltos - multBaixos) * pow(10, metade) + multBaixos;
		
	}
	
	return c;
}