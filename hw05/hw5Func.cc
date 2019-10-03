#include <cstdio>
#include <cstdlib>
#include <jpeglib.h>

void clearArray(unsigned char* deleteMe)
{
    delete[] deleteMe;
    deleteMe = NULL;
}
unsigned char* createImageDataArray(const char* fileName, int* width, int* height)
{
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;


    if( (imageFile = fopen(fileName, "rb")) != NULL)
    {      
        //Open the file
        imageFile = fopen(fileName, "rb");
        //Parse the header data
        fscanf(imageFile, "%s", isP6);
        fscanf(imageFile, "%d %d", width, height);
        fscanf(imageFile, "%d\n", &colorsN);

        //Big check to make sure we are indeed dealing with a PPM file
        if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
        {   
        
            //Set the array length, height x width x 3
            int length = *height * *width * 3;
            //Create an array of unsigned characters with the length we got above
            unsigned char* imageDataArray = new unsigned char[length];
            //fread fills the array with data it gets from the file in size char
            fread(imageDataArray, sizeof(char), length, imageFile);
            //always close
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
    else
    {
        printf("Cannot find file: '%s'\n", fileName);
        exit(1);
    }                                                                                                                                                                                                                                                                                                            
}

void write_JPEG_file (const char* filename, int quality, unsigned char* image_buffer, int image_width, int image_height)
{
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	FILE * outfile;		
	JSAMPROW row_pointer[1];
	int row_stride;		

	cinfo.err = jpeg_std_error(&jerr);

	jpeg_create_compress(&cinfo);


	if ((outfile = fopen(filename, "wb")) == NULL) 
	{

        fprintf(stderr, "can't open %s\n", filename);
        exit(1);
	
	}

	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = image_width;
	cinfo.image_height = image_height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);
	jpeg_start_compress(&cinfo, TRUE);

	row_stride = image_width * 3;

	while (cinfo.next_scanline < cinfo.image_height) 
	{

        row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
        
	}

	jpeg_finish_compress(&cinfo);

	fclose(outfile);
	jpeg_destroy_compress(&cinfo);
    
}

unsigned char* blueify(unsigned char* imageDataArray, int width, int height)
{
    int length = height * width * 3;
    unsigned char* blueArray = new unsigned char[length];
       
    
    for(int i = 0; i < length; i++)
    {
        blueArray[i] = imageDataArray[i];
        i++;
        blueArray[i] = imageDataArray[i];
        i++;
        blueArray[i] = 255;
    }

    return blueArray;
}


unsigned char* redify(unsigned char* imageDataArray, int width, int height)
{
    int length = height * width * 3;
    unsigned char* redArray = new unsigned char[length];
       
    
    for(int i = 0; i < length; i++)
    {
        redArray[i] = 255;
        i++;
        redArray[i] = imageDataArray[i];
        i++;
        redArray[i] = imageDataArray[i];
    }

    return redArray;
}

unsigned char* greenify(unsigned char* imageDataArray, int width, int height)
{
    int length = height * width * 3;
    unsigned char* greenArray = new unsigned char[length];
       
    
    for(int i = 0; i < length; i++)
    {
        greenArray[i] = imageDataArray[i];
        i++;
        greenArray[i] = 255;
        i++;
        greenArray[i] = imageDataArray[i];
    }

    return greenArray;
}

unsigned char* greyScale(unsigned char* imageDataArray, int width, int height)
{
    int length = height * width * 3;
    unsigned char* greyArray = new unsigned char[length];

    for(int i = 0; i < length; i++)
    {
        int mean = 0;
        mean += imageDataArray[i];
        mean += imageDataArray[i+1];
        mean += imageDataArray[i+2];

        mean /= 3;
        
        greyArray[i] = mean;
        i++;
        greyArray[i] = mean;
        i++;
        greyArray[i] = mean;
    }

    return greyArray;
    
}