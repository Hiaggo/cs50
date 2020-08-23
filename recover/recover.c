#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Checks if the user wrote the name of the file
    if (argc < 2)
    {
        printf("Usage : recover\n");
        return 1;
    }

    FILE *fp = fopen(argv[1], "r");

    // If it couldn't open the file, or the file doesn't exist, it'll return a NULL pointer
    if (!fp)
    {
        return 1;
    }

    BYTE buffer[512];
    char filename[8]; // 8 memory positions because of the seven characters plus the '\0' character
    int i = 0; // Counter of files
    FILE *img = NULL;

    // While fread returns 1 (number of blocks that we want to look at) the loop continues
    while (fread(buffer, 512, 1, fp) == 1)
    {
        // Checks if it's the header of a jpg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && ((buffer[3] & 0xf0) == 0xe0))
        {

            // Checks if there is no image
            if (!img)
            {
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                i++;
            }

            else
            {
                fclose(img);
                sprintf(filename, "%03i.jpg", i);
                img = fopen(filename, "w");
                fwrite(buffer, 512, 1, img);
                i++;
            }

        }

        // Since the header wasn't found, it checks if there's an open image
        else if (img)
        {
            fwrite(buffer, 512, 1, img);
        }
    }

    // Closes all the files
    fclose(img);
    fclose(fp);
    return 0;
}
