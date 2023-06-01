#include "Span.hpp"

int main() 
{
    try {
        Span span(10000);

        for (int i = 0; i < 10000; ++i) {
            span.addNumber(i);
        }

        int shortest = span.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;

        int longest = span.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    return 0;
}
