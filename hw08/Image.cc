#include <iostream>
#include "Image.h"
#include <jpeglib.h>
#include <cstdio>
#include <cstdlib>




Image::Image() {
    width = -1;
    height = -1;
    imageDataArray = nullptr;
    std::cout << "Made an image obj" << std::endl;
}


void Image::createImageDataArray(const char* fileName){
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;


    if( (imageFile = fopen(fileName, "rb")) != nullptr){
        std::cout << "image exists: " << fileName << std::endl;    
        //Open the file
        imageFile = fopen(fileName, "rb");
        //Parse the header data
        fscanf(imageFile, "%s", isP6);
        fscanf(imageFile, "%d %d", &width, &height);
        fscanf(imageFile, "%d\n", &colorsN);
        std::cout << "Got image info" << width << " x " << height << " -- " << colorsN << std::endl;

        //Big check to make sure we are indeed dealing with a PPM file
        if(isP6[0] == 'P' && isP6[1] == '6' && width > 0 && height > 0 && colorsN == 255){
            std::cout << "yes it's a ppm" << std::endl; 
        
            //Set the array length, height x width x 3
            int length = height * width * 3;
            imageDataArray = new unsigned char[length];
            std::cout << "length  =   " << length << std::endl;
            //fread fills the array with data it gets from the file in size char
            fread(imageDataArray, sizeof(char), length, imageFile);
            std::cout << "Read the file with fread" << std::endl;
            //always close
            fclose(imageFile);    

        }else{
            printf("\n!Invalid or corrupt header!\n");
            fclose(imageFile);
        }
    }else{
        printf("Cannot find file: '%s'\n", fileName);
       //exit(1);
    }                                                                                                                                                                                                                                                                                                            
}

//Function to write a jpeg
//
void Image::write_JPEG_file (const char* filename, int quality)/*, unsigned char* image_buffer, int image_width, int image_height)*/{
    //Create the required structs cinfo and jerr
    //
	struct jpeg_compress_struct cinfo;
	struct jpeg_error_mgr jerr;

	FILE * outfile;		
	JSAMPROW row_pointer[1];
	int row_stride;		

	cinfo.err = jpeg_std_error(&jerr);

	jpeg_create_compress(&cinfo);

    //Check if we can open the file with the given filename
    //
	if ((outfile = fopen(filename, "wb")) == NULL) 
	{

        fprintf(stderr, "can't open %s\n", filename);
        exit(1);
	
	}

    //Set up the cinfo struct with width, height, amount of components and
    // an enum that we are setting to JCS_RGB
    //
	jpeg_stdio_dest(&cinfo, outfile);

	cinfo.image_width = width;
	cinfo.image_height = height;
	cinfo.input_components = 3;
	cinfo.in_color_space = JCS_RGB;

	jpeg_set_defaults(&cinfo);
	jpeg_set_quality(&cinfo, quality, TRUE);
	jpeg_start_compress(&cinfo, TRUE);

    //Set the length and write to the file
    //
	row_stride = width * 3;

	while (cinfo.next_scanline < cinfo.image_height) 
	{

        row_pointer[0] = & imageDataArray[cinfo.next_scanline * row_stride];
        (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
        
	}

    //Finish the job
    //
	jpeg_finish_compress(&cinfo);

	fclose(outfile);
	jpeg_destroy_compress(&cinfo);
    
}

Image::~Image(){
    delete[] imageDataArray;
    imageDataArray = nullptr;
}