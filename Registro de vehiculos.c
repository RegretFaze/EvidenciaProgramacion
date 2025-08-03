#include <stdio.h>
#include <stdlib.h> 
#include <string.h>

void clearScreen() {
#ifdef _WIN32
	system("cls"); // Para Windows
#else
	system("clear"); // Para Linux/macOS
#endif
}

// Función para registrar un nuevo vehículo
void registerVehicle() {
	FILE *file;
	char ownerName[100];
	char plate[20];
	int year;
	
	// Abrir el archivo en modo de añadir
	file = fopen("matriculas.txt", "a");
	
	if (file == NULL) {
		printf("Error al abrir el archivo!\n");
		return;
	}
	
	// Obtener la entrada del usuario
	printf("\n--- Registrar Nuevo Vehiculo ---\n");
	printf("Ingrese nombre del propietario: ");
	// Consumir el caracter de nueva línea que pueda haber quedado
	getchar();
	fgets(ownerName, sizeof(ownerName), stdin);
	ownerName[strcspn(ownerName, "\n")] = 0; // Eliminar el salto de línea
	
	printf("Ingrese placa del vehiculo: ");
	scanf("%s", plate);
	
	printf("Ingrese anio del vehiculo: ");
	scanf("%d", &year);
	
	// Escribir los datos en el archivo
	fprintf(file, "%s | %s | %d\n", ownerName, plate, year);
	
	// Cerrar el archivo
	fclose(file);
	
	printf("Datos guardados correctamente en matriculas.txt.\n");
	printf("Presione Enter para continuar...");
	getchar(); // Consumir el salto de línea pendiente
	getchar(); // Esperar la pulsación de Enter
	clearScreen(); // Limpiar la pantalla después de la acción
}

// Función para leer e imprimir todos los registros de vehículos
void displayVehicles() {
	FILE *file;
	char line[256]; // Buffer para cada línea
	
	// Abrir el archivo en modo de lectura
	file = fopen("matriculas.txt", "r");
	
	if (file == NULL) {
		printf("No hay registros de vehiculos. El archivo matriculas.txt no existe o esta vacio.\n");
		printf("Presione Enter para continuar...");
		getchar(); // Consumir el salto de línea pendiente
		getchar(); // Esperar la pulsación de Enter
		clearScreen(); // Limpiar la pantalla después de la acción
		return;
	}
	
	printf("\n--- Registros de Vehiculos ---\n");
	// Leer e imprimir cada línea hasta el final del archivo
	while (fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
	}
	
	// Cerrar el archivo
	fclose(file);
	
	printf("\nPresione Enter para continuar...");
	getchar(); // Consumir el salto de línea pendiente
	getchar(); // Esperar la pulsación de Enter
	clearScreen(); // Limpiar la pantalla después de la acción
}

int main() {
	int choice;
	
	do {
		printf("\n--- Menu Principal ---\n");
		printf("1. Registrar nuevo vehiculo\n");
		printf("2. Mostrar todos los vehiculos\n");
		printf("3. Salir\n");
		printf("Ingrese su opcion: ");
		scanf("%d", &choice);
		
		// Limpiar el buffer de entrada antes de la siguiente lectura
		while (getchar() != '\n'); 
		
		switch (choice) {
		case 1:
			clearScreen(); // Limpiar antes de la acción
			registerVehicle();
			break;
		case 2:
			clearScreen(); // Limpiar antes de la acción
			displayVehicles();
			break;
		case 3:
			printf("Saliendo del programa. ¡Hasta luego!\n");
			break;
		default:
			printf("Opcion invalida. Por favor, intente de nuevo.\n");
			printf("Presione Enter para continuar...");
			getchar(); // Consumir el salto de línea pendiente
			getchar(); // Esperar la pulsación de Enter
			clearScreen(); // Limpiar la pantalla después de la acción
		}
	} while (choice != 3);
	
	return 0;
}
