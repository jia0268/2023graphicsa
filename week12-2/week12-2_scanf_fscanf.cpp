#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt","r");
    ///�e�@�ӽd�Ҥw�g�g�n�ɤF
    char line[100];
    fscanf(fin,"%s",line);
    printf("�qfile.txt Ū��F: %s\n",line);

    fscanf(fin,"%s",line);
    printf("�qfile.txt Ū��F: %s\n",line);
}
