#include <cstdio>
#include "hw4Functions.h"

unsigned char* createFlatArray( int* width, int* height)
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
        //printf("Name: \ttest.ppm\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n", isP6, *width, *height, colorsN);
        //printf("Press <Enter> to proceed with copy...");
        //getchar();
        //printf("\e[1;1H\e[2J");
        //Set the array length, height x width x 3
        int length = *height * *width * 3;
        //Create an array of unsigned characters with the length we got above
        unsigned char* imageDataArray = new unsigned char[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArray, sizeof(char), length, imageFile);
        //always close
        fclose(imageFile);
        
        /*
        
        int w = *width;
        int h = *height;
        int** array = new int*[h];
        array[0] = new int[w * h];

        for(int j = 1; j < h; ++j)
        {
            array[j] = array[j-1] + w;
        }

        */        

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
    unsigned char* imageDataArray;
    int width = 0, height = 0;

    imageDataArray = createFlatArray(&width, &height);
    int length = width * height;
    int intArray[length];
    
    
    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(&intArray[i]);
        bytes[0] = 0;
        bytes[1] = imageDataArray[i*3];
        bytes[2] = imageDataArray[i*3+1];
        bytes[3] = imageDataArray[i*3+2];
    }


    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(&intArray[i]);
        imageDataArray[i*3] = bytes[1];
        imageDataArray[i*3+1] = bytes[2];
        imageDataArray[i*3+2] = bytes[3];
    }
    


    FILE* copyImageFile = fopen("copy.ppm", "w");
    fprintf(copyImageFile, "P6\n%d %d\n255",width, height);
    


    fwrite(imageDataArray, sizeof(char),length*3, copyImageFile);

    delete []imageDataArray;
    imageDataArray = NULL;

    fclose(copyImageFile);

	//just commit




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
