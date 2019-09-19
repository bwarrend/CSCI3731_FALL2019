#include <cstdio>

unsigned char* createImageDataArray(char fileName[], int* width, int* height)
{
    FILE* imageFile = nullptr;
    char isP6[2];
    int colorsN = 0;

    imageFile = fopen(fileName, "r");

    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);


    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {
        printf("Name: \t%s\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n",fileName, isP6, *width, *height, colorsN);
        printf("Press <Enter> to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");

        int length = *height * *width * 3;
        unsigned char* imageDataArray = new unsigned char[length];
        fread(imageDataArray, sizeof(char), length, imageFile);
        fclose(imageFile);


        

        return imageDataArray;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                                                                                        
}

void createImageCopy(unsigned char* imageDataArray, int* width, int* height)
{
    int length = *height * *width * 3;
    FILE* copyImageFile = fopen("copy.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255",*width, *height);
    fwrite(imageDataArray, sizeof(char), length, copyImageFile);
    fclose(copyImageFile);
    
}

void blueify(unsigned char* imageDataArray, int* width, int* height)
{
    int length = *height * *width * 3;
    FILE* copyImageFile = fopen("copy_blue.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255\n",*width, *height);
    
    
    for(int i = 0; i < length; i++)
    {
        fprintf(copyImageFile, "%c", imageDataArray[i]);
        i++;
        fprintf(copyImageFile, "%c", imageDataArray[i]);
        i++;
        fprintf(copyImageFile, "%c", 255);
    }

    fclose(copyImageFile);
}

void greenify(unsigned char* imageDataArray, int* width, int* height)
{
    int length = *height * *width * 3;
    FILE* copyImageFile = fopen("copy_green.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255\n",*width, *height);
    
    
    for(int i = 0; i < length; i++)
    {
        fprintf(copyImageFile, "%c", imageDataArray[i]);
        i++;
        fprintf(copyImageFile, "%c", 255);
        i++;
        fprintf(copyImageFile, "%c", imageDataArray[i]);
    }

    fclose(copyImageFile);
}

void redify(unsigned char* imageDataArray, int* width, int* height)
{
    int length = *height * *width * 3;
    FILE* copyImageFile = fopen("copy_red.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255\n",*width, *height);
    
    
    for(int i = 0; i < length; i++)
    {
        fprintf(copyImageFile, "%c", 255);
        i++;
        fprintf(copyImageFile, "%c", imageDataArray[i]);
        i++;
        fprintf(copyImageFile, "%c", imageDataArray[i]);
    }

    fclose(copyImageFile);
}

void greyScale(unsigned char* imageDataArray, int* width, int* height)
{
    int length = *height * *width * 3;
    FILE* copyImageFile = fopen("copy_grey.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255\n",*width, *height);

    for(int i = 0; i < length; i++)
    {
        int mean = 0;
        mean += imageDataArray[i];
        mean += imageDataArray[i+1];
        mean += imageDataArray[i+2];

        mean /= 3;
        
        fprintf(copyImageFile, "%c", mean);
        i++;
        fprintf(copyImageFile, "%c", mean);
        i++;
        fprintf(copyImageFile, "%c", mean);
    }

    fclose(copyImageFile);
    
}