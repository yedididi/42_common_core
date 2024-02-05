#include "Span.hpp"

Span::Span() : MaxNumber(0)
{
    unsigned int &tmp = const_cast<unsigned int &>(this->MaxNumber);
    tmp = 0;
    this->CurrentNumber = 0;
}

Span::Span(unsigned int N) : MaxNumber(N)
{
    unsigned int &tmp = const_cast<unsigned int &>(this->MaxNumber);
    tmp = N;
    this->CurrentNumber = 0;
    this->vec = new std::vector<int>;
}

Span::Span(const Span &copy) : MaxNumber(copy.MaxNumber)
{
    if (&copy != this)
    {
        unsigned int &tmp = const_cast<unsigned int &>(this->MaxNumber); 
        tmp = copy.MaxNumber;
        this->CurrentNumber = copy.CurrentNumber;
        this->vec = new std::vector<int>;
        for (std::vector<int>::iterator itr = copy.vec->begin(); itr != copy.vec->end(); ++itr)
        {
            this->vec->push_back(*itr);
        }
    }
}

Span Span::operator=(const Span &copy)
{
    if (&copy != this)
    {
        unsigned int &tmp = const_cast<unsigned int &>(this->MaxNumber); 
        tmp = copy.MaxNumber;
        this->CurrentNumber = copy.CurrentNumber;
        this->vec = new std::vector<int>;
        for (std::vector<int>::iterator itr = copy.vec->begin(); itr != copy.vec->end(); ++itr)
        {
            this->vec->push_back(*itr);
        }
    }
    return (*this);
}

Span::~Span()
{
    delete (this->vec);
}

void    Span::addNumber(int NewNum)
{
    if (this->CurrentNumber == this->MaxNumber)
        throw ClassIsFull();
    this->vec->push_back(NewNum);
    this->CurrentNumber++;
}

int     Span::shortestSpan()
{
    int shortestSpan = 0;

    if (this->CurrentNumber == 0 || this->CurrentNumber == 1)
        throw NoSpanFound();
    Span sorted_vec(*this);
    std::sort(sorted_vec.vec->begin(), sorted_vec.vec->end());
    shortestSpan = *(sorted_vec.vec->end() - 1) - *(sorted_vec.vec->begin());
    for (std::vector<int>::iterator itr = sorted_vec.vec->begin(); itr != sorted_vec.vec->end() - 1; ++itr)
    {
        if (*itr && *(itr + 1) && (shortestSpan > (*(itr + 1) - *itr)))
            shortestSpan = (*(itr + 1) - *itr);
    }
    return (shortestSpan);
}

int     Span::longestSpan()
{
    int longestSpan = 0;
   
    if (this->CurrentNumber == 0 || this->CurrentNumber == 1)
        throw NoSpanFound();
    longestSpan = *std::max_element(this->vec->begin(), this->vec->end()) - *std::min_element(this->vec->begin(), this->vec->end());
    return (longestSpan);
}

void    Span::addManyNumber(std::vector<int>& container)
{
    std::vector<int>::iterator itr = container.begin();
    while (itr != container.end())
    {
        this->vec->push_back(*itr);
        this->CurrentNumber++;
        ++itr;
    }
}

int    Span::ClassIsFull(void)
{
    std::cout << "Class Is Full" << std::endl;
    throw std::exception();
}
        
int    Span::NoSpanFound(void)
{
    std::cout << "No Span Found" << std::endl;
    throw std::exception();
}