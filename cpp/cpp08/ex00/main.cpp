#include "easyfind.hpp"

int main(void)
{
    try
    {
        std::cout << "-----testing vector-----\n";
        std::vector<int> int_vec;

        int_vec.push_back(10);
        int_vec.push_back(20);
        int_vec.push_back(30);
        int_vec.push_back(40);
        int_vec.push_back(50);
        int_vec.push_back(60);

        std::cout << "found " << easyfind(int_vec, 30) << std::endl;

        std::cout << "\n-----testing list-----\n";
        std::list<int> int_lst;

        int_lst.push_back(10);
        int_lst.push_back(20);
        int_lst.push_back(30);
        int_lst.push_back(40);
        int_lst.push_back(50);
        int_lst.push_back(60);

        std::cout << "found " << easyfind(int_lst, 40) << std::endl;
        // std::cout << "found " << easyfind(int_lst, 4000) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}