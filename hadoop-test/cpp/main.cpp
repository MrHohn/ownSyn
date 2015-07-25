/*
**hadoop的mapreduce框架，其中map数据准备，reduce数据汇总，我们通过客户端程序和hadoop集群进行通信
**一般java程序使用streaming标准流，c++使用socket套接字
**map在数据节点上执行，本地化无网络占用；reduce由map提供数据（map输出=reduce输入），网络占用较高；
**一般java入参可以用int和string，但c++只有string，虽然简化接口，但很多时候需要人工转化
***********************************
**hadoop集群执行word统计功能
**hadoop执行task方法：runTask
**hadoop执行job命令：mapredjob.sh
**HDFS数据文件：/input/wordcount/sample.txt
**HDFS输出文件：/output/wordcount 
*/
#include "wordcount.h"

int main(int argc, char *argv[]) 
{  
  return HadoopPipes::runTask(HadoopPipes::TemplateFactory<WordcountMapper, WordcountReducer>());  
}  
