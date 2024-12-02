#ifndef wikigraph_h
#define wikigraph_h

#include <string>
#include <vector>
#include "wikipage.h"

class WikiGraph {

    public:
    
    void addPage(const WikiPage& page);

    void addLink(const std::string& originalTitle, const std::string& newTitle);

    std::vector<std::string> findBestPath(const std::string& startTitle, const std::string& endTitle);

    private:

    std::vector<WikiPage> pages;

};

#endif