#include <iostream>

#include "cxxlogger.h"

int main()
{
    CxxLogger ml("MAIN");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    std::cout << "Hello, World!" << std::endl;
    ml.save(CxxLogger::LOGG_TYPE::WARNING_TYPE, "warning information");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::ERROR_TYPE, "error");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    ml.save(CxxLogger::LOGG_TYPE::INFO_TYPE, "start program");
    return 0;
}
