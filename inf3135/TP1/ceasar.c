#include "ceasar.h"
#include "fileIO.h"
#include "CEASAR_str.h"
#include "decode.h"

int main (int argc, char **argv)
{
  int end_signal = EXIT_SUCCESS;
  long fileSizeIO;
  char *result;
  if (argc != 3)
  {
    printf("ERROR : arguments incorrect\n");
    end_signal = EXIT_FAILURE;
  }      
  else 
  {
    fileSizeIO = getFileSize(argv[1]);
    if (fileSizeIO == -1)
      end_signal = EXIT_FAILURE;
    else
    {
      CEASAR_str_t *fi = newCEASAR_str(fileSizeIO);
      CEASAR_str_t *fo = newCEASAR_str(fileSizeIO);

      if (fi == NULL || fo == NULL)
      {
        printf("ERROR : couldn't allocate memory\n");
        end_signal = EXIT_FAILURE;
      }
      else
      {
        initCEASAR_str(argv[1], "rb", fi);
        initCEASAR_str(argv[2], "wb", fo);

        write (decode(fi->string), fo);
        
        if(closeCeasar(fi) != 0 ||
          closeCeasar(fo) != 0)
        {
          printf("ERROR : failed to close the files");
          end_signal = EXIT_FAILURE;
        }
      }
    }
  }
  return end_signal;
}

int getFileSize (char *fileName)
{   
  int ret;
  FILE *file = fopen(fileName, "r");
  if(file == NULL)
  {
    printf("ERROR : no such file\n");
    ret = -1;
  }
  else 
  {
    fseek(file, 0L, SEEK_END);
    ret = ftell(file);
    fseek(file, 0L, SEEK_SET);
    fclose(file);
  }
  return ret;
}
