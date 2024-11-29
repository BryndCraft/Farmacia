#include <graphics.h>
#include <mouse.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

void boton(int x, int y, int tamano, int largo);
void triangulo(int x, int y, int centro, int orientacion);
void cuadrado(int x, int y, int alto, int ancho);
void cruz(int x, int y, int altura, int ancho);
int mensaje_pregunta(char mensaje[]);
int Error(char mensaje[]);
void campos_registro2( char opcion[]);
void campos_registro( char opcion1[], char opcion2[], char opcion3[]);
void interfaz_clientes(void);
void interfaz_inventario(void);
int Error_con_retorno(char mensaje[]);
void header(void);
void interfaz_menu_login(void);
void pantalla_error(int intentos, char usuario[]);
void comprobacion(int *intentos, char usuario[], char contrasena[], void (*funcion)(),  void (*funcion2)());

void boton(x, y, largo, tamano){

	arc(x, y, 90, 270, tamano);
	line(x, y - tamano, largo, y-tamano);
	line(x, y + tamano, largo, y + tamano);
	arc(largo, y, 270, 90, tamano );

}


void triangulo(x, y, centro, orientacion){


	if(orientacion == 1){
		line(x, y, centro + x, y );
		line(x, y, x - centro , y);

		line(centro + x, y, x, y -centro );
		line(x - centro, y, x , y - centro);
	}else if(orientacion  == 2){

		line(x, y, x, centro + y);
		line(x, y, x, y - centro);

		line(x, centro + y, x + centro, y);
		line(x , y - centro, x + centro, y);

	}else if( orientacion == 3){

		line(x, y, x, centro + y);
		line(x, y, x, y - centro);

		line(x, centro + y, x - centro, y);
		line(x , y - centro, x - centro, y);

	}else if(orientacion == 4){

        line(x, y, centro + x, y );
		line(x, y, x - centro , y);

		line(centro + x, y, x, y +centro );
		line(x - centro, y, x , y + centro);
	}



}

void cuadrado(x, y, alto, ancho){

    int radio = 20;


    arc(x + radio, y + radio, 80, 194, radio);


    line(x + radio, y, x + ancho - radio, y);


    arc(x + ancho - radio, y + radio, 349, 100, radio);


    line(x, y + radio, x, y + alto - radio + 4);


    arc(x + radio, y + alto - radio, 194, 280, radio);


   line(x + radio, y + alto, x + ancho - radio, y + alto);


    line(x + ancho, y + radio, x + ancho, y + alto - radio + 4);


    arc(x + ancho - radio, y + alto - radio, 260, 346, radio);

}



void cruz(x, y, altura, anchura){

    int barraHorizontalAlto = altura / 4;
    int barraVerticalAncho = anchura / 4;


    bar(x - (anchura / 2), y - (barraHorizontalAlto / 2), x + (anchura / 2), y + (barraHorizontalAlto / 2));


    bar(x - (barraVerticalAncho / 2), y - (altura / 2), x + (barraVerticalAncho / 2), y + (altura / 2));





}



int Error(char mensaje[]){

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
	settextstyle(0,0,2);
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
	while(!kbhit() || kbhit()){

	  if(kbhit()){
			getch();

	  }	
	  if(minlimit(1, 340, 220, 420, 260) && mclick()){

		return 0;

	  }

	}
	
	return 1;

}

int mensaje_pregunta(char mensaje[]){

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
	outtextxy(150, 140, mensaje);

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

	while(!kbhit() || kbhit()){
		if(kbhit()){
			getch();

		}


		if(minlimit(1, 150, 180, 240, 220) && mclick()){

		   return 0;
		}

		if(minlimit(1, 340, 180, 430, 220) && mclick()){
			return 1;

		}

	}
	return 1;
}



void campos_registro( char opcion1[], char opcion2[], char opcion3[]){

	int j;
	cleardevice();
	setfillstyle(1, WHITE);
	bar(0, 0, 640, 480);
	header();
	setcolor(BLACK);
	cuadrado(40, 90, 350, 560);
	setfillstyle(1, CYAN);
	floodfill(100, 200, BLACK);

	settextstyle(1, 0, 1);
	setfillstyle(1, LIGHTGRAY);
	for(j = 123; j < 320; j += 70){
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


}

void campos_registro2( char opcion[]){

	cleardevice();
	setfillstyle(1, WHITE);
	bar(0, 50, 640, 480);
	setcolor(BLACK);
	cuadrado(40, 90, 350, 560);
	header();
	setfillstyle(1, CYAN);
	floodfill(100, 200, BLACK);

	settextstyle(1, 0, 1);
	setfillstyle(1, LIGHTGRAY);
	setcolor(BLACK);
	boton(80, 193, 540, 20);
	floodfill(100, 193 , BLACK);
	
	outtextxy(80, 185, opcion);


	setcolor(LIGHTCYAN);
	boton(250, 350, 400, 40);
	setfillstyle(1, LIGHTCYAN);
	floodfill(250, 350, LIGHTCYAN);

	setcolor(BLACK);
	settextstyle(0, 0 , 2);
	outtextxy(275, 340, "Seguir");


}
void interfaz_clientes(){
	int i,j;
	header();
	 setcolor(BLACK);

	 for(i=50; i < 600; i += 200){
		for(j = 80; j < 400; j+=200){
			if(i == 450 && j == 280){
			}else{
				cuadrado(i, j, 150, 150);
				circle(i + 75, j + 60, 40);
				setfillstyle(1, CYAN);
				floodfill(i + 130, j + 50, BLACK);
			}
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



}

void interfaz_inventario(){
	int i,j;
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
}

int Error_con_retorno(char mensaje[]){
	mocultar();
	setfillstyle(1, WHITE);
	setcolor(BLACK);
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
	settextstyle(0, 0 , 2);
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
	while(!kbhit() || kbhit){
		
		if(kbhit()){
			getch();

	  	}
		if(getch() == 13){
			return 0;
			}
	}

}


void comprobacion(int *intentos, char usuario[], char contrasena[], void (*funcion)(),  void (*funcion2)()){


	if(*intentos == 3){

	 exit(0);
	}

	else if( (strcmp(usuario, "mario") || strcmp(contrasena, "123") )!= 0){
		(*intentos)++;
		funcion();

	}
	else{
		mver();
		funcion2();
	}
}


void interfaz_menu_login(){

	setfillstyle(SOLID_FILL, CYAN);
	bar(0, 0, 640, 480);

	setcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	cuadrado(100, 80, 300, 450);
	floodfill(150, 90, WHITE);

	setcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
	outtextxy(280, 110, "LOGIN");

	setcolor(LIGHTGRAY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	boton(150, 170, 500, 20);
	floodfill(152, 172, LIGHTGRAY);

	boton(150, 250, 500, 20);
	floodfill(152, 254, LIGHTGRAY);

	setcolor(LIGHTCYAN);
	boton(250, 320, 400, 20);
	setfillstyle(SOLID_FILL, LIGHTCYAN);
	floodfill(255, 325, LIGHTCYAN);

	setcolor(BLACK);
	outtextxy(265, 313, "Ingresar");

	setfillstyle(SOLID_FILL, BLACK);
	setcolor(BLACK);
	pieslice(165, 185, 0, 180, 9);
	circle(165, 165, 8);
	floodfill(168, 168, BLACK);

	bar(155, 250, 175, 265);
	arc(165, 250, 0, 180, 7);
	arc(165, 250, 0, 180, 10);
	floodfill(165, 242, BLACK);

	settextstyle(0, 0, 2);
	outtextxy(210, 165, "Usuario");
	outtextxy(210, 245, "Contrasena");

}



