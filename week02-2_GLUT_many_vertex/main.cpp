#include <GL/glut.h>
void myVertex(float x, float y)
{
    glVertex2f( (x-100)/100.0, -(y-100)/100.0 );
}
void display()
{
    glColor3f(247/255.0,247/255.0,247/255.0);
    glBegin(GL_POLYGON);///�}�l�e�I��
        glVertex2f( 1, 1);
        glVertex2f(-1, 1);
        glVertex2f(-1,-1);
        glVertex2f( 1,-1);
    glEnd();///�����e

    glColor3f(244/255.0,209/255.0,33/255.0);
    glBegin(GL_POLYGON);///�}�l�e�֥d�C�{�l
        myVertex(45,134);///glVertex2f( (45-100)/100.0, -(134-100)/100.0 );
        myVertex(36,171);///glVertex2f( (36-100)/100.0, -(171-100)/100.0 );
        myVertex(108,179);///glVertex2f( (108-100)/100.0, -(179-100)/100.0 );
        myVertex(104,117);///glVertex2f( (104-100)/100.0, -(117-100)/100.0 );
        ///�f�Z�G��@�b�B���@�b�By�ܭt��
    glEnd();///�����e

	glutSwapBuffers();///��GLUT��e��swap�e����ܪ��a��
}
int main(int argc, char *argv[])
{ ///�W���O�S�O��main�禡,���ܦh�Ѽ�
	glutInit(&argc, argv);///��GLUT�}�_��
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///����ܪ��Ҧ��]�w�n
	glutCreateWindow("GLUT Shapes");///�n�}����
	glutDisplayFunc(display);///�n��ܪ������禡
	glutMainLoop();///�̫��main�j��,���b�̫᭱
}
