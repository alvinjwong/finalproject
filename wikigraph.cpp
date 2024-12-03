#include "wikipage.h"
#include "wikigraph.h"
#include <vector>
#include <string>
#include <algorithm>

void WikiGraph::addPage(const WikiPage& page) {
    pages.push_back(page);
}

void WikiGraph::addLink(const std::string& originalTitle, const std::string& newTitle) {
    for (auto& page : pages) {
        if (page.getTitle() == originalTitle) {
            page.addLinks(newTitle);
            return;
        }
    }
}

std::vector<std::string> WikiGraph::findBestPath(const std::string& startTitle, const std::string& endTitle) {
    std::vector<std::string> currentPath = {startTitle};
    std::vector<std::string> visitedPath = {startTitle};
    std::vector<std::vector<std::string>> paths = {currentPath};

    while (!paths.empty()) {
        currentPath = paths.back();
        paths.pop_back();
        const std::string& currentPageTitle = currentPath.back();

        if (currentPageTitle == endTitle) {
            return currentPath;
        }

        for (const auto& page : pages) {
            if (page.getTitle() == currentPageTitle) {
                for (const auto& link : page.getAllLinks()) {
                    if (std::find(visitedPath.begin(), visitedPath.end(), link) == visitedPath.end()) {
                        visitedPath.push_back(link);
                        std::vector<std::string> newPath = currentPath;
                        newPath.push_back(link);
                        paths.push_back(newPath);
                    }
                }
                break;
            }

        }

    }
    return {};
}

