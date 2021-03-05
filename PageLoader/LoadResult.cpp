#include "LoadResult.h"
#include <string>
#include <iostream>
#include <curlpp/cURLpp.hpp>
#include <curlpp/Options.hpp> 

std::string LoadResult::return_body()
{
    return body;
}

long int LoadResult::return_status()
{
    return status;
}