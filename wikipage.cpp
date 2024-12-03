#include "wikipage.h"
#include <string>
#include <vector>


WikiPage::WikiPage(const std::string& title) : title(title) {}

std::string WikiPage::getTitle() const {
    return title;
}

std::vector<std::string> WikiPage::getAllLinks() const {
    return links;
}

void WikiPage::addLinks(const std::string& link) {
    links.push_back(link);
}