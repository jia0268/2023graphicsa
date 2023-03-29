#include <opencv/highgui.h>

int main()
{
    IplImage * img = cvLoadImage ("柯南.jpg");
    cvShowImage ("week07",img);
    cvWaitKey(0);
}
