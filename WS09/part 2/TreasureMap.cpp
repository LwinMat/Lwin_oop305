// Workshop 9 - Multi-threading
// TreasureMap.cpp
// Michael Huang

#include <iostream>
#include <fstream>
#include <string>
#include  <functional>
#include <thread>
#include<numeric>
#include<algorithm>
#include <future>
#include "TreasureMap.h"

namespace sdds{

    size_t digForTreasure(const std::string& str, char mark){
        size_t cnt = 0;
        for (auto& x : str){
            if (x == mark){
                cnt++;
            }
        }
        return cnt;
    }

    TreasureMap::TreasureMap(const char* filename){
        std::fstream fin(filename);
        if (fin){
            fin >> rows;
            fin.ignore();
            map = new std::string[rows];
            size_t idx = 0;
            while(fin){
                getline(fin, map[idx]);
                idx++;
            }
            colSize = map[0].length();
        }
        else {
            throw std::string(filename) + " cannot be opened";
        }
    }

    TreasureMap::~TreasureMap(){
        delete [] map;
    }

    std::ostream& TreasureMap::display(std::ostream& os) const{
        if (map){
            for (size_t i = 0; i < rows; ++i){
                os << map[i] << std::endl;
            }
        }
        else 
            os << "The map is empty!" << std::endl;
        return os;
    }

    void TreasureMap::enscribe(const char* filename){
        // Binary write
        if (map){
            // TODO: Open a binary file stream to the filename and
            //         then write the row number to the binary file 
            //         then each of the rows of the map.
            //       If the file cannot be open, raise an exception to
            //         inform the client.
            std::ofstream W_file(filename, std::ios::out | std::ios::binary | std::ios::trunc | std::ios::ate);
            
            if (W_file.is_open() == false) {
                throw std::string("File cannot open!");
                
            }
            else {
                size_t i = 0;
                W_file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
                W_file.write(reinterpret_cast<char*>(&colSize), sizeof(colSize));

                while (i < rows) {
                    W_file.write(map[i].c_str(), colSize);
                    i++;
                }


                W_file.close();
            }

            

            // END TODO
        }
        else{
            throw std::string("Treasure map is empty!");
        }
    }

    void TreasureMap::recall(const char* filename){
        // Binary read
        // TODO: Open a binary file stream to the filename
        //         and read from it to populate the current object.
        //       The first 4 bytes of the file will be the number of rows
        //         for the map followed another 4 bytes for the colSize
        //         of each row in the map.
        //       Afterwards is each row of the map itself.
        //       If the file cannot be open, raise an exception to inform
        //         the client.
        std::ifstream f_read;
        f_read.open(filename, std::ios::in | std::ios::binary);

        if (f_read.is_open() == false) {
            throw std::string("File cannot open!");
        }
        else {
            
            f_read.read(reinterpret_cast<char*>(&rows), sizeof(rows));
            f_read.read(reinterpret_cast<char*>(&colSize), sizeof(colSize));

            this->map = new std::string[rows];

            auto i = 0u;
            char* temp = new char[colSize+1] {};
            while (i < rows) {
                f_read.read(temp, colSize);
                map[i] = temp;
                i++;
            }
            delete[] temp;

        }

        // END TODO
    }

    void TreasureMap::clear(){
        delete [] map;
        map = nullptr;
        rows = 0;
        colSize = 0;
    }

    size_t TreasureMap::findTreasure(char mark){
        size_t count = 0;

        // TODO: For part 2, comment this "for" loop and write the multihreaded version.
        /*for (size_t i = 0; i < rows; ++i){
            count += digForTreasure(map[i], mark);
        }*/
        size_t startIn = 0;
        size_t iterate = rows / 4;

        std::packaged_task<size_t()> task1(std::bind(digForTreasure, stringCreater(startIn, iterate), mark));
        auto result1 = task1.get_future();
        std::packaged_task<size_t()> task2(std::bind(digForTreasure, stringCreater(startIn, iterate), mark));
        auto result2 = task2.get_future();
        std::packaged_task<size_t()> task3(std::bind(digForTreasure, stringCreater(startIn, iterate), mark));
        auto result3 = task3.get_future();
        std::packaged_task<size_t()> task4(std::bind(digForTreasure, stringCreater(startIn, iterate), mark));
        auto result4 = task4.get_future();

        //creating threads
        std::thread t1(std::move(task1));
        std::thread t2(std::move(task2));
        std::thread t3(std::move(task3));
        std::thread t4(std::move(task4));

        t1.join();
        t2.join();
        t3.join();
        t4.join();

        count += result1.get();
        count += result2.get();
        count += result3.get();
        count += result4.get();

        return count; 

    }
    std::string TreasureMap::stringCreater(size_t& pos, size_t R)
    {
        std::string s;
        size_t start = pos;
        for (size_t i = start; (i < (start + R) && i < rows); ++i,pos++) {
            s += map[i];
        }
        return s;

    }
}

