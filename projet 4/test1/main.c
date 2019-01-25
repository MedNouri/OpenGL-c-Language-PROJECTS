#include <GL/glut.h>

#include <stdlib.h>


static void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* ecraser l'ecran */
    glutSwapBuffers();
    glFlush();
}

void clavier(unsigned char bouton, int x,int y){
     
     switch(bouton){
     case'r' : glClearColor(1,0,0,1) ; break;
     case'v' : glClearColor(0,1,0,1) ; break;
     case'b' : glClearColor(0,0,1,1) ; break;
     case'j' : glClearColor(1,1,0,1) ; break;
     case'c' : glClearColor(0,1,1,1) ; break;
     case'n' : glClearColor(0,0,0,1) ; break;
     
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

    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();

    return EXIT_SUCCESS;
}

