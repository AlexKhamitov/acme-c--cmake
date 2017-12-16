#include "array.hpp"
#include <cstddef>
#include <cstring>

namespace Array {

    using std::size_t;

    size_t Array::get_index(const size_t *coords) const
    {
        size_t step = 1;
        size_t index = 0;
        for(size_t i = 0; i < dims_num; ++i) {
            index += coords[i] * step;
            step *= dims[i];
        }
        return index;
    }

    Array::Array()
        : dims_num(0),
          dims(nullptr),
          data(nullptr)
    {

    }

    Array::~Array()
    {
        delete[] dims;
        delete[] data;
    }

    Array::Array(size_t dims_num, const size_t *dims, bool symbol)
        : dims_num(dims_num)
    {
        this->dims = new size_t[dims_num];
        size_t k = dims_num ? 1 : 0;
        for(size_t i = 0; i < dims_num; ++i)
        {
            k *= dims[i];
            this->dims[i] = dims[i];
        }
        data = new bool[k];
        memset(data, symbol, k);
    }

    Array::Array(const Array &array)
        : dims_num(array.dims_num)
    {
        size_t *new_dims = new size_t[dims_num];
        size_t k = dims_num ? 1 : 0;
        for(size_t i = 0; i < dims_num; ++i)
        {
            k *= array.dims[i];
            new_dims[i] = array.dims[i];
        }
        bool *new_data = new bool[k];
        memcpy(new_data, array.data, k);
        delete[] data;
        delete[] dims;
        data = new_data;
        dims = new_dims;
    }

    Array::Array(Array &&array)
        : dims_num(array.dims_num),
          dims(array.dims),
          data(array.data)
    {
        array.dims_num = 0;
        array.dims = nullptr;
        array.data = nullptr;
    }

    Array& Array::operator = (const Array& array)
    {
        if(this != &array)
        {
            dims_num = array.dims_num;
            size_t *new_dims = new size_t[dims_num];
            size_t k = dims_num ? 1 : 0;
            for(size_t i = 0; i < dims_num; ++i)
            {
                k *= array.dims[i];
                new_dims[i] = array.dims[i];
            }
            bool *new_data = new bool[k];
            memcpy(new_data, array.data, k);
            delete[] data;
            delete[] dims;
            data = new_data;
            dims = new_dims;
        }
        return *this;
    }

    Array& Array::operator = (Array&& array)
    {
        if(this != &array)
        {
            dims_num = array.dims_num;
            delete[] dims;
            delete[] data;
            dims = array.dims;
            data = array.data;
        }
        return *this;
    }

    bool Array::operator [] (const size_t *coords) const
    {
        return data[get_index(coords)];
    }

    bool& Array::operator [] (const size_t *coords)
    {
        bool& element = data[get_index(coords)];
        return element;
    }

    bool Array::operator == (const Array& array) const
    {
        if(this == &array)
            return true;
        if(dims_num != array.dims_num)
            return false;
        if(memcmp(dims, array.dims, dims_num*sizeof(size_t)))
            return false;
        std::size_t k = dims_num ? 1 : 0;
        for(size_t i = 0; i < dims_num; ++i)
            k *= dims[i];
        return !memcmp(data, array.data, k);
    }

    bool Array::operator != (const Array& array) const
    {
        return !operator ==(array);
    }

    size_t Array::get_dims_num() const
    {
        return dims_num;
    }

    size_t Array::get_dim_size(size_t i) const
    {
        return dims[i];
    }




struct S {
    bool* p;
    std::size_t* array;
    std::size_t dim;
};
/*
namespace {

inline std::size_t get_index(const_S_t acme, const std::size_t *coord) {
    std::size_t step = 1;
    std::size_t d = 0;
    for(std::size_t i = 0; i < acme->dim; ++i) {
        d += coord[i] * step;
        step *= acme->array[i];
    }
    return d;
}
}

S_t init(const std::size_t *array, bool symbol, std::size_t dim) {
    S_t acme = new S;
    acme->array = new std::size_t[dim];
    acme->dim = dim;
    std::size_t k = 1;
    for(std::size_t i = 0; i < dim; ++i) {
        k *= array[i];
        acme->array[i] = array[i];
    }
    acme->p = new bool[k];
    memset(acme->p, symbol, k);
    return acme;
}

std::size_t dimension(const_S_t acme) {
    return acme->dim;
}

const std::size_t* array_size(const_S_t acme) {
    return acme->array;
}

void rec_symbol(S_t acme, bool symbol, const std::size_t *coord) {
    acme->p[get_index(acme, coord)] = symbol;
}

bool read_symbol(const_S_t acme, const std::size_t *coord) {
    return acme->p[get_index(acme, coord)];
}

bool compare(const_S_t acme1, const_S_t acme2) {
    std::size_t k = 1;
    if(acme1->dim != acme2->dim)
        return false;
    for(std::size_t i = 0; i < acme1->dim; ++i) {
        if(acme1->array[i] != acme2->array[i])
            return false;
        k *= acme1->array[i];
    }
    return memcmp(acme1->p, acme2->p, k*sizeof(bool)) == 0;
}

void destroy(S_t acme) {
    delete[] acme->p;
    delete[] acme->array;
    delete acme;
}
*/
}
