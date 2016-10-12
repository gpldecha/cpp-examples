#ifndef FORLOOPTRAVERSALS_H_
#define FORLOOPTRAVERSALS_H_

#include <vector>
#include <cmath>
#include <iostream>

typedef enum{TB,L1,L2,L3,L4,L5} types;

std::string enum2str(types type){
    std::string name = "";
    switch(type){
    case TB:
    {
        name = "TB";
        break;
    }
    case L1:
    {
        name = "L1";
        break;
    }
    case L2:
    {
        name = "L2";
        break;
    }
    case L3:
    {
        name = "L3";
        break;
    }
    case L4:
    {
        name = "L4";
        break;
    }
    case L5:
    {
        name = "L5";
        break;
    }
    }
    return name;
}


template <typename T>
struct vec3D {
    typedef std::vector<std::vector<std::vector<T> > > type;
};


class Base_cube{

public:

    virtual void init(unsigned long long nbStates) = 0;
    virtual unsigned long long  sum() const = 0;

    void print_size_memory(){
        std::cout<< "size_memory = " << size_memory/1000.0 << "kb" << std::endl;
        std::cout<< "size_memory = " << size_memory/1000000.0 << "Mb" << std::endl;
    }

public:

    unsigned long long num_states;
    long int size_memory;

};


class Text_book_cube : public Base_cube{

public:

    void init(unsigned long long nbStates){

        unsigned long long bin_s = static_cast<unsigned long long>(std::floor(std::cbrt(nbStates)));
        if(bin_s == 0){
            bin_s = 1;
        }
        num_states = std::pow(bin_s,3.0);

        std::cout<< "nbStates: " << nbStates <<  "\tbins_s: " << bin_s << "\tactual nbStates: " << num_states << std::endl;

        cube = vec3D<int>::type(bin_s, std::vector<std::vector<int> >(bin_s, std::vector<int>(bin_s, 1.0)));

        size_memory = sizeof(int) * num_states;


    }

    unsigned long long  sum() const {
        unsigned long long  v = 0;
        for(size_t i = 0; i < cube.size(); i++){
            for(size_t j = 0; j < cube[i].size();j++){
                for(size_t k = 0; k < cube[i][j].size();k++){
                          v += cube[i][j][k] + std::rand();
                }
            }
        }
        return v;
    }

private:

     vec3D<int>::type cube;
};


template <typename T>
class Linearised_cube : public Base_cube{

public:

    Linearised_cube(types lt){
        ltypes = lt;
    }

    void init(unsigned long long nbStates){

        long int bin_s = static_cast<long int>(std::floor(std::cbrt(nbStates)));
        if(bin_s == 0){
            bin_s = 1;
        }
        num_states = std::pow(bin_s,3.0);

        std::cout<< "nbStates: " << nbStates <<  "\tbins_s: " << bin_s << "\tactual nbStates: " << num_states << std::endl;
        cube.resize(num_states);

        size_memory = sizeof(int) * num_states;

        width  = bin_s;
        height = bin_s;
        depth  = bin_s;

    }

    unsigned long long  sum() const{

        unsigned long long  v = 0;

        switch(ltypes){
        case L1:
        {
            for ( int i = 0; i < width; ++i )
                for ( int j = 0; j < height; ++j )
                    for ( int k = 0; k < depth; ++k )
                        v += cube[(long)i*(long)height*(long)depth + (long)j*(long)depth + (long)k] + std::rand();
            break;
        }
        case L2:
        {

            long index = 0;
            for ( int i = 0; i < width; ++i )
                for ( int j = 0; j < height; ++j )
                    for ( int k = 0; k < depth; ++k )
                        v += cube[index++] + std::rand();
            break;
        }

        case L3:
        {
            long index = 0;
            const long indexend = (long)width * (long)height * (long)depth;
            while ( index != indexend )
                    v += cube[index++] + std::rand();

            break;
        }
        case L4:
        {
            break;
        }
        }


        return v;
    }

private:

    types ltypes;

private:

    std::vector<T> cube;
    int width,height,depth;

};




#endif
