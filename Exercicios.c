#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

//Exe1
int pin(int num){
	return (num < 10 ? num : (num % 10) * pow(10, (int)log10(num)) + pin(num/10));
}

//Exe2
void fat(int num){
	if(num > 0){
		fat(num-1);
	}
	printf("[%d]", num);
}

//Exe3
void fatrev(int num){
	if(num >= 0){
		printf("[%d]", num);
		fatrev(num-1);
	}
}



//Exe4
int isPrimo(int num, int divisor){
	if(divisor == 1)
		return 1;
	else
		if(num%divisor == 0){
			return 0;
		}else
			return isPrimo(num,divisor-1);
}

//Exe5
int comb(int n, int k){
	if(k == 1){
		return n;
	}else if(n == k){
		return 1;
	}else
		return comb(n-1,k-1) + comb(n-1,k);
}


//Exe6
int divrussa(int num1, int num2){
	int soma = 0;
	if(num1 > 0){
		soma = divrussa(num1/2, num2*2);
	}
	if(num1%2 != 0){
		soma = soma + num2;
	}
return soma;
}


int main(int argc, char const *argv[]){
	
	int num = 123;

	
	printf("Exercicio 1\n");
	printf("%d\n", pin(num));

	printf("\nExercicio 2\n");
	fat(100); printf("\n");

	printf("\nExercicio 3\n");
	fatrev(100); printf("\n");

	printf("\nExercicio 4\n");
	printf("%d\n", isPrimo(7,6));

	printf("\nExercicio 5\n");
	printf("%d\n", comb(4,3));

	printf("\nExercicio 6\n");
	printf("%d\n",  divrussa(146, 37));

	return 0;
} 