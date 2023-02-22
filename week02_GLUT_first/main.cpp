#include <GL/glut.h>
void display()
{
    ///glColor3f(0,1,0);///綠色
	///glutSolidTeapot(0.5);///畫出一個實心的茶壺，它的大小是0.5
    glBegin(GL_POLYGON);///開始畫出多邊形
        glColor3f(1,0,0);  glVertex2f( 0, 1);///紅色的頂點 Vertex
        glColor3f(0,1,0);  glVertex2f(-1,-1);///綠色的頂點 Vertex
        glColor3f(0,0,1);  glVertex2f(+1,-1);///藍色的頂點 Vertex
    glEnd();///結束畫

	glColor3f(1,1,0);///黃色
	glutSolidTeapot(0.3);///畫出一個實心的茶壺，它的大小是0.3
	glutSwapBuffers();///請GLUT把畫面swap送到顯示的地方
}
int main(int argc, char *argv[])
{ ///上面是特別的main函式,有很多參數
	glutInit(&argc, argv);///把GLUT開起來
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);///把顯示的模式設定好
	glutCreateWindow("GLUT Shapes");///要開視窗
	glutDisplayFunc(display);///要顯示的對應函式
	glutMainLoop();///最後用main迴圈,壓在最後面
}
