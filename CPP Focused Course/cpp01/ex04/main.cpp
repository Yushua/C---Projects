/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/01 13:55:10 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/18 21:05:31 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

int main(int argc, char **argv)
{
    if (argc > 4)
    {
        std::cout << "Too many arguments!!" << std::endl;
        return (1);
    }
	else if (argc < 4)
	{
		std::cout << "Too few arguments!!" << std::endl;
		return (1);
	}
	std::ifstream	file(argv[1]);
	if (!file.is_open())
	{
		std::cout << "Cannot open the file!!" << std::endl;
		return (1);
	}
	else if (file.peek() == EOF)
	{
		std::cout << "Empty file!!" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	filename.append(".replace");
	const std::string str1 = argv[2];
	const std::string str2 = argv[3];
	std::ifstream myfile(argv[1], std::ios_base::ate);
	std::ofstream replace_file(filename.c_str());

	int length = myfile.tellg();
	myfile.seekg(0, std::ios_base::beg);
	char *line = new char[length + 1];
	myfile.read(line, length);
	myfile.close();
	line[length] = '\0';
	std::string string = line;
	delete[] line;

	size_t	pos;
	do
	{
		pos = string.find( str1 );
		if (pos != std::string::npos)
		{
			string.erase( pos, str1.length());
			string.insert( pos, str2 );
		}
	}
	while (pos != std::string::npos);

	replace_file << string;
	replace_file.close();
    return (0);
}
