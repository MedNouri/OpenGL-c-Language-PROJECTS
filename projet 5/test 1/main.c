
#include <GL/glut.h>

#include <stdlib.h>

float d=-0.3,e=-0.8;


static void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* ecraser l'ecran */
    
    
    
    // creation d'un careaux
    glColor3d(0,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(d,d+0.3);
    glVertex2f(d,e);
    glVertex2f(e+0.3,e);
    glVertex2f(e+0.3,d+0.3);
    glEnd();

    
    
    glutSwapBuffers();
    glFlush();
}



void special(int bouton,int x,int y){
     
     switch(bouton){
     case GLUT_KEY_UP    : d=d+0.1; e=e+0.1 ; break;
     case GLUT_KEY_DOWN  : d=d-0.1; e=e-0.1 ; break;
     case GLUT_KEY_LEFT  : d=d-0.1; e=e+0.1 ; break;
     case GLUT_KEY_RIGHT : d=d+0.1; e=e-0.1 ; break;
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
    glutSpecialFunc(special);
    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();

    return EXIT_SUCCESS;
}
