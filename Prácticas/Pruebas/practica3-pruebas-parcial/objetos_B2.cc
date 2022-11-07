//**************************************************************************
// Práctica 2 
//**************************************************************************

#include "objetos_B2.h"
#include "file_ply_stl.hpp"


//*************************************************************************
// _puntos3D
//*************************************************************************

_puntos3D::_puntos3D()
{
}

//*************************************************************************
// dibujar puntos
//*************************************************************************

void _puntos3D::draw_puntos(float r, float g, float b, int grosor)
{
int i;
glPointSize(grosor);
glColor3f(r,g,b);
glBegin(GL_POINTS);
for (i=0;i<vertices.size();i++){
	glVertex3fv((GLfloat *) &vertices[i]);
	}
glEnd();
}


//*************************************************************************
// _triangulos3D
//*************************************************************************

_triangulos3D::_triangulos3D()
{
}


//*************************************************************************
// dibujar en modo arista
//*************************************************************************

void _triangulos3D::draw_aristas(float r, float g, float b, int grosor)
{
int i;
glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
glLineWidth(grosor);
glColor3f(r,g,b);
glBegin(GL_TRIANGLES);
for (i=0;i<caras.size();i++){
	glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
	glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
	}
glEnd();
}

//*************************************************************************
// dibujar en modo sólido con un único color
//*************************************************************************

void _triangulos3D::draw_solido(float r, float g, float b)
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glColor3f(r,g,b);
  glBegin(GL_TRIANGLES);
  for(i = 0; i < caras.size(); i++){
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();



}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada cara
//*************************************************************************

void _triangulos3D::draw_solido_colores()
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glBegin(GL_TRIANGLES);
  for(i = 0; i < caras.size(); i++){
    //Aqui poner una condicion para que cada vez sea un color distinto
    glColor3f(colores_caras[i].r, colores_caras[i].g, colores_caras[i].b);
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();
}

//*************************************************************************
// dibujar en modo sólido con colores diferentes para cada vértice
//*************************************************************************

void _triangulos3D::draw_solido_colores_vertices( )
{
  int i;
  glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);
  glBegin(GL_TRIANGLES);
  for(i = 0; i < caras.size(); i++){
    //Aqui poner una condicion para que cada vez sea un color distinto
    glColor3f(colores_vertices[caras[i]._0].r, colores_vertices[caras[i]._0].g, colores_vertices[caras[i]._0].b);
    glVertex3fv((GLfloat *) &vertices[caras[i]._0]);
    glColor3f(colores_vertices[caras[i]._1].r, colores_vertices[caras[i]._1].g, colores_vertices[caras[i]._1].b);
    glVertex3fv((GLfloat *) &vertices[caras[i]._1]);
    glColor3f(colores_vertices[caras[i]._2].r, colores_vertices[caras[i]._2].g, colores_vertices[caras[i]._2].b);
    glVertex3fv((GLfloat *) &vertices[caras[i]._2]);
  }
  glEnd();
}


//*************************************************************************
// dibujar con distintos modos
//*************************************************************************

void _triangulos3D::draw(_modo modo, float r, float g, float b, float grosor)
{
switch (modo){
	case POINTS:draw_puntos(r, g, b, grosor);break;
	case EDGES:draw_aristas(r, g, b, grosor);break;
	case SOLID:draw_solido(r, g, b);break;
	case SOLID_COLORS:draw_solido_colores();break;
  case SOLID_COLORS_VERTEX:draw_solido_colores_vertices();break;
	}
}

//*************************************************************************
// asignación colores
//*************************************************************************

void _triangulos3D::colors_random()
{
int i, n_c;
n_c=caras.size();
colores_caras.resize(n_c);
srand (time(NULL));
for (i=0;i<n_c;i++)  
  {colores_caras[i].r=rand()%1000/1000.0;
   colores_caras[i].g=rand()%1000/1000.0;
   colores_caras[i].b=rand()%1000/1000.0;
  }
}

//*************************************************************************

void _triangulos3D::colors_chess(float r1, float g1, float b1, float r2, float g2, float b2)
{
int i, n_c;
n_c=caras.size();
colores_caras.resize(n_c);
for (i=0;i<n_c;i++)  
  {if (i%2==0) 
     {colores_caras[i].r=r1;
      colores_caras[i].g=g1;
      colores_caras[i].b=b1;
     }
   else 
     {colores_caras[i].r=r2;
      colores_caras[i].g=g2;
      colores_caras[i].b=b2;
     } 
  }
}


//*************************************************************************
// objetos o modelos
//*************************************************************************

//*************************************************************************
// clase cubo
//*************************************************************************

_cubo::_cubo(float tam)
{
//vertices
  vertices.resize(8);
  vertices[0].x=-tam; vertices[0].y=-tam; vertices[0].z=tam;  
  vertices[1].x=tam; vertices[1].y=-tam; vertices[1].z=tam; 
  vertices[2].x=tam; vertices[2].y=-tam; vertices[2].z=-tam;    
  vertices[3].x=-tam; vertices[3].y=-tam; vertices[3].z=-tam;   
  vertices[4].x=-tam; vertices[4].y=tam; vertices[4].z=tam;   
  vertices[5].x=tam; vertices[5].y=tam; vertices[5].z=tam;    
  vertices[6].x=tam; vertices[6].y=tam; vertices[6].z=-tam;   
  vertices[7].x=-tam; vertices[7].y=tam; vertices[7].z=-tam;

//Colores de los vertices
  colores_vertices.resize(8);
  for(int i=0; i<8; i++){
    colores_vertices[i].r=rand()%1000/1000.0;
    colores_vertices[i].g=rand()%1000/1000.0; 
    colores_vertices[i].b=rand()%1000/1000.0; 

  }

// triangulos
  caras.resize(12);
  caras[0]._0=0; caras[0]._1=1; caras[0]._2=4;      //C0
  caras[1]._0=1; caras[1]._1=5; caras[1]._2=4;      //C1
  caras[2]._0=1; caras[2]._1=2; caras[2]._2=5;      //C2
  caras[3]._0=2; caras[3]._1=6; caras[3]._2=5;      //C3
  caras[4]._0=2; caras[4]._1=3; caras[4]._2=6;      //C4
  caras[5]._0=3; caras[5]._1=7; caras[5]._2=6;      //C5
  caras[6]._0=3; caras[6]._1=0; caras[6]._2=7;      //C6
  caras[7]._0=0; caras[7]._1=4; caras[7]._2=7;      //C7
  caras[8]._0=3; caras[8]._1=2; caras[8]._2=0;      //C8
  caras[9]._0=2; caras[9]._1=1; caras[9]._2=0;      //C9
  caras[10]._0=4; caras[10]._1=5; caras[10]._2=7;     //C10
  caras[11]._0=5; caras[11]._1=6; caras[11]._2=7;     //C11

//Colores a las caras
  colors_random();

}


//*************************************************************************
// clase piramide
//*************************************************************************

_piramide::_piramide(float tam, float al)
{

//vertices 
vertices.resize(5); 
vertices[0].x=-tam;vertices[0].y=0;vertices[0].z=tam;
vertices[1].x=tam;vertices[1].y=0;vertices[1].z=tam;
vertices[2].x=tam;vertices[2].y=0;vertices[2].z=-tam;
vertices[3].x=-tam;vertices[3].y=0;vertices[3].z=-tam;
vertices[4].x=0;vertices[4].y=al;vertices[4].z=0;

//Colores de los vertices
colores_vertices.resize(8);
for(int i=0; i<8; i++){
  colores_vertices[i].r=rand()%1000/1000.0;
  colores_vertices[i].g=rand()%1000/1000.0; 
  colores_vertices[i].b=rand()%1000/1000.0; 
}

caras.resize(6);
caras[0]._0=0;caras[0]._1=1;caras[0]._2=4;
caras[1]._0=1;caras[1]._1=2;caras[1]._2=4;
caras[2]._0=2;caras[2]._1=3;caras[2]._2=4;
caras[3]._0=3;caras[3]._1=0;caras[3]._2=4;
caras[4]._0=3;caras[4]._1=1;caras[4]._2=0;
caras[5]._0=3;caras[5]._1=2;caras[5]._2=1;

//Colores a las caras
colors_random();
}

//*************************************************************************
// clase cubo+piramide
//*************************************************************************
_cubop::_cubop(float tam, float al)
{
//vertices
  vertices.resize(9);
  vertices[0].x=-tam; vertices[0].y=-tam; vertices[0].z=tam;  
  vertices[1].x=tam; vertices[1].y=-tam; vertices[1].z=tam; 
  vertices[2].x=tam; vertices[2].y=-tam; vertices[2].z=-tam;    
  vertices[3].x=-tam; vertices[3].y=-tam; vertices[3].z=-tam;   
  vertices[4].x=-tam; vertices[4].y=tam; vertices[4].z=tam;   
  vertices[5].x=tam; vertices[5].y=tam; vertices[5].z=tam;    
  vertices[6].x=tam; vertices[6].y=tam; vertices[6].z=-tam;   
  vertices[7].x=-tam; vertices[7].y=tam; vertices[7].z=-tam;
  vertices[8].x=0;vertices[8].y=al+tam;vertices[8].z=0;

//Colores de los vertices
  colores_vertices.resize(9);
  for(int i=0; i<9; i++){
    colores_vertices[i].r=rand()%1000/1000.0;
    colores_vertices[i].g=rand()%1000/1000.0; 
    colores_vertices[i].b=rand()%1000/1000.0; 

  }

// triangulos
  caras.resize(14);
  caras[0]._0=0; caras[0]._1=1; caras[0]._2=4;      //C0
  caras[1]._0=1; caras[1]._1=5; caras[1]._2=4;      //C1
  caras[2]._0=1; caras[2]._1=2; caras[2]._2=5;      //C2
  caras[3]._0=2; caras[3]._1=6; caras[3]._2=5;      //C3
  caras[4]._0=2; caras[4]._1=3; caras[4]._2=6;      //C4
  caras[5]._0=3; caras[5]._1=7; caras[5]._2=6;      //C5
  caras[6]._0=3; caras[6]._1=0; caras[6]._2=7;      //C6
  caras[7]._0=0; caras[7]._1=4; caras[7]._2=7;      //C7
  caras[8]._0=3; caras[8]._1=2; caras[8]._2=0;      //C8
  caras[9]._0=2; caras[9]._1=1; caras[9]._2=0;      //C9
  
  caras[10]._0=4;caras[10]._1=5;caras[10]._2=8;
  caras[11]._0=4;caras[11]._1=7;caras[11]._2=8;
  caras[12]._0=5;caras[12]._1=6;caras[12]._2=8;
  caras[13]._0=6;caras[13]._1=7;caras[13]._2=8;

//Colores a las caras
  colors_random();

}

//*************************************************************************
// clase objeto ply
//*************************************************************************


_objeto_ply::_objeto_ply() 
{
   // leer lista de coordenadas de vértices y lista de indices de vértices
 
}



void _objeto_ply::parametros(char *archivo)
{
int n_ver,n_car;

vector<float> ver_ply ;
vector<int>   car_ply ;
 
_file_ply::read(archivo, ver_ply, car_ply );

n_ver=ver_ply.size()/3;
n_car=car_ply.size()/3;

printf("Number of vertices=%d\nNumber of faces=%d\n", n_ver, n_car);

vertices.resize(n_ver);
caras.resize(n_car);
//vértices

for(int i = 0; i<n_ver; i++){
  vertices[i].x=ver_ply[3*i];
  vertices[i].y=ver_ply[3*i+1];
  vertices[i].z=ver_ply[3*i+2];
}

colores_vertices.resize(n_ver);
for(int i=0; i<n_ver; i++){
  colores_vertices[i].r=rand()%1000/1000.0;
  colores_vertices[i].g=rand()%1000/1000.0; 
  colores_vertices[i].b=rand()%1000/1000.0; 
}

//Caras 
for(int i = 0; i<n_car; i++){
  caras[i].x=car_ply[3*i];
  caras[i].y=car_ply[3*i+1];
  caras[i].z=car_ply[3*i+2];
}

//Colores a las caras
colores_caras.resize(n_car);

srand(10);
for(int i=0; i<n_car; i++){
  if(vertices[caras[i]._0].y>0.0){
    colores_caras[i].r=rand()%1000/1000.0;
    colores_caras[i].g=0.0;
  }else{
    colores_caras[i].r=0.0; 
    colores_caras[i].g=rand()%1000/1000.0; 
  }
  colores_caras[i].b=0.0;
}
}



//************************************************************************
// objeto por revolucion
//************************************************************************

_rotacion::_rotacion()
{

}


void _rotacion::parametros(vector<_vertex3f> perfil, int num, int tipo, int tapa_in, int tapa_su)
{
  int i,j;
  _vertex3f vertice_aux;
  _vertex3i cara_aux;
  int num_aux;
  float radio;

  // tratamiento de los vértice
  radio=sqrt(perfil[0].x*perfil[0].x+perfil[0].y*perfil[0].y);

  num_aux=perfil.size();
  if(tipo==1) num_aux=num_aux-1;
  vertices.resize(num_aux*num+2);
  for (j=0;j<num;j++){
    for (i=0;i<num_aux;i++){
      vertice_aux.x=perfil[i].x*cos(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*sin(2.0*M_PI*j/(1.0*num));
      vertice_aux.z=-perfil[i].x*sin(2.0*M_PI*j/(1.0*num))+
                    perfil[i].z*cos(2.0*M_PI*j/(1.0*num));
      vertice_aux.y=perfil[i].y;
      vertices[i+j*num_aux]=vertice_aux;
    }
  }

  colores_vertices.resize(vertices.size());
  for(int i=0; i<vertices.size(); i++){
    colores_vertices[i].r=rand()%1000/1000.0;
    colores_vertices[i].g=rand()%1000/1000.0; 
    colores_vertices[i].b=rand()%1000/1000.0; 
  }

  // tratamiento de las caras 

  caras.resize(2*(num_aux-1)*num+2*num);
  int c = 0;

  for(j=0; j<num; j++){
    for(i=0;i<num_aux-1;i++){
      caras[c]._0=i+j*num_aux;
      caras[c]._1=((j+1)%num)*num_aux+i;
      caras[c]._2=1+i+j*num_aux;
      c=c+1;
      caras[c]._0=((j+1)%num)*num_aux+i;
      caras[c]._1=((j+1)%num)*num_aux+1+i;;
      caras[c]._2=1+i+j*num_aux;
      c=c+1;
    }
  }



  // tapa inferior
  int total=num_aux*num;
  if(tapa_in == 1){
    vertices[total].x=0.0;
    if(tipo==2) vertices[total].y = -radio;
    else vertices[total].y=perfil[0].y;
    vertices[total].z=0.0;

    for(j=0; j<num; j++){
      caras[c]._0=j*num_aux;
      caras[c]._1=((j+1)%num)*num_aux;
      caras[c]._2=total;
      c=c+1;
    }
  }
 
  // tapa superior
  if(tapa_su == 1){
    vertices[total+1].x=0.0;
    if(tipo==1) vertices[total+1].y=perfil[1].y;
    if(tipo==0) vertices[total+1].y=perfil[num_aux-1].y;
    if(tipo==2) vertices[total+1].y=radio;
    vertices[total+1].z=0.0;

    for(j=0; j<num; j++){
      caras[c]._0=total+1;
      caras[c]._1=((j+1)%num)*num_aux+num_aux-1;
      caras[c]._2=num_aux-1+j*num_aux;
      c=c+1;
    }
  }

  //Colores a las caras
  colors_random();
  /*colores_caras.resize(caras.size());

  for(int i=0; i<caras.size(); i++){

    if(tipo == 0){
      if(vertices[caras[i]._0].y>=0.0){
        colores_caras[i].r=0.0; 
        colores_caras[i].g=(rand()%1000/1000.0)+0.2;
        colores_caras[i].b=0.0;
      }else{
        colores_caras[i].r=0.0; 
        colores_caras[i].g=0.0;
        colores_caras[i].b=(rand()%1000/1000.0)-0.3;
      }
    }
  }*/
}


//*************************************************************************
// cilindro
//*************************************************************************
_cilindro::_cilindro(float radio, float altura, int num){
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x=radio; aux.y=-altura/2.0; aux.z=0.0;
  perfil.push_back(aux);
  aux.x=radio; aux.y=altura/2.0; aux.z=0.0;
  perfil.push_back(aux);
  parametros(perfil,num,0,1,1);
}

//*************************************************************************
// cono
//*************************************************************************
_cono::_cono(float radio, float altura, int num){
  vector<_vertex3f> perfil;
  _vertex3f aux;

  aux.x=radio; aux.y=0.0; aux.z=0.0;
  perfil.push_back(aux);
  aux.x=0.0; aux.y=altura; aux.z=0.0;
  perfil.push_back(aux);
  parametros(perfil,num,1,1,1);
}

//*************************************************************************
// Esfera
//*************************************************************************
_esfera::_esfera(float radio, int num1, int num2){
  vector<_vertex3f> perfil;
  _vertex3f aux;
  int i;
  for(i=0;i<num1;i++){
    aux.x=radio*cos(M_PI*i/(num1*1.0)-M_PI/2.0);
    aux.y=radio*sin(M_PI*i/(num1*1.0)-M_PI/2.0);
    aux.z=0.0;
    perfil.push_back(aux);
  }
  parametros(perfil,num2,2,1,1);
}

//*************************************************************************
// nube
//*************************************************************************
_nube::_nube(float radio1, float radio2, int num1, int num2){
  vector<_vertex3f> perfil;
  _vertex3f aux;
  int i;

  for(i=0;i<num1/2.0;i++){
    aux.x=radio2*cos(M_PI*i/(num1*1.0)-M_PI/2.0);
    aux.y=radio2*sin(M_PI*i/(num1*1.0)-M_PI/2.0);
    aux.z=0.0;
    perfil.push_back(aux);

  }
  for(i=0;i<num1/2.0;i++){
    aux.x=radio1*cos(M_PI*i/(num1*1.0)-M_PI/2.0);
    aux.y=radio1*sin(M_PI*i/(num1*1.0)-M_PI/2.0)+radio2;
    aux.z=0.0;
    if(aux.x>radio2)perfil.push_back(aux);
  }
  
  parametros(perfil,num2,2,1,0);
}

//************************************************************************
// rotación PLY
//************************************************************************

_rotacion_PLY::_rotacion_PLY()
{

}

void _rotacion_PLY::parametros_PLY(char *archivo, int num){
  int n_vert;
  vector<int> car_ply;
  vector<float> ver_ply;
  vector<_vertex3f> perfil;
  _vertex3f aux;

  _file_ply::read(archivo, ver_ply, car_ply);
  n_vert=ver_ply.size()/3;

  //Tratamiento de vértices
  vertices.resize(n_vert);
  for(int i = 0; i<n_vert; i++){
    aux.x=ver_ply[3*i];
    aux.y=ver_ply[3*i+1];
    aux.z=ver_ply[3*i+2];
    perfil.push_back(aux);
  }

  parametros(perfil,num,0,1,0);
}


//************************************************************************
// objeto por extrusión
//************************************************************************

_extrusion::_extrusion(vector<_vertex3f> poligono, float x, float y, float z)
{
int i;
_vertex3f vertice_aux;
_vertex3i cara_aux;
int num_aux;

// tratamiento de los vértice

num_aux=poligono.size();
vertices.resize(num_aux*2);
for (i=0;i<num_aux;i++)
    {
      vertices[2*i]=poligono[i];
      vertices[2*i+1].x=poligono[i].x+x;
      vertices[2*i+1].y=poligono[i].y+y;
      vertices[2*i+1].z=poligono[i].z+z;
    }

colores_vertices.resize(num_aux*2);
for(int i=0; i<num_aux*2; i++){
  colores_vertices[i].r=rand()%1000/1000.0;
  colores_vertices[i].g=rand()%1000/1000.0; 
  colores_vertices[i].b=rand()%1000/1000.0; 
}    
// tratamiento de las caras 

caras.resize(num_aux*2);
int c=0;
for (i=0;i<num_aux;i++)         
  {
   caras[c]._0=i*2;
   caras[c]._1=(i*2+2)%(num_aux*2);
   caras[c]._2=i*2+1;    
   c=c+1;
   caras[c]._0=(i*2+2)%(num_aux*2);
   caras[c]._1=(i*2+2)%(num_aux*2)+1;
   caras[c]._2=i*2+1;    
   c=c+1;    
      
   }

   //Colores a las caras
	colors_random();
}

//************************************************************************
// práctica 3, objeto jerárquico articulado
//************************************************************************

//************************************************************************
// piezas
//************************************************************************

//************************************************************************
// cabeza
//************************************************************************
_cabeza::_cabeza()
{
	ancho=0.4;
	alto=0.4;
	fondo=0.55;
	cubo.colors_chess(1.0,0.5,0.0,1.0,0.35,0.0);
};

void _cabeza::draw(_modo modo, float r, float g, float b, float grosor)
{
	glPushMatrix();
	glScalef(ancho, alto, fondo);
	cubo.draw(modo, r, g, b, grosor);
	glPopMatrix();
};

//************************************************************************
// cuerpo
//************************************************************************

_cuerpo::_cuerpo()
{
	ancho=0.9;
	alto=0.4;
	fondo=0.5;
	cubo.colors_chess(1.0,0.5,0.0,1.0,0.35,0.0);
};

void _cuerpo::draw(_modo modo, float r, float g, float b, float grosor)
{
	glPushMatrix();
	glScalef(ancho, alto, fondo);
	cubo.draw(modo, r, g, b, grosor);
	glPopMatrix();
};

//************************************************************************
// pata
//************************************************************************

_pata::_pata()
{
	ancho=0.1;
	alto=0.25;
	fondo=0.1;
	cubo.colors_chess(1.0,0.5,0.0,1.0,0.35,0.0);
};

void _pata::draw(_modo modo, float r, float g, float b, float grosor)
{
	glPushMatrix();
	glScalef(ancho, alto, fondo);
	glTranslatef(0.5,0,0);
	cubo.draw(modo, r, g, b, grosor);
	glPopMatrix();
};

//************************************************************************
// oreja
//************************************************************************
_oreja::_oreja()
{
	ancho=0.1;
	alto=0.1;
	fondo=0.1;
	piramide.colors_chess(1.0,0.5,0.0,1.0,0.35,0.0);
};

void _oreja::draw(_modo modo, float r, float g, float b, float grosor)
{
	glPushMatrix();
	glScalef(ancho, alto, fondo);
	piramide.draw(modo, r, g, b, grosor);
	glPopMatrix();
};

//************************************************************************
// Hocico
//************************************************************************
_hocico::_hocico()
{
	ancho=0.1;
	alto=0.1;
	fondo=0.25;
	cubo.colors_chess(0.0,0.0,0.0,0.0,0.0,0.0);
};

void _hocico::draw(_modo modo, float r, float g, float b, float grosor)
{
	glPushMatrix();
	glScalef(ancho, alto, fondo);
	cubo.draw(modo, r, g, b, grosor);
	glPopMatrix();
};

//************************************************************************
// Cola
//************************************************************************

_cola::_cola()
{
alto=0.25;
radio=0.1;
cilindro.colors_chess(1.0,0.5,0.0,1.0,0.35,0.0);
};

void _cola::draw(_modo modo, float r, float g, float b, float grosor)
{
glPushMatrix();
glRotatef(90,0,0,1);
glScalef(radio, alto, radio);
cilindro.draw(modo, r, g, b, grosor);
glPopMatrix();

};

//************************************************************************
// Ojo
//************************************************************************

_ojo::_ojo()
{
radio=0.04;
esfera.colors_chess(1.0,1.0,1.0,1.0,1.0,1.0);
};

void _ojo::draw(_modo modo, float r, float g, float b, float grosor)
{
glPushMatrix();
glScalef(radio, radio, radio);
esfera.draw(modo, r, g, b, grosor);
glPopMatrix();

};

//************************************************************************
// Ojo
//************************************************************************

_pupila::_pupila()
{
radio=0.02;
esfera.colors_chess(0.0,0.0,0.0,0.0,0.0,0.0);
};

void _pupila::draw(_modo modo, float r, float g, float b, float grosor)
{
glPushMatrix();
glScalef(radio, radio, radio);
esfera.draw(modo, r, g, b, grosor);
glPopMatrix();

};

//************************************************************************
// zorro (montaje del objeto final)
//************************************************************************

_zorro::_zorro()
{
	giro_cuerpo = 0.0;
	giro_cuerpo_max = 45;
	giro_cuerpo_min = 0;

	giro_cabeza = 0.0;
	giro_cabeza_max = 0;
	giro_cabeza_min = -45;
	giro_cabeza_horizontal = 0.0;
	giro_cabeza_horizontal_max = 67;
	giro_cabeza_horizontal_min = -67;

	giro_oreja = 0.0;
	giro_oreja_max = 0;
	giro_oreja_min = -45;

	giro_patas_traseras = 0.0;
	giro_patas_traseras_max = 45;
	giro_patas_traseras_min = -90;

	giro_patas_delanteras = 0.0;
	giro_patas_delanteras_max = 45;
	giro_patas_delanteras_min = -90;

	giro_cola = 0.0;
	giro_cola_max = +45;
	giro_cola_min = -45;
};


void _zorro::draw(_modo modo, float r, float g, float b, float grosor)
{
//Todo el cuerpo
glPushMatrix();
	glRotatef(giro_cuerpo,0,0,1);
	cuerpo.draw(modo, r, g, b, grosor);

	//Cabeza
	glPushMatrix();
		glTranslatef((cabeza.ancho+cuerpo.ancho)/2.0,-(cabeza.alto+cuerpo.alto)/12.0,0);
		glRotatef(giro_cabeza,0,0,1);
		glRotatef(giro_cabeza_horizontal,0,1,0);
		cabeza.draw(modo, r, g, b, grosor);

		glPushMatrix();
			glTranslatef(cabeza.ancho/2.0,0,cabeza.ancho/2.0);
			ojo.draw(modo, r, g, b, grosor);
			glTranslatef(0,0,-cabeza.ancho+ojo.radio/2.0);
			ojo.draw(modo, r, g, b, grosor);
      glTranslatef(ojo.radio/2.0+pupila.radio/2.0,0,0);
      pupila.draw(modo, r, g, b, grosor);
      glTranslatef(0,0,+cabeza.ancho-ojo.radio/2.0);
      pupila.draw(modo, r, g, b, grosor);
		glPopMatrix();

		glTranslatef(cabeza.ancho/2.0+hocico.ancho/2.0,-cabeza.alto/2.0+hocico.alto/2.0,0);
		hocico.draw(modo, r, g, b, grosor);

		glTranslatef(-hocico.ancho,cabeza.alto-oreja.alto/2.0,-cabeza.fondo/2 + oreja.fondo);
		glRotatef(giro_oreja,0,0,1);
		oreja.draw(modo, r, g, b, grosor);
		glTranslatef(0,0,hocico.fondo+oreja.fondo);
		oreja.draw(modo, r, g, b, grosor);

	glPopMatrix();

	//Patas traseras
	glPushMatrix();
		glTranslatef(-cuerpo.ancho/2 + pata.ancho,(-cuerpo.alto/2.0),cuerpo.fondo/2 - pata.fondo);
		glRotatef(giro_patas_traseras,0,0,1);
		pata.draw(modo, r, g, b, grosor);
		glTranslatef(0, 0,-(pata.fondo+cuerpo.fondo/2.0)+pata.fondo/2);
		pata.draw(modo, r, g, b, grosor);
	glPopMatrix();

	//Patas delanteras
	glPushMatrix();
		glTranslatef(cuerpo.ancho/2 - 2*pata.ancho,-cuerpo.alto/2.0,-cuerpo.fondo/2 + pata.fondo);
		glRotatef(giro_patas_delanteras,0,0,1);
		pata.draw(modo, r, g, b, grosor);

		glTranslatef(0,0,pata.fondo+cuerpo.fondo/2.0-pata.fondo/2);
		pata.draw(modo, r, g, b, grosor);
	glPopMatrix();

	//Cola
	glPushMatrix();
		glTranslatef(-cuerpo.ancho/2.0-cola.alto/2.0,0,0);
		glRotatef(giro_cola,0,1,0);
		cola.draw(modo, r, g, b, grosor);
	glPopMatrix();

glPopMatrix();



};

//************************************************************************
// Objeto examen
//************************************************************************

_objeto::_objeto()
{
giro_base2 = 0.0;
giro_cl1 = 0.0;
lado_c1=1.0;
lado_c2=0.5;
radio_cl1=0.15;
alt_cl1=0.35;
radio_cl2=0.1;
fondo_cl2=0.5;
base1.colors_chess(1.0,1.0,0.0,1.0,1.0,0.0);
base2.colors_chess(1.0,0.0,1.0,1.0,0.0,1.0);
pilar1.colors_chess(0.0,1.0,0.0,0.0,1.0,0.0);
cl2.colors_chess(1.0,0.0,0.0,1.0,0.0,0.0);
};

void _objeto::draw(_modo modo, float r, float g, float b, float grosor)
{
glPushMatrix();
  glTranslatef(0,lado_c1/2.0,0);
  glScalef(lado_c1, lado_c1, lado_c1);
  base1.draw(modo, r, g, b, grosor);
glPopMatrix();

glPushMatrix();
  glTranslatef(lado_c1/2.0,lado_c1+lado_c2/2.0,-lado_c1/2.0);
  glScalef(lado_c2, lado_c2, lado_c2);
  glRotatef(giro_base2,0,1,0);
  base2.draw(modo, r, g, b, grosor);

  glTranslatef(0,lado_c2+alt_cl1,0);
  glScalef(radio_cl1, alt_cl1, radio_cl1);
  glRotatef(giro_cl1,0,1,0);
  pilar1.draw(modo, r, g, b, grosor);
glPopMatrix();

glPushMatrix();
    glTranslatef(lado_c1/2.0,lado_c1+lado_c2/2.0+lado_c2+alt_cl1-fondo_cl2/2.0+radio_cl2,-lado_c1/2.0+fondo_cl2/2.2-radio_cl1/2.2);
    glRotatef(90,1,0,0);
    glScalef(radio_cl2, fondo_cl2/2.2, radio_cl2);
    cl2.draw(modo, r, g, b, grosor);
glPopMatrix();

/*
glPushMatrix();
glTranslatef(-2*ancho/6,-alto/2.0,0);
glRotatef(90,1,0,0);
glScalef(radio, fondo/2.2, radio);
rueda.draw(modo, r, g, b, grosor);
glPopMatrix();
/*
glPushMatrix();
glScalef(ancho, alto, fondo);
base.draw(modo, r, g, b, grosor);
glPopMatrix();*/
};