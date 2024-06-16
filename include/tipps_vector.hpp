#include <ipp.h>
#include <complex>
#include "tipp_error.hpp"

namespace tipp
{

    namespace ipp
    {

        // Custom allocator
        template <typename T>
        class IPPAllocator
        {
        public:
            using value_type = T;
            using pointer = T *;
            using const_pointer = const T *;
            using reference = T &;
            using const_reference = const T &;
            using size_type = std::size_t;
            using difference_type = std::ptrdiff_t;

            // Rebind allocator to another type
            template <typename U>
            struct rebind
            {
                using other = IPPAllocator<U>;
            };

            // Constructor
            IPPAllocator() noexcept {}

            // Copy constructor
            template <typename U>
            IPPAllocator(const IPPAllocator<U> &) noexcept {}

            // Allocate memory
            pointer allocate(size_type n, const void *hint = 0)
            {
                if (n > max_size())
                    throw std::bad_alloc();
                return static_cast<pointer>(ippsMalloc_32fc(n * sizeof(T)));
            }

            // Deallocate memory
            void deallocate(pointer p, size_type n) noexcept
            {
                ippsFree(p);
            }

            // Construct an object in allocated memory
            template <typename U, typename... Args>
            void construct(U *p, Args &&...args)
            {
                ::new ((void *)p) U(std::forward<Args>(args)...);
            }

            // Destroy an object in allocated memory
            template <typename U>
            void destroy(U *p)
            {
                p->~U();
            }

            // Returns the maximum number of elements that can be allocated
            size_type max_size() const noexcept
            {
                return size_type(~0) / sizeof(T);
            }
        };

        // Equality comparison operator
        template <typename T, typename U>
        bool operator==(const IPPAllocator<T> &, const IPPAllocator<U> &) noexcept
        {
            return true;
        }

        // Inequality comparison operator
        template <typename T, typename U>
        bool operator!=(const IPPAllocator<T> &, const IPPAllocator<U> &) noexcept
        {
            return false;
        }

        // ippsMalloc
        // limited to 2GB of memory
        template <typename T>
        static inline T *ippsMalloc(int len) { return ippsMalloc_8u(len); } // default
        template <>
        Ipp8u *ippsMalloc<Ipp8u>(int len) { return ippsMalloc_8u(len); }
        template <>
        Ipp16u *ippsMalloc<Ipp16u>(int len) { return ippsMalloc_16u(len); }
        template <>
        Ipp32u *ippsMalloc<Ipp32u>(int len) { return ippsMalloc_32u(len); }
        template <>
        Ipp8s *ippsMalloc<Ipp8s>(int len) { return ippsMalloc_8s(len); }
        template <>
        Ipp16s *ippsMalloc<Ipp16s>(int len) { return ippsMalloc_16s(len); }
        template <>
        Ipp32s *ippsMalloc<Ipp32s>(int len) { return ippsMalloc_32s(len); }
        template <>
        Ipp64s *ippsMalloc<Ipp64s>(int len) { return ippsMalloc_64s(len); }
        template <>
        Ipp32f *ippsMalloc<Ipp32f>(int len) { return ippsMalloc_32f(len); }
        template <>
        Ipp64f *ippsMalloc<Ipp64f>(int len) { return ippsMalloc_64f(len); }
        template <>
        Ipp8sc *ippsMalloc<Ipp8sc>(int len) { return ippsMalloc_8sc(len); }
        template <>
        Ipp16sc *ippsMalloc<Ipp16sc>(int len) { return ippsMalloc_16sc(len); }
        template <>
        Ipp32sc *ippsMalloc<Ipp32sc>(int len) { return ippsMalloc_32sc(len); }
        template <>
        Ipp64sc *ippsMalloc<Ipp64sc>(int len) { return ippsMalloc_64sc(len); }
        template <>
        Ipp32fc *ippsMalloc<Ipp32fc>(int len) { return ippsMalloc_32fc(len); }
        template <>
        Ipp64fc *ippsMalloc<Ipp64fc>(int len) { return ippsMalloc_64fc(len); }
        template <>
        std::complex<float> *ippsMalloc<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc(len)); }
        template <>
        std::complex<double> *ippsMalloc<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc(len)); }

        // ippsMalloc_L
        // platform aware function -- introduced in 2017
        template <typename T>
        static inline T *ippsMalloc_L(int len) { return ippsMalloc_8u_L(len); } // default
        template <>
        Ipp8u *ippsMalloc_L<Ipp8u>(int len) { return ippsMalloc_8u_L(len); }
        template <>
        Ipp16u *ippsMalloc_L<Ipp16u>(int len) { return ippsMalloc_16u_L(len); }
        template <>
        Ipp32u *ippsMalloc_L<Ipp32u>(int len) { return ippsMalloc_32u_L(len); }
        template <>
        Ipp8s *ippsMalloc_L<Ipp8s>(int len) { return ippsMalloc_8s_L(len); }
        template <>
        Ipp16s *ippsMalloc_L<Ipp16s>(int len) { return ippsMalloc_16s_L(len); }
        template <>
        Ipp32s *ippsMalloc_L<Ipp32s>(int len) { return ippsMalloc_32s_L(len); }
        template <>
        Ipp64s *ippsMalloc_L<Ipp64s>(int len) { return ippsMalloc_64s_L(len); }
        template <>
        Ipp32f *ippsMalloc_L<Ipp32f>(int len) { return ippsMalloc_32f_L(len); }
        template <>
        Ipp64f *ippsMalloc_L<Ipp64f>(int len) { return ippsMalloc_64f_L(len); }
        template <>
        Ipp8sc *ippsMalloc_L<Ipp8sc>(int len) { return ippsMalloc_8sc_L(len); }
        template <>
        Ipp16sc *ippsMalloc_L<Ipp16sc>(int len) { return ippsMalloc_16sc_L(len); }
        template <>
        Ipp32sc *ippsMalloc_L<Ipp32sc>(int len) { return ippsMalloc_32sc_L(len); }
        template <>
        Ipp64sc *ippsMalloc_L<Ipp64sc>(int len) { return ippsMalloc_64sc_L(len); }
        template <>
        Ipp32fc *ippsMalloc_L<Ipp32fc>(int len) { return ippsMalloc_32fc_L(len); }
        template <>
        Ipp64fc *ippsMalloc_L<Ipp64fc>(int len) { return ippsMalloc_64fc_L(len); }
        template <>
        std::complex<float> *ippsMalloc_L<std::complex<float>>(int len) { return reinterpret_cast<std::complex<float> *>(ippsMalloc_32fc_L(len)); }
        template <>
        std::complex<double> *ippsMalloc_L<std::complex<double>>(int len) { return reinterpret_cast<std::complex<double> *>(ippsMalloc_64fc_L(len)); }

        static inline void Copy(const Ipp8u *pSrc, Ipp8u *pDst, int len) { AssertNoError(ippsCopy_8u(pSrc, pDst, len)); }                        // unsigned char
        static inline void Copy(const Ipp8s *pSrc, Ipp8s *pDst, int len) { AssertNoError(ippsCopy_8u((Ipp8u *)pSrc, (Ipp8u *)pDst, len)); }      // signed char  // REUSE
        static inline void Copy(const Ipp16u *pSrc, Ipp16u *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // unsigned short  // REUSE
        static inline void Copy(const Ipp16s *pSrc, Ipp16s *pDst, int len) { AssertNoError(ippsCopy_16s(pSrc, pDst, len)); }                     // signed short
        static inline void Copy(const Ipp32u *pSrc, Ipp32u *pDst, int len) { AssertNoError(ippsCopy_32s((Ipp32s *)pSrc, (Ipp32s *)pDst, len)); } // unsigned int
        static inline void Copy(const Ipp32s *pSrc, Ipp32s *pDst, int len) { AssertNoError(ippsCopy_32s(pSrc, pDst, len)); }                     // signed int
        static inline void Copy(const Ipp32f *pSrc, Ipp32f *pDst, int len) { AssertNoError(ippsCopy_32f(pSrc, pDst, len)); }                     // float
        static inline void Copy(const Ipp64s *pSrc, Ipp64s *pDst, int len) { AssertNoError(ippsCopy_64s(pSrc, pDst, len)); }                     // __int64 (Windows*) or long long (Linux*)
        static inline void Copy(const Ipp64f *pSrc, Ipp64f *pDst, int len) { AssertNoError(ippsCopy_64f(pSrc, pDst, len)); }                     // double
        static inline void Copy(const Ipp8sc *pSrc, Ipp8sc *pDst, int len) { AssertNoError(ippsCopy_16s((Ipp16s *)pSrc, (Ipp16s *)pDst, len)); } // REUSE another copy function
        static inline void Copy(const Ipp16sc *pSrc, Ipp16sc *pDst, int len) { AssertNoError(ippsCopy_16sc(pSrc, pDst, len)); }                  // complex short
        static inline void Copy(const Ipp32sc *pSrc, Ipp32sc *pDst, int len) { AssertNoError(ippsCopy_32sc(pSrc, pDst, len)); }                  // complex signed int
        static inline void Copy(const Ipp32fc *pSrc, Ipp32fc *pDst, int len) { AssertNoError(ippsCopy_32fc(pSrc, pDst, len)); }                  // complex float
        static inline void Copy(const Ipp64sc *pSrc, Ipp64sc *pDst, int len) { AssertNoError(ippsCopy_64sc(pSrc, pDst, len)); }                  // complex signed long long
        static inline void Copy(const Ipp64fc *pSrc, Ipp64fc *pDst, int len) { AssertNoError(ippsCopy_64fc(pSrc, pDst, len)); }                  // complex double

        template <typename T>
        class vector
        {
        protected:
            size_t numel = 0;
            size_t cap = 0;
            T *m_data = nullptr;

        public:
            // Constructors

            // Default constructor
            vector() = default;

            explicit vector(size_t count)
            {
                numel = count;
                reserve(numel);
            }

            vector(size_t count, const T &value)
            {
                DEBUG("vector(size_t count, const T &value)\n");
                numel = count;
                reserve(numel);
                set(value);
            }

            // Copy constructor
            vector(const vector &other)
                : numel(other.numel)
            {
                reserve(numel);
                Copy(other.m_data, m_data, (int)numel); // cannot do this as some types dont have a copy
                for (size_t i = 0; i < numel; i++)
                    m_data[i] = other.m_data[i]; // TODO: write using ippsCopy? would require template specializations
            }

            // Copy Assignment operator
            vector &operator=(const vector &other)
            {
                DEBUG("vector& operator=(const vector &other)\n");

                // set size
                numel = other.numel;
                // set cap
                reserve(numel); // even if count is 0, reserve() will do nothing
                // copy data
                // Copy<T>(other.m_data, m_data, (int)numel);
                for (size_t i = 0; i < numel; i++)
                    m_data[i] = other.m_data[i]; // TODO: write using ippsCopy? would require template specializations
                return *this;
            }

            // Move constructor
            vector(vector &&other)
                : numel(other.numel), cap(other.cap), m_data(other.m_data)
            {
                DEBUG("vector(vector &&other)\n");

                // nullify the other
                other.m_data = nullptr;
                other.cap = 0;
                other.numel = 0;
            }

            // Move Assignment operator
            vector &operator=(vector &&other)
            {
                if (this != &other)
                {
                    DEBUG("vector& operator=(vector &&other)\n");
                    // Free existing resource
                    ippsFree(m_data);
                    // move parameters
                    numel = other.numel;
                    cap = other.cap;
                    m_data = other.m_data;
                    // nullify the other
                    other.m_data = nullptr;
                    other.cap = 0;
                    other.numel = 0;
                }
                return *this;
            }

            ~vector()
            {
                DEBUG("~vector()\n");
                ippsFree(m_data);
            }

            void resize(size_t new_count)
            {
                DEBUG("void resize(size_t new_count)\n");
                // if count is more than capacity then reserve more
                if (new_count > cap)
                    reserve(new_count); // this sets cap to new_count

                // no matter what, set the numel to the new count
                numel = new_count;
            }

            void resize(size_t new_count, const T &value)
            {
                DEBUG("void resize(size_t new_count, const T& value)\n");
                // keep the old size
                size_t oldsize = numel;

                // resize as per normal
                resize(new_count);

                // write the values from the old to the new (strictly if its larger)
                if (numel > oldsize)
                {
                    if (isZero(value))
                        zero(oldsize, numel - oldsize); // zero up to the new count
                    else
                        set(oldsize, numel - oldsize, value); // set the value up to the new count
                }
            }

            // These only have specializations, see below
            void reserve(size_t new_cap);
            void zero(int start, int length);
            void zero()
            {
                zero(0, numel); // simply call the other one to fill the whole vector with 0
            }

            void set(int start, int length, const T &value);
            void set(const T &value)
            {
                set(0, numel, value); // simply call the other one to fill the whole vector
            }
            // end of specializations

            // Everything else below is to do with read-only access
            T *data()
            {
                return m_data;
            }

            const T *data() const
            {
                return m_data;
            }

            T &back()
            {
                return m_data[numel - 1];
            }

            const T &back() const
            {
                return m_data[numel - 1];
            }

            T &front()
            {
                return m_data[0];
            }

            const T &front() const
            {
                return m_data[0];
            }

            T &at(size_t pos)
            {
                if (pos < numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("ippe::vector::range_check: Size is ") + std::to_string(numel));
            }

            const T &at(size_t pos) const
            {
                if (pos < numel && pos >= 0)
                    return m_data[pos];
                else
                    throw std::out_of_range(std::string("ippe::vector::range_check: Size is ") + std::to_string(numel));
            }

            // true to std::vector, this will not perform bounds checking
            T &operator[](size_t pos)
            {
                return m_data[pos];
            }

            const T &operator[](size_t pos) const
            {
                return m_data[pos];
            }

            void push_back(const T &value) // for now lets not deal with lvalue/rvalue refs
            {
                // check size
                if (numel == cap)
                {
                    cap = cap == 0 ? 1 : cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(cap * 2);         // we double the capacity, similar to how std::vector does it
                }

                m_data[numel] = value;
                numel++;
            }

            void push_back(T &&value)
            {
                // check size
                if (numel == cap)
                {
                    cap = cap == 0 ? 1 : cap; // if cap is 0 (blank ctor then initialise with something small)
                    reserve(cap * 2);         // we double the capacity, similar to how std::vector does it
                }

                m_data[numel] = value;
                numel++;
            }

            size_t size() const
            {
                return numel;
            }

            size_t capacity() const
            {
                return cap;
            }

            void clear()
            {
                numel = 0;
            }

            bool empty() const
            {
                return numel == 0;
            }

            // Iterators
            T *begin()
            {
                return m_data;
            }

            const T *begin() const
            {
                return m_data;
            }

            T *end()
            {
                return m_data + numel;
            }

            const T *end() const
            {
                return m_data + numel;
            }

            // Const iterators
            const T *cbegin() const
            {
                return m_data;
            }

            const T *cend() const
            {
                return m_data + numel;
            }
        };

    }
};