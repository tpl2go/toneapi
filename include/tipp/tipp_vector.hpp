#pragma once
#include "s_support.hpp"
#include "s_initialization.hpp"
#include "tipp_error.hpp"
#include <stdexcept>
#include <utility>

namespace tipp
{

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
            swap(a.m_numel, b.m_numel);
            swap(a.m_data, b.m_data);
            swap(a.m_cap, b.m_cap);
        }

    protected:
        size_type m_numel = 0;
        size_type m_cap = 0;
        pointer m_data = nullptr;

    public:
        // Constructors

        // Default constructor
        vector() = default;

        explicit vector(size_type count)
        {
            reserve(count);
            m_numel = count;
        }

        vector(size_type count, const value_type &value)
        {
            reserve(count);
            m_numel = count;
            set(value);
        }

        // Copy constructor
        // creates a deep copy of the argument
        // invoked in situations like:
        //     vector a;
        //     vector b(a);
        vector(const vector &other)
        {
            reserve(m_numel);
            Copy(other.m_data, m_data, (int)m_numel);
            m_numel = other.m_numel;
        }

        // Move constructor
        // Move constructors typically "steal" the resources held by the argument
        // rather than make copies of them, and leave the argument in some valid
        // but otherwise indeterminate state.
        // invoked in situations like:
        //     vector a;
        //     vector b(std::move(a));
        //
        //     vector c = functionReturningVector();
        vector(vector &&other) noexcept
        {
            // steal other's data
            m_numel = other.m_numel;
            m_cap = other.m_cap;
            m_data = other.m_data;

            // nullify other
            other.m_data = nullptr;
            other.m_cap = 0;
            other.m_numel = 0;
        }

        // Copy Assignment operator
        // invoked in situations like:
        //     vector a;
        //     vector b;
        //     a = b;
        vector &operator=(vector &other)
        {
            if (this != &other)
            {
                if (other.m_numel > 0)
                {
                    reserve(other.m_numel);
                    Copy(other.m_data, m_data, (int)m_numel);
                }
                m_numel = other.m_numel;
            }
            return *this;
        }

        // Move Assignment operator
        // Move assignment operators typically "steal" the resources held by the argument
        // invoked in situations like:
        //     vector a;
        //     vector b;
        //     a = std::move(b);

        vector &operator=(vector &&other) noexcept
        {
            if (this != &other)
            {
                // free own data
                if (m_data != nullptr)
                    ippsFree(m_data);

                // steal other's data
                m_numel = other.m_numel;
                m_cap = other.m_cap;
                m_data = other.m_data;

                // nullify other
                other.m_data = nullptr;
                other.m_cap = 0;
                other.m_numel = 0;
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

            if (new_count > m_numel) // value initialise new elements
                for (int i = m_numel; i < new_count; i++)
                    new (&m_data[i]) value_type{};
            else if (new_count < m_numel) // destroy excess elements
                for (int i = new_count; i < m_numel; i++)
                    m_data[i].~value_type();

            m_numel = new_count;
        }

        void resize(size_t new_count, const T &value)
        {

            reserve(new_count);

            if (new_count > m_numel) // copy construct new elements
                for (int i = m_numel; i < new_count; i++)
                    new (&m_data[i]) value_type(value);
            else if (new_count < m_numel) // destroy excess elements
                for (int i = new_count; i < m_numel; i++)
                    m_data[i].~value_type();

            m_numel = new_count;
        }

        void reserve(size_type new_cap)
        {
            if (new_cap > m_cap)
            {
                value_type *new_data = ippsMalloc<value_type>(new_cap);
                if (m_data != nullptr)
                {
                    Copy(m_data, new_data, (int)m_numel);
                    ippsFree(m_data);
                }
                m_data = new_data;
                m_cap = new_cap;
            }
        }

        void set(const_reference value)
        {
            for (int i = 0; i < m_numel; i++)
                new (&m_data[i]) value_type(value);
        }

        pointer data() { return m_data; }
        const_pointer data() const { return m_data; }

        reference back() { return m_data[m_numel - 1]; }
        const_reference back() const { return m_data[m_numel - 1]; }

        reference front() { return m_data[0]; }

        const_reference front() const { return m_data[0]; }

        reference at(size_type pos)
        {
            if (pos < m_numel && pos >= 0)
                return m_data[pos];
            else
                throw std::out_of_range(std::string("tipp::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
        }

        const_reference at(size_type pos) const
        {
            if (pos < m_numel && pos >= 0)
                return m_data[pos];
            else
                throw std::out_of_range(std::string("tipp::vector.at Size is ") + std::to_string(m_numel) + std::string(", pos is ") + std::to_string(pos));
        }

        reference operator[](size_type pos) { return m_data[pos]; }

        const_reference operator[](size_type pos) const { return m_data[pos]; }

        void push_back(const_reference value)
        {
            // check size
            if (m_numel == m_cap)
            {
                m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
            }

            m_data[m_numel] = value;
            m_numel++;
        }

        void push_back(T &&value)
        {
            // check size
            if (m_numel == m_cap)
            {
                m_cap = m_cap == 0 ? 1 : m_cap; // if cap is 0 (blank ctor then initialise with something small)
                reserve(m_cap * 2);             // we double the capacity, similar to how std::vector does it
            }

            m_data[m_numel] = value;
            m_numel++;
        }

        size_type size() const { return m_numel; }

        size_type capacity() const { return m_cap; }

        void clear() { m_numel = 0; }

        bool empty() const noexcept { return m_numel == 0; }

        // Iterators
        pointer begin() { return m_data; }

        const_pointer begin() const { return m_data; }

        pointer end() { return m_data + m_numel; }

        const_pointer end() const { return m_data + m_numel; }

        // Const iterators
        const_pointer cbegin() const { return m_data; }

        const_pointer cend() const { return m_data + m_numel; }
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
