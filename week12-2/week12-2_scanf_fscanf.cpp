#include <stdio.h>
int main()
{
    FILE * fin = fopen("file.txt","r");
    ///前一個範例已經寫好檔了
    char line[100];
    fscanf(fin,"%s",line);
    printf("從file.txt 讀到了: %s\n",line);

    fscanf(fin,"%s",line);
    printf("從file.txt 讀到了: %s\n",line);
}
