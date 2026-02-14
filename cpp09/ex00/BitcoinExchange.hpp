#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_baseData;

		bool	validateDate(const std::string &date) const;
		bool	validateValue(const std::string &value) const;

	public:
		typedef std::map<std::string, float>::iterator	MapIter;
		typedef std::map<std::string, float>::const_iterator	Const_MapIter;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	processInput(const std::string &input) const;
};

#endif
