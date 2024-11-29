#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>


int nombre_valido(char nombre[]);
int fecha_valida(int dia, int mes, char anio[]);
int medida_valida(int cantidad_medida, char unidad_medida[]);
int numero_valido(char numero[]);
int pregunta_validacion(char pregunta[]);
int cantidad_valida(char cantidad[]);
int telefono_valido(char telefono[]);

int nombre_valido(char nombre[]){
	  int i;
	  int solo_espacios = 1;
	  for(i = 0; nombre[i] != '\0'; i++){
		  if(!isalpha(nombre[i]) && nombre[i] != ' '){
			return 1;

		  }

		  if(nombre[i] != ' '){
			solo_espacios = 0;
			
			}
	  }

	 if(solo_espacios){
		return 1;

		}
	 return 0;
}

int fecha_valida(int dia, int mes, char anio[]){

	int diasEnMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int i;
	int anio_entero;
	for(i = 0; anio[i] != '\0'; i++){
		  if(!isdigit(anio[i])){
			return 1;

		  }
	 }
	
	if(anio[0] == '0'){
		return 1;
	}
	anio_entero = atoi(anio);	

	if(anio_entero <= 2024 || anio_entero > 2100 || mes < 1 || mes > 12 || dia < 1){
		return 1;

	}

	if(dia > diasEnMes[mes - 1]){

		return 1;

	}

	return 0;

}

int numero_valido(char numero[]){
	  int i;
	  int numero_entero;
	  for(i = 0; numero[i] != '\0'; i++){
		  if(!isdigit(numero[i]) || numero[i] == ' '){
			return 1;

		  }
	  }
	  if(numero[0] == '0'){

		return 1;
	  }
	  numero_entero = atoi(numero);
	  if(numero_entero <= 0){
		return 1;

	  }
	  return 0;
}


int medida_valida(int cantidad, char unidad_medida[]){

    char medida[20];
    int i;
	
    for (i = 0; unidad_medida[i] != '\0'; i++) {
        medida[i] = tolower(unidad_medida[i]);
    }
    medida[i] = '\0'; 


    if (strcmp(medida, "ml") != 0 && strcmp(medida, "g") != 0 && strcmp(medida, "mg") && strcmp(medida, "u") != 0) {
        return 1; 
    }

    return 0; 
}

int cantidad_valida(char cantidad[]){

	int i;
	int cantidad_entero;
	  for(i = 0; cantidad[i] != '\0'; i++){
		  if(!isdigit(cantidad[i]) || cantidad[i] == ' '){
			return 1;

		  }
	  }
	  if(cantidad[0] == '0'){

		return 1;
	  }
	  cantidad_entero = atoi(cantidad);
	  if(cantidad_entero < 0){
		return 1;

	  }
	  return 0;	


}
int pregunta_validacion(char pregunta[]){
	int i;

	if (pregunta[0] == '\0') {
        	return 1;
    	}

	for(i = 0; pregunta[i] != '\0'; i++){
		pregunta[i] = tolower(pregunta[i]);

		if(!isalpha(pregunta[i]) || pregunta[i] == ' '){
			return 1;
		}else if(pregunta[0] != 's' && pregunta[0] != 'n'){
			return 1;
		}

	}

	return 0;
                      
}
 
int telefono_valido(char telefono[]){

	int i;

	 if(strlen(telefono) != 8){
        	return 1; 
	}
   
    	for (i = 0; telefono[i] != '\0'; i++) {
        	if(!isdigit(telefono[i])){
            		return 1; 
        	}
    	}

	return 0;
}
