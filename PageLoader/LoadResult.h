#ifndef LOAD_RESULT_H
#define LOAD_RESULT_H

#include "LoadResult.h"
#include <string>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp> 

class LoadResult
{
private:
    long int status;
    std::string body;
public:
    
    LoadResult() {};

    LoadResult(const long int& STATUS, const std::string& BODY)
    : status(STATUS), body(BODY)
    {

    }

    //std::string get_body(const std::string& url, long& curlinfoResponseCode);

    std::string return_body(); // getter
    
   // long int get_status();

    long int return_status();
};



#endif