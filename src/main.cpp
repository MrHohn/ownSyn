#include "wordcount.h"  
  
int main(int argc, char *argv[])   
{    
  return HadoopPipes::runTask(HadoopPipes::TemplateFactory<WordcountMapper, WordcountReducer>());    
}    
