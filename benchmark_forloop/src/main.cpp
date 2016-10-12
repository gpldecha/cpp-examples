#include "BenchMark.h"
#include "save.h"
#include "tlimits.h"

void benchmark(){
    std::vector<int> Mb(7);
    Mb[0] = 1;
    Mb[1] = 10;
    Mb[2] = 100;
    Mb[3] = 500;
    Mb[4] = 800;
    Mb[5] = 1000;
    Mb[6] = 2000;

    std::vector<Data> data(Mb.size());
    std::vector<types> all_types;
    all_types.push_back(TB);
    all_types.push_back(L1);
    all_types.push_back(L2);
    all_types.push_back(L3);

    Save save;

    for(size_t t = 3; t < 4;t++){
        for(size_t i = 0; i < Mb.size();i++){
            {
                std::cout<< " ===  Mb(" << Mb[i] << ") === " << std::endl;
                BenchMark benchMark;
                benchMark.init(all_types[t],Mb[i]);
                benchMark.run();
                data[i] = benchMark.data;
            }
        }

        save.save_to_file(data);
    }



}

void testlimits(){

    TLimits::print();

}



int main(int ac, const char* av[]){


   //testlimits();

    benchmark();

	return 0;
}

