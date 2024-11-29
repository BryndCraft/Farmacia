#include <conio.h>
#include <utilidades.h>
#include <validacion.h>

#define MAX 20
#define MAX_DESC 40

typedef struct{
	int codigo;
	char nombre[MAX];
	int precio;
	char fecha_vencimiento[MAX];
	char unidad_medida[MAX];
	int cantidad;
	char descripcion[100];


}Producto;

typedef struct{

	int codigo;
	char telefono[9];
	char nombre[MAX];
	int credito;
	int membresia;
	char direccion[MAX_DESC];

}Cliente;


void menu_login(void);
void inicio(void);
void final(void);
void ventana_principal(void);
void inventario(void);
void header(void);
void agregar(void);
void campos_registro(char opcion1[], char opcion2[], char opcion3[]);
void buscar(void);
void informacion_producto(int n);
void actualizar(void);
void menu_actualizar(int n);
void cambiar_propiedad_interfaz(void);
void ver(void);
void agregar_fichero(void);
void nombre_actualizar(int indice);
void codigo_actualizar(int indice);
void precio_actualizar(int indice);
void fecha_vencimiento_actualizar(int indice);
void unidad_medida_actualizar(int indice);
void cantidad_actualizar(int indice);
void descripcion_actualizar(int indice);
void eliminar(void);
void vender(void);
void menu_vender(int indice);
void menu_vender_clientes(int indice);
void menu_informacion_cliente(int indice, int indice_cliente);
void menu_compra_producto(int indice_prod, int indice_cliente);
void descripcion_actualizar(int indice);
void descripcion_actualizar_icono(int indice);


void clientes_menu(void);
void interfaz_clientes(void);
void registrar_clientes(void);
void buscar_clientes(void);
void ver_clientes(void);
void actualizar_clientes(void);
void eliminar_clientes(void);
void campos_registro2(char opcion[]);
void agregar_fichero_cliente(void);
void informacion_cliente(int indice);
void menu_actualizar_clientes(int indice);
void nombre_actualizar_cliente(int indice);
void codigo_actualizar_cliente(int indice);
void credito_actualizar_cliente(int indice);
void direccion_actualizar_cliente(int indice);
void membresia_actualizar_cliente(int indice);
void telefono_actualizar_cliente(int indice);


void ver_clientes(void);
void eliminar_clientes(void);
void agregar_fichero_registro(char nombre_cliente[], char nombre_producto[], int credito_final, int precio_producto, int cant_vendida);


Producto medicamentos[10];
Cliente clientes[10];

int count_p = 0;
int count_c = 0;
int i, j;
char usuario[10];
char contrasena[10];
char numero_intentos[30];
int intentos= 1;
int registro;


int main(){
  medicamentos[0].codigo = 30;
strcpy(medicamentos[0].nombre, "acetaminofen");
medicamentos[0].precio = 10;
strcpy(medicamentos[0].fecha_vencimiento, "30/10/2025");
strcpy(medicamentos[0].unidad_medida, "30ml");
medicamentos[0].cantidad = 300;
strcpy(medicamentos[0].descripcion, "sin descripcion");
count_p++;
clientes[0].codigo = 30;
strcpy(clientes[0].telefono, "81253437");
strcpy(clientes[0].nombre, "Mario");
clientes[0].credito = 1000;
clientes[0].membresia = 1;
strcpy(clientes[0].direccion, "Managua Americas 1");
count_c++;
  inicio();
  mver();
  menu_login();
  final();
return 0;

}


void inicio(){

	int graphic = DETECT, modo;

	clrscr();

	initgraph(&graphic, &modo, "");
	cleardevice();

}

void final(){


	getch();
	closegraph();

}


void ventana_principal(){
	int seleccion = 0;
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
	
	setfillstyle(1, LIGHTGRAY);
	header();
	mver();
	while(!kbhit()){
		if(minlimit(1, 210, 150, 410, 210) == 1){
			setcolor(LIGHTGRAY);
			boton(240, 180, 380, 38);
			if(mclick()){
				seleccion = 1;
				break;
			}
		}else if(minlimit(1, 220, 160, 400, 200) == 0){
				setcolor(WHITE);
				boton(240, 180, 380, 38);

	   	}
		if(minlimit(1, 210, 230, 410, 290) == 1){
			setcolor(LIGHTGRAY);
			boton(240, 260, 380, 38);
            		if(mclick()){
				seleccion = 2;
				break;
			}
		}else if(minlimit(1, 220, 240, 400, 300) == 0){
				setcolor(WHITE);
				boton(240, 260, 380, 38);


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

	if(seleccion == 1){
		inventario();

	}else if(seleccion == 2){
		clientes_menu();
	}
}



void inventario(){

	int seleccion = 0;
	cleardevice();
	mocultar();
	setfillstyle(1, WHITE);
	bar(0,0, 640,480);
	interfaz_inventario();
	setfillstyle(1, BLACK);
	bar(10, 80, 40, 85);
	triangulo(10, 83, 7, 3);
	floodfill(8, 83, BLACK);
	mver();
	while(!kbhit() || kbhit()){

		if(kbhit()){
			getch();

		}
		if(minlimit(1, 50, 80, 200, 230) && mclick()){
		   seleccion = 1;
		   break;

		}

		if(minlimit(1, 250, 80, 400, 230) && mclick()){
		   seleccion = 2;
		   break;

		}
		if(minlimit(1, 450, 80, 600, 230) && mclick()){
		   seleccion = 3;
		   break;

		}
		if(minlimit(1, 50, 280, 200, 430) && mclick()){
		  seleccion = 4;
		  break;
		}
		if(minlimit(1,250, 280, 400, 430) && mclick()){
		   seleccion = 5;
		   break;
		}if(minlimit(1, 450, 280, 600, 430) && mclick()){
		   seleccion = 6;
		    break;
		}
		if(minlimit(1, 3, 76, 40, 89) && mclick()){
		   seleccion = 7;
		   break;
		}



	}

	if(seleccion == 1){
		agregar();
	}else if(seleccion == 2){
		buscar();
	}else if(seleccion == 3){
		actualizar();
	}else if(seleccion == 4){
		eliminar();
	}else if(seleccion == 5){
		ver();
	}else if(seleccion == 6){
		vender();
	}else if(seleccion == 7){
		ventana_principal();
	}

}

void agregar(){

        /* Elementos del producto*/
	char nombre[MAX];
	char fecha_vencimiento[MAX];
	char unidad_medida[MAX];
	char codigo[MAX];
	char precio[MAX];
	char cantidad[MAX];
	char descripcion[MAX_DESC];
	char unidad_medida_string[MAX];
	int valido, resultado = 0;
	int codigo_entero;
	int retorno;
	int eleccion;
	int dia, mes;
	int cantidad_medida;
	char anio[MAX];
	mver();

	fflush(stdin);
	 if(mensaje_pregunta("Seguro que quieres agregar un producto?") == 1){
		inventario();
	}else{
		eleccion = 1;
	}

	mocultar();
	/*Validacion del nombre */

	if(eleccion == 1){
		do{
			campos_registro("Nombre:", "Vencimiento:", "Codigo:");
			setcolor(WHITE);
			boton(70, 125, 555, 26);
			valido = 1;
			setfillstyle(1, LIGHTGRAY);
			bar(160, 112, 320, 140);
			gotoxy(23, 8);
			fgets(nombre, sizeof(nombre), stdin);
	   		nombre[strcspn(nombre, "\n")] = '\0';
			if(nombre_valido(nombre) == 1){
				if(Error_con_retorno("Escribe un nombre valido") == 0){
				valido = 0;
				}
			}
			for(i = 0; i < count_p; i++){
				if(strcmp(nombre, medicamentos[i].nombre) == 0){

					if(Error_con_retorno("Este nombre ya esta en uso") == 0){

						valido = 0;
						break;
					}
				}
			}

		}while(valido == 0);

	/*Validacion de la fecha */


		do{
			setcolor(CYAN);
			boton(70, 125, 555, 26);
			setcolor(WHITE);
			boton(70, 195, 555, 26);
			valido = 1;
			setfillstyle(1, LIGHTGRAY);
			bar(190, 182, 320, 193);
			gotoxy(27, 13);
			resultado = scanf("%d/%d/%s", &dia, &mes, &anio);
			if(resultado != 3){
				if(Error_con_retorno("Escriba una fecha valida") == 0){
					valido = 0;
					while(getchar() != '\n');
					campos_registro("Nombre:", "Vencimiento:", "Codigo:");
					gotoxy(23, 8);
					printf("%s", nombre);
				}
			}else if(fecha_valida(dia, mes, anio) == 1){
		   	if(Error_con_retorno("Escriba una fecha valida") == 0){
				valido = 0;
		   		while(getchar() != '\n');
				campos_registro("Nombre:", "Vencimiento:", "Codigo:");	
				gotoxy(23, 8);
				printf("%s", nombre);
		   	}
	   	}
	   	sprintf(fecha_vencimiento, "%02d/%02d/%s",dia, mes,anio);
		}while(valido == 0);

		while (getchar() != '\n');

		/*Validacion del codigo*/

		do{
			valido = 1;
			setcolor(CYAN);
			boton(70, 195, 555, 26);
			setcolor(WHITE);
			boton(70, 265, 555, 26);
			setfillstyle(1, LIGHTGRAY);
			bar(170, 252, 320, 264);
			gotoxy(22, 17);

			fgets(codigo, sizeof(codigo), stdin);
			codigo[strcspn(codigo, "\n")] = '\0';

			if(numero_valido(codigo) == 1){

				if(Error_con_retorno("Ingresa una codigo valida") == 0){
					campos_registro("Nombre:", "Vencimiento:", "Codigo:");
					valido = 0;
					gotoxy(23, 8);
					printf("%s", nombre);
					gotoxy(27, 13);
					printf("%s", fecha_vencimiento);
				}
			}

			codigo_entero = atoi(codigo);

			for(i = 0; i < count_p; i++){
				if(medicamentos[i].codigo == codigo_entero){
					if(Error_con_retorno("Este codigo ya esta siendo utilizado") == 0){
						campos_registro("Nombre:", "Vencimiento:", "Codigo:");
						valido = 0;
						gotoxy(23, 8);
						printf("%s", nombre);
						gotoxy(27, 13);
						printf("%s", fecha_vencimiento);
					}
				}
			}

			if(valido == 1){
		 		if(codigo_entero > 100){
					if(Error_con_retorno("Ingresa un codigo del (1-100)") == 0){
						campos_registro("Nombre:", "Vencimiento:", "Codigo:");
						valido = 0;
						gotoxy(23, 8);
						printf("%s", nombre);
						gotoxy(27, 13);
						printf("%s", fecha_vencimiento);
					}
	   			}
			}

		}while(!valido);

			/*Validacion del la unidad de medida*/

		do{
			campos_registro("Unidad de medida(mg,ml,g):", "Precio:", "Cantidad:");
			valido = 1;
			setcolor(WHITE);
			boton(70, 125, 555, 26);
			setfillstyle(1, LIGHTGRAY);
			bar(200, 252, 320, 264);
			gotoxy(45, 8);


			resultado = scanf("%d%s", &cantidad_medida, &unidad_medida);
			if(resultado != 2){
				if(Error_con_retorno("Escriba una unidad valida") == 0){
					valido = 0;
					while(getchar() != '\n');
				}
			}else if(medida_valida(cantidad_medida, unidad_medida) == 1){

				if(Error_con_retorno("Ingresa una unidad valida") == 0){
					valido = 0;
					while(getchar() != '\n');
				}
			}


			
			sprintf(unidad_medida_string, "%d%s", cantidad_medida, unidad_medida);
		}while(!valido);
		
		while(getchar() != '\n');
		/*Validacion del precio*/

		do{
			setcolor(CYAN);
			boton(70, 125, 555, 26);
			setcolor(WHITE);
			boton(70, 195, 555, 26);
			valido = 1;
			setfillstyle(1, LIGHTGRAY);
			bar(200, 182, 320, 193);
			gotoxy(21, 13);
			fgets(precio, sizeof(precio), stdin);
			precio[strcspn(precio, "\n")] = '\0';

			if(numero_valido(precio) == 1){

				if(Error_con_retorno("Ingresa un precio valido") == 0){
					campos_registro("Unidad de medida(mg,ml,g):", "Precio:", "Cantidad:");
					valido = 0;
					gotoxy(45, 8);
					printf("%s", unidad_medida_string);
				}
			}


		}while(valido == 0);

		/*Validacion de la cantidad*/

		do{
			setcolor(CYAN);
			boton(70, 195, 555, 26);
			setcolor(WHITE);
			boton(70, 265, 555, 26);
			valido = 1;
			setfillstyle(1, LIGHTGRAY);
			bar(200, 252, 320, 264);
			gotoxy(22, 17);
			fgets(cantidad, sizeof(cantidad), stdin);
			cantidad[strcspn(cantidad, "\n")] = '\0';

			if(numero_valido(cantidad) == 1){

				if(Error_con_retorno("Ingresa una cantidad valida") == 0){
					campos_registro("Unidad de medida(mg,ml,g):", "Precio:", "Cantidad:");
					valido = 0;
					gotoxy(45, 8);
					printf("%s", unidad_medida_string);
					gotoxy(21, 13);
					printf("%s", precio);
				}
			}


		}while(valido == 0);

	/*Validacion de la descripcion*/
		mver();
		retorno = mensaje_pregunta("Quieres ingresar una descripcion al producto");
		if(retorno == 0){

			eleccion = 1;
		}else if(retorno == 1){
			eleccion = 0;
		}

		if(eleccion == 1){
			do{
				valido = 1;
		  		cleardevice();
		  		mocultar();
		  		setfillstyle(1, WHITE);
		  		bar(0, 50, 640, 480);
		  		header();
		  		setcolor(BLACK);
		  		cuadrado(40, 120, 120, 550);
		  		boton(270, 280, 380, 30);
		  		setfillstyle(1,LIGHTCYAN);
		  		floodfill(275, 252, BLACK);
				settextstyle(0, 0, 2);
		  		outtextxy(255, 275, "Finalizar");

		  		settextstyle(1, 0, 4);
		  		outtextxy(60, 70, "Descripcion de producto");

				gotoxy(10, 9);
				fgets(descripcion, sizeof(descripcion), stdin);
				descripcion[strcspn(descripcion, "\n")] = '\0';

				if(nombre_valido(descripcion) == 1){

					if(Error_con_retorno("Ingresa una descripcion valida") == 0){
						valido = 0;
					}
				}
			 	strcpy(medicamentos[count_p].descripcion, descripcion);
		  	}while(valido == 0);


		}else if(eleccion == 0){
			strcpy(medicamentos[count_p].descripcion, "Sin descripcion");
		}

		
		strcpy(medicamentos[count_p].nombre, nombre);
		strcpy(medicamentos[count_p].fecha_vencimiento, fecha_vencimiento);
		strcpy(medicamentos[count_p].unidad_medida, unidad_medida_string);
		medicamentos[count_p].codigo = codigo_entero;
		medicamentos[count_p].cantidad = atoi(cantidad);
		medicamentos[count_p].precio = atoi(precio);


		count_p++;
		agregar_fichero();
		fflush(stdin);
		mver();
		inventario();
	}
}


void buscar(){
	char busqueda[30];
	int encontrado = 0;
	int seleccion;
	if(count_p == 0){
		if(Error("No hay medicamentos disponibles") == 0){
			inventario();
		}

	}
	fflush(stdin);
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setcolor(BLACK);
	settextstyle(2, 0, 5);
	outtextxy(230, 60, "Ingresa el nombre o codigo");
	cuadrado(50,80, 370, 550);
	boton(80, 120, 560, 15);
	mver();
	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 65, 105, 575, 135) && mclick()){

		   seleccion = 1;
		   break;


	   }
	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }

	if(seleccion == 1){
		mocultar();
		   gotoxy(11, 8);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();
	}else if(seleccion == 2){
		inventario();
	}

	for(i = 0; i < count_p; i++){

		if(strcmp(busqueda, medicamentos[i].nombre) == 0 || medicamentos[i].codigo == atoi(busqueda)){

		   informacion_producto(i);
		   encontrado = 1;

		}
   	}

	if(encontrado == 0){

			if(Error_con_retorno("No existe este producto") == 0){
			buscar();
			}
	}

}

void informacion_producto(int n){

	   char nombres[60], descripcion[100], fecha_vencimiento[40],
	   unidad_medida[40], codigo[20], cantidad[20], precio[30];

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

	   sprintf(precio, "Precio del producto: $%d", medicamentos[n].precio);
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

	mver();
	if(count_p == 0){
		if(Error("No hay medicamentos disponibles") == 0){
			inventario();
		}

	}
	for(i = 0; i < count_p; i++){

		 sprintf(nombres, "%d %s", i + 1, medicamentos[i].nombre);
		 outtextxy(250, j, nombres);
		 j += 20;

	}
	
	mver();
	while(!kbhit() || kbhit()){
		if(kbhit()){
			getch();

		}

		if(mclick() && minlimit(1, 10, 5, 250, 40)){
			inventario();
			break;
		}
	}



}

void actualizar(){

	char nombres[MAX];
	char busqueda[MAX];
	int encontrado = 0;
	int seleccion;
	int y= 170;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);

	mver();
	if(count_p == 0){
		if(Error("No hay medicamentos disponibles") == 0){
			inventario();
		}

	}
	mver();
	setcolor(BLACK);
	outtextxy(150, 100, "Ingresa cual producto deseas actualizar");

	boton(110, 135, 500, 10);

	for(i=0; i < count_p; i++){
		sprintf(nombres, "%d.%s",i +1, medicamentos[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();

	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 100, 125, 510, 145) && mclick()){

		 seleccion = 1;
		break;


	   }

	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }
	if(seleccion == 1){
		   mocultar();
		   gotoxy(15, 9);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();

	}else if(seleccion == 2){
		inventario();
	}
	for(i = 0; i < count_p; i++){

		if(strcmp(busqueda, medicamentos[i].nombre) == 0 || medicamentos[i].codigo == atoi(busqueda)){
		   encontrado = 1;
	           menu_actualizar(i);

		}
   	}
	if(encontrado == 0){

			if(Error_con_retorno("No existe este producto") == 0){
			   actualizar();
			}
	}




}



void menu_actualizar(int n){

	 int j;

	 int seleccion = 0;
	 mocultar();
	 setfillstyle(1, WHITE);
	 bar(0, 50, 640, 480);

	 setfillstyle(1, BLACK);
	 bar(40, 70, 70, 75);
	 triangulo(40, 73, 7, 3);
	 floodfill(38, 73, BLACK);

	 bar(580, 70, 610, 75);
	 triangulo(610, 73, 7, 2);
	 floodfill(612, 73, BLACK);
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

	 while(!kbhit() || kbhit()){
		if(kbhit()){
			getch();

	    	}
		if(minlimit(1, 65, 155, 265, 205) && mclick()){
			seleccion = 1;
			break;
		}
		if(mclick() && minlimit(1, 65, 255, 265, 305)){
			seleccion = 2;
			break;
		}
		if(mclick() && minlimit(1,65, 355, 265, 405)){
			seleccion = 3 ;
			break;
		}
		if(mclick() && minlimit(1, 365, 155, 565, 205)){

			seleccion = 4;
			break;
		}
		if(mclick() && minlimit(1, 365, 255, 565, 305)){
			seleccion = 5;
			break;
		}
		if(mclick() && minlimit(1, 365, 355, 565, 405)){
			seleccion = 6;
			break;
		}
		if(mclick() && minlimit(1, 580, 65, 617, 78)){
			seleccion = 7;
			break;
		}
		if(mclick() && minlimit(1, 33, 66, 70, 80)){
			seleccion = 8;
			break;
		}


	}

	if(seleccion == 1){
		nombre_actualizar(n);
	}
	else if(seleccion == 2){
		codigo_actualizar(n);
	}else if(seleccion == 3){
		precio_actualizar(n);
	}else if(seleccion == 4){

		fecha_vencimiento_actualizar(n);
	}else if(seleccion == 5){
		cantidad_actualizar(n);
	}else if(seleccion == 6){
		unidad_medida_actualizar(n);
	}else if(seleccion == 7){
		descripcion_actualizar_icono(n);
	}
	else if(seleccion == 8){
		actualizar();
	}
	
	agregar_fichero();
	actualizar();

}

void nombre_actualizar(int indice){

	char nuevo_nombre[MAX];
	char antiguo_nombre[40];
	int verdad;
	int i;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_nombre, "Nombre actual:%s", medicamentos[indice].nombre);
		outtextxy(130, 110, antiguo_nombre);
		outtextxy(130, 160, "Nuevo nombre");
		gotoxy(18, 13);
		fflush(stdin);
		fgets(nuevo_nombre, sizeof(nuevo_nombre), stdin);
		nuevo_nombre[strcspn(nuevo_nombre, "\n")] = '\0';
		while(kbhit()){
			getch();
			}

		if(nombre_valido(nuevo_nombre) == 1){
			if(Error_con_retorno("Escribe un nombre valido") == 0){
				verdad = 0;
			}
		}
		for(i = 0; i < count_p; i++){
			if(strcmp(nuevo_nombre, medicamentos[i].nombre) == 0){

				if(Error_con_retorno("Este nombre ya esta en uso") == 0){

					verdad = 0;
					break;
				}
			}
		}
		mver();
	}while(verdad == 0);

	strcpy(medicamentos[indice].nombre, nuevo_nombre);

}
void codigo_actualizar(int indice){

	char nuevo_codigo[MAX];
	char antiguo_codigo[MAX];
	int codigo_entero;
	int verdad;
	int i;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_codigo, "Codigo actual:%d", medicamentos[indice].codigo);
		outtextxy(130, 110, antiguo_codigo);
		outtextxy(130, 160, "Nuevo codigo");
		gotoxy(18, 13);
		fgets(nuevo_codigo, sizeof(nuevo_codigo), stdin);
	   	nuevo_codigo[strcspn(nuevo_codigo, "\n")] = '\0';
		if(numero_valido(nuevo_codigo) == 1){
			if(Error_con_retorno("Escribe un codigo valido") == 0){
				verdad = 0;
			}
		}
		codigo_entero = atoi(nuevo_codigo);
		for(i = 0; i < count_p; i++){
			if(medicamentos[i].codigo == codigo_entero){

				if(Error_con_retorno("Este codigo ya esta en uso") == 0){

					verdad = 0;
					break;
				}
			}
		}

		if(codigo_entero > 100){
			if(Error_con_retorno("Ingresa un codigo entre (1-100)") == 0){
					verdad = 0;
			}
		}


		mver();
	}while(verdad == 0);

	medicamentos[indice].codigo = codigo_entero;

}
void precio_actualizar(int indice){

	char nuevo_precio[MAX];
	char antiguo_precio[MAX];
	int precio_entero;
	int verdad;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_precio, "Precio actual:$%d", medicamentos[indice].precio);
		outtextxy(130, 110, antiguo_precio);
		outtextxy(130, 160, "Nuevo precio");
		gotoxy(18, 13);
		fgets(nuevo_precio, sizeof(nuevo_precio), stdin);
	   	nuevo_precio[strcspn(nuevo_precio, "\n")] = '\0';
		if(numero_valido(nuevo_precio) == 1){
			if(Error_con_retorno("Escribe un precio valido") == 0){
				verdad = 0;
			}
		}
		precio_entero = atoi(nuevo_precio);

		mver();
	}while(verdad == 0);

	medicamentos[indice].precio = precio_entero;
}


void fecha_vencimiento_actualizar(int indice){

	int dia, mes;
	char anio[MAX];
	char fecha_vencimiento[MAX];
	int verdad, resultado;
	char fecha_actual[MAX];

	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		sprintf(fecha_actual, "Fecha actual:%d", medicamentos[indice].fecha_vencimiento);
		outtextxy(130, 110, fecha_actual);
		outtextxy(130, 160, "Nueva fecha de vencimiento:");
		gotoxy(18, 13);
		resultado = scanf("%d/%d/%s", &dia, &mes, &anio);
		if(resultado != 3){
			if(Error_con_retorno("Escriba una fecha valida") == 0){
				verdad = 0;
				while(getchar() != '\n');
			}
		}else if(fecha_valida(dia, mes, anio) == 1){
		   	if(Error_con_retorno("Escriba una fecha valida") == 0){
				verdad = 0;
		   		while(getchar() != '\n');
		   	}
	   	}
	   	sprintf(fecha_vencimiento, "%02d/%02d/%s",dia, mes,anio);
	}while(verdad == 0);

	while (getchar() != '\n');
	strcpy(medicamentos[indice].fecha_vencimiento, fecha_vencimiento);

}

void cantidad_actualizar(int indice){

	char nueva_cantidad[MAX];
	char antigua_cantidad[MAX];
	int cantidad_entero;
	int verdad;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antigua_cantidad, "Cantidad actual:%d", medicamentos[indice].cantidad);
		outtextxy(130, 110, antigua_cantidad);
		outtextxy(130, 160, "Nueva cantidad");
		gotoxy(18, 13);
		fgets(nueva_cantidad, sizeof(nueva_cantidad), stdin);
	   	nueva_cantidad[strcspn(nueva_cantidad, "\n")] = '\0';
		if(cantidad_valida(nueva_cantidad) == 1){
			if(Error_con_retorno("Escribe una cantidad valido") == 0){
				verdad = 0;
			}
		}
		cantidad_entero = atoi(nueva_cantidad);

		mver();
	}while(verdad == 0);

	medicamentos[indice].cantidad = cantidad_entero;


}

void unidad_medida_actualizar(int indice){

	int verdad, resultado;
	int cantidad_medida;
	char unidad_medida[MAX];
	char unidad_medida_string[MAX];
	char antigua_medida[MAX];
	do{
			verdad = 1;
			cambiar_propiedad_interfaz();
			settextstyle(0,0, 2);
			sprintf(antigua_medida, "Unidad actual:%s", medicamentos[indice].unidad_medida);
			outtextxy(130, 110, antigua_medida);
			outtextxy(130, 160, "Nueva Unidad de medida:");
			gotoxy(18, 13);
			resultado = scanf("%d%s", &cantidad_medida, &unidad_medida);
			if(resultado != 2){
				if(Error_con_retorno("Escriba una unidad valida") == 0){
					verdad = 0;
					while(getchar() != '\n');
				}
			}else if(medida_valida(cantidad_medida, unidad_medida) == 1){

				if(Error_con_retorno("Ingresa una unidad valida") == 0){
					verdad = 0;
					while(getchar() != '\n');
				}
			}
	}while(verdad == 0);

	sprintf(unidad_medida_string, "%d%s", cantidad_medida, unidad_medida);
	strcpy(medicamentos[indice].unidad_medida, unidad_medida_string);

	while(getchar() != '\n');
}

void descripcion_actualizar_icono(int indice){
	
	int seleccion = 0;

	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setfillstyle(1, BLACK);
	bar(40, 55, 70, 60);
	triangulo(40, 58, 7, 3);
	floodfill(38, 58, BLACK);	
	setfillstyle(1,BLACK);
	setcolor(BLACK);
	boton(250, 200, 350, 25);
	outtextxy(250, 190, "Descripcion");
	rectangle(225, 175, 375, 225);
	mver();
	mver();
	mver();
	while(!kbhit() || kbhit()){
		
	
		if(kbhit()){
			getch();
		}
	
	 	if(minlimit(1,32, 52, 70, 65) && mclick()){
			seleccion = 1;
			break;
		
		}
		if(minlimit(1,225, 175, 375, 225) && mclick()){
			seleccion = 2;
			break;
		}
	
	}
	
	if(seleccion == 1){
		menu_actualizar(indice);
	}else if(seleccion == 2){
		descripcion_actualizar(indice);
	}
	

}
void descripcion_actualizar(int indice){

	char descripcion[MAX_DESC];
	int valido;
	do{
		valido = 1;
		cleardevice();
		mocultar();
		setfillstyle(1, WHITE);
		bar(0, 50, 640, 480);
		header();
		setcolor(BLACK);
		cuadrado(40, 120, 120, 550);
		boton(270, 280, 380, 30);
		setfillstyle(1,LIGHTCYAN);
		floodfill(275, 252, BLACK);
		settextstyle(0, 0, 2);
		outtextxy(255, 275, "Finalizar");

		settextstyle(1, 0, 4);
		outtextxy(60, 70, "Descripcion nueva de producto");

		gotoxy(10, 9);
		fgets(descripcion, sizeof(descripcion), stdin);
		descripcion[strcspn(descripcion, "\n")] = '\0';

		if(nombre_valido(descripcion) == 1){

			if(Error_con_retorno("Ingresa una descripcion valida") == 0){
					valido = 0;
			}
		}
	}while(valido == 0);
	

	strcpy(medicamentos[indice].descripcion, descripcion);
}

void eliminar(){

	char nombres[MAX];
	int verdad;
	char num_eliminar[MAX];
	char producto_eliminar[MAX];
	char nombre_eliminar[MAX];
	int num_eliminar_entero;
	int encontrado = 0;
	int seleccion;
	int y, j;
	int i, k;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);

	mver();
	if(count_p == 0){
		if(Error("No hay medicamentos disponibles") == 0){
			inventario();
		}

	}
      do{
	y = 190;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);
	outtextxy(150, 100, "Ingresa cuantos productos deseaa eliminar ");

	boton(110, 135, 500, 10);
	outtextxy(250, 170, "Lista de productos");
	for(i=0; i < count_p; i++){
		sprintf(nombres, "%d.%s",i +1, medicamentos[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();
	mver();
	mver();

	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 100, 125, 510, 145) && mclick()){

		 seleccion = 1;
		break;


	   }

	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }
	if(seleccion == 1){
		   mocultar();
		   gotoxy(15, 9);
		   fgets(num_eliminar, sizeof(num_eliminar), stdin);
		   num_eliminar[strcspn(num_eliminar, "\n")] = '\0';
		   mver();

	}else if(seleccion == 2){
		inventario();
	}


	verdad = 1;
	if(numero_valido(num_eliminar) == 1){
				if(Error_con_retorno("Ingresa una cantidad valida") == 0){
					verdad = 0;

				}
	}
	num_eliminar_entero = atoi(num_eliminar);
	if(num_eliminar_entero > count_p){
			if(Error_con_retorno("Ingresa una cantidad valida") == 0){
				verdad = 0;

			}
	}


      }while(verdad == 0);


		verdad = 1;
		for(i = 0; i < num_eliminar_entero; i++){
			cambiar_propiedad_interfaz();
			settextstyle(0,0, 1);
			sprintf(producto_eliminar, "Ingresa el nombre del producto:%d", i+1);
			outtextxy(130, 160, producto_eliminar);
			gotoxy(18, 13);
			fgets(nombre_eliminar, sizeof(nombre_eliminar), stdin);
			nombre_eliminar[strcspn(nombre_eliminar, "\n")] = '\0';
			encontrado = 0;
			 for(j = 0; j < count_p; j++){
				if(strcmp(medicamentos[j].nombre, nombre_eliminar) == 0){
				   encontrado = 1;

				   for(k = j; k < count_p; k++){
						medicamentos[k] = medicamentos[k + 1];
					
				   }
				   count_p--;
				   agregar_fichero();
				   break;
				}

			 }
			if(!encontrado){
				if(Error_con_retorno("Este nombre no existe") == 0){
						mver();
						eliminar();
						break;
				}
			}




		}
	mver();
	inventario();


}


void vender(){

	
	char nombres[MAX];
	char busqueda[MAX];
	int encontrado = 0;
	int seleccion;
	int y= 170;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);

	mver();
	if(count_p == 0){
		if(Error("No hay medicamentos disponibles") == 0){
			inventario();
		}
	}else if(count_c == 0){
		if(Error("No hay clientes disponibles") == 0){
			inventario();
		}
	}

	mver();
	outtextxy(150, 100, "Ingresa cual producto desea vender");

	boton(110, 135, 500, 10);

	for(i=0; i < count_p; i++){
		sprintf(nombres, "%d.%s",i +1, medicamentos[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();

	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 65, 105, 575, 135) && mclick()){

		 seleccion = 1;
		break;


	   }

	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }
	if(seleccion == 1){
		   mocultar();
		   gotoxy(15, 9);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();

	}else if(seleccion == 2){
		inventario();
	}
	for(i = 0; i < count_p; i++){

		if(strcmp(busqueda, medicamentos[i].nombre) == 0 || medicamentos[i].codigo == atoi(busqueda)){
		   encontrado = 1;
	           menu_vender(i);

		}
   	}
	if(encontrado == 0){

			if(Error_con_retorno("No existe este producto") == 0){
			   vender();
			}
	}


}


void menu_vender(int indice_prod){

	
	char nombre[40], cantidad[40], codigo[40], precio[40];
	int j;
	 int seleccion = 0;
	 mocultar();
	 setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	 
	 setcolor(BLACK);
	 setfillstyle(1, BLACK);
	 bar(40, 70, 70, 75);
	 triangulo(40, 73, 7, 3);
	 floodfill(38, 73, BLACK);

	 setcolor(BLACK);
	 settextstyle(0, 0, 2);
	 cuadrado(10, 80, 380, 620);

	 bar(580, 70, 610, 75);
	 triangulo(610, 73, 7, 2);
	 floodfill(612, 73, BLACK);
	 setcolor(BLACK);


	 settextstyle(0,0,2);
	 outtextxy(200, 100, "Producto Encontrado");
	 settextstyle(1, 0, 3);
	 outtextxy(20, 130, "Informacion del producto");
	 settextstyle(0, 0, 1);


	 sprintf(nombre, "Nombre del producto: %s", medicamentos[indice_prod].nombre);
	 outtextxy(20, 180, nombre);
	 
	 sprintf(cantidad, "Cantidad de productos: %d", medicamentos[indice_prod].cantidad);
	 outtextxy(20, 220, cantidad);

	 sprintf(codigo, "Codigo del producto: %d", medicamentos[indice_prod].codigo);
	 outtextxy(20, 240, codigo);
	
	 sprintf(precio, "Precio del producto: $%d", medicamentos[indice_prod].precio);
	 outtextxy(20, 260, precio);
	mver();
	mver();
	mver();
	while(kbhit() || !kbhit()){
		if(kbhit()){
			getch();
		}
		
		if(minlimit(1, 32, 65, 70, 78) && mclick()){
			seleccion = 1;
			break;

		}
		
		if(minlimit(1, 580, 65, 617, 78) && mclick()){
			seleccion = 2;
			break;
		}
	}
	 

	if(seleccion == 1){

		vender();
	}else if (seleccion == 2){
		menu_vender_clientes(indice_prod);
	}
	


}


void menu_vender_clientes(int indice_prod){

	int seleccion;
	char busqueda[30];
	int encontrado = 0;
	fflush(stdin);
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setcolor(BLACK); 
	
	settextstyle(2, 0, 5);
	outtextxy(200, 60, "Ingresa el nombre o codigo del cliente");
	cuadrado(50,80, 370, 550);
	boton(80, 120, 560, 15);
	
	setfillstyle(1, BLACK);
	bar(40, 55, 70, 60);
	triangulo(40, 58, 7, 3);
	floodfill(38, 58, BLACK);


	mver();
	mver();
	mver();
	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 65, 105, 575, 135) && mclick()){

		   seleccion = 1;
		   break;


	   }
	   if(mclick() && minlimit(1,32, 52, 70, 65)){
			seleccion = 2;
			break;
	   }
	}

	if(seleccion == 1){
		mocultar();
		   gotoxy(11, 8);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();
	}else if(seleccion == 2){
		menu_vender(indice_prod);
	}

	for(i = 0; i < count_c; i++){

		if(strcmp(busqueda, clientes[i].nombre) == 0 || clientes[i].codigo == atoi(busqueda)){
		   encontrado = 1;
		   menu_informacion_cliente(indice_prod, i);
		}
   	}

	if(encontrado == 0){

			if(Error_con_retorno("No existe este cliente") == 0){
				menu_vender_clientes(indice_prod);
			}
	}



}


void menu_informacion_cliente(int indice_prod, int indice_cliente){

	char nombre[40], credito[40], telefono[40], direccion[80],
	membresia[40], codigo[30];
	int j;
	 int seleccion = 0;
	 mocultar();
	 setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	 setfillstyle(1, BLACK);
	 bar(40, 70, 70, 75);
	 triangulo(40, 73, 7, 3);
	 floodfill(38, 73, BLACK);

	 setcolor(BLACK);
	 settextstyle(0, 0, 2);
	 cuadrado(10, 80, 380, 620);

	 bar(580, 70, 610, 75);
	 triangulo(610, 73, 7, 2);
	 floodfill(612, 73, BLACK);
	 setcolor(BLACK);


	 settextstyle(0,0,2);
	 outtextxy(200, 100, "Cliente Encontrado");
	 settextstyle(1, 0, 3);
	 outtextxy(20, 130, "Informacion del Cliente");
	 settextstyle(0, 0, 1);


	 sprintf(nombre, "Nombre del cliente: %s", clientes[indice_cliente].nombre);
	 outtextxy(20, 180, nombre);


	 sprintf(credito, "Credito del cliente: $%d", clientes[indice_cliente].credito);
	 outtextxy(20, 200, credito);


	 sprintf(telefono, "Telefono del cliente: %s", clientes[indice_cliente].telefono);
	 outtextxy(20, 220, telefono);

	sprintf(codigo, "Codigo del cliente: %d", clientes[indice_cliente].codigo);
	outtextxy(20, 240, codigo);

	sprintf(membresia, "Estado de membresia: %s.", clientes[indice_cliente].membresia == 1 ? "Cliente con membresia" : "Cliente sin membresia");
	outtextxy(20, 260, membresia);

	 sprintf(direccion, "Direccion del cliente: %s", clientes[indice_cliente].direccion);
	 outtextxy(20, 280, direccion);
	 
	
	mver();
	mver();
	mver();
	while(kbhit() || !kbhit()){
		if(kbhit()){
			getch();
		}
		
		if(minlimit(1, 40, 70, 70, 75) && mclick()){
			seleccion = 1;
			break;

		}
		
		if(minlimit(1, 580, 70, 610, 75) && mclick()){
			seleccion = 2;
			break;
		}
	}


	if(seleccion == 1){

		menu_vender_clientes(indice_prod);
	}else if (seleccion == 2){
		menu_compra_producto(indice_prod, indice_cliente);
	}

}

void menu_compra_producto(int indice_prod, int indice_cliente){

	char cantidad_comprar[20];
	int cantidad_comprar_entero;
	char credito_final_string[50];
	char cantidad_final_string[50];
	int cantidad_final, credito_final;
	int verdad, seleccion, descuento, precio_pagar, precio_membresia;
	int valido;
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(2,0, 5);
		outtextxy(130, 160, "Cantidad productos a comprar: ");
		gotoxy(18, 13);
		fgets(cantidad_comprar, sizeof(cantidad_comprar), stdin);
	   	cantidad_comprar[strcspn(cantidad_comprar, "\n")] = '\0';
		if(numero_valido(cantidad_comprar) == 1){
			if(Error_con_retorno("Escribe una cantidad valida") == 0){
				menu_informacion_cliente(indice_prod, indice_cliente);
				verdad = 0;
				
			}
		}
		cantidad_comprar_entero = atoi(cantidad_comprar);
		if(cantidad_comprar_entero > medicamentos[indice_prod].cantidad){
			if(Error_con_retorno("La cantidad sobrepasa el inventario") == 0){
				menu_informacion_cliente(indice_prod, indice_cliente);
				verdad = 0;
				
			}
		}

		mver();
	}while(verdad == 0);
	precio_pagar = medicamentos[indice_prod].precio * cantidad_comprar_entero;
	if( cantidad_comprar_entero > 10 && clientes[indice_cliente].membresia == 1){
		outtextxy(100, 300, "Este cliente posee membresia y se le hara un descuento del 10%");
		outtextxy(200, 320, "Presione Enter");
		descuento = precio_pagar * 0.10;
		getch();
		if(clientes[indice_cliente].credito < (precio_pagar + descuento)){
			if(Error_con_retorno("El cliente tiene credito insuficiente") == 0){
				menu_informacion_cliente(indice_prod, indice_cliente);
			}
		}else if(clientes[indice_cliente].credito > (precio_pagar + descuento)){
			credito_final = clientes[indice_cliente].credito - precio_pagar + descuento;
			cantidad_final = medicamentos[indice_prod].cantidad - cantidad_comprar_entero;
		}

	}else if(cantidad_comprar_entero < 10 && clientes[indice_cliente].membresia == 1){
		outtextxy(10, 300, "Este cliente posee membresia pero necesita comprar mas de 10 productos para aplicarse");
		outtextxy(200, 320, "Presione Enter");
		getch();
		if(mensaje_pregunta("Quieres volver a ingresar una cantidad mayor?") == 1){
			if(clientes[indice_cliente].credito < precio_pagar){
				if(Error_con_retorno("El cliente tiene credito insuficiente") == 0){
					menu_informacion_cliente(indice_prod, indice_cliente);
				}
			}else{
				credito_final = clientes[indice_cliente].credito - precio_pagar;
				cantidad_final = medicamentos[indice_prod].cantidad - cantidad_comprar_entero;
			}
		}else{
			menu_informacion_cliente(indice_prod, indice_cliente);
		}
	}else if(clientes[indice_cliente].membresia == 0){
		outtextxy(100, 300, "Este cliente no posee membresia");
		outtextxy(200, 320, "Presione Enter");
		getch();
		if(clientes[indice_cliente].credito < precio_pagar){
			if(Error_con_retorno("El cliente tiene credito insuficiente") == 0){
				menu_informacion_cliente(indice_prod, indice_cliente);
			}
		}else{
			credito_final = clientes[indice_cliente].credito - precio_pagar;
			cantidad_final = medicamentos[indice_prod].cantidad - cantidad_comprar_entero;
		}
	}

	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	sprintf(credito_final_string, "El credito final del cliente es: $%d", credito_final);
	sprintf(cantidad_final_string, "La cantidad final de productos es: %d", cantidad_final);
	settextstyle(2, 0, 4);
	outtextxy(100, 100, credito_final_string);
	outtextxy(100, 130, cantidad_final_string);
	outtextxy(100, 160, "Presione enter para terminar");
	getch();
	clientes[indice_cliente].credito = credito_final;
	medicamentos[indice_prod].cantidad = cantidad_final;
	registro++;
	agregar_fichero_registro(medicamentos[indice_prod].nombre, clientes[indice_cliente].nombre, credito_final, medicamentos[indice_prod].precio, cantidad_comprar_entero);
	inventario();
	
	
}


void cambiar_propiedad_interfaz(){

	cleardevice();
	header();
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	setcolor(BLACK);
	cuadrado(100, 150, 100, 400);
	settextstyle(2, 0, 6);

	setfillstyle(1, LIGHTGRAY);
	bar(130, 185, 480, 230);

}





void clientes_menu(){

	int seleccion = 0;
	cleardevice();
	mocultar();
	setfillstyle(1, WHITE);
	bar(0,0, 640,480);
	interfaz_clientes();
	setfillstyle(1, BLACK);
	rectangle(3, 76, 40, 89);
	bar(10, 80, 40, 85);
	triangulo(10, 83, 7, 3);
	floodfill(8, 83, BLACK);
	setfillstyle(1, WHITE);
	mver();
	mver();
	mver();
	while(!kbhit() || kbhit()){

		if(kbhit()){
			getch();

		}
		if(minlimit(1, 50, 80, 200, 230) && mclick()){
		   seleccion = 1;
		   break;

		}

		if(minlimit(1, 250, 80, 400, 230) && mclick()){
		   seleccion = 2;
		   break;

		}
		if(minlimit(1, 450, 80, 600, 230) && mclick()){
		   seleccion = 3;
		   break;

		}
		if(minlimit(1, 50, 280, 200, 430) && mclick()){
		  seleccion = 4;
		  break;
		}
		if(minlimit(1,250, 280, 400, 430) && mclick()){
		   seleccion = 5;
		   break;
		}
		if(minlimit(1, 3, 76, 40, 89) && mclick()){
		   seleccion = 6;
		   break;
		
		}
			


	}

	if(seleccion == 1){
		registrar_clientes();
	}else if(seleccion == 2){
		buscar_clientes();
	}else if(seleccion == 3){
		actualizar_clientes();
	}else if(seleccion == 4){
		eliminar_clientes();
	}else if(seleccion == 5){
		ver_clientes();
	}else if(seleccion == 6){
		ventana_principal();
	}



}

void registrar_clientes(){


        /* Elementos del producto*/
	char nombre[MAX];
	char telefono[MAX];
	char credito[MAX];
	char unidad_medida[MAX];
	char codigo[MAX];
	int retorno;
	char precio[MAX];
	char cantidad[MAX];
	char direccion[MAX_DESC];
	char unidad_medida_string[MAX];
	int valido, resultado = 0;
	int codigo_entero;
	int seleccion = 1;
	int eleccion;
	mver();

	fflush(stdin);
	 if(mensaje_pregunta("Seguro que quieres registrar un Cliente?") == 1){
		clientes_menu();
	}else{
	}

	mocultar();
	/*Validacion del nombre */


	do{
		valido = 1;
		campos_registro("Nombre:", "Telefono:", "Codigo:");
		setcolor(WHITE);
		boton(70, 125, 555, 26);
		gotoxy(23, 8);
		fgets(nombre, sizeof(nombre), stdin);
	   	nombre[strcspn(nombre, "\n")] = '\0';
		if(nombre_valido(nombre) == 1){
			if(Error_con_retorno("Escribe un nombre valido") == 0){
				valido = 0;
			}
		}
		for(i = 0; i < count_c; i++){
			if(strcmp(nombre, clientes[i].nombre) == 0){

				if(Error_con_retorno("Este nombre ya esta en uso") == 0){

					valido = 0;
					break;
				}
			}
		}

	}while(valido == 0);

	/*Validacion del numero de telefono */


	do{
		valido = 1;
		setcolor(CYAN);
		boton(70, 125, 555, 26);
		setcolor(WHITE);
		boton(70, 195, 555, 26);
		gotoxy(25, 13);
		fgets(telefono, sizeof(telefono), stdin);
	   	telefono[strcspn(telefono, "\n")] = '\0';

		if(telefono_valido(telefono) == 1){
			if(Error_con_retorno("Ingresa un numero de telefono valido") == 0){
				campos_registro("Nombre:", "Telefono:", "Codigo:");
				gotoxy(23, 8);
				printf("%s", nombre);
				valido = 0;
			}
		}
		for(i = 0; i < count_c; i++){
			if(strcmp(telefono, clientes[i].telefono) == 0){

				if(Error_con_retorno("Un cliente ya tiene este numero") == 0){
					campos_registro("Nombre:", "Telefono:", "Codigo:");
					gotoxy(23, 8);
					printf("%s", nombre);
					valido = 0;
					break;
				}
			}
		}
	}while(valido == 0);
	   /*Validacion del codigo*/
	do{


		valido = 1;
		setcolor(CYAN);
		boton(70, 195, 555, 26);
		setcolor(WHITE);
		boton(70, 265, 555, 26);
		gotoxy(22, 17);

		fgets(codigo, sizeof(codigo), stdin);
		codigo[strcspn(codigo, "\n")] = '\0';

		if(numero_valido(codigo) == 1){

			if(Error_con_retorno("Ingresa una codigo valido") == 0){
				campos_registro("Nombre:", "Telefono:", "Codigo:");
				valido = 0;
				gotoxy(23, 8);
				printf("%s", nombre);
				gotoxy(25, 13);
				printf("%s", telefono);
			}
		}

		for(i = 0; i < count_c; i++){
			if(clientes[i].codigo == atoi(codigo)){
				if(Error_con_retorno("Este codigo ya esta siendo utilizado") == 0){
					campos_registro("Nombre:", "Telefono:", "Codigo:");
					valido = 0;
					gotoxy(23, 8);
					printf("%s", nombre);
					gotoxy(25, 13);
					printf("%s", telefono);
				}
			}
		}

		if(valido == 1){
		 	if(atoi(codigo) > 100){
				if(Error_con_retorno("Ingresa un codigo del (1-100)") == 0){
					campos_registro("Nombre:", "Telefono:", "Codigo:");
					valido = 0;
					gotoxy(23, 8);
					printf("%s", nombre);
					gotoxy(25, 13);
					printf("%s", telefono);
				}
	   		}
		}
	}while(valido == 0);


	do{
		valido = 1;
		campos_registro2("Credito:");
		setcolor(WHITE);
		boton(70, 195, 555, 26);
		gotoxy(22, 13);

		fgets(credito, sizeof(credito), stdin);
		credito[strcspn(credito, "\n")] = '\0';

		if(numero_valido(credito) == 1){

			if(Error_con_retorno("Ingresa un credito valido") == 0){
				campos_registro2("Credito:");
				valido = 0;
			}
		}

	}while(valido == 0);

	do{
		valido = 1;
		cleardevice();
		mocultar();
		setfillstyle(1, WHITE);
		bar(0, 50, 640, 480);
		header();
		setcolor(BLACK);
		cuadrado(40, 120, 120, 550);
		boton(270, 280, 380, 30);
		setfillstyle(1,LIGHTCYAN);
		floodfill(275, 252, BLACK);
		settextstyle(0, 0, 2);
		outtextxy(260, 275, "Seguir");

		settextstyle(1, 0, 4);
		outtextxy(60, 70, "Direccion del cliente");

		gotoxy(10, 9);
		fgets(direccion, sizeof(direccion), stdin);
		direccion[strcspn(direccion, "\n")] = '\0';

	}while(valido == 0);

	
	clientes[count_c].membresia = 0;
	strcpy(clientes[count_c].nombre, nombre);
	strcpy(clientes[count_c].telefono, telefono);
	strcpy(clientes[count_c].direccion, direccion);
	clientes[count_c].credito = atoi(credito);
	clientes[count_c].codigo = atoi(codigo);
	count_c++;
	agregar_fichero_cliente();
	clientes_menu();
}

void buscar_clientes(){

	int seleccion;
	char busqueda[30];
	int encontrado = 0;
	if(count_c == 0){
		if(Error("No hay Clientes registrados") == 0){
			clientes_menu();
		}

	}
	fflush(stdin);
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setcolor(BLACK);
	settextstyle(2, 0, 7);
	cuadrado(50,80, 370, 550);
	boton(80, 120, 560, 15);
	mver();
	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 65, 105, 575, 135) && mclick()){

		   seleccion = 1;
		   break;


	   }
	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }

	if(seleccion == 1){
		mocultar();
		   gotoxy(11, 8);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();
	}else if(seleccion == 2){
		clientes_menu();
	}

	for(i = 0; i < count_c; i++){

		if(strcmp(busqueda, clientes[i].nombre) == 0 || clientes[i].codigo == atoi(busqueda)){

		   informacion_cliente(i);
		   encontrado = 1;
		   break;

		}
   	}

	if(encontrado == 0){

			if(Error_con_retorno("No existe este cliente") == 0){
				buscar_clientes();
			}
	}





};



void informacion_cliente(int indice){

   	   char nombre[50], codigo[50], telefono[50],
	   membresia[50], credito[50], direccion[100]; 

	   settextstyle(2, 0, 4);
	   setcolor(BLACK);
	   cuadrado(80, 170, 250, 490);

	   sprintf(nombre, "Nombre: %s",  clientes[indice].nombre);
	   outtextxy(100, 200, nombre);

	   sprintf(codigo, "Codigo: %d", clientes[indice].codigo);
	   outtextxy(100, 220, codigo);

	   sprintf(telefono, "Telefono: %s", clientes[indice].telefono);
	   outtextxy(100, 240, telefono);

	   sprintf(membresia, "Membresia: %s", (clientes[indice].membresia == 1) ? "Cliente con membresia" : "Cliente sin membresia");
	   outtextxy(100, 260, membresia);

	   sprintf(credito, "Credito: $%d", clientes[indice].credito);
	   outtextxy(100, 280, credito);

	   sprintf(direccion, "Direccion del cliente: %s", clientes[indice].direccion);
	   outtextxy(100, 300, direccion);


	getch();
	buscar_clientes();
	


}
void actualizar_clientes(){


	char nombres[MAX];
	char busqueda[MAX];
	int encontrado = 0;
	int seleccion;
	int y= 170;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);

	mver();
	if(count_c == 0){
		if(Error("No hay Clientes disponibles") == 0){
			clientes_menu();
		}

	}
	mver();
	outtextxy(150, 100, "Ingresa cual cliente deseas actualizar");

	boton(110, 135, 500, 10);

	for(i=0; i < count_c; i++){
		sprintf(nombres, "%d.%s",i +1, clientes[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();

	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 100, 125, 510, 145) && mclick()){

		 seleccion = 1;
		break;


	   }

	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }
	if(seleccion == 1){
		   mocultar();
		   gotoxy(15, 9);
		   fgets(busqueda, sizeof(busqueda), stdin);
		   busqueda[strcspn(busqueda, "\n")] = '\0';
		   mver();

	}else if(seleccion == 2){
		clientes_menu();
	}
	for(i = 0; i < count_c; i++){

		if(strcmp(busqueda, clientes[i].nombre) == 0 || clientes[i].codigo == atoi(busqueda)){
		   encontrado = 1;
	           menu_actualizar_clientes(i);
		   break;

		}
   	}
	if(encontrado == 0){

			if(Error_con_retorno("No existe este Cliente") == 0){
			   actualizar_clientes();
			}
	}

}

void menu_actualizar_clientes(int indice){

	 int j;

	 int seleccion = 0;
	 mocultar();
	 setfillstyle(1, WHITE);
	 bar(0, 50, 640, 480);

	 setfillstyle(1, BLACK);
	 bar(40, 70, 70, 75);
	 triangulo(40, 73, 7, 3);
	 floodfill(38, 73, BLACK);
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
	 outtextxy(130, 370, "Credito");
	 outtextxy(420, 170, "Direccion");
	 outtextxy(430, 270, "Membresia");
	 outtextxy(430, 370, "Telefono");
	 mver();

	 while(!kbhit() || kbhit()){
		if(kbhit()){
			getch();

	    	}
		if(minlimit(1, 65, 155, 265, 205) && mclick()){
			seleccion = 1;
			break;
		}
		if(mclick() && minlimit(1, 65, 255, 265, 305)){
			seleccion = 2;
			break;
		}
		if(mclick() && minlimit(1,65, 355, 265, 405)){
			seleccion = 3 ;
			break;
		}
		if(mclick() && minlimit(1, 365, 155, 565, 205)){

			seleccion = 4;
			break;
		}
		if(mclick() && minlimit(1, 365, 255, 565, 305)){
			seleccion = 5;
			break;
		}
		if(mclick() && minlimit(1, 365, 355, 565, 405)){
			seleccion = 6;
			break;
		}
		if(mclick() && minlimit(1, 33, 66, 70, 80)){
			seleccion = 7;
			break;
		}


	}

	if(seleccion == 1){
		nombre_actualizar_cliente(indice);
	}
	else if(seleccion == 2){
		codigo_actualizar_cliente(indice);
	}else if(seleccion == 3){
		credito_actualizar_cliente(indice);
	}else if(seleccion == 4){
		direccion_actualizar_cliente(indice);
	}else if(seleccion == 5){
		membresia_actualizar_cliente(indice);
	}else if(seleccion == 6){
		telefono_actualizar_cliente(indice);
	}else if(seleccion == 7){
	      actualizar_clientes();
	}
	mver();
	agregar_fichero_cliente();
	actualizar_clientes();


}

void nombre_actualizar_cliente(indice){

	char nuevo_nombre[MAX];

	char antiguo_nombre[50];
	int verdad;
	int i;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_nombre, "Nombre actual:%s", clientes[indice].nombre);
		outtextxy(130, 110, antiguo_nombre);
		outtextxy(130, 160, "Nuevo nombre");
		gotoxy(18, 13);
		fflush(stdin);
		fgets(nuevo_nombre, sizeof(nuevo_nombre), stdin);
		nuevo_nombre[strcspn(nuevo_nombre, "\n")] = '\0';
		while(kbhit()){
			getch();
			}

		if(nombre_valido(nuevo_nombre) == 1){
			if(Error_con_retorno("Escribe un nombre valido") == 0){
				verdad = 0;
			}
		}
		for(i = 0; i < count_c; i++){
			if(strcmp(nuevo_nombre, clientes[i].nombre) == 0){

				if(Error_con_retorno("Este nombre ya esta en uso") == 0){

					verdad = 0;
					break;
				}
			}
		}
		mver();
	}while(verdad == 0);

	strcpy(clientes[indice].nombre, nuevo_nombre);
	mver();

}

void codigo_actualizar_cliente(int indice){

	char nuevo_codigo[MAX];
	char antiguo_codigo[MAX];
	int codigo_entero;
	int verdad;
	int i;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_codigo, "Codigo actual:%d", clientes[indice].codigo);
		outtextxy(130, 110, antiguo_codigo);
		outtextxy(130, 160, "Nuevo codigo");
		gotoxy(18, 13);
		fgets(nuevo_codigo, sizeof(nuevo_codigo), stdin);
	   	nuevo_codigo[strcspn(nuevo_codigo, "\n")] = '\0';
		if(numero_valido(nuevo_codigo) == 1){
			if(Error_con_retorno("Escribe un codigo valido") == 0){
				verdad = 0;
			}
		}
		codigo_entero = atoi(nuevo_codigo);
		for(i = 0; i < count_c; i++){
			if(clientes[i].codigo == codigo_entero){

				if(Error_con_retorno("Este codigo ya esta en uso") == 0){

					verdad = 0;
					break;
				}
			}
		}

		if(codigo_entero > 100){
			if(Error_con_retorno("Ingresa un codigo entre (1-100)") == 0){
					verdad = 0;
			}
		}


		mver();
	}while(verdad == 0);

	clientes[indice].codigo = codigo_entero;
	mver();
}

void credito_actualizar_cliente(int indice){

	char nuevo_credito[MAX];
	char antiguo_credito[MAX];
	int verdad;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antiguo_credito, "Credito actual:%d", clientes[indice].credito);
		outtextxy(130, 110, antiguo_credito);
		outtextxy(130, 160, "Nuevo Credito");
		gotoxy(18, 13);
		fgets(nuevo_credito, sizeof(nuevo_credito), stdin);
	   	nuevo_credito[strcspn(nuevo_credito, "\n")] = '\0';
		if(cantidad_valida(nuevo_credito) == 1){
			if(Error_con_retorno("Escribe una cantidad valido") == 0){
				verdad = 0;
			}
		}

		mver();
	}while(verdad == 0);

	clientes[indice].credito = atoi(nuevo_credito);
	mver();

};

void direccion_actualizar_cliente(int indice){

	char nueva_descripcion[MAX_DESC];
	char antigua_descripcion[100];
	int verdad;
	int i;
	mocultar();
	do{
		verdad = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(antigua_descripcion, "Descripcion actual:%s", clientes[indice].descripcion);
		outtextxy(130, 110, antigua_descripcion);
		outtextxy(130, 160, "Nueva descripcion");
		gotoxy(18, 13);
		fflush(stdin);
		fgets(nueva_descripcion, sizeof(nueva_descripcion), stdin);
		nueva_descripcion[strcspn(nueva_descripcion, "\n")] = '\0';
		while(kbhit()){
			getch();

		}
	}while(verdad == 0);

	strcpy(clientes[indice].descripcion, nueva_descripcion);
	mver();

}

void membresia_actualizar_cliente(int indice){

	int retorno, eleccion;

	cleardevice();
	mver();
	settextstyle(0, 0, 2);

	if(clientes[indice].membresia == 1){
		outtextxy(200,250, "Este cliente posee membresia");
		retorno = mensaje_pregunta("Quieres quitarle la membresia a este cliente?");

		if(retorno == 0){
			clientes[indice].membresia = 0;
		}else if(retorno == 1){
			actualizar_clientes();
		}

	}else if(clientes[indice].membresia == 0){
		outtextxy(200,250, "Este cliente no posee membresia");
		retorno = mensaje_pregunta("Quieres agregarle una membresia a este cliente?(Precio $500)");

		if(retorno == 0){
			if(clientes[indice].credito < 500){
				if(Error_con_retorno("No posee suficiente credito") == 0){
					menu_actualizar_clientes(indice);
				}
			}else{
			clientes[indice].credito = clientes[indice].credito - 500;
			clientes[indice].membresia = 1;
			}
		}else if(retorno == 1){
			actualizar_clientes();
		}
	}


}

void telefono_actualizar_cliente(int indice){

	int valido;
	char telefono[MAX];
	char telefono_actual[40];

	do{
		valido = 1;
		cambiar_propiedad_interfaz();
		settextstyle(0,0, 2);
		sprintf(telefono_actual, "Nombre actual:%s", clientes[indice].telefono);
		outtextxy(130, 110, telefono_actual);
		outtextxy(130, 160, "Nuevo telefono");
		gotoxy(18, 13);
		fflush(stdin);
		fgets(telefono, sizeof(telefono), stdin);
		telefono[strcspn(telefono, "\n")] = '\0';
		while(kbhit()){
			getch();


		}
		if(telefono_valido(telefono) == 1){
			if(Error_con_retorno("Ingresa un numero de telefono valido") == 0){
				valido = 0;
			}
		}
		for(i = 0; i < count_c; i++){
			if(strcmp(telefono, clientes[i].telefono) == 0){

				if(Error_con_retorno("Un cliente ya tiene este numero") == 0){
					valido = 0;
					break;
				}
			}
		}
	}while(valido == 0);

	strcpy(clientes[indice].telefono, telefono);
	mver();
}

void ver_clientes(){

	int seleccion;
	char nombres[40];
	j = 170;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);

	settextstyle(0, 0, 2);
	setcolor(BLACK);
	outtextxy(180, 90, "Lista de Clientes");

	cuadrado(50, 120, 350, 550);
	settextstyle(2, 0, 6);

	mver();
	if(count_c == 0){
		if(Error("No hay clientes registrados") == 0){
			clientes_menu();
		}

	}
	for(i = 0; i < count_c; i++){

		 sprintf(nombres, "%d %s", i + 1, clientes[i].nombre);
		 outtextxy(250, j, nombres);
		 j += 20;

	}
	
	mver();
	while(!kbhit() || kbhit()){
		if(kbhit()){
			getch();

		}

		if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 1;
			break;
		}
	}

	if(seleccion == 1){
		clientes_menu();
	}
}
void eliminar_clientes(){

	char nombres[MAX];
	int verdad;
	char num_eliminar[MAX];
	char cliente_eliminar[MAX];
	char nombre_eliminar[MAX];
	int num_eliminar_entero;
	int encontrado = 0;
	int seleccion;
	int y, j;
	int i, k;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);

	mver();
	if(count_c == 0){
		if(Error("No hay clientes disponibles") == 0){
			clientes_menu();
		}

	}
      do{
	y = 190;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	settextstyle(0, 0, 1);
	setcolor(BLACK);
	outtextxy(150, 100, "Ingresa cuantos Clientes deseaa eliminar ");

	boton(110, 135, 500, 10);
	outtextxy(250, 170, "Lista de Clientes");
	for(i=0; i < count_c; i++){
		sprintf(nombres, "%d.%s",i +1, clientes[i].nombre);
		outtextxy(250, y, nombres);
		y+=20;

	}
	mver();
	mver();
	mver();

	while(!kbhit() || kbhit()){
	    if(kbhit()){
			getch();

	    }

	   if(minlimit(1, 100, 125, 510, 145) && mclick()){

		 seleccion = 1;
		break;


	   }

	   if(mclick() && minlimit(1, 10, 5, 250, 40)){
			seleccion = 2;
			break;
		}
	 }
	if(seleccion == 1){
		   mocultar();
		   gotoxy(15, 9);
		   fgets(num_eliminar, sizeof(num_eliminar), stdin);
		   num_eliminar[strcspn(num_eliminar, "\n")] = '\0';
		   mver();

	}else if(seleccion == 2){
		clientes_menu();
	}


	verdad = 1;
	if(numero_valido(num_eliminar) == 1){
				if(Error_con_retorno("Ingresa una cantidad valida") == 0){
					verdad = 0;

				}
	}
	num_eliminar_entero = atoi(num_eliminar);
	if(num_eliminar_entero > count_c){
			if(Error_con_retorno("Ingresa una cantidad valida") == 0){
				verdad = 0;

			}
	}


      }while(verdad == 0);


		verdad = 1;
		for(i = 0; i < num_eliminar_entero; i++){
			cambiar_propiedad_interfaz();
			settextstyle(0,0, 1);
			sprintf(cliente_eliminar, "Ingresa el nombre del producto:%d", i+1);
			
			outtextxy(130, 160, cliente_eliminar);
			gotoxy(18, 13);
			fgets(nombre_eliminar, sizeof(nombre_eliminar), stdin);
			nombre_eliminar[strcspn(nombre_eliminar, "\n")] = '\0';
			encontrado = 0;
			 for(j = 0; j < count_c; j++){
				if(strcmp(clientes[j].nombre, nombre_eliminar) == 0){
				   encontrado = 1;

				   for(k = j; k < count_c; k++){
						clientes[k] = clientes[k + 1];
					
				   }
				   count_c--;
				   agregar_fichero_cliente();
				   break;
				}

			 }
			if(!encontrado){
				if(Error_con_retorno("Este nombre no existe") == 0){
						mver();
						eliminar_clientes();
						break;
				}
			}




		}

	mver();
	clientes_menu();
};


void menu_login(){
	char caracter;
	int i = 0;
	mocultar();
	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	cuadrado(10, 50, 500, 400);
	interfaz_menu_login();
	mver();
	setcolor(LIGHTGRAY);
	settextstyle(0,0,2);
	outtextxy(210, 165, "Usuario");
	gotoxy(25, 11);
	fgets(usuario, sizeof(usuario), stdin);
	usuario[strcspn(usuario, "\n")] = '\0';


	mocultar();
	setcolor(LIGHTGRAY);
	settextstyle(0, 0, 2);
	outtextxy(210, 245, "Contrasena");
	gotoxy(25, 16);
	while(1){
          	caracter=getch();
          	if(caracter==13){
			contrasena[i]='\0';
            		break;
          	}else if(caracter==8){
            		if(i>0){
             			i--;
             			printf("\b \b");
			}
	 		}else{
            			if(i<MAX){
            				printf("*");
							contrasena[i]=caracter;
            				i++;
                		}
			}
	}

	contrasena[strcspn(contrasena, "\n")] = '\0';
	mver();
	if(getch() == 13){
		comprobacion(intentos, usuario, contrasena, menu_login, ventana_principal);
	}else{
		mver();
		 ventana_principal();
	}

}

void agregar_fichero(){

	int i;
	 FILE *file = fopen("C:\\TC20\\archivos\\medicamentos.TXT", "w");
    	if (file == NULL) {
        	printf("Error al abrir el fichero.\n");
		}

	if(count_p == 0){
		fprintf(file, "No hay medicamentos disponibles");

	}
	for(i = 0; i < count_p; i++){
		fprintf(file, "Nombre del producto: %s\nUnidad de medida del producto: %s\nFecha de vencimiento del producto: %s\nCodigo del producto: %d\nCantidad de producto: %d\nPrecio del producto: $%d\nDescripcion del producto: %s\n", medicamentos[i].nombre, medicamentos[i].unidad_medida,medicamentos[i].fecha_vencimiento, medicamentos[i].codigo, medicamentos[i].cantidad, medicamentos[i].precio,medicamentos[i].descripcion);
	}
		fclose(file);

}


void agregar_fichero_cliente(){

	int i;
	 FILE *file = fopen("C:\\TC20\\archivos\\Clientes.TXT", "w");
    	if (file == NULL) {
        	printf("Error al abrir el fichero.\n");
		}

	if(count_c == 0){
		fprintf(file, "No hay clientes registrados");

	}
	for(i = 0; i < count_c; i++){
		fprintf(file, "Nombre del Cliente: %s\nCredito: %d\nTelefono: %s\nMembresia: %d\nCodigo: %d\nDireccion del cliente:%s\n\n", clientes[i].nombre, clientes[i].credito, clientes[i].telefono,clientes[i].membresia, clientes[i].codigo, clientes[i].direccion);
	}
        fclose(file);

}

void agregar_fichero_registro(char nombre_cliente[], char nombre_producto[], int credito_final, int precio_producto, int cant_vendida){

	int i;
	 FILE *file = fopen("C:\\TC20\\archivos\\registro.TXT", "a");
    	if (file == NULL) {
        	printf("Error al abrir el fichero.\n");
		}

	if(registro == 0){
		fprintf(file, "No hay registros");

	}
	
	fprintf(file,"Nombre del producto: %s  | Precio del producto: %d | Cantidad vendida: %d | Vendido a: %s | Credito final del cliente: %d\n", nombre_cliente, precio_producto, cant_vendida, nombre_producto, credito_final);
        fclose(file);

}

