#include <cstdio>
#include <jpeglib.h>
#include <setjmp.h>


unsigned char* createImageDataArray(const char* fileName, int* width, int* height)
{
    FILE* imageFile;
    char isP6[2];
    int colorsN = 0;

    //Open the file
    imageFile = fopen(fileName, "rb");
    //Parse the header data
    fscanf(imageFile, "%s", isP6);
    fscanf(imageFile, "%d %d", width, height);
    fscanf(imageFile, "%d", &colorsN);

    //Big check to make sure we are indeed dealing with a PPM file
    if(isP6[0] == 'P' && isP6[1] == '6' && *width > 0 && *height > 0 && colorsN == 255)
    {   
        //Make sure the user is ready for what comes next
        printf("Name: \t%s\nStyle: \t%s\nSize: \t%dx%d\nColors: %d\n",fileName, isP6, *width, *height, colorsN);
        printf("Press <Enter> to proceed with copy...");
        getchar();
        printf("\e[1;1H\e[2J");
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
        return NULL;
    }                                                                                                                                                                                                                                                                                                              
}

write_JPEG_file (char* filename, int quality, unsigned char* image_buffer, int image_width, int image_height)
{
	

  struct jpeg_compress_struct cinfo;

  struct jpeg_error_mgr jerr;

  FILE * outfile;		
  JSAMPROW row_pointer[1];
  int row_stride;		


  cinfo.err = jpeg_std_error(&jerr);

  jpeg_create_compress(&cinfo);


  if ((outfile = fopen(filename, "wb")) == NULL) {
    fprintf(stderr, "can't open %s\n", filename);
    exit(1);
  }
  jpeg_stdio_dest(&cinfo, outfile);


  cinfo.image_width = image_width; 	/* image width and height, in pixels */
  cinfo.image_height = image_height;
  cinfo.input_components = 3;		/* # of color components per pixel */
  cinfo.in_color_space = JCS_RGB; 	/* colorspace of input image */


  jpeg_set_defaults(&cinfo);



  jpeg_set_quality(&cinfo, quality, TRUE /* limit to baseline-JPEG values */);



  jpeg_start_compress(&cinfo, TRUE);


  row_stride = image_width * 3;	/* JSAMPLEs per row in image_buffer */

  while (cinfo.next_scanline < cinfo.image_height) {

    row_pointer[0] = & image_buffer[cinfo.next_scanline * row_stride];
    (void) jpeg_write_scanlines(&cinfo, row_pointer, 1);
  }



  jpeg_finish_compress(&cinfo);

  fclose(outfile);


  jpeg_destroy_compress(&cinfo);


}


int main()

{
	


	return 0;

}

