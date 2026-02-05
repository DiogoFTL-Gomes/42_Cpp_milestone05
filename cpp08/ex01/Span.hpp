#ifndef SPAN_HPP
# define SPAN_HPP

#include <vector>
#include <exception>
#include <cstddef>

class Span {
	private:
		std::vector<int>	_arr;
		unsigned int		_maxSize;
	public:
		Span(unsigned int n);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span();

		void	addNumber(int numb);
		template <typename It> void	addNumber(It first, It last){
			size_t count = std::distance(first, last);

			if (_arr.size() + count > _maxSize)
				throw std::exception();
			_arr.insert(_arr.end(), first, last);
		}

		int	shortestSpan() const;
		int	longestSpan() const;
};

#endif