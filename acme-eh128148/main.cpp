#include <iostream>
#include <random>
#include "array.hpp"

int rand(int min, int max) {
    static std::mt19937 prng(std::random_device{}());
    return std::uniform_int_distribution <> (min, max)(prng);
}

bool is_included(std::size_t x1, std::size_t y1,std::size_t z1,
                 std::size_t x2, std::size_t y2, std::size_t z2, std::size_t d) {
    return 4*((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) + (z1-z2)*(z1-z2)) <= d*d;
}

int main()
{
    using std::size_t;

    size_t a, b, c, n, d;
    std::cout << "Enter cheese's parametrs: width, height, depth; bomb's numbers and diameter" << '\n';
    if(!(std::cin >> a >> b >> c >> n >> d)) {
        std::cerr << "Incorrect data";
        return 1;
    }

    size_t dims[3] = {a, b, c};
    Array::Array array(3, dims, true);

    size_t x_bomb,y_bomb,z_bomb;
    size_t coords[3] = {};

    for(size_t q = 0; q < n; ++q) {
        x_bomb = rand(0, array.get_dim_size(0)-1);
        y_bomb = rand(0, array.get_dim_size(1)-1);
        z_bomb = rand(0, array.get_dim_size(2)-1);
        for(size_t i = 0; i < array.get_dim_size(0); ++i) {
            for(std::size_t j = 0; j < array.get_dim_size(1); ++j) {
                for(std::size_t k = 0; k < array.get_dim_size(2); ++k) {
                    if(is_included(x_bomb, y_bomb, z_bomb, i, j, k, d)) {
                        coords[0] = i;
                        coords[1] = j;
                        coords[2] = k;
                        array[coords] = false;
                    }

                }
            }
        }
    }
    std::cout << "Result: \n";

    for(size_t k = 0; k < array.get_dim_size(2); ++k) {
        coords[2] = k;
        std::cout << '\n';
        for(std::size_t i = 0; i < array.get_dim_size(0); ++i) {
            coords[0] = i;
            for(std::size_t j = 0; j < array.get_dim_size(1); ++j) {
                coords[1] = j;
                std::cout << (array[coords] ? '#': ' ');
            }
            std::cout << '\n';
        }
        std::cout << "-----";
    }
    std::cout << '\n';

}
