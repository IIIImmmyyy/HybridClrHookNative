# HybridClrHookNative

- [README 中文](./README.md)
- [README English](./README-en.md)

## 介绍

这是一个HybridClr的Hook框架，用于处理Unity使用了HybridClr函数无法被hook的情况。

## 平台支持

- Arm64
- Arm32 (付费版支持)

## 功能支持

- 入参修改
- 支持所有的HybridClr版本
- 静态、非静态函数的hook
- 返回值修改(付费版支持)
- Clr与本体桥接函数的修改(付费版支持)
- virtual函数的hook(付费版支持)
- 重载函数的hook(付费版支持)
- CLR内反射函数的hook(付费版支持)

## 使用方法

- 第一种：使用Cmake将libhook.so链接到你的项目中 使用clr.h 完成使用

- 第二种：

 ```c++
   void* handle= dlopen("libhook.so", RTLD_NOW);
   void* addObsAddr = dlsym(handle, "HybridClrAddObs");
   //调用addObsAddr函数
  typedef  void (*HybridClrAddObs)(Obs* obs);
    auto addObs = (HybridClrAddObs)addObsAddr;
    //分别代表 dll名称, namespace, 类名, 方法名, 方法参数个数
    auto test = new TestObs("HotUpdate.dll", "HotUpdate", "Hello", "Run", 0);
    addObs(test);       
```

Obs实现如下

```c++
void TestObs::OnMethodEnter(Arg *args,uint32_t argCount) {
  
    LOGI("Run Enter");
}
void TestObs::OnMethodExit(Arg *ret) {

    LOGI("test exit %i",ret->i32);

    ret->i32=0;
    LOGI("test exit edit %i",ret->i32);
}
```

- 以上请都保证都在libil2cpp加载之前完成调用;否则工作异常

## 联系方式:

### 295238641@qq.com  (请注明来意) qq: 29538641


