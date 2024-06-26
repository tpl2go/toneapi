#include <ipp.h>
#include <complex>
#include "tipp_error.hpp"

namespace tipp
{

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

    template <typename T>
    class vector
    {
        typedef T value_type;
        typedef T *pointer;
        typedef const T *const_pointer;
        typedef T &reference;
        typedef const T &const_reference;
        typedef size_t size_type;
        typedef ptrdiff_t difference_type;

        friend void swap(vector &a, vector &b) noexcept
        {
            using std::swap;
            swap(a.numel, b.numel);
            swap(a.m_data, b.m_data);
            swap(a.cap, b.cap);
        }

    public:
        // Constructors

        // Default constructor
        vector() = default;

        explicit vector(size_type count)
        {
            numel = count;
            reserve(numel);
        }

        vector(size_type count, const value_type &value)
        {
            numel = count;
            reserve(numel);
            set(value);
        }

        // Copy constructor
        vector(const vector &other)
        {
            reserve(numel);
            Copy(other.m_data, m_data, (int)numel);
            numel = other.numel;
        }

        // Move constructor
        // Move constructors typically "steal" the resources held by the argument
        // rather than make copies of them, and leave the argument in some valid
        // but otherwise indeterminate state.
        vector(vector &&other)
        {
            // steal other's data
            numel = other.numel;
            cap = other.cap;
            m_data = other.m_data;

            // nullify other
            other.m_data = nullptr;
            other.cap = 0;
            other.numel = 0;
        }

        // Copy Assignment operator
        vector &operator=(vector &other)
        {
            if (this != &other)
            {
                if (other.numel > 0)
                {
                    reserve(other.numel);
                    Copy(other.m_data, m_data, (int)numel);
                }
                numel = other.numel;
            }
            return *this;
        }

        // Move Assignment operator
        vector &operator=(vector &&other) noexcept
        {
            if (this != &other)
            {
                // free own data
                if (m_data != nullptr)
                    ippsFree(m_data);

                // steal other's data
                numel = other.numel;
                cap = other.cap;
                m_data = other.m_data;

                // nullify other
                other.m_data = nullptr;
                other.cap = 0;
                other.numel = 0;
            }
            return *this;
        }

        ~vector()
        {
            if (m_data != nullptr)
                ippsFree(m_data);
        }

        /*
        Resizes the container so that it contains n elements.
        If n is smaller than the current container size, the content is reduced to its first n elements, removing those beyond (and destroying them).
        If n is greater than the current container size, the content is expanded by inserting at the end as many elements as needed to reach a size of n.
        If val is specified, the new elements are initialized as copies of val, otherwise, they are value-initialized.
        If n is also greater than the current container capacity, an automatic reallocation of the allocated storage space takes place.
         */
        void resize(size_type new_count)
        {

            reserve(new_count);

            if (new_count > numel) // value initialise new elements
                for (int i = numel; i < new_count; i++)
                    new (&m_data[i]) value_type{};
            else if (new_count < numel) // destroy excess elements
                for (int i = new_count; i < numel; i++)
                    m_data[i].~value_type();

            numel = new_count;
        }

        void resize(size_t new_count, const T &value)
        {

            reserve(new_count);

            if (new_count > numel) // copy construct new elements
                for (int i = numel; i < new_count; i++)
                    new (&m_data[i]) value_type(value);
            else if (new_count < numel) // destroy excess elements
                for (int i = new_count; i < numel; i++)
                    m_data[i].~value_type();

            numel = new_count;
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > cap)
            {
                value_type *new_data = ippsMalloc<value_type>(new_cap);
                if (m_data != nullptr)
                {
                    Copy(m_data, new_data, (int)numel);
                    ippsFree(m_data);
                }
                m_data = new_data;
                cap = new_cap;
            }
        }

        void set(const_reference value)
        {
            for (int i = 0; i < numel; i++)
                new (&m_data[i]) value_type(value);
        }

        pointer data() { return m_data; }
        const_pointer data() const { return m_data; }

        reference back() { return m_data[numel - 1]; }
        const_reference back() const { return m_data[numel - 1]; }

        reference front() { return m_data[0]; }

        const_reference front() const { return m_data[0]; }

        reference at(size_type pos)
        {
            if (pos < numel && pos >= 0)
                return m_data[pos];
            else
                throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(numel) + std::string(", pos is ") + std::to_string(pos));
        }

        const_reference at(size_type pos) const
        {
            if (pos < numel && pos >= 0)
                return m_data[pos];
            else
                throw std::out_of_range(std::string("tipp::ipps::vector.at Size is ") + std::to_string(numel) + std::string(", pos is ") + std::to_string(pos));
        }

        reference operator[](size_type pos) { return m_data[pos]; }

        const_reference operator[](size_type pos) const { return m_data[pos]; }

        void push_back(const_reference value)
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

        size_type size() const { return numel; }

        size_type capacity() const { return cap; }

        void clear() { numel = 0; }

        bool empty() const noexcept { return numel == 0; }

        // Iterators
        pointer begin() { return m_data; }

        const_pointer begin() const { return m_data; }

        pointer end() { return m_data + numel; }

        const_pointer end() const { return m_data + numel; }

        // Const iterators
        const_pointer cbegin() const { return m_data; }

        const_pointer cend() const { return m_data + numel; }

    protected:
        size_type numel = 0;
        size_type cap = 0;
        pointer m_data = nullptr;
    };

    // Custom Allocator for use with STL vector
    template <class T>
    struct IPPallocator
    {
        typedef T value_type;
        IPPallocator() noexcept {} // default ctor not required by C++ Standard Library

        // A converting copy constructor:
        template <class U>
        IPPallocator(const IPPallocator<U> &) noexcept {}

        template <class U>
        bool operator==(const IPPallocator<U> &) const noexcept { return true; }

        template <class U>
        bool operator!=(const IPPallocator<U> &) const noexcept { return false; }

        T *allocate(const size_t n) const
        {
            return ippsMalloc<T>(n);
        }
        void deallocate(T *const p, size_t) const noexcept
        {
            ippsFree(p);
        }
    };

}
