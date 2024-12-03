#include "wikigraph.h"
#include "wikipage.h"
#include <iostream>
#include <cassert>

//I used chatgpt to write me some unit tests to test my code

void runTests() {
    // Test 1: Adding a single page to the WikiGraph
    {
        WikiGraph graph;
        WikiPage page("Cat");
        graph.addPage(page);
        assert(graph.findBestPath("Cat", "Cat").size() == 1);
        std::cout << "Test 1 passed.\n";
    }

    // Test 2: Adding multiple pages to the WikiGraph
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        assert(graph.findBestPath("Cat", "Dog").size() == 0);
        std::cout << "Test 2 passed.\n";
    }

    // Test 3: Adding a link between pages
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addLink("Cat", "Dog");
        assert(graph.findBestPath("Cat", "Dog").size() == 2);
        std::cout << "Test 3 passed.\n";
    }

    // Test 4: No link between pages
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        assert(graph.findBestPath("Cat", "Dog").size() == 0);
        std::cout << "Test 4 passed.\n";
    }

    // Test 5: Adding a link to itself
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addLink("Cat", "Cat");
        assert(graph.findBestPath("Cat", "Cat").size() == 1);
        std::cout << "Test 5 passed.\n";
    }

    // Test 6: Path with multiple links
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addPage(WikiPage("Animal"));
        graph.addLink("Cat", "Dog");
        graph.addLink("Dog", "Animal");
        assert(graph.findBestPath("Cat", "Animal").size() == 3);
        std::cout << "Test 6 passed.\n";
    }

    // Test 7: Cyclic links
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addLink("Cat", "Dog");
        graph.addLink("Dog", "Cat");
        assert(graph.findBestPath("Cat", "Dog").size() == 2);
        std::cout << "Test 7 passed.\n";
    }

    // Test 8: No pages in graph
    {
        WikiGraph graph;
        assert(graph.findBestPath("Cat", "Dog").size() == 0);
        std::cout << "Test 8 passed.\n";
    }

    // Test 9: Finding path when start equals end
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        assert(graph.findBestPath("Cat", "Cat").size() == 1);
        std::cout << "Test 9 passed.\n";
    }

    // Test 10: Finding path when page does not exist
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        assert(graph.findBestPath("Cat", "Dog").size() == 0);
        std::cout << "Test 10 passed.\n";
    }

    // Test 11: Multiple paths available
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addPage(WikiPage("Animal"));
        graph.addLink("Cat", "Dog");
        graph.addLink("Cat", "Animal");
        graph.addLink("Dog", "Animal");
        assert(graph.findBestPath("Cat", "Animal").size() == 2);
        std::cout << "Test 11 passed.\n";
    }

    // Test 12: Disconnected graph
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addPage(WikiPage("Fish"));
        graph.addLink("Cat", "Dog");
        assert(graph.findBestPath("Cat", "Fish").size() == 0);
        std::cout << "Test 12 passed.\n";
    }

    // Test 13: Complex graph with branches
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addPage(WikiPage("Fish"));
        graph.addPage(WikiPage("Bird"));
        graph.addLink("Cat", "Dog");
        graph.addLink("Dog", "Fish");
        graph.addLink("Cat", "Bird");
        assert(graph.findBestPath("Cat", "Fish").size() == 3);
        std::cout << "Test 13 passed.\n";
    }

    // Test 14: Self-loop with other links
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addLink("Cat", "Cat");
        graph.addLink("Cat", "Dog");
        assert(graph.findBestPath("Cat", "Dog").size() == 2);
        std::cout << "Test 14 passed.\n";
    }

    // Test 15: Path with no links to target
    {
        WikiGraph graph;
        graph.addPage(WikiPage("Cat"));
        graph.addPage(WikiPage("Dog"));
        graph.addPage(WikiPage("Bird"));
        graph.addLink("Cat", "Dog");
        assert(graph.findBestPath("Dog", "Bird").size() == 0);
        std::cout << "Test 15 passed.\n";
    }
}

int main() {
    runTests();
    std::cout << "All tests passed successfully.\n";
    return 0;
}
