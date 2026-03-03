#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
#include <cstdlib>

class PMergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;

		void	importValues(char **lines);
		void	printVec();
		void	printDeq();
		void	sortVec(std::vector<int> &vecMain);
		void	sortDeq(std::deque<int> &deqMain);
		void	compareSendValues(std::vector<int> &stayV, std::vector<int> &mainV, int a, int b);
		std::vector<size_t>	generateJacobsthalOrder(size_t size);
		size_t	binarySearch(std::vector<int>	&mainV, int value);

	public:
		PMergeMe(char **lines);
		PMergeMe(const PMergeMe &other);
		PMergeMe &operator=(const PMergeMe &other);
		~PMergeMe();
};

#endif