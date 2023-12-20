#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // only accept one command-line argument
    if (argc > 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    // open file name given by argv[1] for reading ("r")
    FILE *inptr = fopen(argv[1], "r");

    if (inptr == NULL)
    {
        printf("Could not open file\n");
        return 1;
    }

    char jpg_name[8];
    int jpg_count = 0;

#define BLOCK_SIZE 512
    uint8_t buffer[BLOCK_SIZE];

    // declaring a pointer to a output file and initializing it to NULL
    FILE *outptr = NULL;

    /**The fread function reads data from a file into a buffer. It takes four arguments:
     * a pointer to the buffer, the size of the items to read,the number of items to read, and a file pointer.
     * In this case, it's reading BLOCK_SIZE bytes at a time from the file.*/
    while (fread(buffer, 1, BLOCK_SIZE, inptr) == BLOCK_SIZE)
    {
        // check for JPEG Pattern
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if no jpg found close output file
            if (jpg_count > 0)
            {
                fclose(outptr);
            }
            /** create name for the new JPEG file. The %03d format specifier; counter will be printed as decimal number,
             * padded with zeroes to be three digits long for the file name*/
            sprintf(jpg_name, "%03d.jpg", jpg_count);
            outptr = fopen(jpg_name, "w");

            // increment count
            jpg_count++;
        }

        // check if file was opened successfully before trying to write to it
        if (outptr != NULL)
        {
            // writes one block of data from buffer to the file
            fwrite(buffer, BLOCK_SIZE, 1, outptr);
        }
    }

    // close the output file only if it has been opened
    if (outptr != NULL)
    {
        fclose(outptr);
    }

    // close input file
    fclose(inptr);

    return 0;
}