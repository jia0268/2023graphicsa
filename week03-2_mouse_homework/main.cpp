#include <GL/glut.h>
#include <stdio.h>
void display()
{
    glBegin(GL_POLYGON);
    glVertex2f(0.796,0.468);
    glVertex2f(0.660,0.412);
    glVertex2f(0.512,0.360);
    glVertex2f(0.612,0.176);
    glVertex2f(0.700,0.172);
    glVertex2f(0.732,0.216);
    glVertex2f(0.780,0.324);
    glVertex2f(0.900,0.428);
    glVertex2f(0.900,0.508);
    glVertex2f(0.880,0.552);
    glEnd();
	glutSwapBuffers();
}

void mouse(int button, int state, int x,int y)///小寫的
{
    float X = (x-250)/250.0;
    float Y =-(y-250)/250.0;///口訣:減一半、除一半、 y負號
    if(state==GLUT_DOWN){
        printf("    glVertex2f(%.3f,%.3f);\n", X, Y);
    }
}
int main(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(500,500);
    glutCreateWindow("week03");

	glutDisplayFunc(display);
    glutMouseFunc(mouse);///請mouse函式幫忙

	glutMainLoop();
}
