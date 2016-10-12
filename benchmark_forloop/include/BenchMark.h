#ifndef BENCHMARK_H_
#define BENCHMARK_H_

#include "ForLoopTraversal.h"
#include "getcputime.h"
#include <assert.h>
#include <chrono>

namespace bmk{
struct Data{
    int    Mb;
    double long time;
    std::string    type;
};
}

using namespace bmk;

class BenchMark{

public:

    ~BenchMark(){
        if(methods != NULL){
            delete methods;
            methods = NULL;
        }
    }

    void init(types METHOD,int Mb){

        if(METHOD == TB)
        {
            methods = dynamic_cast<Base_cube*>( new Text_book_cube() );
        }else{
            methods = dynamic_cast<Base_cube*>( new Linearised_cube<int>(METHOD) );
        }

        data.type = enum2str(METHOD);

        std::cout<< "type\t" << data.type << std::endl;

        unsigned long long num_bytes = ( Mb * 1000000.0);
        unsigned long long num_states = num_bytes/(unsigned long long)sizeof(int);

        data.Mb = Mb;
        methods->init(num_states);
        methods->print_size_memory();


    }

    void run(){

        double v  = 0;
        const auto start_time = std::chrono::steady_clock::now();

        v = methods->sum();

        data.time = std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now() - start_time).count() / 1000000000.0;
        std::cout<< "data.time: " << data.time << std::endl;
    }

private:


    Base_cube * methods;

public:

    Data data;



};

#endif
