#include "Span.hpp"

int main(void)
{
    try
    {
        {
            Span sp = Span(5);

            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            // sp.addNumber(9);
            std::cout << "shortestSpan is:" << sp.shortestSpan() << std::endl;
            std::cout << "longestSpan is:" << sp.longestSpan() << std::endl;
        }

        {
            Span sp = Span(10000);
            std::vector<int> big_vec;

            for (int i = 0; i < 10000; ++i)
                big_vec.push_back(i);
            sp.addManyNumber(big_vec);
            std::cout << "\nshortestSpan is:" << sp.shortestSpan() << std::endl;
            std::cout << "longestSpan is:" << sp.longestSpan() << std::endl;
        }
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}