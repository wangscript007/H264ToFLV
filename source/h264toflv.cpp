//作者  蔡砚刚  20160614  xiaoc@pku.edu.cn
#include <stdlib.h>
#include "h264toflv.h"
#include "flvfile.h"
#include "encapsulation.h"

int main(int argc, char **argv)
{
    flv_param m_param; //配置参数信息
    bool ret = false;

    EncaFlv *encflv = new EncaFlv();

    flv_param_default(&m_param);//设置默认参数
    ret = parse(&m_param,argc,argv);  //解析参数
    if(!ret) //参数配置错误
    {
        system("pause");
        return 0;
    }

    openFlvFiles();//打开相关读写文件

    encflv->create(&m_param); //申请内存
    encflv->encapsulate();//分析flv文件
    encflv->destory();//释放内存

    delete encflv;
    closeFlvFiles();//关闭相关读写文件
    system("pause");
    return 0;
}