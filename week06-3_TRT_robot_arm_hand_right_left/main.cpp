///����������w���ֱ�
#include <GL/glut.h>
float angle = 0;
void drawHand()
{
    glPushMatrix();
        glScalef(1,0.3,0.3);
        glutSolidCube(0.5);
    glPopMatrix();
}
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///�屳��

        glPushMatrix();
            glTranslatef(0.25,0,0); ///(3)����ȥ
            glRotatef(angle,0,0,1);    ///(2)�D��
            glTranslatef(0.25,0,0); ///(1)�����D���ģ��ŵ����g
            ///��ǰ���TRT���_
            drawHand();///�����ֱ�

            glPushMatrix();
                glTranslatef(0.25,0,0); ///(3)����ȥ
                glRotatef(angle,0,0,1); ///(2)�D��
                glTranslatef(0.25,0,0); ///(1)�����D���ģ��ŵ����g
                drawHand();///��������
            glPopMatrix();

        glPopMatrix();

        glPushMatrix();
            glTranslatef(-0.25,0,0); ///(3)����ȥ
            glRotatef(angle,0,0,1);    ///(2)�D��
            glTranslatef(-0.25,0,0); ///(1)�����D���ģ��ŵ����g
            ///��ǰ���TRT���_
            drawHand();///�����ֱ�

            glPushMatrix();
                glTranslatef(-0.25,0,0); ///(3)����ȥ
                glRotatef(angle,0,0,1); ///(2)�D��
                glTranslatef(-0.25,0,0); ///(1)�����D���ģ��ŵ����g
                drawHand();///��������
            glPopMatrix();

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
