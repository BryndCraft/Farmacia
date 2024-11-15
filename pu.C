#include <stdio.h>
#include <conio.h>
#include <mouse.h>
#include <graphics.h>
#include <utilidades.h>
#include <string.h>
#include <stdlib.h>
#include <dos.h>
#include <ctype.h>
#define MAX 20

typedef struct{
	int codigo;
	char nombre[MAX];
	int precio;
	char fecha_vencimiento[MAX];
	char unidad_medida[MAX];
	int cantidad;
	char descripcion[100];


}Producto;

void inicio(void);
void final(void);
void ventana_principal(void);
void inventario(void);
void header(void);
void agregar(void);
void descripcion_producto(void);
void Error(char mensaje[], void (*funcion)(void));
void campos_registro(char opcion1[], char opcion2[], char opcion3[]);
void buscar(void);
void informacion_producto(int n);
void actualizar(void);
void menu_actualizar(int n);
void cambiar_propiedad_interfaz(void);
void ver(void);
void menu_login(void);
void comprobacion(void);
void pantalla_error(void);

Producto medicamentos[MAX];

int count_p = 0;
int i, j;
char usuario[100];
char contrasena[100];
char numero_intentos[100];
int intentos = 0;
int main(){

  strcpy("Brynd", medicamentos[0].nombre);
  inicio();
  mver();
  menu_login();
  final();
return 0;

}

void inicio(){

	int graficos = DETECT, modo;

	clrscr();

	initgraph(&graficos, &modo, "");
	cleardevice();
}

void final(){


	getch();
	closegraph();

}


void ventana_principal(){

	mocultar();
	cleardevice();
    setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);

	setcolor(BLACK);
	settextstyle(0,0, 3);
	outtextxy(260, 90, "Menu");
	boton(240, 180, 380, 30);
	boton(240, 260, 380, 30);
	boton(240, 340, 380, 30);


	settextstyle(2, 0 , 5);


	outtextxy(280, 170, "Inventario");
	rectangle(240 , 160, 270, 195);
	rectangle(242, 162, 268, 193);
	line(245, 170, 265, 170);
	line(245, 175, 265, 175);
	line(245, 180, 265, 180);
	line(245, 185, 265, 185);




	outtextxy(280, 250, "Cliente");
	setfillstyle(1, BLACK);
	pieslice(250, 270, 0, 180, 10);
	circle(250, 250, 6);
	floodfill(250, 250, BLACK);


	outtextxy(280, 330, "Salir");
	circle(250, 335, 15);

	line(242, 330, 257, 345);
	line(242, 345, 257, 330);
	setfillstyle(1, LIGHTRED);
	floodfill(243, 346, BLACK);

	header();
	mver();

	while(!kbhit()){

	if(minlimit(1, 210, 230, 410, 290) == 1){
			setcolor(LIGHTGRAY);
			boton(240, 260, 380, 38);
            if(mclick()){

				inventario();
				break;
			}
	}else if(minlimit(1, 220, 240, 400, 300) == 0){
				setcolor(WHITE);
				boton(240, 260, 380, 38);


	}
	if(minlimit(1, 210, 150, 410, 210) == 1){
			setcolor(LIGHTGRAY);
			boton(240, 180, 380, 38);
			if(mclick()){

				inventario();
				break;
			}
	}else if(minlimit(1, 220, 160, 400, 200) == 0){
				setcolor(WHITE);
				boton(240, 180, 380, 38);

	   }


   if(minlimit(1, 210, 310, 410, 370) == 1){
			setcolor(LIGHTGRAY);
			boton(240, 340, 380, 38);
            if(mclick()){

				exit(0);
				break;
			}
	}else if(minlimit(1, 220, 320, 400, 340) == 0){
				setcolor(WHITE);
				boton(240, 340, 380, 38);


	}
    if(mclick() && minlimit(1, 10, 5, 250, 40)){
			ventana_principal();
			break;
		}

	}

}



void inventario(){

	 cleardevice();
	 mocultar();
	 setfillstyle(1, WHITE);
	 bar(0,0, 640,480);

	 header();
	 setcolor(BLACK);

	 for(i=50; i < 600; i += 200){
		for(j = 80; j < 400; j+=200){
			cuadrado(i, j, 150, 150);
			circle(i + 75, j + 60, 40);
			setfillstyle(1, LIGHTCYAN);
			floodfill(i + 130, j + 50, BLACK);
		}
	 }
	 /*1 icono*/
	 setfillstyle(1, BLACK);
	 cruz(125, 140, 50, 50);
	 settextstyle(1, 0, 2);
	 outtextxy(90, 190, "Agregar");

	 /*2 icono*/
	 circle(315, 130, 17);
	 circle(315, 130, 20);
	 line(330, 144, 350, 164);
	 line(325, 148, 341, 164);
	 line(341, 164, 350, 164);

	 setfillstyle(1, BLACK);
	 floodfill(297, 130, BLACK);
	 floodfill(333, 130, BLACK);
	 floodfill(328, 149, BLACK);
	 outtextxy(300, 190, "Buscar");

	 /*3 icono*/

	 arc(525, 140, 90, 210, 20);
	 arc(525, 140, 90, 210, 25);
	 triangulo(525, 118, 10, 2);
	 line(503, 154, 508, 150);
	 floodfill(505, 150, BLACK);
	 floodfill(528, 120, BLACK);

	 arc(525,140, 270, 40, 20);
	 arc(525, 140, 270, 40, 25);
	 triangulo(525, 162, 10, 3);
	 line(544, 123, 540, 127);
	 floodfill(542, 128, BLACK);
	 floodfill(522, 160, BLACK);

	 outtextxy(480, 190, "Actualizar");

	 /*4 icono*/

	 settextstyle(10, 0, 5);
	 outtextxy(113, 285, "X");
	 floodfill(125, 340, BLACK);
	 settextstyle(1,0,2);
	 outtextxy(85, 390, "Eliminar");

	/*5 icono*/

	ellipse(325, 340, 0, 360, 30, 20);
	floodfill(325, 340, BLACK);
	setcolor(WHITE);
	circle(325, 340, 9);
	circle(325, 340, 16);
	setfillstyle(1, WHITE);
	floodfill(325, 350, WHITE);
	setcolor(BLACK);
	outtextxy(310, 390, "Ver");

	/*6 icono*/
	settextstyle(10,0, 5);
	outtextxy(510, 285, "S");
	setfillstyle(1, BLACK);
	floodfill(528, 340, BLACK);
	floodfill(535, 325, BLACK);
	floodfill(514, 355, BLACK);
	setfillstyle(1, BLACK);
	bar(520, 305, 530, 370);
	settextstyle(1, 0, 2);

	outtextxy(500, 390, "Vender");

	mver();
	while(!kbhit()){

		if(minlimit(1, 50, 80, 200, 230) && mclick()){
		   agregar();
		   break;

		}

		if(minlimit(1, 250, 80, 400, 230) && mclick()){
		  if(count_p == 0){
			Error("No hay medicamentos disponibles", inventario);
		  }else{
		   buscar();
		   break;
		   }
		}

		if(minlimit(1, 450, 80, 600, 230 )&& mclick() ) {
			if(count_p == 0){
				Error("No hay medicamentos disponibles", inventario);
				}else{

				actualizar();
				break;
				}

			}
		if(minlimit(1,250, 280, 400, 430) && mclick()){
			if(count_p == 0){

				Error("No hay medicamentos disponibles", inventario);
			}else{

			ver();
			break;

			}

		}
		if(minlimit(1, 20, 5, 250, 50) && mclick()){
	 		ventana_principal();
		}

	}
}

void agregar(){

        /* Elementos del producto*/
	int precio = 0, codigo = 0, cantidad = 0;
	char nombre[MAX], descripcion[100], venci[MAX], medida[MAX];
	int valido, resultado = 0;
	int dia = 0, mes = 0, ano = 0;
	char dia_cadena[3], mes_cadena[3], ano_cadena[8];

	strcpy(nombre, "");
	strcpy(venci, "");
	strcpy(medida, "");

	/*Llamar a funcion para que se muestren los primeros 3 campos
	 del registro del producto*/
	
	campos_registro("Nombre", "Cantidad", "Codigo");




	do{

		valido = 1;
		setfillstyle(1, LIGHTGRAY);
		bar(160, 112, 320, 144);
		gotoxy(22, 8);
		scanf("%s", nombre);
		printf("%s", nombre);
		for(i = 0; nombre[i] != '\0'; i++){
			if(isdigit(nombre[i])){
				printf("capo no escribas numeros");
				valido = 0;
				getch();
				break;
			}
		}
		for(i = 0; i < count_p; i++){
			if(strcmp(nombre, medicamentos[i].nombre) == 0){

					printf("ESte nombre ya esta utilizado capo");
					valido = 0;
					getch();
					break;
			}
		}

	}while(!valido);



	do{	
		valido = 1;
		setfillstyle(1, LIGHTGRAY);
		bar(170, 182, 320, 214);
		gotoxy(22, 13);
		
		resultado = scanf("%d", &cantidad);
		if(resultado != 1){
			printf("capo no escribas letras");
			valido = 0;
			getch();
			dos

		}
		if(cantidad < 0){

			printf("Escribe una cantidad valida");
			valido = 0;
			getch();
		}


	}while(!valido);



	do{	
		valido = 1;
		setfillstyle(1, LIGHTGRAY);
		bar(170, 252, 320, 284);
		gotoxy(22, 18);
		
		resultado = scanf("%d", &codigo);
		if(resultado != 1){
			printf("capo no escribas letras");
			valido = 0;
			getch();
			while (getchar() != '\n');

		}
		if(precio < 0){

			printf("Escribe una cantidad valida");
			valido = 0;
			getch();
		}


	}while(!valido);
	
	campos_registro("Medida", "Vencimiento", "Precio");
	
	

	do{
		valido = 1;
		setfillstyle(1, LIGHTGRAY);
		bar(170, 182, 320, 214);
		gotoxy(22, 13);
		resultado = scanf("%d/%d/%d", &dia, &mes, &ano);
		if(resultado != 3){
			printf("escribe bien la fecha feo");
			valido = 0;
			while (getchar() != '\n');
		}
		else if( (dia <=0 || dia >= 32) || (mes <= 0 || mes > 12) || (
		ano < 2024) ){
			printf("Escribe una fecha de caducidad valida");
			valido = 0;
		}
	if(valido){
		sprintf(dia_cadena, "%d/", dia);
		sprintf(mes_cadena, "%d/", mes);
		sprintf(ano_cadena, "%d", ano);

		strcpy(venci, dia_cadena);
		strcat(venci, mes_cadena);
		strcat(venci, ano_cadena);
	}
	}while(!valido);
	
	do{	
		valido = 1;
		setfillstyle(1, LIGHTGRAY);
		bar(170, 252, 320, 284);
		gotoxy(22, 18);
		
		resultado = scanf("%d", &precio);
		if(resultado != 1){
			printf("capo no escribas letras");
			valido = 0;
			getch();
			while (getchar() != '\n');

		}
		if(precio < 0){
			printf("Escribe un precio valido");
			valido = 0;
			getch();
		}


	}while(!valido);

	descripcion_producto();
	gotoxy(22, 13);
	scanf("%s", descripcion);
	while (getchar() != '\n');


	strcpy(medicamentos[count_p].nombre, nombre);
	strcpy(medicamentos[count_p].descripcion, descripcion);
	strcpy(medicamentos[count_p].fecha_vencimiento, venci);
	strcpy(medicamentos[count_p].unidad_medida, medida);

	medicamentos[count_p].codigo = codigo;
	medicamentos[count_p].precio = precio;
	medicamentos[count_p].cantidad = cantidad;

	count_p++;
	getch();
	inventario();
}




void campos_registro( char opcion1[], char opcion2[], char opcion3[]){

     cleardevice();
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	header();
	setcolor(BLACK);
	cuadrado(40, 90, 350, 560);
	setfillstyle(1, CYAN);
	floodfill(100, 200, BLACK);

	settextstyle(1, 0, 1);
	setfillstyle(1, LIGHTGRAY);
	for(j = 130; j < 320; j += 70){
		boton(80, j, 540, 20);
		floodfill(100, j , BLACK);
	}


	outtextxy(80, 115, opcion1);
	outtextxy(80, 185, opcion2);
	outtextxy(80, 255, opcion3);

	setcolor(LIGHTCYAN);
	boton(250, 350, 400, 40);
	setfillstyle(1, LIGHTCYAN);
	floodfill(250, 350, LIGHTCYAN);

	setcolor(BLACK);
	settextstyle(0, 0 , 2);
	outtextxy(275, 340, "Seguir");


	mver();



}



void descripcion_producto(){

	cleardevice();
	mocultar();

	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	header();

	setcolor(BLACK);
	cuadrado(100, 100, 200, 450);
	setfillstyle(1, LIGHTGRAY);
	floodfill(120, 110, BLACK);

	setcolor(BLACK);
	settextstyle(0,0,1);
	outtextxy(150, 140, "Desea ingresar una descripcion ?");

	setcolor(WHITE);
	boton(170, 200, 220, 20);
	boton(360, 200, 410, 20);

	setfillstyle(1, WHITE);
	floodfill(175, 205, WHITE);
	floodfill(365, 205, WHITE);

	setcolor(BLACK);
	settextstyle(0, 0, 2);
	outtextxy(180, 193, "Si");
	outtextxy(370, 193, "No");


   	mver();
	while(!kbhit()){

		if(minlimit(1, 150, 180, 240, 220) && mclick()){
		  cleardevice();
		  mocultar();
		  setfillstyle(1, WHITE);
		  bar(0, 50, 640, 480);
		  header();
		  setcolor(BLACK);
		  cuadrado(40, 90, 200, 550);
		  boton(270, 370, 380, 30);
		  setfillstyle(1,LIGHTCYAN);
		  floodfill(275, 372, BLACK);
		  settextstyle(0, 0, 2);
		  outtextxy(255, 365, "Finalizar");

		  settextstyle(0, 0, 1);
		  outtextxy(60, 70, "Descripcion de producto");


		  mver();
		  break;
		}

		if(minlimit(1, 340, 180, 430, 220) && mclick()){

			inventario();
			break;

		}



	}


}


void Error(char mensaje[], void (*funcion)(void) ){

	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	cuadrado(100, 100, 200, 450);
	setfillstyle(1, BLUE);
	floodfill(130, 150, BLACK);


	setcolor(LIGHTGRAY);
	setfillstyle(1, LIGHTGRAY);
	rectangle(110, 150, 540, 290);


	floodfill(120, 155, LIGHTGRAY);

	setcolor(BLACK);
	triangulo(210, 240, 71, 1);
	setfillstyle(1, YELLOW);
	floodfill(210, 230, BLACK);

	setcolor(WHITE);
	outtextxy(120, 115, "ERROR!");
	setcolor(BLACK);
	settextstyle(0, 0, 6);
	outtextxy(190, 190, "!");

	settextstyle(2, 0 , 5);
	outtextxy(270, 190, mensaje);
	setcolor(WHITE);
	boton(360, 240, 400, 20);
	setfillstyle(1, WHITE);
	floodfill(360, 245, WHITE);
	setcolor(BLACK);
	settextstyle(0, 0, 2);
	outtextxy(365, 235, "OK");

	setfillstyle(1, BLACK);
	mver();
	while(!kbhit()){

	  if(minlimit(1, 340, 220, 420, 260) && mclick()){

		funcion();
		break;

	  }

	}


}



void buscar(){

	char busqueda[30];
	int encontrado = 0;
	char nombres[50];
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setcolor(BLACK);
	settextstyle(2, 0, 7);
	cuadrado(50,80, 370, 550);
	boton(80, 120, 560, 15);


	mver();

	while(!kbhit()){

	   if(minlimit(1, 65, 105, 575, 135) && mclick()){

		   mocultar();
		   gotoxy(11, 8);
		   gets(busqueda);
		   mver();
		   break;


	   }
	  if(mclick() && minlimit(1, 10, 5, 250, 40)){
			ventana_principal();
			break;
		}
	}

	for(i = 0; i < count_p; i++){

		if(strcmp(busqueda, medicamentos[i].nombre) == 0){

		   informacion_producto(i);
		   encontrado = 1;

		}else if(encontrado == 0){


			outtextxy(200, 300, "No existe ese producto");
			getch();
			buscar();
		}
   }
}

void informacion_producto(int n){

	   char nombres[100], descripcion[100], fecha_vencimiento[100],
	   unidad_medida[100], codigo[20], cantidad[20], precio[30];

	   settextstyle(2, 0, 4);
	   setcolor(BLACK);
	   cuadrado(80, 170, 250, 490);

	   sprintf(nombres, "Nombre: %s",  medicamentos[n].nombre);
	   outtextxy(100, 200, nombres);

	   sprintf(codigo, "Codigo: %d", medicamentos[n].codigo);
	   outtextxy(100, 220, codigo);

	   sprintf(fecha_vencimiento, "Fecha de vecimiento: %s", medicamentos[n].fecha_vencimiento);
	   outtextxy(100, 240, fecha_vencimiento);

	   sprintf(unidad_medida, "Unidad de medida: %s", medicamentos[n].unidad_medida);
	   outtextxy(100, 260, unidad_medida);

	   sprintf(cantidad, "Cantidad: %d", medicamentos[n].cantidad);
	   outtextxy(100, 280, cantidad);

	   sprintf(precio, "Precio del producto: %d", medicamentos[n].precio);
	   outtextxy(100, 300, precio);


	   if(strcmp(medicamentos[n].descripcion, "") == 0 ){

		 outtextxy(100, 320, "Descripcion: Este producto no tiene descripcion");

	   }else{
			sprintf(descripcion, "Descripcion: %s" ,medicamentos[n].descripcion);
			outtextxy(100, 320, descripcion);

	   }

	getch();
	buscar();

}


void ver(){

	char nombres[MAX];
	j = 170;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	settextstyle(0, 0, 2);
	setcolor(BLACK);
	outtextxy(180, 90, "Lista de productos");

	cuadrado(50, 120, 350, 550);
	settextstyle(2, 0, 6);

	for(i = 0; i < count_p; i++){

		 sprintf(nombres, "%d %s", i + 1, medicamentos[i].nombre);
		 outtextxy(250, j, nombres);
		 j += 20;

	}
	
	mver();
	while(!kbhit()){

	if(mclick() && minlimit(1, 10, 5, 250, 40)){
			inventario();
			break;
		}
	}



}

void actualizar(){

	char nombres[MAX];
	char busqueda[MAX];
	int dia = 0, mes = 0, ano = 0;
	int encontrado = 0;
	int y= 170, j;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);
	outtextxy(150, 100, "Ingresa cual producto deseas actualizar");

	boton(110, 135, 500, 10);

	for(i=0; i < count_p; i++){
		sprintf(nombres, "%d.%s",i +1, medicamentos[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();

	while(!kbhit()){

		if(minlimit(1,100, 125, 510, 145) && mclick()){

			mocultar();
			gotoxy(15, 9);
			fgets(busqueda, sizeof(busqueda), stdin);
			busqueda[strcspn(busqueda, "\n")] = '\0';
			mver();
			break;
		}
		if(mclick() && minlimit(1, 10, 5, 250, 40)){
			inventario();
			break;
		}
	}

	for(i = 0; i < count_p; i++){

		if( (strcmp(busqueda, medicamentos[i].nombre))
		== 0 || atoi(&busqueda[0]) == 1+i){
			menu_actualizar(i);
			encontrado = 1;
		 }


	}


	if(encontrado == 0){

		Error("No existe ese producto", actualizar);


	}


}


void menu_actualizar(int n){

	 int j;
	 int dia = 0, mes = 0 , ano = 0;
	 char dia_cadena [3], mes_cadena[3], ano_cadena[8]; 
	 int valor_entero = 0;
	 int resultado;
	 char valor[MAX];
	 mocultar();
	 setfillstyle(1, WHITE);
	 bar(0, 50, 640, 480);

	 setcolor(BLACK);
	settextstyle(0, 0, 2);
	outtextxy(160, 100, "Selecciona una opcion");
	 for(i = 90; i < 500; i+=300){
		for(j = 180; j < 400; j+=100){
			boton(i, j, i +150, 25);
		}

	 }

	 settextstyle(2, 0, 6);
	 outtextxy(130, 170, "Nombre");
	 outtextxy(130, 270, "Codigo");
	 outtextxy(130, 370, "Precio");
	 outtextxy(420, 170, "Vencimiento");
	 outtextxy(430, 270, "Cantidad");
	 outtextxy(430, 370, "Medida");
	 mver();

	 while(!kbhit()){
		if(mclick() && minlimit(1, 10, 5, 250, 40)){
			actualizar();
			break;
		}
		if(minlimit(1, 65, 155, 265, 205) == 1){
			 setcolor(LIGHTGRAY);
			 boton(90, 180, 240, 35);
		   if(mclick()){
			 mocultar();
			 cambiar_propiedad_interfaz();
             outtextxy(130, 160, "Nuevo nombre");
			 mver();

			 mocultar();
			 gotoxy(18, 13);
			 gets(valor);
			 for(i = 0; valor[i] != '\0'; i++){
			   if(isdigit(valor[i])){
					printf("capo no escribas numeros");
					getch();
					menu_actualizar(n);
					mver();

					break;
			   }


			 }


			 for(i = 0; i < count_p; i++){

				if(strcmp(valor, medicamentos[n].nombre) == 0){

					printf("ESte nombre ya esta utilizado capo");
					getch();
					menu_actualizar(n);
					break;
				}


			}

			 strcpy(medicamentos[n].nombre, valor);
			 mver();
			 printf("\n%s", medicamentos[n].nombre);
			 mver();
			 menu_actualizar(n);
			 break;
		   }
		}else if(minlimit(1, 65, 155, 265, 205) == 0){
			  setcolor(WHITE);
			  boton(90, 180, 240, 35);


		}

		if(minlimit(1, 365, 155, 565, 205) == 1){
			setcolor(LIGHTGRAY);
			boton(390, 180, 540, 35);
            if(mclick()){
		/*Comprobar valor de la fecha*/
			mocultar();
			 cambiar_propiedad_interfaz();
             outtextxy(130, 160, "Nueva fecha");
			 mver();

			 mocultar();
			 gotoxy(18, 13);
		 resultado = scanf("%d/%d/%d", &dia, &mes, &ano);
			 if(resultado != 3){
				printf("escribe bien la fecha feo");
			 }else{
			 printf("%d%d%d", dia, mes, ano);
			 }
			 if( (dia <=0 || dia >= 32) || (mes <= 0 || mes > 12) || (
			 ano < 2024) ){
				printf("Escribe una fecha de caducidad valida");
			 }
			sprintf(dia_cadena, "%d/", dia);
			sprintf(mes_cadena, "%d/", mes);
			sprintf(ano_cadena, "%d", ano);

			strcpy(valor, dia_cadena);
			strcat(valor, mes_cadena);
			strcat(valor, ano_cadena);
			printf("%s", valor);
			 break;
			}
		}else if(minlimit(1, 365, 155, 565, 205) == 0){
			setcolor(WHITE);
			boton(390, 180, 540, 35);


		}

	   if(minlimit(1, 65, 255, 265, 305) == 1){
			setcolor(LIGHTGRAY);
			boton(90, 280, 240, 35);

			if(mclick()){
			 mocultar();
			 cambiar_propiedad_interfaz();
             outtextxy(130, 160, "Nuevo Codigo");

			 gotoxy(18, 13);
			 scanf("%s", &valor);
			 
			   if(atoi(valor) == 0){
					printf("capo no escribas letras");
					getch();
					menu_actualizar(n);
					mver();

					break;
			   }


			
			valor_entero = atoi(valor);
			printf("%d", valor_entero);
			printf("\n%d", medicamentos[1].codigo);
			 for(i = 0; i < count_p; i++){

				if(valor_entero == medicamentos[i].codigo){

					printf("ESte codigo ya esta utilizado capo");
					getch();
					menu_actualizar(n);
					break;
				}
			

			}
			mver();
			break;
		    }	
			
		}else if(minlimit(1, 65, 255, 265, 305) == 0){
			setcolor(WHITE);
			boton(90, 280, 240, 35);


		}

		if(minlimit(1,365, 255, 565, 305) == 1){
			setcolor(LIGHTGRAY);
			boton(390, 280, 540, 35);
             if(mclick()){
			 mocultar();
			 cambiar_propiedad_interfaz();
             outtextxy(130, 160, "Nueva cantidad");
			 mver();

			 mocultar();
			 gotoxy(18, 13);
			 resultado = scanf("%d", &valor_entero);
			   if(resultado != 1){
					printf("capo no escribas letras");
					getch();
					menu_actualizar(n);
					mver();

			}
			if(valor_entero < 0){

				printf("Escribe una cantidad valida");
			}else{

				medicamentos[n].cantidad = valor_entero;
			}
			mver();
			break;
		}
		}else if(minlimit(1, 365, 255, 565, 305) == 0){
			setcolor(WHITE);
			boton(390, 280, 540, 35);


		}

		if(minlimit(1,65, 355, 265, 405) == 1){
			setcolor(LIGHTGRAY);
			boton(90, 380, 240, 35);
                      if(mclick()){
			 mocultar();
			 cambiar_propiedad_interfaz();
             outtextxy(130, 160, "Nuevo precio");
			 mver();

			 mocultar();
			 gotoxy(18, 13);
			 resultado = scanf("%d", &valor_entero);
			   if(resultado != 1){
					printf("capo no escribas letras");
					getch();
					mver();
					menu_actualizar(n);
					

			}
			if(valor_entero < 0){

				printf("Escribe un precio valido");
				mver();
				menu_actualizar(n);
			}else{

				medicamentos[n].precio= valor_entero;
			}
			mver();
			break;
		}

		}else if(minlimit(1, 65, 355, 265, 405) == 0){
			setcolor(WHITE);
			boton(90, 380, 240, 35);


		}


		if(minlimit(1,365, 355, 565, 405) == 1){
			setcolor(LIGHTGRAY);
			boton(390, 380, 540, 35);
			if( mclick()) {
			}

		}else if(minlimit(1, 365, 355, 565, 405) == 0){
			setcolor(WHITE);
			boton(390, 380, 540, 35);


		}

	 }


}


void cambiar_propiedad_interfaz(){

	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	setcolor(BLACK);
	cuadrado(100, 150, 100, 400);
	settextstyle(2, 0, 6);

	setfillstyle(1, LIGHTGRAY);
	bar(130, 185, 480, 230);

}

void menu_login(){

	mocultar();
	/* fondo color cyan */
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 640, 480);

	/*Recuadro de color blanco*/
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	cuadrado(100, 80, 300, 450);
	floodfill(150, 90, WHITE);

	/*Titulo de Login*/
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(280, 110, "LOGIN");

	/*Boton de Usuario*/
	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	boton(150, 170, 500, 20);
	floodfill(152, 172, LIGHTGRAY);

	/*Boton de contrasena*/
	boton(150, 250, 500, 20);
	floodfill(152, 254, LIGHTGRAY);

	/*Boton de Ingresar*/
	setcolor(LIGHTCYAN);
	boton(250, 320, 400, 20);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	floodfill(255, 325, LIGHTCYAN);

	setcolor(BLACK);
	outtextxy(265, 313, "Ingresar");

	/*Icono de usuario*/
	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	pieslice(165, 185, 0, 180, 9);
	circle(165, 165, 8);
	floodfill(168, 168, BLACK);

	/*Icono de Candado*/
	bar(155, 250, 175, 265);
	arc(165, 250, 0, 180, 7);
	arc(165, 250, 0, 180, 10);
	floodfill(165, 242, BLACK);

	/*Texto de usuario y contrasena*/
	settextstyle(0, 0, 2);
	outtextxy(210, 165, "Usuario");
	outtextxy(210, 245, "Contrasena");

	mver();
	while(!kbhit()){
		if(mclick() && minlimit(1, 130, 150, 520, 190)){

			mocultar();
			setcolor(LIGHTGRAY);
			settextstyle(0,0,2);
			outtextxy(210, 165, "Usuario");
			gotoxy(25, 11);
			scanf("%s", usuario);
			mver();

	}

		else if(mclick() && minlimit(1, 130, 230, 520, 270)){

			mocultar();
			setcolor(LIGHTGRAY);
			settextstyle(0, 0, 2);
			outtextxy(210, 245, "Contrasena");
			gotoxy(25, 16);
			scanf("%s", contrasena);
			mver();
		}
		else if(mclick() && minlimit(1, 230, 300, 420, 340)){

		   mocultar();
		   setcolor(WHITE);
		   settextstyle(0, 0,2 );
		   outtextxy(265, 313, "Ingresar");
		   comprobacion();
		   mver();
		}

	}


}

void comprobacion(){


	if(intentos == 3){

	 exit(0);
	}

	else if( (strcmp(usuario, "mario") || strcmp(contrasena, "123") )!= 0){

	  pantalla_error();

	}
	else{
		mver();
		 ventana_principal();
	}
}

void pantalla_error(){

	cleardevice();
	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 640, 480);
	setfillstyle(SOLID_FILL, WHITE);
	setcolor(BLACK);
	cuadrado(200, 150 , 150, 250);
	floodfill(210,160, BLACK);
	settextstyle(2, 0, 4);
	if(strcmp(usuario, "") != 0){
		intentos += 1;
		sprintf(numero_intentos, "Usted lleva %d intento fallido", intentos);
		outtextxy(230, 230, numero_intentos);
	}else if( strcmp(usuario, "") == 0){

		outtextxy(230, 230, "Tienes que ingresar un nombre de usuario");

	}
	getch();
	mver();
	menu_login();
}




void header(){

	mocultar();
 	setfillstyle(1, CYAN);
	bar(0, 0, 640, 50);
	setfillstyle(1, RED);
	setcolor(WHITE);
	settextstyle(0, 0, 4);
	outtextxy(30, 10, "FARMA");
	setfillstyle(1, BLACK);
	cruz(220, 20, 30, 30);
	
	setfillstyle(1, BLACK);
	mver();
}