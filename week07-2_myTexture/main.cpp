#include <opencv/highgui.h> ///ʹ�� OpenCV 2.1 ���^����, ֻҪ�� High GUI ����
#include <opencv/cv.h>
#include <GL/glut.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV�x�D
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV�Dɫ�� (��Ҫcv.h)
    glEnable(GL_TEXTURE_2D); ///1. �_���N�D����
    GLuint id; ///�ʂ�һ�� unsigned int ����, �� �N�DID
    glGenTextures(1, &id); /// �a��Generate �N�DID
    glBindTexture(GL_TEXTURE_2D, id); ///����bind �N�DID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �N�D����, ���^���b�Ĺ��DT, ���ظ��N�D
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �N�D����, ���^���b�Ĺ��DS, ���ظ��N�D
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �N�D����, �Ŵ�r�ăȲ�, ������c
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �N�D����, �sС�r�ăȲ�, ������c
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    ///glutSolidTeapot( 0.3 );
    glBegin( GL_POLYGON );
        glTexCoord2f(0,0); glVertex2f(-1,+1);
        glTexCoord2f(1,0); glVertex2f(+1,+1);
        glTexCoord2f(1,1); glVertex2f(+1,-1);
        glTexCoord2f(0,1); glVertex2f(-1,-1);
    glEnd();
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week09 texture");

    glutDisplayFunc(display);
    myTexture("earth.jpg");

    glutMainLoop();
}