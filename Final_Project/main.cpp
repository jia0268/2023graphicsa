#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel * head = NULL;
GLMmodel * body = NULL;
GLMmodel * leftarm = NULL;
GLMmodel * rightarm = NULL;
GLMmodel * lefthand = NULL;
GLMmodel * righthand = NULL;
GLMmodel * leftleg = NULL;
GLMmodel * rightleg = NULL;
GLMmodel * leftlowleg = NULL;
GLMmodel * rightlowleg = NULL;
GLMmodel * leftlowarm = NULL;
GLMmodel * rightlowarm = NULL;
GLMmodel * leftshoe = NULL;
GLMmodel * rightshoe = NULL;
int show[5]={1,1,1,1,1};
int ID=2;///0:頭 1:身體 2:右上手臂 3:右下手臂
void keyboard(unsigned char key,int x,int y)
{
    if(key=='0') ID=0;
    if(key=='1') ID=1;
    if(key=='2') ID=2;
    if(key=='3') ID=3;
    ///if(key=='0') show[0] = !show[0];
    ///if(key=='1') show[1] = !show[1];
    ///if(key=='2') show[2] = !show[2];
    ///if(key=='3') show[3] = !show[3];
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
            rightarm = glmReadOBJ("model/rightarm.obj");
            rightlowarm = glmReadOBJ("model/rightlowarm.obj");
            righthand = glmReadOBJ("model/righthand.obj");
            ///glmUnitize(body);
        }
        if(ID==0)glColor3f(1,0,0);///選定的,設紅色
        else glColor3f(1,1,1);///沒選定,設白色
        if(show[0])glmDraw(head, GLM_MATERIAL);

        if(ID==1)glColor3f(1,0,0);///選定的,設紅色
        else glColor3f(1,1,1);///沒選定,設白色
        if(show[1])glmDraw(body, GLM_MATERIAL);

        glPushMatrix();

            glTranslatef(-1.226666,0.373333,0);///反過來
            ///glTranslatef(-teapotX,-teapotY,0);///TRT建出來
            glRotatef(angle,0,0,1);///TRT建出來
            ///glTranslatef(teapotX,teapotY,0);///TRT建出來
            glTranslatef(1.226666,-0.373333,0);

            if(ID==2)glColor3f(1,0,0);///選定的,設紅色
            else glColor3f(1,1,1);///沒選定,設白色
            if(show[2])glmDraw(rightarm, GLM_MATERIAL);
            glPushMatrix();

                ///glTranslatef(teapotX,teapotY,0);
                glTranslatef(-1.973332,0.133333,0);
                glRotatef(angle,0,0,1);
                glTranslatef(1.973332,-0.133333,0);

                if(ID==3)glColor3f(1,0,0);///選定的,設紅色
                else glColor3f(1,1,1);///沒選定,設白色
                if(show[3])glmDraw(rightlowarm, GLM_MATERIAL);
                glPushMatrix();

                    ///glTranslatef(teapotX,teapotY,0);
                    glTranslatef(-2.453331,-0.779999,0);
                    glRotatef(angle,0,0,1);
                    glTranslatef(2.453331,0.779999,0);
                    if(ID==4)glColor3f(1,0,0);///選定的,設紅色
                    else glColor3f(1,1,1);///沒選定,設白色
                    if(show[4])glmDraw(righthand, GLM_MATERIAL);
                glPopMatrix();
            glPopMatrix();
        glPopMatrix();

        //if(ID==3)glColor3f(1,0,0);///選定的,設紅色
        //else glColor3f(1,1,1);///沒選定,設白色
        //if(show[3])glmDraw(rightlowarm, GLM_MATERIAL);
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);///放個小茶壺在正中心,當參考點
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void motion(int x, int y)
{
    teapotX += (x - oldX)/150.0;
    teapotY -= (y - oldY)/150.0;
    oldX = x;
    oldY = y;
    angle = x;
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
