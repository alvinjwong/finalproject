#ifndef wikigraph_h
#define wikigraph_h

#include <string>
#include <vector>
#include "wikipage.h"

class WikiGraph {

    public:
    
    /**
     * @param page This takes a reference of a Wikipage
     * @brief This adds a page into the vector of WikiPage of pages
     */
    void addPage(const WikiPage& page);

    /**
     * @param originalTitle, newTitle both of these are const std::string&
     * @brief This takes the original title of the page you are on and the title of the new wiki page you are trying to hyperlink
     * @brief and adds on the link between these two pages.
     */
    void addLink(const std::string& originalTitle, const std::string& newTitle);

    /**
     * @param startTitle, endTitle this takes const std::string& for both of these parameters
     * @brief This loops through every possible path and finds the best path from the original wiki page to the ending wiki page.
     * @details This function first starts with setting the current path and the visited path of startTitle, because that is where we first begin
     * This also adds the current place we are at into a {start} path. After it checks if there are more paths to go through, and selects
     * the last {wikipedia paths} that is in the paths vector. It gets rid of the current paths vector so it won't loop again, and then
     * it takes the last page/room of the {currentpath} path, for ex: {pencil, lead} will take lead, and then it will check it against
     * the final endTitle and see if it matches. If it matches, thats the best path, if else, we continue. We then find the page that the
     * part of the path is at, and get all the links that are linked to that page. After we check all of the links to see if we had been there
     * before. If we have not been there, we continue. We then add the next link to the visitedpath vector so we will not loop that page again,
     * and then we create a copy of the place we are at and the path of pages we were on, and we add on the next link we were about to go to
     * onto that copy of the path for a new path. We then add this new path into our paths vector and update what paths we have to traverse.
     * we also go back to the for loop and check if the originalpath had any other links to other pages, and we repeat the checking for visits,
     * creation of new paths, and adding new paths onto paths vector for every link. We repeat this process until we reach the end and determine
     * the best path. 
     */
    std::vector<std::string> findBestPath(const std::string& startTitle, const std::string& endTitle);

    private:
    
    /**
     * @brief this is a vector of WikiPages with the name of the vector called pages. It stores WikiPage objects.
     */
    std::vector<WikiPage> pages;

};

#endif