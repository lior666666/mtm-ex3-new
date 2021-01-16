#include "partA/exceptions.h"
#include <vector>
#include <iostream>
#include <memory>

namespace mtm{
    template <typename T>
    std::vector<T> slice(std::vector<T> vec, int start, int step, int stop)
    {
        size_t size = vec.size();
        if (start < 0 || start >= size || stop < 0 || stop > size || step <= 0)
        {
            throw BadInput();
        }
        std::vector<T> sliced_vector;
        if (start >= stop)
        {
            return sliced_vector;
        }
        for (int i = start; i < stop; i += step)
        {
            sliced_vector.push_back(vec.at(i));
        }
        return sliced_vector;
    }
}

class A {
    public:
        std::vector<std::shared_ptr<int>> values;
        void add(int x)
        {
            std::shared_ptr<int> ptr(new int(x));
            values.push_back(ptr);
        }
};

int main() {
    /*try{
        std::vector<std::vector<char>> warp_vec_sliced1;
        std::vector<std::vector<int>> warp_vec_sliced2;
        std::vector<char> vec1 {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
        std::vector<int> vec2 {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
        warp_vec_sliced1.push_back(mtm::slice(vec1, 0, 2, 4));
        warp_vec_sliced1.push_back(mtm::slice(vec1, 1, 1, 5));
        warp_vec_sliced1.push_back(mtm::slice(vec1, 3, 3, 10));
        warp_vec_sliced2.push_back(mtm::slice(vec2, 0, 10, 14));
        warp_vec_sliced2.push_back(mtm::slice(vec2, 6, 1, 12));
        warp_vec_sliced2.push_back(mtm::slice(vec2, 3, 5, 15));
        for(size_t j = 0; j < warp_vec_sliced1.size(); ++j)
        {
            for(size_t i = 0; i < warp_vec_sliced1[j].size(); ++i) {
                std::cout << "**char** " << j << " try: " << warp_vec_sliced1[j][i] << std::endl;
            }
        }
        for(size_t j = 0; j < warp_vec_sliced2.size(); ++j)
        {
            for(size_t i = 0; i < warp_vec_sliced2[j].size(); ++i) {
                std::cout << "**int** " << j << " try: " << warp_vec_sliced2[j][i] << std::endl;
            }
        }
    } catch (mtm::BadInput) {
        std::cout << "BadInput" << std::endl;
    }**/
    A a, sliced;
    a.add(0); a.add(1); a.add(2); a.add(3); a.add(4); a.add(5);
    sliced.values = mtm::slice(a.values, 1, 1, 4);
    *(sliced.values[0]) = 800;
    std::cout << *(a.values[1]) << std::endl;
    return 0;
}