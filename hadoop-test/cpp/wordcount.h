#include <algorithm> 
#include <stdint.h>
#include <string>
#include <vector>
#include "Pipes.hh"  
#include "TemplateFactory.hh"  
#include "StringUtils.hh" 
#include <iostream>
using namespace std;

class WordcountMapper : public HadoopPipes::Mapper 
{ 
	public:  
		WordcountMapper(HadoopPipes::TaskContext& context);	
		vector<string> split(const string& src, const string& separator);
		//重写map程序
	  void map(HadoopPipes::MapContext& context);
};  

class WordcountReducer : public HadoopPipes::Reducer 
{  
	public:  
	  WordcountReducer(HadoopPipes::TaskContext& context);
	  //重写reduce程序
	  void reduce(HadoopPipes::ReduceContext& context);
};
