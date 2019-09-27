#include <cstdio>

int** createImageDataArray2D( int* width, int* height)
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

        int length = *height * *width * 3;
        //Create an array of unsigned characters with the length we got above
        unsigned char* imageDataArrayFlatChar = new unsigned char[length];
        //fread fills the array with data it gets from the file in size char
        fread(imageDataArrayFlatChar, sizeof(char), length, imageFile);
        //always close
        fclose(imageFile);


        int wid = *width;
        int hei = *height;
        length = wid * hei;

        int imageDataArrayFlatInt[length];


        for(int i = 0; i < length; i++)
        {
            unsigned char* bytes = (unsigned char*)(&imageDataArrayFlatInt[i]);
            bytes[0] = 0;
            bytes[1] = imageDataArrayFlatChar[i*3];
            bytes[2] = imageDataArrayFlatChar[i*3+1];
            bytes[3] = imageDataArrayFlatChar[i*3+2];
        }



        int** imageDataArray2D = new int* [*height];
        imageDataArray2D[0] = new int[*width * *height];
        
        for(int j = 1; j < *height; ++j) 
        {
            imageDataArray2D[j] = imageDataArray2D[j-1] + *width;
        }


        for(int i = 0; i < *width * *height; ++i)
        {
            (*imageDataArray2D)[i] = imageDataArrayFlatInt[i];
        }
                

        return imageDataArray2D;
    }
    else
    {
        printf("\n!Invalid or corrupt header!\n");
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}

void writeCopyImage(int** imageDataArray2D, const int width, const int height, const char* fileName)
{

    int length = width * height;

    int imageDataArrayFlatInt[length];

    unsigned char imageDataArrayFlatChar[length*3];


    for(int i = 0; i < width * height; ++i)
    {
        imageDataArrayFlatInt[i] = (*imageDataArray2D)[i];   
    }


    for(int i = 0; i < length; i++)
    {
        unsigned char* bytes = (unsigned char*)(&imageDataArrayFlatInt[i]);
        imageDataArrayFlatChar[i*3] = bytes[1];
        imageDataArrayFlatChar[i*3+1] = bytes[2];
        imageDataArrayFlatChar[i*3+2] = bytes[3];
    }


    FILE* copyImageFile = fopen(fileName, "w");
    fprintf(copyImageFile, "P6\n%d %d\n255",width, height);

    fwrite(imageDataArrayFlatChar, sizeof(char),length*3, copyImageFile);

    fclose(copyImageFile);
    

}