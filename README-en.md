# HybridClrHookNative

- [README 中文](./README.md)
- [README English](./README-en.md)

## Introduction

This is a Hook framework for HybridClr, designed to resolve issues where Unity functions using HybridClr cannot be hooked.

## Platform Support

- Arm64
- Arm32 (Supported in paid version)

## Features
- Argument modification
- Compatibility with all HybridClr versions
- Hook support for static/non-static functions
- Return value modification (Supported in paid version)
- CLR and native bridge function modification (Supported in paid version)
- Virtual function hooking (Supported in paid version)
- Overloaded function hooking (Supported in paid version)

## Usage

### Method 1:
Link `libhook.so` to your project using CMake and utilize `clr.h`.

### Method 2:
Dynamically load `libhook.so` and access symbols:

```c++
void* handle = dlopen("libhook.so", RTLD_NOW);
void* addObsAddr = dlsym(handle, "HybridClrAddObs");

typedef void (*HybridClrAddObs)(Obs* obs);
auto addObs = (HybridClrAddObs)addObsAddr;

// Parameters: DLL name, namespace, class name, method name, argument count
auto test = new TestObs("HotUpdate.dll", "HotUpdate", "Hello", "Run", 0);
addObs(test);

```
Obs Implementation Example:

```c++
void TestObs::OnMethodEnter(Arg* args, uint32_t argCount) {
    LOGI("Run Enter");
}

void TestObs::OnMethodExit(Arg* ret) {
    LOGI("test exit %i", ret->i32);
    ret->i32 = 0;
    LOGI("test exit edit %i", ret->i32);
}
```
- Important: Ensure all initialization calls are completed before loading libil2cpp, otherwise functionality may fail.
### Contact:
- Email: 295238641@qq.com (Please specify your purpose when contacting)



