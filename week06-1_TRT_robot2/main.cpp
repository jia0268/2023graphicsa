#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02,30,30);///�����ĵĈA��

    glPushMatrix();
        glTranslatef(0.4,0.5,0);   ///(3)���԰��֒쵽�κεط�
        glRotatef(angle,0,0,1);    ///(2)���D
        glTranslatef(0.46,-0.05,0);///(1)���D�ӵ����ģ��Ƅӵ����g
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01; ///�ѽǶ�++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week06");

    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
