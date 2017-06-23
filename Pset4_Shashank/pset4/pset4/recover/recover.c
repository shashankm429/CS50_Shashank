#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <cs50.h>
typedef uint8_t BYTE;
int main()
{
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open file card.raw .\n");
        return 1;
    }
    BYTE buffer[512];
    FILE* img = NULL;
    int fileCount = 0;
    char title[8];
    while(fread(buffer, 512, 1, inptr))
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
        {
            if (img != NULL)
            {
                fclose(img);
            }
            sprintf(title,"%03d.jpg", fileCount);
            fileCount++;
            img = fopen(title, "w");
        }
        if (img != NULL)
        {
            fwrite(buffer, 512, 1, img);
        }
    }
    if (img != NULL)
    {
        fclose(img);
    }
    fclose(inptr);
    return 0;
}
