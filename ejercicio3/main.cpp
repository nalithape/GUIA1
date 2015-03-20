/* PROGRAMA REALIZADO POR LA BACHILLER MARIA TERESA MELENDEZ SERRANO ,
 ESTUDIANTE DE LA UNIVERSIDAD DE EL SALVADOR , ESTE SCRIPT
PRETENDE DIBUJAR UNA FIGURA GEOMETRIA, UTILIZANDO CUADROS Y TRIANGULOS*/

//LIBRERIAS A UTILIZAR
#include <windows.h>// PERMITIRA USAR GLUT EN WINDOWS
#include <GL/gl.h>// PERMITIRA USAR OPEN GL
#include <GL/glut.h>// PERMITIRA USAR GLUT
void cuadro(void)// CREACION DE FUNCION CUADRO PARA CREACION DE FIGURA
{
	glClear (GL_COLOR_BUFFER_BIT);// LIMPIANDO COLOR DE PANTALLA
	glColor3f (0, 0, 0.5);// DAMOS COLOR AZUL OSCURO AL RECTANGULO
	glBegin(GL_QUADS);//DIBUJAMOS CUADRO
	glVertex2d (-0.5, 0.25);
	glVertex2d (0.5,0.25);
    glVertex2d (0.5,-0.25);
	glVertex2d (-0.5,-0.25);

	glEnd();

		glColor3f (0, 1, 0.5);// DAMOS COLOR CELESTE AL CUADRADO
	glBegin(GL_QUADS);//DIBUJAMOS CUADRO
	glVertex2d (-0.60, 0.2);
	glVertex2d (-0.5,0.2);
    glVertex2d (-0.5,0.05);
    glVertex2d (-0.60,0.05);

	glEnd();

	glColor3f (0, 1, 0.5);//DAMOS COLOR CELESTE ALCUADRADO
	glBegin(GL_QUADS);//DIBUJAMOS CUADRO
	glVertex2d (-0.65, -0.2);
	glVertex2d (-0.5,-0.2);
    glVertex2d (-0.5,-0.05);
    glVertex2d (-0.65,-0.05);

	glEnd();

		glColor3f (1,0.7, 0);// DAMOS COLOR AMARILO AL TRIANGULO
	glBegin(GL_TRIANGLES);//DIBUJAMOS TRIANGULO
	glVertex2d (0, 0.8);
	glVertex2d (-0.25,0.25);
    glVertex2d (0.25,0.25);
	glEnd();

glColor3f (1.0, 1.0,1);// DAMOS COLOR BLANCO AL TRIANGULO
	glBegin(GL_TRIANGLES);// DIBUJAMOS TRIANGULO
	glVertex2d (-0.25,0.25);
    glVertex2d (0, 0.8);
    glVertex2d (-.50, 0.8);
	glEnd();

		glColor3f (1,0.7, 0);//DAMOS COLOR AMARILLO AL TRIANGLO
	glBegin(GL_TRIANGLES);//DIBUJAMOS TRIANGULO
	glVertex2d (0, -0.8);
	glVertex2d (-0.25,-0.25);
    glVertex2d (0.25,-0.25);
	glEnd();

glColor3f (1.0, 1.0,1);//DAMOS COLOR BLANCO AL TRIANGULO
	glBegin(GL_TRIANGLES);//DIBUJAMOS TRIANGULO
	glVertex2d (-0.25,-0.25);
    glVertex2d (0, -0.8);
    glVertex2d (-.50, -0.8);
	glEnd();

	glColor3f (0, 1.0, 0);//DAMOS COLOR VERDE AL TRIANGULO
	glBegin(GL_TRIANGLES);//DIBUJAMOS TRIANGULO
	glVertex2d (0.8, 0);
	glVertex2d (0.5,0.3);
    glVertex2d (0.5,-0.3);

	glEnd();

	glFlush();//REFORZAMOS COLOR


}



int main(int argc, char** argv)
{
	glutInit (&argc, argv);//INICIAMOS GLUT
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(750,500); // Tamaño de la ventana
	glutInitWindowPosition(250,250); // posicion de la ventana
	glutCreateWindow("figura 1"); // Mombre de la ventana
	glutDisplayFunc(cuadro); //llamas a la funcion display
	glutMainLoop(); // enalce entre la funcion y el programa principal
	return 0;
}
