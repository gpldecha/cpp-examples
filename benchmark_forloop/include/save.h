#ifndef SAVE_H_
#define SAVE_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>

#include "BenchMark.h"

class Save{


public:

    void save_to_file(const std::vector<Data>& data){

        if(data.size() == 0){
            std::cout<< "data.size = 0, no data to save" << std::endl;
            return;
        }

        std::ofstream file;

        std::string file_name = "/home/guillaume/MatlabWorkSpace/bigO/benchmark_save";
        file_name = file_name + "/" + data[0].type + "_" + currentDateTime() + ".csv";
        file.open(file_name);

        if(file){
           /* file << "description\n";
            file << "-----------\n\n";
            file << "type: " << data[0].type << "\n\n";
            file << "data\n";
            file << "----\n\n";*/
            for(size_t i = 0; i < data.size();i++){
                file << data[i].Mb << "," << prd(data[i].time,15) << "\n";
            }
            file.close();
            std::cout<< "file: " << file_name << "\tsaved !" << std::endl;
        }else{
            std::cout<< "failed to open : " << file_name << " !" << std::endl;
        }



    }

private:



                        /* Convert double to string with specified number of places after the decimal
                                   and left padding. */
    std::string prd(double x, const int width) {
                        std::stringstream ss;
                        ss << std::fixed << std::right;
                        ss.fill(' ');        // fill space around displayed #
                        ss.width(width);     // set  width around displayed #
                        //ss << std::scientific;
                        //ss << ss.precision(decDigits);
                        ss << x;
                        return ss.str();
    }

    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    const std::string currentDateTime() {
        std::time_t     now = time(0);
        std::tm *localTime = localtime(&now);
        std::string time("");

        int Day    = localTime->tm_mday;
        int Month  = localTime->tm_mon + 1;
        int Year   = localTime->tm_year + 1900;
        int Hour   = localTime->tm_hour;
        int Min    = localTime->tm_min;
        int Sec    = localTime->tm_sec;


        time = time + std::string(boost::lexical_cast<std::string>(Day))    + "-"
                    + std::string(boost::lexical_cast<std::string>(Month))  + "-"
                    + std::string(boost::lexical_cast<std::string>(Year))   + "_"
                    + std::string(boost::lexical_cast<std::string>(Hour))   + "h"
                    + std::string(boost::lexical_cast<std::string>(Min))    + "m"
                    + std::string(boost::lexical_cast<std::string>(Sec))    + "s";

        return time;
    }



};

#endif
