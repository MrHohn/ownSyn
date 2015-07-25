#include "wordcount.h"

WordcountMapper::WordcountMapper(HadoopPipes::TaskContext& context)
{
}

void WordcountMapper::map(HadoopPipes::MapContext& context)
{ 
	int count = 1; 
	string line = context.getInputValue();  
	vector<string> wordVec = split(line, " ");
	for(unsigned i=0; i<wordVec.size(); i++)
	{
		context.emit(wordVec[i], HadoopUtils::toString(count));
	}
}  

vector<string> WordcountMapper::split(const string& src, const string& separator)
{
    vector<string> dest;
    string str = src;
    string substring;
    string::size_type start = 0, index = 0;
		while(index != string::npos)    
		{
        index = str.find_first_of(separator,start);
        if (index != string::npos)
        { 
            substring = str.substr(start,index-start);
            dest.push_back(substring);
            start = str.find_first_not_of(separator,index);
            if (start == string::npos) return dest;
        }
    }
    substring = str.substr(start);
    dest.push_back(substring);
    return dest;
}
 
WordcountReducer::WordcountReducer(HadoopPipes::TaskContext& context)
{
}
void WordcountReducer::reduce(HadoopPipes::ReduceContext& context)
{  
	int wSum = 0;
  while (context.nextValue())
	{  
    wSum = wSum + HadoopUtils::toInt(context.getInputValue()) ;  
  }  
  context.emit(context.getInputKey(), HadoopUtils::toString(wSum));  
}  
