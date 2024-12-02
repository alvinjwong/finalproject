#ifndef wikipage_h
#define wikipage_h

#include <string>
#include <vector>

class WikiPage {

    public:
    WikiPage(const std::string& title);

    std::string getTitle() const;

    std::vector<std::string> getAllLinks() const;

    void addLinks(const std::string& link);

    private:
    std::string title;
    std::vector<std::string> links;
};

#endif