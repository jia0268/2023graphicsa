#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * leftarm = NULL;
GLMmodel * rightarm = NULL;
GLMmodel * lefthand = NULL;
GLMmodel * righhand = NULL;
GLMmodel * leftleg = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * leftlowleg = NULL;
GLMmodel * rightlowleg = NULL;
GLMmodel * leftlowarm = NULL;
GLMmodel * rightlowarm = NULL;
GLMmodel * leftshoe = NULL;
GLMmodel * rightshoe = NULL;
int show[4]={0,1,0,0}; ///用 show[i] 來決定要不要顯示
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') show[0] = !show[0];
    if(key=='1') show[1] = !show[1];
    if(key=='2') show[2] = !show[2];
    if(key=='3') show[3] = !show[3];
    glutPostRedisplay();
}///下面舊的先註解掉
FILE * fin= NULL;///一開始檔案沒開，NULL
FILE * fout = NULL;///要讀檔案用的指標，一開始也是NULL
float teapotX=0,teapotY=0;///看移動值
float angle=0,angle2=0,angle3=0;///擺動作
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(0.2,0.2,0.2);
        if(body==NULL){
            head = glmReadOBJ("model/head.obj");
            body = glmReadOBJ("model/body.obj");
            leftarm = glmReadOBJ("model/leftarm.obj");
            rightarm = glmReadOBJ("model/rightarm.obj");
            ///glmUnitize(body);
        }
        if(show[0])glmDraw(head, GLM_MATERIAL);
        if(show[1])glmDraw(body, GLM_MATERIAL);
        glPushMatrix();
            glTranslated(teapotX,teapotY,0);
            if(show[2])glmDraw(leftarm, GLM_MATERIAL);
        glPopMatrix();
        if(show[3])glmDraw(rightarm, GLM_MATERIAL);
    glPopMatrix();
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    glutPostRedisplay();
}
void mouse(int button,int state, int x, int y)
{
    if(state==GLUT_DOWN){
        oldX = x;
        oldY = y;
        angle = x;
        ///teapotX = (x-150)/150.0;
        ///teapotY = (150-y)/150.0;
        ///if(fout==NULL) fout = fopen("file4.txt","w");
        ///fprintf(fout, " %f %f\n", teapotX, teapotY);
    }
    display();
}
//void keyboard(unsigned char key, int x,int y)
//{
//    if(fin==NULL){
//        fclose(fout);
//        fin = fopen("file4.txt","r");
//    }
//    fscanf(fin, "%f %f", &teapotX,&teapotY);
//    display();
//}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week12");

    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);
    glutKeyboardFunc(keyboard);

    glutMainLoop();
}
