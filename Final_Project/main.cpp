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
int show[4]={0,0,1,0};
int ID=2;///0:�Y 1:���� 2:���W���u 3:�k�W���u
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
}///�U���ª������ѱ�
FILE * fin= NULL;///�@�}�l�ɮרS�}�ANULL
FILE * fout = NULL;///�nŪ�ɮץΪ����СA�@�}�l�]�ONULL
float teapotX=0,teapotY=0;///�ݲ��ʭ�
float angle=0,angle2=0,angle3=0;///�\�ʧ@
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
        if(ID==0)glColor3f(1,0,0);///��w��,�]����
        else glColor3f(1,1,1);///�S��w,�]�զ�
        if(show[0])glmDraw(head, GLM_MATERIAL);

        if(ID==1)glColor3f(1,0,0);///��w��,�]����
        else glColor3f(1,1,1);///�S��w,�]�զ�
        if(show[1])glmDraw(body, GLM_MATERIAL);

        glPushMatrix();

            ///glTranslatef(-teapotX,-teapotY,0);
            ///glRotatef(angle,0,0,1);///TRT�إX��
            glTranslatef(teapotX,teapotY,0);

            if(ID==2)glColor3f(1,0,0);///��w��,�]����
            else glColor3f(1,1,1);///�S��w,�]�զ�
            if(show[2])glmDraw(leftarm, GLM_MATERIAL);
        glPopMatrix();

        if(ID==3)glColor3f(1,0,0);///��w��,�]����
        else glColor3f(1,1,1);///�S��w,�]�զ�
        if(show[3])glmDraw(rightarm, GLM_MATERIAL);
    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);///��Ӥp�����b������,��Ѧ��I
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
