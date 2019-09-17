#include <cstdio>

int headerReader(char fileName[], int* width, int* height)
{
    FILE* imageFile = nullptr;
    char isP6[2];
    int colorsN = 0;

    imageFile = fopen(fileName, "r");

    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);
    fclose(imageFile);

    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {
        printf("Name: \t%s\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n",fileName, isP6, *width, *height, colorsN);
        printf("Press Any Key to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");
        return 1;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return 0;
    }                                                                                                                                                                                                                                                                                                                                                                        
}


unsigned char* imageDataToArray(char fileName[], int length)
{
    unsigned char* imageDataArray = new unsigned char[length];
    
    FILE* imageFile = fopen(fileName, "r");
    

    //for(int i = 0; i < length; i++)
    //{

        fread(imageDataArray, sizeof(char), length, imageFile);

    //}
    
    fclose(imageFile);


    //PRINT IT
    for(int i = 0; i < length; i++)
    {
        printf("\n%c", imageDataArray[i]);
    }

    return imageDataArray;
}
