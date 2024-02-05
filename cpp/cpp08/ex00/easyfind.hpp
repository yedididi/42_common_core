#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <list>

template <typename T>
int easyfind(T &con, int num)
{
    typename T::iterator ret_itr;

    ret_itr = std::find(con.begin(), con.end(), num);
    if (ret_itr == con.end())
        throw (std::exception());
    return (*ret_itr);
}

#endif