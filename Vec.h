#ifndef VEC_GUARD
#define VEC_GUARD

#include <cstdlib>
#include <stdexcept>

class Vec {
    private:
        int* data;
        int* limit;
    public:
        Vec(): data(NULL) {  }
        explicit Vec(size_t n) {
            data = new int[n];
            limit = data + n;
        }
        Vec(size_t n, int val) {
            data = new int[n];
            limit = data + n;
            for(int* b = data; b != limit; b++)
                *b = val;
        }
        // copy constructor
        Vec(const Vec& arr){
            size_t n = arr.size();
            data = new int[n];
            limit = data + n;
            int* azer = data;
            for(int* b = arr.data; b != arr.limit; b++, azer++){
                *azer  = *b;
            }
        }
        // move constructor
        Vec(Vec&& arr){
            data = arr.data;
            limit = arr.limit;
            arr.data = NULL;
            arr.limit = NULL;
        }
        Vec& operator=(const Vec& rhs){
            if(this != &rhs){
                size_t n = rhs.size();
                data = new int[n];
                limit = data + n;
                int* azer = data;
                for(int* b = rhs.data; b != rhs.limit; b++, azer++){
                    *azer  = *b;
                }
            }
        }
        int& operator[](size_t idx){
            if(idx >= size())
                throw std::out_of_range("waaa yal rojla!");
            return data[idx];
        }

        int operator[](size_t idx) const {
            if(idx >= size())
                throw std::out_of_range("waaa yal rojla!");
            return data[idx];
        } 

        int* begin(){
            return data;
        }

        const int* begin() const {
            return data;
        }

        int* end(){
            return limit;
        }
        const int* end() const {
            return limit;
        }


        ~Vec() {
            delete[] data;
        }

        size_t size() const {
            return limit - data;
        }
};

#endif