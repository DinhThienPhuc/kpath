#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUMBERS_OF_LATTICES 14
#define BUF_SIZE 4096
#define Q_CHARACTER_NUMBER 161

int main()
{
    FILE *fp;
    int input = 100, counter = 0;
    char buf[BUF_SIZE], kpath[BUF_SIZE];
    const char *lattices[] = {
        "CUB - Cubic",                       // Perfect
        "FCC - Face-centered Cubic",         // Perfect
        "BCC - Body-centered Cubic",         // Perfect
        "TET - Tetragonal",                  // Perfect
        "BCT - Body-centered Tetragonal",    //
        "ORC - Orthorhombic",                // Perfect
        "ORCF - Face-centered Orthorhombic", //
        "ORCI - Body-centered Orthorhombic", //
        "ORCC - C-centered Orthorhombic",    // Perfect
        "HEX - Hexagonal",                   // Perfect
        "RHL - Rhombohedral",                //
        "MCL - Monoclinic",                  //
        "MCLC - C-centered Monoclinic",      //
        "TRI - Triclinic",                   //
    };
    const char *shortNames[] = {
        "lattices/cub",
        "lattices/fcc",
        "lattices/bcc",
        "lattices/tet",
        "lattices/bct",
        "lattices/orc",
        "lattices/orcf",
        "lattices/orci",
        "lattices/orcc",
        "lattices/hex",
        "lattices/rhl",
        "lattices/mcl",
        "lattices/mclc",
        "lattices/tri",
    };
    while (0 != input)
    {
        const char *fname = shortNames[input - 1];

        for (int i = 0; i < NUMBERS_OF_LATTICES; i++)
        {
            printf("%d: %s\n", i + 1, lattices[i]);
        }
        printf("\nSelect the number correspond with the lattice and press enter. Hit 0 to quit: ");
        scanf("%d", &input);
        if (input <= 0 || input > NUMBERS_OF_LATTICES)
        {
            // fclose(fp);
            if (fp)
            {
                fclose(fp);
            }
            printf("Goodbye! :>\n");
            return 0;
        }
        printf("\nCurrent lattice that is chosen: %s\n", lattices[input - 1]);
        if ((fp = fopen(fname, "r")) == NULL)
        {
            perror("Open file: ");
            return 1;
        }
        printf("\n----------------------------------------------\n");
        while (fgets(buf, sizeof(buf), fp) != NULL)
        {
            buf[strlen(buf)] = '\0';
            printf("%s", buf);
            counter++;
        }
        printf("\n----------------------------------------------\n");
    }

    return 0;
}