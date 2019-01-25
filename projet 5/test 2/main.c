
#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>

float a=0; 
float b=0; 
int cas=1;

static void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* ecraser l'ecran */
    
    

    

    // creation d'un careaux
    glColor3d(-a,b,0);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0.1,0);
    glVertex2f(0.1,-0.1);
    glVertex2f(0,-0.1);
    glEnd();


glPushMatrix();
glTranslatef(cos(a),sin(b),0);   
    // creation d'un careaux
    glColor3d(a,0,a);
    glBegin(GL_POLYGON);
    glVertex2f(0,0);
    glVertex2f(0.1,0);
    glVertex2f(0.1,-0.1);
    glVertex2f(0,-0.1);
    glEnd();
glPopMatrix();
   
    glutSwapBuffers();
    glFlush();
}



void special(int bouton,int x,int y){
     
if(b>3.1){cas=-cas;} 
if(b<0){cas=-cas;} 

     if(bouton==GLUT_KEY_LEFT){              
      if(cas==1){
       a=a+0.1;
       b=b+0.1;
      }else 
      if(cas==-1){
       a=a-0.1;
       b=b-0.1;
      }
     }
     
     
     if(bouton==GLUT_KEY_RIGHT){ 
      if(cas==-1){
       a=a+0.1;
       b=b+0.1;
      }else 
      if(cas==1){
       a=a-0.1;
       b=b-0.1;
      }
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
