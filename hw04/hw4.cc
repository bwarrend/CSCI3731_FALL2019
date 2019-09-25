#include <cstdio>
#include "hw4Functions.h"

int** createFlatArray( int* width, int* height)
{
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;

    //Open the file
    imageFile = fopen("test.ppm", "rb");
    //Parse the header data
    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);

    //Big check to make sure we are indeed dealing with a PPM file
    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {   
        //Make sure the user is ready for what comes next
        printf("Name: \ttest.ppm\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n", isP6, *width, *height, colorsN);
        printf("Press <Enter> to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");
        //Set the array length, height x width x 3
        int length = *height * *width;
        //Create an array of unsigned characters with the length we got above
        int* imageDataArray = new int[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArray, sizeof(int), length, imageFile);
        //always close
        fclose(imageFile);

        int** array = new int*[height];
        array[0] = new int[width * height];

        for(int j = 1; j < height; ++j)
        {
            array[j] = array[j-1] + width;
        }

        delete []imageDataArray;
        imageDataArray = NULL;

        return imageDataArray;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}




int main(int argc, char** argv)
{

    int* imageDataArray;
    int width = 0, height = 0;

    imageDataArray = createFlatArray(&width, &height);


    for(int i = 0; i < width*height; ++i)
    {   
        unsigned char* bytes = (unsigned char*)(&imageDataArray[i]);
        printf("%d %d %d %d\n", bytes[0], bytes[1], bytes[2], bytes[3]);
    }






    /*
    int** array = new int*[height];
    imageDataArray[0] = new int[width*height];

    for(int j=1; j<height; ++j)
    {
        imageDataArray[j] = imageDataArray[ j-1] + width;
    }
    */













    return 0;
}
