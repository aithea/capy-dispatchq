//
// Created by denn nevera on 30/10/2018.
//


#include "capy_dispatchq.hpp"

#include <string>
#include <streambuf>
#include <strstream>
#include <iostream>

int random(int min, int max)
{
    static bool first = true;
    if (first)
    {
        srand( time(NULL) );
        first = false;
    }
    return min + rand() % (( max + 1 ) - min);
}


int main()
{
    try {
        auto main_thread_id = std::this_thread::get_id();

        auto q99 = capy::dispatchq::Queue(99);
        auto q10 = capy::dispatchq::Queue(10);

        int w = 10;
        for (int j = 0; j < w ; ++j) {
            q10.async([=,&q10]{
                std::cerr << "\n=Q10-[" << j << "] " << q99.is_default() << ", " << q99.get_id()<< std::endl << std::flush;
                std::this_thread::sleep_for(std::chrono::seconds(1));
            });
        }

        for (int j = 0; j < 100 ; ++j) {
            q99.async([=,&q99]{
                std::cerr << "\n#Q99-[" << j << "] " << q99.is_default() << ", " << q99.get_id() << std::endl << std::flush;
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
            });
        }


        for (int j = 0; j < 100 ; ++j) {
            capy::dispatchq::main::async([=]{
                std::cerr << "\n@A00-[" << j << "] " << main_thread_id << ", "
                << capy::dispatchq::Queue::get_default()->is_default() << ", " << capy::dispatchq::Queue::get_default()->get_id() << std::endl << std::flush;

                std::this_thread::sleep_for(std::chrono::milliseconds(100));

                if (j>20) {
                  capy::dispatchq::main::loop::exit();
                }

            });
        }

      capy::dispatchq::main::loop::run();

        std::cerr << "Exited ......" << std::endl;

        q10.stop();
        q99.stop();
    }
    catch (...) {
        std::cerr << "Error ......" << std::endl;
    }

    exit(0);
}
