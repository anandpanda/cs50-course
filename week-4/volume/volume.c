#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

void copy_header(FILE *input, FILE *output);
void process_samples(FILE *input, FILE *output, float factor);

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file
    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        fclose(input);
        printf("Could not open output file.\n");
        return 1;
    }

    // Determine scaling factor
    float factor = atof(argv[3]);

    // Copy header from input file to output file
    copy_header(input, output);

    // Read samples from input file and write updated data to output file
    process_samples(input, output, factor);

    // Close files
    fclose(input);
    fclose(output);

    return 0;
}

void copy_header(FILE *input, FILE *output)
{
    uint8_t header[HEADER_SIZE];
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);
}

void process_samples(FILE *input, FILE *output, float factor)
{
    int16_t buffer;
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
}
