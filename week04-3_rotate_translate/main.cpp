#include <GL/glut.h>
float angle = 0;///宣告 global 全域變數 angle
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); ///清背景
    glPushMatrix(); ///備份矩陣
        glTranslatef( 0.6, 0, 0);///新加的程式碼
        glRotatef(angle, 0, 1, 0);///旋轉 angle 角度
        glColor3f(1,1,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣
    glPushMatrix(); ///備份矩陣
        glRotatef(angle, 0, 1, 0);///旋轉 angle 角度
        glTranslatef( 0.6, 0, 0);///新加的程式碼
        glColor3f(1,0,0);
        glutSolidTeapot( 0.3 );
    glPopMatrix(); ///還原矩陣
    glutSwapBuffers();
    angle++;
}
int main(int argc, char* argv[] )
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04");

    glutDisplayFunc(display);
    glutIdleFunc(display);///有空idle時,就重畫畫面
    glutMainLoop();
}
