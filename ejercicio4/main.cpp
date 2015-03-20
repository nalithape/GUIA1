/* PROGRAMA CREADO POR LA BACHILLER MARIA TERESA MELENDEZ SERRANO , ESTUDIANTE DE LA
CARRERA DE INGENIERIA DE SISTEMAS EN LA UNIVERSIDAD DE EL SALVADOR, EL PRESENTE SCRIPT
MUESTRA UN CUBO CON SUS 6 DIFERENTES CARAS, LAS CUALES PUEDES GIRAR Y MOVER A TU ANTOJO
ADEMAS DE PODER MINIMIZAR O MAXIMIZAR SOBRE EL EJE Y */

#include <windows.h>//LIBRERIA QUE NOS SERVIRA PARA CORRER PROGRAMA EN WINDOWS
#include <stdio.h>// LIBRERIA QUE PERMITE LA UTILIZACION DE CODIGO EN C
#include <GL/glut.h>// LIBRERIA QUE NOS PERMITIRA LA UTILIZACION DE GL Y GLUT
#include <GL/gl.h>// LIBRERIA QUE NOS PERMITIRA UTILIZAR OPEN GL
#include <stdlib.h>//LIBRERIA QUE NOS PERMITE USAR EL CODIGO ASCII

//DECLARACION DE FUNCIONES Y VARIABLES LOCALES
void display();
void llavesespeciales();
void   gluLookAt();
void translate();
double rotary=0;
double rotarx=0;
double translateX=0;
double translateY=0;
double translateZ=0;
double ScalefY=1;
//----------------------------
// FUNCION DISPLAY, DONDE DIBUJAREMOS EL CUBO
void display()
{
  //  BORRA LA PANTALLA Y EL BUFFER DE Z
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

  // RESETEAMOS PARA QUE TODO NOS ESTE COMO SIN CAMBIOS
  glLoadIdentity();
glRotatef( rotarx, 1.0, 0.0, 0.0 );// NOS SERVORA PARA ROTAR EN EJE X
  glRotatef( rotary, 0.0, 1.0, 0.0 ); // NOS SERVIRA PARA ROTAR EN EJE Y
glTranslatef (translateX,0.0,0.0);// NOS SERVIRA PARA MOVERNOS EN EL EJE X
glTranslatef (0.0,translateY,0.0);// NOS SERVIRA PARA MOVERNOS EN EL EJE Y
glTranslatef (0.0,0.0,translateZ);// NOS SERVIRA PARA MOVERNOS EN EL EJE Z
glScalef( 1.0, ScalefY, 1.0 );// DONDE USAREMOS PARAPODER CAMBIAR DE TAMANO SOBRE EL EJE Y

  //DIBUJO DEL LADO FRONTAL DEL CUBO
  // LOS VALORES VIENEN DADO ASI: GLVERTEX3F(x,y,z) DANDO UN RANGO MAXIMO DE 1 Y MINIMO DE-1
  glBegin(GL_POLYGON);
  glColor3f(1.0, 1.0, 1.0 );//ESPECIFICAMOS CODIGO DE COLOR BLANCO PARA ESQUINA SUPERIOR IZQUIERDA
  glVertex3f( -0.5,  0.5, -0.5 );
  glColor3f( 1.0, 0.0, 0.0 );// ESPECIFICAMOS CODIGO DE COLOR ROJO PARA ESQUINA INFERIOR DERECHA
  glVertex3f(  0.5,  0.5, -0.5 );
  glColor3f( 0.0, 0.0, 1.0 );// ESPECIFICAMOS CODIGO COLOR AZUL PARA ESQUINA SUPERIOR DERECHA
  glVertex3f(  0.5, -0.5, -0.5 );
  glColor3f( 1.0, 0.90, 0.0 );// ESPECIFICAMOS CODIGO DE COLOR AMARILLO PARA ESQUINA INFERIOR IZQUIERDA
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  //DIBUJO DEL LADO SUPERIOR DEL CUBO
  glBegin(GL_POLYGON);
  glColor3f(   0.0,  0.0,  1.0 );// ESPECIFICAMOS CODIGO DE COLOR AZUL PARA TODA LA CARA
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.25, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
//DIBUJO DEL LADO TRACERO DEL CUBO
  glBegin(GL_POLYGON);// ESPECIFICAMOS CODIGO DE COLOR BLANCO PARA TODA LA CARA
  glColor3f(   1.0,  1.0, 1.0 );
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5 );
  glVertex3f( -0.5, -0.5, 0.5 );
  glEnd();

  //DIBUJO DEL LADO DERECHO DEL CUBO
  glBegin(GL_POLYGON);
  glColor3f(  0.0,  1.0, 0.0 );// ESPECIFICAMOS CODIGO DE COLOR VERDE PARA TODA LA CARA
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();

  //DIBUJO DEL LADO IZQUIERDO DEL CUBO
  glBegin(GL_POLYGON);// ESPECIFICAMOS CODIGO DE COLOR AMARILLO PARA TODA LA CARA
  glColor3f(   1.0,  1.0,  0.0 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
   //DIBUJO DEL LADO INFERIOR DEL CUBO
   glBegin(GL_POLYGON);// ESPECIFICAMOS CODIGO DE COLOR ROJO PARA TODA LA CARA
  glColor3f(   1.0,  0.0,  0.0 );
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();

  glFlush();
  glutSwapBuffers();// INTERCAMBIANDO BUFFER
}

// ----------------------------------------------------------
// LLAMANDO A FUNCION LLAVESESPECIALES, ESTA NOS PERMITIRA ASIGNAR A
// LAS TECLAS DIRECCIONALES UN EVENTO , EN ESTE CASO PROPORCIONAMOS EL ESPACIO QUE ROTARA EN EJE X Y Y
void llavesespeciales( int key, int x, int y ) {
  //  ABRIMOS UN IF PARA QUE INICIALIACE AL TECLEAR CADA UNA DE LAS DIRECCIONALES
  if (key == GLUT_KEY_RIGHT)
    rotary += 5;// ROTAMOS 5 GRADOS AL EJE Y POSITIVO, CON LA FECLA DERECHA
  else if (key == GLUT_KEY_LEFT)// ROTAMOS 5 GRADOS AL EJE Y NEGATIVO, CON LA FLECHA IZQUIERDA
    rotary -= 5;
  else if (key == GLUT_KEY_UP)// ROTAMOS 5 GRADOS AL EJE X POSITIVO, CON LA FLECHA ARRIBA
    rotarx += 5;
  else if (key == GLUT_KEY_DOWN)// ROTAMOS 5 GRADOS AL EJE X NEGATIVO CON LA FLECHA ABAJO
    rotarx -= 5;
  glutPostRedisplay();// ACTUALIZANDO VENTANA

}
//--------------------
// FUNCION TRANSLATE NOS PERMITIRA COLOCARLE UN EVENTO EN LAS TECLAS NORMALES DEL TECLADO, USANDO LAS
//LETRAS O EL CODIGO ASCII
void Translate(unsigned char key, int x, int y)
{
    //ABRIMOS UN SWITCH PARA PODER COLOCAR EVENTO EN CASO DE TECLEAR ALGUNO DE LAS LETRAS QUE SE MOSTRARA A CONTINUACION
    switch (key) {
            case 'X':translateX += 0.1;// AL TECLEAR X MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO X
                    break;
            case 'x':translateX -= 0.1;// AL TECLEAR X MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO X
                    break;
            case 'Y':translateY += 0.1;// AL TECLEAR Y MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO Y
                    break;
            case 'y':translateY -= 0.1;// AL TECLEAR y MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO y
                    break;
            case 'Z':translateZ += 0.1;// AL TECLEAR Z MAYUSCULA NOS PODREMOS MOVER EN EL EJE POSITIVO Z
                    break;
            case 'z':translateZ -= 0.1;// AL TECLEAR Z MINUSCULA NOS PODREMOS MOVER EN EL EJE NEGATIVO z
                    break;
            case 'S':ScalefY += 0.1;// AL TECLEAR S MAYUSCULA PODRMOS USAR GLSCALE EN EL EJE Y Y Y AGRANDARLO
                    break;
            case 's':ScalefY -= 0.1;// AL TECLEAR S MINUSCULA PODREMOS USAR GLSCALE EN ELE Y Y MINIMIZARLO
                    break;
            case 27: exit(0);// EN CODIGO ASCII 27 ES EL NUMERO QUE REPRESENTA A LA TECLA ESC
             break; // AL TECLEAR ESC SE CERRARA EL SCRIPT
    }
    glutPostRedisplay();//ACTUALIZANDO VENTANA
}
// ---------------------------------
// FUNCION PRINCIPAL MAIN
int main(int argc, char* argv[]){

  //INICIALIZANDO PARAMETROS DE GLUT
  glutInit(&argc,argv);

  //  SOLICITANDO COLOR ORIGINAL VENTANA
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

  // CREANDO VENTANA
  glutCreateWindow("CUBO MOVIL EN 3D");

  //  HABILITANDO Z-BUFFER
  glEnable(GL_DEPTH_TEST);

  // LLAMANDO A CADA UNA DE LAS FUNCIONES AGREGADAS
  glutDisplayFunc(display);// POR MEDIO DE GLUTDISPLAYFUN DIBUJAMOS EL CUBO
   glutSpecialFunc(llavesespeciales);// POR MEDIO DE GLUTSPECIALFUNC PODEMOS ASIGNAR EVENTOS A LAS TECLAS ESPECIALES
   glutKeyboardFunc(Translate);//POR MEDIO DE GLUTKEYBOARDFUNC SERVIRA PARA ASIGNAR EVENTOS A TECLAS NORMALES
  // PASANDO EL CONTROL DE EVENTOS AL GLUT
  glutMainLoop();
 // RETORNANDO AL SISTEMA OPERATIVO
  return 0;
}
