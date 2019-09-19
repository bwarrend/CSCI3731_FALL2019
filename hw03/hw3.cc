#include <cstdio>
#include "hw3Functions.h"


int main(int argc, char** argv)
{
    printf("\e[1;1H\e[2J");
    printf("\n****PPM Image Copier****\n");

    char* fileName = nullptr;
    FILE* imageFile = nullptr;
    int width = 0;
    int height = 0;

    if(argc == 2)
    {
        fileName = argv[1];

        if( (imageFile = fopen(fileName, "r")) != NULL)
        {

            createImageCopy(createImageDataArray(fileName, &width, &height), &width, &height);
            printf("Image copied successfully! (I hope)\n");
            printf("Press <Enter> to exit\n");
            getchar();
            printf("\e[1;1H\e[2J");

            
        }
        else
        {
            printf("File '%s' does not exist or otherwise cannot be opened.\n", fileName);
        }
    }
    else
    {
        printf("Invalid console argument provided. Try ./hw3 FILENAME\n");    
    }


    



    return 0;
}