#include "CEASAR_str.h"

CEASAR_str_t *newCEASAR_str(long size)
{
  CEASAR_str_t *ret = malloc(sizeof(CEASAR_str_t));
  
  if(ret == NULL)
    return NULL;
   
  ret->string = malloc(size*sizeof(char));
  
  if(ret->string == NULL)
  {
    free(ret);
    return NULL;
  }    
  ret->fileSize = size;
  
 return ret;
}

void destCEASAR_str(CEASAR_str_t *cstr)
{
  if (cstr != NULL)
  {
    free(cstr->string);
    free(cstr);
  }
}
