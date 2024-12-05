#ifndef wikipage_h
#define wikipage_h

#include <string>
#include <vector>

class WikiPage {

    public:
    /**
     * @param title a constant std::string that represents the title of the wiki page. It passes a reference.
     * 
     * @brief Constructor for WikiPage
     */
    WikiPage(const std::string& title);

    /**
     * @return this function returns the title of the wikipage
     * @brief It allows other functions to use the title from the wikipages to check
     * @brief whether it is able to create a wiki ladder
     */
    std::string getTitle() const;
    
    /**
     * @return this function returns all std::vector<std::string> links
     * @brief this function returns all the links that is on the wiki page
     */
    std::vector<std::string> getAllLinks() const;

    /**
     * @param link a function that takes a constant std::string of the link that you want to add into the wiki page
     * @brief It adds the link to the wiki page, allowing others to access it. It creates a reference to the std::string link.
     */
    void addLinks(const std::string& link);

    private:
    /**
     * @brief this is the title of the wiki page
     */
    std::string title;

    /**
     * @brief These are the links of the wiki page, it stores all the links in a vector
     */
    std::vector<std::string> links;
};

#endif