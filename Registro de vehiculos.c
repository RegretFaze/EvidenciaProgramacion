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

// Funci�n para registrar un nuevo veh�culo
void registerVehicle() {
	FILE *file;
	char ownerName[100];
	char plate[20];
	int year;
	
	// Abrir el archivo en modo de a�adir
	file = fopen("matriculas.txt", "a");
	
	if (file == NULL) {
		printf("Error al abrir el archivo!\n");
		return;
	}
	
	// Obtener la entrada del usuario
	printf("\n--- Registrar Nuevo Vehiculo ---\n");
	printf("Ingrese nombre del propietario: ");
	// Consumir el caracter de nueva l�nea que pueda haber quedado
	getchar();
	fgets(ownerName, sizeof(ownerName), stdin);
	ownerName[strcspn(ownerName, "\n")] = 0; // Eliminar el salto de l�nea
	
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
	getchar(); // Consumir el salto de l�nea pendiente
	getchar(); // Esperar la pulsaci�n de Enter
	clearScreen(); // Limpiar la pantalla despu�s de la acci�n
}

// Funci�n para leer e imprimir todos los registros de veh�culos
void displayVehicles() {
	FILE *file;
	char line[256]; // Buffer para cada l�nea
	
	// Abrir el archivo en modo de lectura
	file = fopen("matriculas.txt", "r");
	
	if (file == NULL) {
		printf("No hay registros de vehiculos. El archivo matriculas.txt no existe o esta vacio.\n");
		printf("Presione Enter para continuar...");
		getchar(); // Consumir el salto de l�nea pendiente
		getchar(); // Esperar la pulsaci�n de Enter
		clearScreen(); // Limpiar la pantalla despu�s de la acci�n
		return;
	}
	
	printf("\n--- Registros de Vehiculos ---\n");
	// Leer e imprimir cada l�nea hasta el final del archivo
	while (fgets(line, sizeof(line), file) != NULL) {
		printf("%s", line);
	}
	
	// Cerrar el archivo
	fclose(file);
	
	printf("\nPresione Enter para continuar...");
	getchar(); // Consumir el salto de l�nea pendiente
	getchar(); // Esperar la pulsaci�n de Enter
	clearScreen(); // Limpiar la pantalla despu�s de la acci�n
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
			clearScreen(); // Limpiar antes de la acci�n
			registerVehicle();
			break;
		case 2:
			clearScreen(); // Limpiar antes de la acci�n
			displayVehicles();
			break;
		case 3:
			printf("Saliendo del programa. �Hasta luego!\n");
			break;
		default:
			printf("Opcion invalida. Por favor, intente de nuevo.\n");
			printf("Presione Enter para continuar...");
			getchar(); // Consumir el salto de l�nea pendiente
			getchar(); // Esperar la pulsaci�n de Enter
			clearScreen(); // Limpiar la pantalla despu�s de la acci�n
		}
	} while (choice != 3);
	
	return 0;
}
