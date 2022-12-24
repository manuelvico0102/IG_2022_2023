//**************************************************************************
// Práctica 2 
//**************************************************************************

#include <GL/glut.h>
#include <ctype.h>
#include <math.h>
#include <vector>
#include "objetos_B2.h"
#include <unistd.h>


using namespace std;

// tipos
typedef enum{CUBO, PIRAMIDE, OBJETO_PLY, ROTACION, CILINDRO, CONO, ESFERA, FIGURA_PLY, EXTRUSION, ZORRO} _tipo_objeto;
_tipo_objeto t_objeto=CUBO;
_modo   modo=POINTS;

// variables que definen la posicion de la camara en coordenadas polares
GLfloat Observer_distance;
GLfloat Observer_angle_x;
GLfloat Observer_angle_y;

// variables que controlan la ventana y la transformacion de perspectiva
GLfloat Size_x,Size_y,Front_plane,Back_plane;

// variables que determninan la posicion y tamaño de la ventana X
int Window_x=50,Window_y=50,Window_width=650,Window_high=650;


// objetos
_cubo cubo;
_piramide piramide(0.85,1.3);
_objeto_ply  ply; 
_rotacion rotacion;
_cilindro cilindro(1,2,20);
_cono cono(1,2,20); 
_esfera esfera(1,20,20);
_extrusion *extrusion;
_rotacion_PLY figura;
_zorro zorro;

//_objeto_ply *ply;
int animacion = 0;
float giro1, giro2, giro3, giro4, giro5, giro6, giro7 = 0;
int flag1, flag2, flag3, flag4, flag5, flag6, flag7 = 0;
int accion1 = 0;
int parada1, parada2, parada3 = 0;
//**************************************************************************
//
//***************************************************************************

void clean_window()
{

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}


//**************************************************************************
// Funcion para definir la transformación de proyeccion
//***************************************************************************

void change_projection()
{

glMatrixMode(GL_PROJECTION);
glLoadIdentity();

// formato(x_minimo,x_maximo, y_minimo, y_maximo,plano_delantero, plano_traser)
//  plano_delantero>0  plano_trasero>PlanoDelantero)
glFrustum(-Size_x,Size_x,-Size_y,Size_y,Front_plane,Back_plane);
}

//**************************************************************************
// Funcion para definir la transformación*ply1 de vista (posicionar la camara)
//***************************************************************************

void change_observer()
{

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}

//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void draw_axis()
{
	
glDisable(GL_LIGHTING);
glLineWidth(2);
glBegin(GL_LINES);
// eje X, color rojo
glColor3f(1,0,0);
glVertex3f(-AXIS_SIZE,0,0);
glVertex3f(AXIS_SIZE,0,0);
// eje Y, color verde
glColor3f(0,1,0);
glVertex3f(0,-AXIS_SIZE,0);
glVertex3f(0,AXIS_SIZE,0);
// eje Z, color azul
glColor3f(0,0,1);
glVertex3f(0,0,-AXIS_SIZE);
glVertex3f(0,0,AXIS_SIZE);
glEnd();
}


//**************************************************************************
// Funcion que dibuja los objetos
//****************************2***********************************************

void draw_objects()
{

switch (t_objeto){
	case CUBO: cubo.draw(modo,1.0,0.0,0.0,5);break;
	case PIRAMIDE: piramide.draw(modo,1.0,0.0,0.0,5);break;
        case OBJETO_PLY: ply.draw(modo,1.0,0.6,0.0,5);break;
        case ROTACION: rotacion.draw(modo,1.0,0.0,0.0,5);break;
        case CILINDRO: cilindro.draw(modo,1.0,0.0,0.0,5);break;
        case CONO: cono.draw(modo,1.0,0.0,0.0,5);break;
        case ESFERA: esfera.draw(modo,1.0,0.0,0.0,5);break;
        case FIGURA_PLY: figura.draw(modo,1.0,0.6,0.0,5);break;
        case EXTRUSION: extrusion->draw(modo,1.0,0.0,0.0,5);break;
        case ZORRO: zorro.draw(modo,1.0,0.0,0.0,5);break;
	}

}


//**************************************************************************
//
//***************************************************************************

void draw(void)
{
clean_window();
change_observer();
draw_axis();
draw_objects();
glutSwapBuffers();
}



//***************************************************************************
// Funcion llamada cuando se produce un cambio en el tamaño de la ventana
//
// el evento manda a la funcion:
// nuevo ancho
// nuevo alto
//***************************************************************************

void change_window_size(int Ancho1,int Alto1)
{
float Aspect_ratio;

Aspect_ratio=(float) Alto1/(float )Ancho1;
Size_y=Size_x*Aspect_ratio;
change_projection();
glViewport(0,0,Ancho1,Alto1);
glutPostRedisplay();
}


//***************************************************************************
// Funcion llamada cuando se aprieta una tecla normal
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton
//***************************************************************************

void normal_key(unsigned char Tecla1,int x,int y)
{
switch (toupper(Tecla1)){
	case 'Q':exit(0);
	case '1':modo=POINTS;break;
	case '2':modo=EDGES;break;
	case '3':modo=SOLID;break;
	case '4':modo=SOLID_COLORS;break;
	case '5':modo=SOLID_COLORS_VERTEX;break;
	case 'S': 
		if(animacion==0){
			giro1=0.25;
            giro2=2.5;
            giro3=2.5;
            giro4=0.5;
            giro5=0.5;
            giro6=0.5;
            giro7=1.0;
	       	animacion=1;
		}else{
			giro1=0;
            giro2=0;
            giro3=0;
            giro4=0;
            giro5=0;
            giro6=0;
            giro7=0;
			animacion=0;
		};break;
        case 'P':t_objeto=PIRAMIDE;break;
        case 'C':t_objeto=CUBO;break;
        case 'O':t_objeto=OBJETO_PLY;break;	
        case 'R':t_objeto=ROTACION;break;
        case 'L':t_objeto=CILINDRO;break;
        case 'N':t_objeto=CONO;break;
        case 'E':t_objeto=ESFERA;break;
        case 'F':t_objeto=FIGURA_PLY;break;
        case 'A':t_objeto=ZORRO;break;	
        case 'X':t_objeto=EXTRUSION;break;
	}
glutPostRedisplay();
}

//***************************************************************************
// Funcion l-olamada cuando se aprieta una tecla especial
//
// el evento manda a la funcion:
// codigo de la tecla
// posicion x del raton
// posicion y del raton

//***************************************************************************

void special_key(int Tecla1,int x,int y)
{

switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;

	case GLUT_KEY_F1:zorro.giro_cuerpo+=1;
        if (zorro.giro_cuerpo > zorro.giro_cuerpo_max)
            zorro.giro_cuerpo = zorro.giro_cuerpo_max;break;
   	case GLUT_KEY_F2:zorro.giro_cuerpo-=1;
        if (zorro.giro_cuerpo < zorro.giro_cuerpo_min) 
            zorro.giro_cuerpo = zorro.giro_cuerpo_min;break;
    case GLUT_KEY_F3:zorro.giro_cabeza+=1;
        if (zorro.giro_cabeza > zorro.giro_cabeza_max)
            zorro.giro_cabeza = zorro.giro_cabeza_max;break;
   	case GLUT_KEY_F4:zorro.giro_cabeza-=1;
        if (zorro.giro_cabeza < zorro.giro_cabeza_min) 
            zorro.giro_cabeza = zorro.giro_cabeza_min;break;
    case GLUT_KEY_F5:zorro.giro_cabeza_horizontal+=1;
        if (zorro.giro_cabeza_horizontal > zorro.giro_cabeza_horizontal_max)
            zorro.giro_cabeza_horizontal = zorro.giro_cabeza_horizontal_max;break;
   	case GLUT_KEY_F6:zorro.giro_cabeza_horizontal-=1;
        if (zorro.giro_cabeza_horizontal < zorro.giro_cabeza_horizontal_min) 
            zorro.giro_cabeza_horizontal = zorro.giro_cabeza_horizontal_min;break;
    case GLUT_KEY_F7:zorro.giro_oreja+=1;
        if (zorro.giro_oreja > zorro.giro_oreja_max)
            zorro.giro_oreja = zorro.giro_oreja_max;break;
   	case GLUT_KEY_F8:zorro.giro_oreja-=1;
        if (zorro.giro_oreja < zorro.giro_oreja_min) 
            zorro.giro_oreja = zorro.giro_oreja_min;break;
    case GLUT_KEY_F9:zorro.giro_patas_traseras+=1;
        if (zorro.giro_patas_traseras > zorro.giro_patas_traseras_max)
            zorro.giro_patas_traseras = zorro.giro_patas_traseras_max;break;
   	case GLUT_KEY_F10:zorro.giro_patas_traseras-=1;
        if (zorro.giro_patas_traseras < zorro.giro_patas_traseras_min) 
            zorro.giro_patas_traseras = zorro.giro_patas_traseras_min;break;
    case GLUT_KEY_F11:zorro.giro_patas_delanteras+=1;
        if (zorro.giro_patas_delanteras > zorro.giro_patas_delanteras_max)
            zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_max;break;
   	case GLUT_KEY_F12:zorro.giro_patas_delanteras-=1;
        if (zorro.giro_patas_delanteras < zorro.giro_patas_delanteras_min) 
            zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_min;break;
    case GLUT_KEY_HOME:zorro.giro_cola+=1;
        if (zorro.giro_cola > zorro.giro_cola_max)
            zorro.giro_cola = zorro.giro_cola_max;break;
   	case GLUT_KEY_END:zorro.giro_cola-=1;
        if (zorro.giro_cola < zorro.giro_cola_min) 
            zorro.giro_cola = zorro.giro_cola_min;break;

	}
glutPostRedisplay();
}

//***************************************************************************
// Animación automatica
//***************************************************************************
void movimiento(){
    if(animacion==1){
        if(accion1 == 0){
        	//Agachar orejas
            if(flag1==0)
                zorro.giro_oreja -= giro1;

            if (zorro.giro_oreja < zorro.giro_oreja_min){
                zorro.giro_oreja = zorro.giro_oreja_min;
                flag1=1;
            }

            if(zorro.giro_oreja == zorro.giro_oreja_min)
                accion1 += 1;

        }else if(accion1 == 1){
        	//Correr
            if(flag2==0)
                zorro.giro_patas_delanteras += giro2;
            else 
                zorro.giro_patas_delanteras -= giro2;

            if (zorro.giro_patas_delanteras > zorro.giro_patas_delanteras_max){
                zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_max;
                flag2=1;
            }

            if (zorro.giro_patas_delanteras < zorro.giro_patas_delanteras_min+45){
                zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_min+45;
                flag2=0;
            }

            if(flag3==0)
                zorro.giro_patas_traseras -= giro3;
            else 
                zorro.giro_patas_traseras += giro3;

            if (zorro.giro_patas_traseras > zorro.giro_patas_traseras_max){
                zorro.giro_patas_traseras = zorro.giro_patas_traseras_max;
                flag3=0;
            }

            if (zorro.giro_patas_traseras < zorro.giro_patas_traseras_min+45){
                zorro.giro_patas_traseras = zorro.giro_patas_traseras_min+45;
                flag3=1;
            }

            if(zorro.giro_patas_delanteras == 0){
                parada1 += 1;
            }

            if(parada1 == 20){
                accion1 +=1;
                parada1 = 0;
            }

        }else if(accion1 == 2){
        	//Levantarse sobre si mismo
            if(flag4==0)
                zorro.giro_cuerpo += giro4;

            if (zorro.giro_cuerpo > zorro.giro_cuerpo_max){
                zorro.giro_cuerpo = zorro.giro_cuerpo_max;
                flag4=1;
            }

            if(flag5==0)
                zorro.giro_cabeza -= giro5;

            if (zorro.giro_cabeza < zorro.giro_cabeza_min){
                zorro.giro_cabeza = zorro.giro_cabeza_min;
                flag5=1;
            }

            if(flag2==0) 
                zorro.giro_patas_delanteras -= giro5;

            if (zorro.giro_patas_delanteras > zorro.giro_patas_delanteras_min+45){
                zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_min+45;
                flag2=1;
            }

            if(flag3==0)
                zorro.giro_patas_traseras -= giro5;

            if (zorro.giro_patas_traseras < zorro.giro_patas_traseras_min+45){
                zorro.giro_patas_traseras = zorro.giro_patas_traseras_min+45;
                flag3=1;
            }

            if(flag1==0)
                zorro.giro_oreja += giro1;

            if (zorro.giro_oreja > zorro.giro_oreja_max){
                zorro.giro_oreja = zorro.giro_oreja_max;
                flag1=1;
            }

            if(flag1==1 && flag2==1 && flag3==1 && flag4==1 && flag5 == 1){
                flag1 = flag2 = flag3 = flag4 = flag5 = 0;
                accion1 +=1;
            }
        }else if(accion1 == 3){
        	//Mirar hacia los dos lados
            if(flag6==0)
                zorro.giro_cabeza_horizontal += giro6;
            else 
                zorro.giro_cabeza_horizontal -= giro6;

            if (zorro.giro_cabeza_horizontal > zorro.giro_cabeza_horizontal_max){
                zorro.giro_cabeza_horizontal = zorro.giro_cabeza_horizontal_max;
                flag6=1;
            }

            if (zorro.giro_cabeza_horizontal < zorro.giro_cabeza_horizontal_min){
                zorro.giro_cabeza_horizontal = zorro.giro_cabeza_horizontal_min;
                flag6=0;
            }

            if(zorro.giro_cabeza_horizontal == 0){
                parada2 += 1;
            }

            if(parada2 == 2){
                accion1 +=1;
                parada2 = 0;
            }
        }else if(accion1 == 4){
            //Bajar todo el cuerpo
            if(flag4==0)
                zorro.giro_cuerpo -= giro4;

            if (zorro.giro_cuerpo < 0){
                zorro.giro_cuerpo = 0;
                flag4=1;
            }

            if(flag1==0)
                zorro.giro_oreja -= giro1;

            if (zorro.giro_oreja < zorro.giro_oreja_min){
                zorro.giro_oreja = zorro.giro_oreja_min;
                flag1=1;
            }

            if(flag2==0) 
                zorro.giro_patas_delanteras += giro5;

            if (zorro.giro_patas_delanteras > zorro.giro_patas_delanteras_max-45){
                zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_max-45;
                flag2=1;
            }

            if(flag3==0)
                zorro.giro_patas_traseras += giro5;

            if (zorro.giro_patas_traseras > zorro.giro_patas_traseras_max-45){
                zorro.giro_patas_traseras = zorro.giro_patas_traseras_max-45;
                flag3=1;
            }

            if(flag1==1 &&flag2==1 && flag3==1 && flag4==1)
            	accion1+=1;

        }else if(accion1 == 5){
            //Comer
            if(flag5==0)
                zorro.giro_cabeza += giro5;
            else 
                zorro.giro_cabeza -= giro5;

            if (zorro.giro_cabeza > -35){
                zorro.giro_cabeza = -35;
                flag5=1;
            }

            if (zorro.giro_cabeza < zorro.giro_cabeza_min){
                zorro.giro_cabeza = zorro.giro_cabeza_min;
                flag5=0;
            }

            if(flag7==0)
                zorro.giro_cola += giro7;
            else 
                zorro.giro_cola -= giro7;

            if (zorro.giro_cola > zorro.giro_cola_max){
                zorro.giro_cola = zorro.giro_cola_max;
                flag7=1;
            }

            if (zorro.giro_cola < zorro.giro_cola_min){
                zorro.giro_cola = zorro.giro_cola_min;
                flag7=0;
            }

            if(zorro.giro_cola == 0){
                parada3 += 1;
            }

            if(parada3 == 6){
                accion1 +=1;
                parada3 = 0;
            }

        }else if(accion1 == 6){
            //Tumbarse
            if(flag5==0)
                zorro.giro_cabeza += giro5;

            if (zorro.giro_cabeza > zorro.giro_cabeza_max){
                zorro.giro_cabeza = zorro.giro_cabeza_max;
                flag5=1;
            }

            if(flag6==0)
                zorro.giro_cabeza_horizontal -= giro6;

            if (zorro.giro_cabeza_horizontal < zorro.giro_cabeza_horizontal_min){
                zorro.giro_cabeza_horizontal = zorro.giro_cabeza_horizontal_min;
                flag6=1;
            }

            if(flag2==1) 
                zorro.giro_patas_delanteras -= giro5;

            if (zorro.giro_patas_delanteras < zorro.giro_patas_delanteras_min){
                zorro.giro_patas_delanteras = zorro.giro_patas_delanteras_min;
                flag2=0;
            }

            if(flag3==1)
                zorro.giro_patas_traseras -= giro5;

            if (zorro.giro_patas_traseras < zorro.giro_patas_traseras_min){
                zorro.giro_patas_traseras = zorro.giro_patas_traseras_min;
                flag3=0;
            }

            if(flag7==0)
                zorro.giro_cola += giro7;

            if (zorro.giro_cola > zorro.giro_cola_max){
                zorro.giro_cola = zorro.giro_cola_max;
                flag7=1;
            }

            if(flag2==0 && flag3==0 && flag5==1 && flag6==1 && flag7 == 1){
            	accion1 +=1;
            	sleep(10);
            }
        }else if(accion1 == 7){
        	//Volver a la posición normal
        	if(flag6==1)
                zorro.giro_cabeza_horizontal += giro6;

            if (zorro.giro_cabeza_horizontal > 0){
                zorro.giro_cabeza_horizontal = 0;
                flag6=0;
            }

            if(flag2==0) 
                zorro.giro_patas_delanteras += giro5;

            if (zorro.giro_patas_delanteras > 0){
                zorro.giro_patas_delanteras = 0;
                flag2=1;
            }

            if(flag3==0)
                zorro.giro_patas_traseras += giro5;

            if (zorro.giro_patas_traseras > 0){
                zorro.giro_patas_traseras = 0;
                flag3=1;
            }

            if(flag7==1)
                zorro.giro_cola -= giro7;

            if (zorro.giro_cola < 0){
                zorro.giro_cola = 0;
                flag7=0;
            }

            if(flag1==1)
                zorro.giro_oreja += giro1;

            if (zorro.giro_oreja > 0){
                zorro.giro_oreja = 0;
                flag1=0;
            }

            if(flag1==0 && flag2==1 && flag3==1 && flag6==0 && flag7 == 0){
            	accion1 = 0;
            	animacion = 0;
            	flag1=flag2=flag3=flag4=flag5=flag6=flag7=0;
            	giro1=giro2=giro3=giro4=giro5=giro6=giro7 = 0;
            }
        }

    	glutPostRedisplay();
    }
}

//***************************************************************************
// Funcion de incializacion
//***************************************************************************

void initialize(void)
{
// se inicalizan la ventana y los planos de corte
Size_x=0.5;
Size_y=0.5;
Front_plane=1;
Back_plane=1000;

// se incia la posicion del observador, en el eje z
Observer_distance=4*Front_plane;
Observer_angle_x=0;
Observer_angle_y=0;

// se indica el color para limpiar la ventana	(r,v,a,al)
// blanco=(1,1,1,1) rojo=(1,0,0,1), ...
glClearColor(1,1,1,1);

// se habilita el z-bufer
glEnable(GL_DEPTH_TEST);
change_projection();
glViewport(0,0,Window_width,Window_high);
}


//***************************************************************************
// Programa principal
//
// Se encarga de iniciar la ventana, asignar las funciones e comenzar el
// bucle de eventos
//***************************************************************************


int main(int argc, char *argv[] )
{
 
// perfil 

vector<_vertex3f> perfil, poligono;
_vertex3f aux;

/*
aux.x=1.0; aux.y=-1.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.5; aux.y=1.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.0; aux.y=1.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.5; aux.y=1.2; aux.z=0.0;
perfil.push_back(aux);
*/
/*
//Lápiz
aux.x=0.4; aux.y=-1.5; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.4; aux.y=-1.2; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.3; aux.y=-1.1; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.3; aux.y=-1.2; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.4; aux.y=-1.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.4; aux.y=1.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.2; aux.y=2.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.1; aux.y=2.5; aux.z=0.0;
perfil.push_back(aux);
*/

//Platillo
aux.x=0.4; aux.y=-0.425; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.6; aux.y=-0.375; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.75; aux.y=-0.25; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.0; aux.y=-0.25; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.25; aux.y=-0.05; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.35; aux.y=0.0; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.25; aux.y=0.05; aux.z=0.0;
perfil.push_back(aux);
aux.x=1.0; aux.y=0.25; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.75; aux.y=0.25; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.6; aux.y=0.375; aux.z=0.0;
perfil.push_back(aux);
aux.x=0.4; aux.y=0.425; aux.z=0.0;
perfil.push_back(aux);



rotacion.parametros(perfil,6,0,1,1);

aux.x=1.0; aux.y=0.0; aux.z=1.0;
poligono.push_back(aux);
aux.x=1.0; aux.y=0.0; aux.z=-1.0;
poligono.push_back(aux);
aux.x=-1.2; aux.y=0.0; aux.z=-1.0;
poligono.push_back(aux);
aux.x=-0.8; aux.y=0.0; aux.z=0.0;
poligono.push_back(aux);
aux.x=-1.2; aux.y=0.0; aux.z=1.0;
poligono.push_back(aux);

extrusion= new _extrusion(poligono, 0.25, 1.0, 0.25);

// se llama a la inicialización de glut
glutInit(&argc, argv);

// se indica las caracteristicas que se desean para la visualización con OpenGL
// Las posibilidades son:
// GLUT_SIMPLE -> memoria de imagen simple
// GLUT_DOUBLE -> memoria de imagen doble
// GLUT_INDEX -> memoria de imagen con color indizado
// GLUT_RGB -> memoria de imagen con componentes rojo, verde y azul para cada pixel
// GLUT_RGBA -> memoria de imagen con componentes rojo, verde, azul y alfa para cada pixel
// GLUT_DEPTH -> memoria de profundidad o z-bufer
// GLUT_STENCIL -> memoria de estarcido_rotation Rotation;
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

// posicion de la esquina inferior izquierdad de la ventana
glutInitWindowPosition(Window_x,Window_y);

// tamaño de la ventana (ancho y alto)
glutInitWindowSize(Window_width,Window_high);

// llamada para crear la ventana, indicando el titulo (no se visualiza hasta que se llama
// al bucle de eventos)
glutCreateWindow("PRACTICA - 2");

// asignación de la funcion llamada "dibujar" al evento de dibujo
glutDisplayFunc(draw);
// asignación de la funcion llamada "change_window_size" al evento correspondiente
glutReshapeFunc(change_window_size);
// asignación de la funcion llamada "normal_key" al evento correspondiente
glutKeyboardFunc(normal_key);
// asignación de la funcion llamada "tecla_Especial" al evento correspondiente
glutSpecialFunc(special_key);

glutIdleFunc(movimiento);
// funcion de inicialización
initialize();

// creación del objeto ply
ply.parametros(argv[1]);
figura.parametros_PLY(argv[2],10);
//ply = new _objeto_ply(argv[1]);

// inicio del bucle de eventos
glutMainLoop();
return 0;
}
