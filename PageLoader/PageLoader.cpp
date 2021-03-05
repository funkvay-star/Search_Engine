#include "LoadResult.cpp"
#include "PageLoader.h"
#include <string>
#include <iostream>

std::string document;


size_t got_data(char* buffer, size_t itemsize, size_t nitems, void* ignorethis)
{
    std::cout << document << "\n";
    size_t bytes = itemsize * nitems;

    document += (std::string(buffer, bytes));

    return bytes;
}

LoadResult PageLoader::get_info_by_url(const std::string& url)
{
    long curlinfoResponseCode = 0;
   // LoadResult getting_body;

    std::string answer = get_data(url, curlinfoResponseCode);

    if(answer == "")
    {
        std::cout << url << "getting ERROR while requesting\n";
        return LoadResult(-1, "");
    }

    return LoadResult(curlinfoResponseCode, answer);
}

std::string PageLoader::get_data(const std::string& url, long& curlinfoResponseCode)
{
        CURL *curl = curl_easy_init();

        if(!curl)
        {
            std::cout << "init failed\n";
            //return "false";

            curlinfoResponseCode = -1;
            return "";
        }

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str()); ///////
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, got_data);

        CURLcode result = curl_easy_perform(curl);
        if(result != CURLE_OK)
        {
            std::cout << "download problem: \n";
            //std::cout << curl_easy_strerror(result);

            curlinfoResponseCode = -1;
            return "";
        }

        curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, curlinfoResponseCode);

        curl_easy_cleanup(curl);
        return document;
}

int main()
{
    PageLoader a;
    LoadResult b;

    int x = 2;
    std::cout << x;

    b = a.get_info_by_url("https://curl.se/libcurl/c/");

    std::cout << b.return_body();
}