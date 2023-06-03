#include "Span.hpp"

int main() 
{
    try {
        Span span(5);

        span.addNumber(6);
		span.addNumber(3);
		span.addNumber(17);
		span.addNumber(9);
		span.addNumber(11);

        int shortest = span.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;

        int longest = span.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    try{
        Span v2(10000);
        std::vector<int> v3;
        for(int i = 0; i < 10000; i++)
            v3.push_back(i);
        v2.addRange(v3.begin(), v3.end());
        int shortest = v2.shortestSpan();
        std::cout << "Shortest span: " << shortest << std::endl;
        int longest = v2.longestSpan();
        std::cout << "Longest span: " << longest << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;   
}
