#include <GL/glut.h>

#include <stdlib.h>

int a,b,c;
a=1;
b=1;
c=1;

static void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* ecraser l'ecran */
    
    // creation d'un careaux
    glColor3d(a,b,c);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,-0.2);
    glVertex2f(-0.3,-0.8);
    glVertex2f(-0.7,-0.8);
    glVertex2f(-0.7,-0.2);
    glEnd();
    
    // creation feuilles
    glColor3d(b,a,c);
    glBegin(GL_POLYGON);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.9,-0.1);
    glVertex2f(0.7,0.1);
    glVertex2f(1,0.3);
    glVertex2f(0.47,0.7);
    glVertex2f(0,0.3);
    glVertex2f(0.3,0.1);
    glVertex2f(0.1,-0.1);
    glVertex2f(0.45,-0.4);
    glEnd();
    
    
    glutSwapBuffers();
    glFlush();
}

void clavier(unsigned char bouton, int x,int y){
     
     switch(bouton){
     case'a' : a=1; b=0; c=0 ; break;
     case'z' : a=0; b=1; c=0 ; break;
     case'e' : a=1; b=1; c=0 ; break;
     case'f' : a=0; b=1; c=1 ; break;
     }
      glutPostRedisplay();
}
    
    
    

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");
    glutDisplayFunc(display);
    glutKeyboardFunc(clavier);

    glClearColor(0.9,0.9,0.9,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();

    return EXIT_SUCCESS;
}

