#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class Span
{
    private:
        std::vector<int>    *vec;
        const unsigned int  MaxNumber;
        unsigned int        CurrentNumber;
        Span();
    public:
        Span(unsigned int N);
        Span(const Span &copy);
        Span operator=(const Span &copy);
        ~Span();
        void    addNumber(int NewNum);
        int     shortestSpan();
        int     longestSpan();
        void    addManyNumber(std::vector<int> &container);
        int    ClassIsFull();
        int    NoSpanFound();
};

#endif