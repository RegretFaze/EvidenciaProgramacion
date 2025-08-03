#include <stdio.h>

int main() {
	int numeros[10];
	int numeroBuscado;
	int i;
	int encontrado = 0;
	int posicion = -1;
	
	printf("Por favor, ingresa 10 números enteros para llenar el arreglo:\n");
	
	for (i = 0; i < 10; i++) {
		printf("Ingresa el número %d: ", i + 1);
		if (scanf("%d", &numeros[i]) != 1) {
			printf("Entrada no válida. Por favor, ingresa solo números enteros.\n");
			while (getchar() != '\n'); 
			i--;
		}
	}
	
	printf("\nArreglo creado: [");
	for (i = 0; i < 10; i++) {
		printf("%d", numeros[i]);
		if (i < 9) {
			printf(", ");
		}
	}
	printf("]\n");
	
	printf("\nIngresa el número que deseas buscar en el arreglo: ");
	while (scanf("%d", &numeroBuscado) != 1) {
		printf("Entrada no válida. Por favor, ingresa un número entero.\n");
		while (getchar() != '\n');
		printf("Ingresa el número que deseas buscar en el arreglo: ");
	}
	
	for (i = 0; i < 10; i++) {
		if (numeros[i] == numeroBuscado) {
			encontrado = 1;
			posicion = i;
			break;
		}
	}
	
	if (encontrado == 1) {
		printf("\n¡Número %d encontrado en el arreglo!\n", numeroBuscado);
		printf("Se encuentra en la posición (índice) %d del arreglo.\n", posicion);
		printf("Para un usuario, esto sería la posición %d (contando desde 1).\n", posicion + 1);
	} else {
		printf("\nEl número %d NO fue encontrado en el arreglo.\n", numeroBuscado);
	}
	
	return 0;
}
