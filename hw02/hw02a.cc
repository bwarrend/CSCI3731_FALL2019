#include <cstdio>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int counter;
  //Initialize the pointer our file.
  FILE* saveFile;
  //Does the file exist?
  if( (saveFile = fopen("savefile", "r")) == NULL)
  {
    //If it doesn't, let's create it and write a 1, because
    //this is our first time running the program. Close file.
    saveFile = fopen("savefile", "w");
    fprintf(saveFile, "1");
    fclose(saveFile);
  }
  //Read the file, keep reading until end of file is reached
  saveFile = fopen("savefile", "r");
  while(fscanf(saveFile, "%d", &counter) != EOF)
  {
    //Print the current counter to console.
    printf("%d\n", counter);
    //Increment the counter and close file.
    counter++;
    fclose(saveFile);
    //Open the file in w mode, which overwrites the data
    //that is currently there
    fopen("savefile", "w");
    fprintf(saveFile,"%d", counter);
    fclose(saveFile);
  }
  return 0;
}
