///��Z�S�D
#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///�屳��

    glColor3f( 0, 1, 0 ); ///�Gɫ��
    glPushMatrix();
        glTranslatef( 0.8, 0, 0 ); ///�����ǾGɫ���Ƅ�
        glRotatef(angle, 0, 0, 1); ///�Č�Z�S�D
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glColor3f( 1, 0, 0 ); ///�tɫ��
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); ///�Č�Z�S�D ///�����Ǽtɫ�D��
        glTranslatef( 0.8, 0, 0 );
        glutSolidTeapot( 0.3 );
    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01; ///�ѽǶ�++
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week05");

    glutDisplayFunc(display);
    glutIdleFunc(display);///�п�idle�r,���خ�����
    glutMainLoop();
}
