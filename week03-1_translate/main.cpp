#include <GL/glut.h>
float X=0, Y=0;///�Q�� global �ܼ�, �A�禡�����ǭ� (�j�g��)
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );///�M�I��
    glPushMatrix();///�ƥ��x�}
        glTranslatef( X, Y, 0 );///�u���o��?�٤���
        glutSolidTeapot(0.3);
    glPopMatrix();///�٭�x�}
	glutSwapBuffers();
}
///#include <stdio.h>
void mouse(int button, int state, int x,int y)///�p�g��
{ ///��mouse�禡����
    X = (x-150)/150.0;
    Y =-(y-150)/150.0;///�f�Z:��@�b�B���@�b�B y�t��
    ///printf("%d %d %d %d\n",button, state, x, y);
    /// button ���� �k�䵥, state ���U�h�O0 ��_�ӬO1
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");

	glutDisplayFunc(display);
    glutMouseFunc(mouse);///��mouse�禡����

	glutMainLoop();
}
