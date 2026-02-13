#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
#include <string>

class BitcoinExchange {
	private:
		std::map<std::string, float>	_baseData;

	public:
		typedef std::map<std::string, float>::iterator	MapIter;

		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &other);
		BitcoinExchange &operator=(const BitcoinExchange &other);
		~BitcoinExchange();

		void	processInput(const std::string &input) const;
};

#endif
