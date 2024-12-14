/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Convert.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ybakker <ybakker@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/20 23:56:51 by ybakker       #+#    #+#                 */
/*   Updated: 2022/08/21 00:02:46 by ybakker       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

Convert::Convert()
{
	std::cout << "Convert is born" << std::endl;
}

Convert::Convert(char *str)
{
	this->_str = str;
	this->_C = str[0];
	this->_I = 0;
	this->_D = 0;
	this->_F = 0;
}

Convert::Convert(Convert& copy)
{
	this->_str = copy._str;
	this->_check = copy._check;
	this->_C = copy._C;
	this->_F = copy._F;
	this->_D = copy._D;
	this->_I = copy._I;
}

Convert&	Convert::operator=(const Convert &other)
{
	if (this != &other)
	{
		this->_str = other._str;
		this->_C = other._C;
		this->_check = other._check;
		this->_F = other._F;
		this->_D = other._D;
		this->_I = other._I;
	}
	return *this;
}

Convert::~Convert()
{;
}

//if its just a normal number, then it fails, like with any float
//int, but wiht more than one number its fine?
int Convert::conversions()
{
	std::string string = "f";
	std::string dstring = "";
	if (!strcmp(this->_str, "-inff") ||!strcmp(this->_str, "-inf") )//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: -inff" << std::endl;
		std::cout << "double\t: -inf" << std::endl;
	}
	else if (!strcmp(this->_str, "+inff") || !strcmp(this->_str, "+inf"))//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: inff" << std::endl;
		std::cout << "double\t: inf" << std::endl;
	}
	else if (!strcmp(this->_str, "nanf") || !strcmp(this->_str, "nan"))//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: nanf" << std::endl;
		std::cout << "double\t: nan" << std::endl;
	}
	else
	{
		int i = 0;
		std::string add = "";
		if (this->_str[i] == '-' || this->_str[i] == '+')
		{
			if (this->_str[i] == '-')
			{
				add = "-";
			}
			std::string copy = this->_str;
			copy.erase(0, 1);
			strcpy(this->_str, copy.c_str());
		}
		if (this->_str[i] == '.')
			return(doDot(add));
		int check = 0;
		if (this->_str[i] == '-' || this->_str[i] == '+')
		{
			check = 1;
			std::cout << "char\t: Non displayable" << std::endl;
		}
		while(isCharacter(this->_str[i]) == 1)
			i++;
		if (i > 1 || (i >= 1 && isdigit(this->_str[i])))//if there is aa1 or aa or a1
		{
			if (check == 0)
				std::cout << "char\t: Non displayable" << std::endl;
			std::cout << "int\t: Impossible" << std::endl;
			std::cout << "float\t: Impossible" << std::endl;
			std::cout << "double\t: Impossible" << std::endl;
			return (-1);
		}
		if (i == 1)
		{
			std::cout << "char\t: " << this->_C << std::endl;
			string = ".0f";
			dstring = ".0";
			return (printNumbers(static_cast<float>(this->_C), string, dstring, add));
		}
		while(isdigit(this->_str[i]))
			i++;
		//after numbers, no characters
		if (this->_str[i] != '.' && this->_str[i] != '\0' && this->_str[i] != 'f')
		{
			//when after no dot there is somethign that should not be
			std::cout << "char\t: Non displayable" << std::endl;
			std::cout << "int\t: Impossible" << std::endl;
			std::cout << "float\t: Impossible" << std::endl;
			std::cout << "double\t: Impossible" << std::endl;
			return (-1);
		}
		if (this->_str[i] != '.')
		{
			string = ".0f";
			dstring = ".0";
			//after this popint, only single chaarcters
			if (i == 1 && this->_str[i] == '\0')//11a
			{
				long int store = atof(this->_str);
				if (store <= 0 || store > 127 || (store >= 0 && store <= 31))
					std::cout << "char\t: Non displayable" << std::endl;
				else
					std::cout << "char\t: " << this->_str << std::endl;
				float store1 = atof(this->_str);
				return (printNumbers(store1, string, dstring, add));
			}
		}
		if (this->_str[i] == '.' && !isdigit(this->_str[i + 1]))
		{
			string = "0f";
			dstring = "0";
		}
		long int store = atof(this->_str);
		float store1 = atof(this->_str);
		if (store < std::numeric_limits<int>::min()|| store > std::numeric_limits<int>::max())
		{
			std::cout << "char\t: Non displayable" << std::endl;
			std::cout << "int\t: Impossible" << std::endl;
			std::cout << "float\t: Impossible" << std::endl;
			std::cout << "double\t: Impossible" << std::endl;
			return (-1);
		}
		if (store <= 0 || store > 127 || (store >= 0 && store <= 31))
		{
			std::cout << "char\t: Non displayable" << std::endl;
			if (this->_str[i] == '.')
				i++;
			if (this->_str[i] == 'f' && this->_str[i + 1] == '\0')
			{
				string = ".0f";
				dstring = ".0";
				return (printNumbers(store1, string, dstring, add));
			}
			while(isdigit(this->_str[i]))
				i++;
			if ((this->_str[i] == 'f' && this->_str[i + 1] == '\0') || this->_str[i] == '\0')
			{
				return (printNumbers(store1, string, dstring, add));
			}
			else
			{
				std::cout << "int\t: Impossible" << std::endl;
				std::cout << "float\t: Impossible" << std::endl;
				std::cout << "double\t: Impossible" << std::endl;
				return (-1);
			}
		}
		else
		{
			std::cout << "char\t: " << static_cast<char>(store) << std::endl;
			return (printNumbers(store1, string, dstring, add));
		}
		return (printNumbers(store1, string, dstring, add));
	}
	return (0);
}

int Convert::doDot(std::string add)
{
	int i = 1;
	std::string string = "f";
	std::string dstring = "";
	std::cout << "char\t: Non displayable" << std::endl;
	if (this->_str[i] == 'f')//.f
	{
		float store1 = 0;
		std::string string = ".f";
		std::string dstring = "";
		std::cout << "int\t: " << static_cast<int>(store1) << std::endl;
		std::cout << "float\t: " << store1 << string << std::endl;
		std::cout << "double\t: " << static_cast<double>(store1) << dstring << std::endl;
		return (0);
	}
	else if (this->_str[i] == '\0')//.f
	{
		float store1 = 0;
		std::cout << "int\t: " << static_cast<int>(store1) << std::endl;
		std::cout << "float\t: " << add << store1 << string << std::endl;
		std::cout << "double\t: " << add << static_cast<double>(store1) << dstring << std::endl;
		return (0);
	}
	while(isdigit(this->_str[i]))
		i++;
	if (this->_str[i] == 'f' || this->_str[i] == '\0')
	{
		float store1 = atof(this->_str);
		std::cout << "int\t: " << static_cast<int>(store1) << std::endl;
		std::cout <<"float\t: " << add << store1 << string << std::endl;
		std::cout <<"double\t: " << add << static_cast<double>(store1) << dstring << std::endl;
	}
	else
	{
		std::cout << "char\t: Non displayable" << std::endl;
		std::cout << "int\t: Impossible" << std::endl;
		std::cout << "float\t: Impossible" << std::endl;
		std::cout << "double\t: Impossible" << std::endl;
	}
	return (0);
}

int Convert::isCharacter(char c)
{
	if (c > 0 && c < 127 )
	{
		if (c >= 48 && c <= 57)
		{
			return (0);
		}
		if (c > 32)
		{
			return (1);
		}
	}
	return (0);
}

int Convert::printNumbers(float store, std::string fstring, std::string dstring, std::string add)
{
	std::cout << "int\t: "<< add << static_cast<int>(store) << std::endl;
	std::cout << "float\t: " << add << store << fstring << std::endl;
	std::cout << "double\t: " << add << static_cast<double>(store) << dstring << std::endl;
	return (0);
}

void Convert::ftNanf()
{
	//Float
	if (!strcmp(this->_str, "-inff") ||!strcmp(this->_str, "-inf") )//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: -inff" << std::endl;
		std::cout << "double\t: -inf" << std::endl;
	}
	else if (!strcmp(this->_str, "+inff") || !strcmp(this->_str, "+inf"))//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: inff" << std::endl;
		std::cout << "double\t: inf" << std::endl;
	}
	else if (!strcmp(this->_str, "nanf") || !strcmp(this->_str, "nan"))//float
	{
		std::cout << "char\t: impossible" << std::endl;
		std::cout << "int\t: impossible" << std::endl;
		std::cout << "float\t: nanf" << std::endl;
		std::cout << "double\t: nan" << std::endl;
	}
	std::cout << "--end--" << std::endl;
}
