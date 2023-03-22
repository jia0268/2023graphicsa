#include <GL/glut.h>
float angle = 0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

    glutSolidSphere(0.02,30,30);///正中心的圓球

    glutSolidTeapot(0.3);///身體

    glPushMatrix();///右手臂
        ///先註解掉 glTranslatef(0.4,0.5,0);   ///(3)可以把手掛到任何地方
        glTranslatef(0.49,0.12,0); ///新的
        glRotatef(angle,0,0,1);    ///(2)旋轉
        glTranslatef(0.46,-0.05,0);///(1)把轉動的中心，移動到中間
        glutSolidTeapot(0.3);

        glPushMatrix();///右手肘
            glTranslatef(0.49,0.12,0); ///新的
            glRotatef(angle,0,0,1);    ///(2)旋轉
            glTranslatef(0.46,-0.05,0);///(1)把轉動的中心，移動到中間
            glutSolidTeapot(0.3);
        glPopMatrix();

    glPopMatrix();

    glutSwapBuffers();
    angle+=0.01; ///把角度++
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
