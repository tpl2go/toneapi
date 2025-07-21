# TONEAPI

This library provides convenience wrappers around Intel IPP for use in C++ codebases.

Instead of:

```cpp
IppStatus sts = ippsAbs_32f_A24(pSrc, pDst, len);
if (sts != 0) throw std::runtime_error();
```

`TONEAPI` offers
```cpp
// implicit error status checking
// overloaded function so that you dont have to select the Abs function of the correct type
ipps::Abs(pSrc, pDst, len);
```

Instead of:

```cpp
// https://www.intel.com/content/www/us/en/developer/articles/training/how-to-use-intel-ipp-s-1d-fourier-transform-functions.html

// Spec and working buffers
IppsDFTSpec_C_32fc *pDFTSpec=0;
Ipp8u  *pDFTInitBuf, *pDFTWorkBuf;

// Query to get buffer sizes
int sizeDFTSpec,sizeDFTInitBuf,sizeDFTWorkBuf;
ippsDFTGetSize_C_32fc(N, IPP_FFT_NODIV_BY_ANY, 
    ippAlgHintAccurate, &sizeDFTSpec, &sizeDFTInitBuf, &sizeDFTWorkBuf);

// Alloc DFT buffers
pDFTSpec    = (IppsDFTSpec_C_32fc*)ippsMalloc_8u(sizeDFTSpec);
pDFTInitBuf = ippsMalloc_8u(sizeDFTInitBuf);
pDFTWorkBuf = ippsMalloc_8u(sizeDFTWorkBuf);

// Initialize DFT
ippsDFTInit_C_32fc(N, IPP_FFT_NODIV_BY_ANY, 
    ippAlgHintAccurate, pDFTSpec, pDFTInitBuf);
if (pDFTInitBuf) ippFree(pDFTInitBuf);

// Do the DFT
ippsDFTFwd_CToC_32fc(pSrc,pDst,pDFTSpec,pDFTWorkBuf);

// Free DFT buffer
if (pDFTWorkBuf) ippFree(pDFTWorkBuf);
if (pDFTSpec) ippFree(pDFTSpec);
```

`TONEAPI` offers
```cpp
ipps::DFT_Engine<Ipp32fc,Ipp32fc> dfteng(128);
dfteng.Fwd(pSrc, pDst);
```

Additionally, if using `TONEAPI`'s built-in `vector` container, you dont have to pass around pointers and lengths

```cpp
ipps::vector<Ipp32fc> src(128);
ipps::DFT_Engine<Ipp32fc,Ipp32fc> dfteng(128);
auto dst = dfteng.Fwd_V(src);
```

## Usage

Namespace alias

```cpp
namespace ipps=tipp::signal;
namespace ippvm=tipp::signal;
```

## Similar Libraries
This is not the first library to wrap Intel IPP. The following repositories have similar aims.
* [ipp_ext by icyveins7](https://github.com/icyveins7/ipp_ext)
* [IPPPlus by Red-Li](https://github.com/Red-Li/IPPPlus)


## Design Principles
1. Instead of returning status codes and requiring the user to check for errors, this library will check every function call and throw a runtime exception if errors are detected
2. Namespaces are designed to follow the intel binaries as closely as possible (ipps, ippvm, ippi, etc)
3. Where possible, we will create additional wrapper functions that accept and return `std::vector` instead of pointers

This library is full of `static inline` because this library is not defining any new implementations. It cannot be compiled into a binary library. It is simply a wrapper that redirects the Intel api and should exist only within the compiler's translation unit. 

## Class Design
When using a class to wrap the management of a resource like memory buffers, it is strongly recommended to specify the following 5 classes --- 1) Copy Constructor 2) Move Constructor, 3) Copy Assignment Operator 4) Move Assignment Operator, 5) Destructor. This is commonly known as the Rule of Five. The move / copy assignment operator is implemented using the copy and swap idiom.

## On memory alignment
Mallocs by modern C++ on 64-bit machines often returns a 16-byte aligned pointer. However, some SMID instructions (like AVX-256, AVX-512) require stricter memory alignment for optimal performance. 
Users of Intel IPP are encouraged to use `IppsMalloc` to create 64-byte aligned memory for use with IPP functions. 
If we were to abide by C++ practices of avoiding mallocs and using containers like `std::vector`, we have two possible options:
1. Create our custom `vector` class that uses `IppsMalloc` and `IppsFree`
2. Use a custom allocator with `std::vector`

This library shall provide both options

For the first option, refer to [ipp_ext by icyveins7](https://github.com/icyveins7/ipp_ext) for a possible implementation. 
Instead, this section will describe how to use the second option.

## Error checking
It might be painful to always be checking the error status of a call to ipp. There is an optional MACROS flag `CHECK_IPP_ERROR` to throw a `runtime_error` whenever the return code isnt 0. 

Functions which dont support multiple types are ignored in this library. For example `ippsCountInRange_32s`, `ippsFindNearestOne_16u`.

Function which offer multiple accuracy levels for the same input type, only the most accurate is selected.

## Contributions
This project welcomes contributions and is keen to hear how it can be tweaked to serve your project needs. Do drop a message under issues if there are requests

## Installation
This is a header only library and follows standard cmake build procedures.

```
mkdir build
cd build
cmake ..
cmake --install . 
```

To install it into a custom user directory, there are two approaches

**Method 1**
```bash
cmake -DCMAKE_INSTALL_PREFIX=/path/to/custom/install/directory ..
cmake --install .
```

**Method 2**
```bash
cmake ..
cmake --install . --config Release --prefix /path/to/custom/install/directory
```

## Consumption by CMAKE projects
`toneapi` offers `TONEAPIConfig.cmake` file for easy inclusion into your C++ CMAKE projects 

```cmake
find_package(toneapi REQUIRED)
```

and set `CMAKE_PREFIX_PATH` environment variable to `/path/to/toneapi/repo/cmake`
