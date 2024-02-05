#include "MutantStack.hpp"

int main()
{
    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5); 
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n-----reverse_iterator-----\n" << std::endl;

    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5); 
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::reverse_iterator it = mstack.rbegin();
        MutantStack<int>::reverse_iterator ite = mstack.rend();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n-----const_iterator-----\n" << std::endl;

    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5); 
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::const_iterator it = mstack.cbegin();
        MutantStack<int>::const_iterator ite = mstack.cend();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }

    std::cout << "\n-----const_reverse_iterator-----\n" << std::endl;

    {
        MutantStack<int> mstack;

        mstack.push(5);
        mstack.push(17);

        std::cout << mstack.top() << std::endl;
        mstack.pop();
        std::cout << mstack.size() << std::endl;

        mstack.push(3);
        mstack.push(5); 
        mstack.push(737);
        mstack.push(0);

        MutantStack<int>::const_reverse_iterator it = mstack.crbegin();
        MutantStack<int>::const_reverse_iterator ite = mstack.crend();

        ++it;
        --it;

        while (it != ite)
        {
            std::cout << *it << std::endl;
            ++it;
        }
        std::stack<int> s(mstack);
    }
    return (0);
}