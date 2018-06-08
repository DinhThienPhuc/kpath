#include <stdio.h>
#include <string.h>

#define NUMBERS_OF_LATTICES 14
#define BUF_SIZE 4096
#define Q_CHARACTER_NUMBER 161

int main()
{
    FILE *fp;
    int input = 100, counter = 0;
    char buf[BUF_SIZE], kpath[BUF_SIZE];
    const char *lattices[] = {
        "CUB\tCubic",                       // Perfect
        "FCC\tFace-centered Cubic",         // Perfect
        "BCC\tBody-centered Cubic",         // Perfect
        "TET\tTetragonal",                  // Perfect
        "BCT\tBody-centered Tetragonal",    //
        "ORC\tOrthorhombic",                // Perfect
        "ORCF\tFace-centered Orthorhombic", //
        "ORCI\tBody-centered Orthorhombic", //
        "ORCC\tC-centered Orthorhombic",    // Perfect
        "HEX\tHexagonal",                   // Perfect
        "RHL\tRhombohedral",                //
        "MCL\tMonoclinic",                  //
        "MCLC\tC-centered Monoclinic",      //
        "TRI\tTriclinic",                   //
    };
    const char *shortNames[] = {
        "cub",
        "fcc",
        "bcc",
        "tet",
        "bct",
        "orc",
        "orcf",
        "orci",
        "orcc",
        "hex",
        "rhl",
        "mcl",
        "mclc",
        "tri",
    };
    while(0 != input)
    {
        for (int i = 0; i < NUMBERS_OF_LATTICES; i++)
        {
            printf("%d: %s\n", i + 1, lattices[i]);
        }
        printf("\nSelect the number correspond with the lattice and press enter: ");
        scanf("%d", &input);
        if(0 == input)
        {
            break;
        }
        printf("\nCurrent lattice that is chosen: %s\n", lattices[input - 1]);
        if ((fp = fopen(shortNames[input - 1], "r")) == NULL)
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
    fclose(fp);
    printf("Goodbye! :>\n");
    return 0;
}