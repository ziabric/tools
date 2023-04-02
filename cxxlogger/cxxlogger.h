#pragma once

#include <filesystem>
#include <string>
#include <chrono>
#include <fstream>

namespace fs = std::filesystem;

class CxxLogger
{
public:
    enum LOGG_TYPE
    {
        INFO_TYPE,
        WARNING_TYPE,
        ERROR_TYPE
    };
public:
    explicit CxxLogger(std::string fileName) : fileName_(fileName)
    {
        createFiles(fileName);
    }
    ~CxxLogger() = default;
private:
    std::string timeToString(std::chrono::system_clock::time_point t)
    {
        std::time_t time = std::chrono::system_clock::to_time_t(t);
        std::string time_str = std::ctime(&time);
        time_str.resize(time_str.size() - 1);
        return time_str;
    }
    void createFiles(std::string& fileName)
    {
        fileName_ = fileName;
        fs::remove_all("./logs");
        fs::create_directory("./logs");
        fullName_ = "./logs/" + fileName + ".log";
        std::ofstream file;
        file.open(fullName_.c_str());
        std::cout<<fullName_<<std::endl;
        if (file.is_open())
        {
            file<<"";
            file.close();
        }
    }
public:
    void save(CxxLogger::LOGG_TYPE loggType, std::string message)
    {
        std::string output;
    
        switch (loggType)
        {
            case LOGG_TYPE::INFO_TYPE:
            {
                output += "  info [ ";
                output += timeToString(std::chrono::system_clock::now());
                output += " ] -> ";
                output += message;
                output += "\n";
                break;
            }
            case LOGG_TYPE::WARNING_TYPE:
            {
                output += "WARNING [ ";
                output += timeToString(std::chrono::system_clock::now());
                output += " ] -> ";
                output += message;
                output += "\n";
                break;
            }
            case LOGG_TYPE::ERROR_TYPE:
            {
                output += "\nERROR [ ";
                output += timeToString(std::chrono::system_clock::now());
                output += " ] -> ";
                output += message;
                output += "\n";
                output += "\n";

                break;
            }
        }
        std::ofstream file;
        file.open(fullName_, std::ios::app);
        if (file.is_open())
        {
            file<<output;
            file.close();
        }
    }
private:
    std::string fileName_;
    std::string fullName_;
};