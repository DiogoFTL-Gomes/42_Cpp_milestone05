#ifndef SCALARCONVERTER_H
# define SCALARCONVERTER_H

# include <string>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter	&operator=(const ScalarConverter&);
		~ScalarConverter();

		static bool	isPseudoNumb(const std::string &literal);

	public:
		static void convert(const std::string &literal);
};

#endif