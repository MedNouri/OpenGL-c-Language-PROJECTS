
#include <GL/glut.h>

#include <stdlib.h>

static int slices = 16;
static int stacks = 16;

/* GLUT callback Handlers */

static void 
resize(int width, int height)
{
    const float ar = (float) width / (float) height;
    
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void 
display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    
// cube kbir
glColor3d(1,0.7,0.4);
glPushMatrix();
        glTranslated(2,0,-8);
        glRotated(0,0,0,0);
        glRotated(0,0,0,1);
        glutSolidCube(3.2);
    glPopMatrix();

glPushMatrix();
        glTranslated(3.5,-0.8,-8);
        glRotated(0,0,0,0);
        glRotated(0,0,0,1);
        glutSolidCube(1.5);
    glPopMatrix();
    
// fenetre
glColor3d(45,82,62);
glPushMatrix();
        glTranslated(1,0.6,-6);
        glRotated(0,0,0,0);
        glRotated(0,0,0,0);
        glutSolidCube(0.8);
    glPopMatrix();


glPushMatrix();
        glTranslated(2.5,0.6,-6);
        glRotated(0,0,0,0);
        glRotated(0,0,0,0);
        glutSolidCube(0.8);
    glPopMatrix();



// place
glColor3d(1,0.7,0.4);
glPushMatrix();
        glTranslated(0.5,0,-8);
        glRotated(0,0,0,0);
        glRotated(45,0,0,1);
        glutSolidCube(2);
    glPopMatrix();
// moteur

glPushMatrix();
        glTranslated(-0.56,-0.75,-8);
        glRotated(0,0,0,0);
        glRotated(0,0,0,1);
        glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
        glTranslated(-1,-0.75,-8);
        glRotated(0,0,0,0);
        glRotated(0,0,0,1);
        glutSolidCube(2);
    glPopMatrix();

// fnar
glColor3d(45,82,62);
glPushMatrix();
        glTranslated(-1.8,-0.5,-6);
        glRotated(60,1,0,0);
        glRotated(0,0,0,1);
        glutSolidSphere(0.3,slices,stacks);
    glPopMatrix();

// rout
glColor3d(0,0,0);
    glPushMatrix();
        glTranslated(3,-1.9,-7.5);
        glRotated(0,0,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

// rout 
glPushMatrix();
        glTranslated(-0.5,-1.9,-7.5);
        glRotated(0,0,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();




    glutSwapBuffers();
}


static void 
key(unsigned char key, int x, int y)
{
    switch (key) 
    {
        case 27 : 
        case 'q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices>3 && stacks>3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

static void 
idle(void)
{
    glutPostRedisplay();
}
/*
const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int 
main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("FreeGLUT Shapes");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
/*
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);*/

    glutMainLoop();

    return EXIT_SUCCESS;
}

