/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee2 <yejlee2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:39:45 by yejlee2           #+#    #+#             */
/*   Updated: 2023/09/29 16:30:09 by yejlee2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    std::ifstream   readfile;
    std::ofstream   writefile;
    std::string     s1;
    std::string     s2;
    std::string     tmp_str;
    std::string     out_file;
    size_t          pos;

    if (argc != 4)
    {
        std::cout << "not 3 arguments" << std::endl;
        return (0);
    }
    out_file = argv[1];
    s1 = argv[2];
    s2 = argv[3];
    readfile.open(out_file);
    out_file.append(".replace");
    writefile.open(out_file);
    while (1)
    {
        getline(readfile, tmp_str);
        pos = 0;
        while (1)
        {
            pos = tmp_str.find(s1, pos);
            if (pos == std::string::npos)
				break ;
            tmp_str.erase(pos, s1.length());
			tmp_str.insert(pos, s2);
			pos += s2.length();
        }
        writefile << tmp_str;
        if (readfile.eof())
            break ;
        writefile << std::endl;
    }
}