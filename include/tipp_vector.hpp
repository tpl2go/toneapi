#include <ipp.h>

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
    }
};