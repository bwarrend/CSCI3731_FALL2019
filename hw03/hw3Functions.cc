#include <cstdio>

unsigned char* imageDataToArray(char fileName[], int* width, int* height)
{   
    unsigned char* imageDataArray = new unsigned char[(*width * *height * 3)];
    FILE* imageFile = nullptr;
    char isP6[2];
    int colorsN = 0;

    imageFile = fopen(fileName, "r");

    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);
    //fclose(imageFile);


    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {
        printf("Name: \t%s\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n",fileName, isP6, *width, *height, colorsN);
        printf("Press Any Key to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");

        //FILE* imageFile = fopen(fileName, "r");

        fread(imageDataArray, sizeof(char), *width * *height, imageFile);
    
        fclose(imageFile);


        return imageDataArray;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        fclose(imageFile);
        return NULL;
    }                                                                                                                                                                                                                                                                                                                                                                        
}



void createImageCopy(unsigned char* imageDataArray, int length)
{
    
    FILE* copyImageFIle = fopen("copy.ppm", "w");

    //fwrite(imageDataArray, sizeof(char), length-100, copyImageFIle);
    
    fclose(copyImageFIle);
    
}