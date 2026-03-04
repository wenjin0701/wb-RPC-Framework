#ifndef _Wrpcapplication_H
#define _Wrpcapplication_H
#include "Wrpcconfig.h"
#include "Wrpcchannel.h" 
#include  "Wrpccontroller.h"
#include<mutex>
//Wrpc基础类，负责框架的一些初始化操作
class WrpcApplication
{
    public:
    static void Init(int argc,char **argv);
    static WrpcApplication & GetInstance();
    static void deleteInstance();
    static Wrpcconfig& GetConfig();
    private:
    static Wrpcconfig m_config;
    static WrpcApplication * m_application;//全局唯一单例访问对象
    static std::mutex m_mutex;
    WrpcApplication() {}
    ~WrpcApplication() {}
    WrpcApplication(const WrpcApplication&)=delete;
    WrpcApplication(WrpcApplication&&)=delete;
};
#endif 
