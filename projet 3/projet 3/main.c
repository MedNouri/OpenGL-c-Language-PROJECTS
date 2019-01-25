#include <GL/glut.h>

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;


static void 
display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); /* ecraser l'ecran */
    
    
    /* 
       pour la creation des objets : 
       GL_LINES,GL_POINTS....
       pour la modification des outils :
       glPointSize(10),glLineWidht(10);
    */


//***************************cration maison*************************************
  
// creation du ligne bas
    glColor3d(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.9,-0.9);
    glVertex2f(0.9,-0.9);
    glEnd();



// creation d'un PORTE
    glColor3d(0,0,0); 
    glBegin(GL_LINES);
    glVertex2f(-0.4,-0.8);
    glVertex2f(-0.4,-0.5);
    
    glVertex2f(-0.4,-0.5);
    glVertex2f(-0.6,-0.5);
    
    glVertex2f(-0.6,-0.5);
    glVertex2f(-0.6,-0.8);
    glEnd();



// creation d'un triangle
    glColor3d(0.5,0.5,0.5);
    glBegin(GL_POLYGON);
    glVertex2f(-0.25,-0.2);
    glVertex2f(-0.5,0.05);
    glVertex2f(-0.75,-0.2);
    glEnd();



// creation d'un carro
    glColor3d(1,0.93,0.93);
    glBegin(GL_POLYGON);
    glVertex2f(-0.3,-0.2);
    glVertex2f(-0.3,-0.8);
    glVertex2f(-0.7,-0.8);
    glVertex2f(-0.7,-0.2);
    glEnd();

//*****************************fin maison***************************************

//******************************cation arbre************************************



// creation d'un tronc
    glColor3d(1,0.5,0);
    glBegin(GL_POLYGON);
    glVertex2f(0.4,-0.8);
    glVertex2f(0.55,-0.8);
    glVertex2f(0.5,-0.4);
    glVertex2f(0.45,-0.4);
    glEnd();



// creation feille
    glColor3d(0,1,0);
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



//*****************************fin arbre***************************************



/*
    glPushMatrix();               // deplacer l'objet
    glTranslated(-0.5,-0.2,0);    // choisir la position à deplacer
    // creation d'un polygone
    glBegin(GL_POLYGON);
    glVertex2f(0.3,0);
    glVertex2f(0,0.3);
    glVertex2f(-0.3,0);
    glEnd();
    glPopMatrix();                // deplacer l'objet

*/
    
    
    
    

    


    glutSwapBuffers();
    glFlush();
}

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");

    //glutReshapeFunc(resize);
    glutDisplayFunc(display);
   
   // glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glutMainLoop();

    return EXIT_SUCCESS;
}

