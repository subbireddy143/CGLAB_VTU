#include<stdio.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void wall(double thickess)
{
    glTranslated(0.5,0,0.5);
    glScaled(1,thickess,1);
    glutSolidCube(1);
}

void tableleg(double thick,double len )
{
    glPushMatrix();
    glTranslated(0,len/2,0);
    glScaled(thick,len,thick);
    glutSolidCube(1.0);
    glPopMatrix();

}

void table(double topwid,double topthick,double legthick,double leglen)
{
    glPushMatrix();
    glTranslated(0,leglen,0);
    glScaled(topwid,topthick,topwid);
    glutSolidCube(1.0);
    glPopMatrix();

    double dist=0.95*topwid/2.0-legthick/2.0;

    glPushMatrix();
    glTranslated(dist,0,dist);
    tableleg(legthick,leglen);

    glTranslated(0,0,-2*dist);
    tableleg(legthick,leglen);

    glTranslated(-2*dist,0,2*dist);
    tableleg(legthick,leglen);

    glTranslated(0,0,-2*dist);
    tableleg(legthick,leglen);

    glPopMatrix();
}

void display()
{
     GLfloat mat_amb[] = {1.0f,0.0f,1.0f,1.0f};
     GLfloat mat_diff[] = {1.0f,1.0f,1.0f,1.0f};
     GLfloat mat_spec[] = {1.0f,1.0f,1.0f,1.0f};
     GLfloat mat_shine[] = {50.0f};

     glMaterialfv(GL_FRONT,GL_AMBIENT,mat_amb);
     glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diff);
     glMaterialfv(GL_FRONT,GL_SPECULAR,mat_spec);
     glMaterialfv(GL_FRONT,GL_SHININESS,mat_shine);

     GLfloat lightintensity[]={0.7f,0.7f,0.7f,1.0f};
     GLfloat lightposition[]={2.0f,6.0f,3.0f,0.0f};

     glLightfv(GL_LIGHT0,GL_POSITION,lightposition);
     glLightfv(GL_LIGHT0,GL_DIFFUSE,lightintensity);

     glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     glOrtho(-1,1,-1,1,1,10);
     glMatrixMode(GL_MODELVIEW);
     gluLookAt(2,1,2,0,0,0,0,1,0);


     glPushMatrix();
     glTranslated(0.4,0.4,0.4);
     glutSolidTeapot(0.1);
     glPopMatrix();

     glPushMatrix();
     glTranslated(0.4,0,0.4);
     table(0.6,0.07,0.06,0.3);
     glPopMatrix();

     glPushMatrix();
     glRotated(90,0,0,1);
     wall(0.02);
     glPopMatrix();

     glPushMatrix();
     glRotated(-90,1,0,0);
     wall(0.02);
     glPopMatrix();

     glPushMatrix();
     wall(0.02);
     glPopMatrix();

     glFlush();
}


int main(int argc,char **argv)
{
     glutInit(&argc,argv);
     glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
     glutInitWindowSize(500,500);

     glutCreateWindow("LAB06 - KALLURU SUBBI REDDY");
     glutDisplayFunc(display);

     glEnable(GL_LIGHTING);
     glEnable(GL_LIGHT0);
     glEnable(GL_NORMALIZE);
     glEnable(GL_DEPTH_TEST);

     glutMainLoop();
}
