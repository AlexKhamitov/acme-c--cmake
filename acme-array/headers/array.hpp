//Лаврентьева А.А. СКБ-161, задача №3.
#ifndef EH128148_HPP
#define EH128148_HPP

#include <cstddef>
#include <ostream>

namespace Array {

    using std::size_t;

    class Array
    {
        std::size_t dims_num;
        std::size_t *dims;
        bool *data;

        public:

        Array();
        ~Array();

        Array(size_t dims_num, const size_t *dims, bool symbol);

        Array(const Array& array);
        Array(Array&& array);

        Array& operator = (const Array& array);
        Array& operator = (Array&& array);

        bool operator [] (const size_t *coords) const;
        bool& operator [] (const size_t *coords);

        bool operator == (const Array& array) const;
        bool operator != (const Array& array) const;

        size_t get_dims_num() const;
        size_t get_dim_size(size_t i) const;

        private:

        size_t get_index(const size_t *coords) const;

    };

}
#endif // EH128148_HPP
