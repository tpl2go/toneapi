# TONEAPI

This library provides **simple** C++ wrappers for Intel IPP.

## Usage

**Example 1: Overloaded Functions**

Instead of:

```cpp
IppStatus sts = ippsAbs_32f_A24(pSrc, pDst, len);
if (sts != 0) throw std::runtime_error();
```

`TONEAPI` offers

```cpp
tipp::s::Abs(pSrc, pDst, len);
```
Function overloading allows you to use IPP functions within templated codes.

**Example 2: Convenience Engines**

Instead of:

Source: [Intel Documentation](https://www.intel.com/content/www/us/en/developer/articles/training/how-to-use-intel-ipp-s-1d-fourier-transform-functions.html)

```cpp
int N = 128;

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
tipp::s::DFT_Engine<Ipp32fc,Ipp32fc> dfteng(128);
dfteng.forward(pSrc, pDst);
```

**Example 3: Error Checking**

Instead of:

```cpp
IppStatus sts = ippsAbs_32f_A24(pSrc, pDst, len);
if (sts != 0) throw std::runtime_error();
```

TONEAPI offers

```cpp
#define ASSERT_TIPP_NOERROR
tipp::s::Abs(pSrc, pDst, len); // error checking built in
```

define the `ASSERT_TIPP_NOERROR` flag within each translation unit to enable throwing an `std::runtime_error` when status is not 0.

## Similar Libraries
This is not the first library to wrap Intel IPP. The following repositories have similar aims.
* [ipp_ext by icyveins7](https://github.com/icyveins7/ipp_ext)
* [IPPPlus by Red-Li](https://github.com/Red-Li/IPPPlus)
* [Integration Wrapper by Intel](https://www.intel.com/content/www/us/en/docs/ipp/developer-reference-integration-wrapper/2020/overview.html)

There is also a large open source collaboration effort under the [UXL foundation](https://uxlfoundation.org/) to implement the oneAPI specification. The oneAPI specification currently doesnt cover Intel IPP but it covers Intel MKL (oneMath) and it offers a nice C++ SYCL interface too. However, to use the oneMath SYCL interface, a Intel DPC++ compiler or clang compiler is needed. For MSVC compatibility, this dumb wrapper is still needed.

## Domains
As much as possible, `TONEAPI` follows the same organization structure as Intel IPP binaries. Functions found in an IPP domain would be wrapped in an equivalent namespace. 
For example:

| domain            | tipp namespace | IPP includes | IPP libraries |
|:-----------------:| :-------------:|:------------:|:-------------:|
| signal processing | `tipp::s`      | `<ipp/ipps.h>`| `ipps.lib`   |
| image processing |   `tipp::i`  | `<ipp/ippi.h>`| `ippi.lib`   |
| computer vision |   `tipp::cv`  | `<ipp/ippcv.h>`| `ippcv.lib`   |



## Design Principles
### static inline
`static inline` is used to avoid causing multiple definition errors when this header library is included in multiple translation units. An additional benefit is that `inline` strongly suggests to the compiler that the wrapper function (and associated error checking) should be inlined away, resulting in zero-runtime overhead.

### Simplicty
This wrapper library is verbose and sometimes repetitive. While MACROS or tag-dispatch could be used to reduce code duplication, it was avoided to maintain simplicity. Learning IPP's API is hard enough. This wrapper intends to offer convenience not additionaly complexity when using IPP.

### Functions without multiple types
Even though it seems meaningless to  which dont support multiple types are ignored in this library. For example `ippsCountInRange_32s`, `ippsFindNearestOne_16u`.

### Functions with multiple accuracy
Function which offer multiple accuracy levels for the same input type, only the most accurate is selected.

### Memory management
Convenience engine classes in this library apply the `rule of zero` by using `tipp::vector` to manage memory. Thus, destructors, copy constructors, move assignment operators etc need not be implemented and the class is kept simple.

**Explanation**:
The C standard guarentees that malloc() return pointers aligned for any fundamental type. 
In practice, 64-bit machines often return 16-byte aligned pointers to support SIMD operations from SSE and SSE2. 
But advanced SMID instructions like AVX-256 and AVX-512 require stricter 32-byte and 64 byte memory alignment respectively. 
The code won't crash if it AVX512 was called on non-aligned memory but there would be a performance hit
`tipp::vector` is a container class that functions similarly to std::vector. Internally it uses `IppMalloc` to allocate 64-byte aligned memory. 



### Static Inline Functions
All wrapper functions use `static inline` to prevent multiple definition errors when the header is included across multiple translation units. The `inline` keyword also encourages the compiler to optimize away the wrapper function calls, resulting in zero runtime overhead while maintaining the convenience of error checking and type safety.

### Simplicity Over Cleverness
This library prioritizes readability and ease of use over code compactness. While macros or template metaprogramming could reduce code duplication, we deliberately avoid such techniques to keep the learning curve shallow. Intel IPP already has a steep learning curve—this wrapper aims to simplify usage, not add complexity.

### Selective Function Coverage
**Single-type functions**: Functions that only support one data type (e.g., `ippsCountInRange_32s`, `ippsFindNearestOne_16u`) are excluded from this library since they don't benefit from C++ function overloading.

**Multiple accuracy variants**: When IPP provides multiple accuracy levels for the same operation and data type, only the highest accuracy variant is wrapped to avoid decision paralysis and ensure consistent quality.

### Memory Management
Convenience engine classes follow the **Rule of Zero** by using `tipp::vector` for automatic memory management. This eliminates the need to manually implement destructors, copy constructors, or move operators, keeping the classes simple and safe.

**Why custom memory allocation?**
While the C standard guarantees that `malloc()` returns pointers aligned for fundamental types, modern SIMD instructions have stricter requirements:
- SSE/SSE2: 16-byte alignment (typically provided by default on 64-bit systems)
- AVX-256: 32-byte alignment 
- AVX-512: 64-byte alignment

Using misaligned memory won't crash your program, but it can significantly impact performance. `tipp::vector` uses Intel IPP's `ippMalloc()` to ensure 64-byte alignment, maximizing performance across all SIMD instruction sets.

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
