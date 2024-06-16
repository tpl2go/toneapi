# Templated Intel Performance Primitives (TIPP)

Ever wanted to use Intel Performance Primitives with templated C++ codes, but realised that eavery function is typed?
This wrapper is designed to solve this problem. In addition, it provides class wrappers around operations that requires mallocing a working memory.

## Similar Libraries
This is not the first library to wrap Intel IPP. The following repositories have similar aims.
* [ipp_ext by icyveins7](https://github.com/icyveins7/ipp_ext)
* [IPPPlus by Red-Li](https://github.com/Red-Li/IPPPlus)


## Design Principles
1. Instead of returning status codes and requiring the user to check for errors, this library will check every function call and throw a runtime exception if errors are detected
2. Namespaces are designed to follow the intel binaries as closely as possible (ipps, ippvm, ippi, etc)
3. Where possible, we will create additional wrapper functions that accept and return `std::vector` instead of pointers

## Class Design
When using a class to wrap the management of a resource like memory buffers, it is strongly recommended to specify the following 5 classes --- 1) Copy Constructor 2) Move Constructor, 3) Copy Assignment Operator 4) Move Assignment Operator, 5) Destructor. This is commonly known as the Rule of Five. The move / copy assignment operator is implemented using the copy and swap idiom.

## On memory alignment
Mallocs by modern C++ on 64-bit machines often returns a 16-byte aligned pointer. However, some SMID instructions (like AVX-256, AVX-512) require stricter memory alignment for optimal performance. Users of Intel IPP are encouraged to use `IppsMalloc` to create 64-byte aligned memory for use with IPP functions. If we were to abide by C++ practices of avoiding mallocs and using containers like `std::vector`, we have two possible options:
1. Create our custom memory alignment `vector` class that uses `IppsMalloc` and `IppsFree`.
2. Use a custom allocator with `std::vector`


For the first option, refer to [ipp_ext by icyveins7](https://github.com/icyveins7/ipp_ext) for a possible implementation. 
Instead, this section will describe how to use the second option.

