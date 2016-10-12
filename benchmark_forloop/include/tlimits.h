#ifndef LOCLIMITS_H_
#define LOCLIMITS_H_
#include <limits>
#include <cmath>

class TLimits{

    public:

       static void print(){
            std::cout << "sizeof\n";
            std::cout << "------\n";
            std::cout<< "sizeof(int):                  "   << sizeof(int) << "\n";
            std::cout<< "sizeof(float):                "   << sizeof(float) << "\n";
            std::cout<< "sizeof(double):               "   << sizeof(double) << "\n";

            std::cout<< "sizeof(unsigned int):         "   << sizeof(unsigned int) << "\n";
            std::cout<< "sizeof(unsigned long int):    "   << sizeof(unsigned long int) << "\n";

            std::cout<< "sizeof(long double):          "   << sizeof(long double) << "\n";

            std::cout<< "max values\n";
            std::cout<< "----------\n";
            std::cout<< "max(int) :               "  << std::numeric_limits<int>::max() << "\n";
            std::cout<< "max(float) :             "  << std::numeric_limits<float>::max() << "\n";
            std::cout<< "max(double) :            "  << std::numeric_limits<double>::max() << "\n";
            std::cout<< "max(unsigned int) :      "  << std::numeric_limits<unsigned int>::max() << "\n";
            std::cout<< "max(unsigned long int) : "  << std::numeric_limits<unsigned long int>::max() << "\n";
            std::cout<< "max(long double) :       "  << std::numeric_limits<long double>::max() << "\n";

            std::cout<< "smallest fraction with double: " << std::endl;
            double tmp = 1.0;
            for(size_t i = 306 ; i <= 308;i++){
                std::cout<< "1.0/(10^"<< i << "): " << tmp / std::pow(10.0,i)  << std::endl;
            }

        }

};

#endif
