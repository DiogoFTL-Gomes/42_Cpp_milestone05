#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>

class RPN {
	private:
		std::stack<int>	_operands;

	public:
		RPN();
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		void	thinkMath(const std::string &line);
		void	doMath(const unsigned char c);
		void	validateLine(const std::string &line) const;
};

#endif