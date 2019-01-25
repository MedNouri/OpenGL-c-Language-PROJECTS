/*
 * FreeGLUT Shapes Demo
 *
 * Written by Nigel Stewart November 2003
 *
 * This program is test harness for the sphere, cone 
 * and torus shapes in FreeGLUT.
 *
 * Spinning wireframe and smooth shaded shapes are
 * displayed until the ESC or q key is pressed.  The
 * number of geometry stacks and slices can be adjusted
 * using the + and - keys.
 */

#include <GL/glut.h>

#include <stdlib.h>



/* GLUT callback Handlers */


void Ecrire_chaine(char *s,int x,int y)
	{
	int longueur=strlen(s),i;
	glRasterPos2i(x,y);
	for(i=0;i<longueur;i++)	
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,s[i]);
		
	}

static void 

display(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glColor3d(0.8,0.5,0.3);
   /* //dessin 
    glBegin(GL_POINTS);
    glPointSize(3.0);
    glVertex2f(0.5,0);
    glEnd();*/
 
 


//moraabé3
glBegin(GL_POLYGON);
glVertex2f(-0.8, -0.2);
glVertex2f(-0.8, -0.9);
glVertex2f(-0.3, -0.9); 
glVertex2f(-0.3, -0.2);
glEnd();

//trin
glColor3d(1,0,0.3);
Ecrire_chaine("maison",0.8,0.8);
glBegin(GL_POLYGON);
glVertex2f(-0.9, -0.2);
glVertex2f(-0.55, 0.3); 
glVertex2f(-0.2, -0.2);

glEnd();

//Bebe
 glColor3d(0,0,0);   
glBegin(GL_LINE_STRIP);
glVertex2f(-0.65, -0.9);
glVertex2f(-0.65, -0.5);
glVertex2f(-0.45, -0.5);
glVertex2f(-0.45, -0.9); 
glEnd();    

//loutani
 glColor3d(0,0,0);   
glBegin(GL_LINE_STRIP);
glVertex2f(-0.9, -0.9);
glVertex2f(0.9, -0.9);
glEnd();    

//chojra
 glColor3d(0.2,0.8,0.3);
glBegin(GL_POLYGON);
glVertex2f(0.37, -0.4);//p1
glVertex2f(0.1, -0.2);//p2
glVertex2f(0.3, -0.15); //p3
glVertex2f(0, 0);//p4
glVertex2f(0.4, 0.2);//P5
glVertex2f(0.8, 0);//P6
glVertex2f(0.5, -0.15);//P7
glVertex2f(0.7, -0.2);//P8
glVertex2f(0.43, -0.4);

glEnd();

//gith3on
 glColor3d(1,0.5,0);
glBegin(GL_POLYGON);
glVertex2f(0.37, -0.4);
glVertex2f(0.35, -0.9);
glVertex2f(0.45, -0.9); 
glVertex2f(0.43, -0.4);
glEnd();


  glutSwapBuffers();
}



int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");

    
    glutDisplayFunc(display);
    
   

    glClearColor(1,1,1,0);
   
    glutMainLoop();

    return EXIT_SUCCESS;
}

