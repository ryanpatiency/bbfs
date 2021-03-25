#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num;
    FILE* fptr;

    // use appropriate location if you are using MacOS or Linux
    fptr = fopen("./bogus.txt", "r+");

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    char buf[100];
    while (1) {
        printf("Enter num: ");
        scanf("%d", &num);
        fprintf(fptr, "i set number %d\n", num);
        fflush(fptr);
        fseek(fptr, 0, SEEK_SET);
        fgets(buf, 100, fptr);
        printf("first line of the file: ");
        printf("%s\n", buf);
        fseek(fptr, 0, SEEK_SET);
    }
    fclose(fptr);

    return 0;
}