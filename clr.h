//
// Created by PC5000 on 2025/3/3.
//

#ifndef IL2CPPDUMPER_CLR_H
#define IL2CPPDUMPER_CLR_H
#include "unistd.h"
#define EXPORT_API __attribute__((visibility("default")))

typedef struct Il2CppObject ;
typedef struct Il2CppString;
union Arg{
    uint64_t __u64;
    void* ptr;
    bool b;
    int8_t i8;
    uint8_t u8;
    int16_t i16;
    uint16_t u16;
    int32_t i32;
    uint32_t u32;
    int64_t i64;
    uint64_t u64;
    float f4;
    double f8;
    Il2CppObject* obj;
    Il2CppString* str;
    Il2CppObject** ptrObj;
};
class Obs {
public:
    const char *dll_Name;
    const char *name_space;
    const char *className;
    const char *methodName;
    int methodCount;

    Obs(const char *dllName,const char *name_space,const char *className,const char *methodName, int methodCount) {
        this->dll_Name = dllName;
        this->name_space = name_space;
        this->className = className;
        this->methodName = methodName;
        this->methodCount = methodCount;
    }

    virtual void OnMethodEnter(Arg *args,uint32_t argCount) = 0;

    virtual void OnMethodExit(Arg *ret) = 0;
};

extern "C"   {
   EXPORT_API  void HybridClrAddObs(Obs *obs);
}

#endif //IL2CPPDUMPER_CLR_H
