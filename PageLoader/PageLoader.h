#ifndef PAGE_LOADER_H
#define PAGE_LOADER_H


#include <string>
#include "LoadResult.h"

class PageLoader
{
private:
   // std::string url;
   std::string get_data(const std::string& url, long& curlinfoResponseCode);

public:
    /*PageLoader(std::string URL)
    : url(URL)
    {
            
    }*/


    LoadResult get_info_by_url(const std::string& url);


};


#endif