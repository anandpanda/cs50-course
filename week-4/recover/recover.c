#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 512
typedef uint8_t BYTE;

void checkFile(FILE *file, const char *filename)
{
    if (file == NULL)
    {
        fprintf(stderr, "Could not open file: %s\n", filename);
        exit(1);
    }
}

int isJPEG(BYTE buffer[])
{
    return buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
           (buffer[3] & 0xf0) == 0xe0;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        exit(1);
    }

    FILE *raw = fopen(argv[1], "r");
    checkFile(raw, argv[1]);

    BYTE buffer[BLOCK_SIZE];
    FILE *img = NULL;
    int counter = 0;

    while (fread(buffer, BLOCK_SIZE, 1, raw) == 1)
    {
        if (isJPEG(buffer))
        {
            if (img != NULL)
                fclose(img);

            char filename[8];
            sprintf(filename, "%03i.jpg", counter++);
            img = fopen(filename, "w");
            checkFile(img, filename);
        }

        if (img != NULL)
            fwrite(buffer, BLOCK_SIZE, 1, img);
    }

    if (img != NULL)
        fclose(img);

    fclose(raw);

    return 0;
}
