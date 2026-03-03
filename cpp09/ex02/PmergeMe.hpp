#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <cstdlib>

class PMergeMe {
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		double				_vecTime;
		double				_deqTime;

		void				importValues(char **lines);
		void				printPMergeMe(std::vector<int> &vecMain);
		void				printPMergeMe(std::deque<int> &deqMain);
		void				sortPMergeMe(std::vector<int> &vecMain);
		void				sortPMergeMe(std::deque<int> &deqMain);
		void				compareSendValues(std::vector<int> &stayV, std::vector<int> &mainV, int a, int b);
		void				compareSendValues(std::deque<int> &stayV, std::deque<int> &mainV, int a, int b);
		size_t				binarySearch(std::vector<int>	&mainV, int value);
		size_t				binarySearch(std::deque<int>	&mainV, int value);
		std::vector<size_t>	generateJacobsthalOrder(size_t size);

	public:
		PMergeMe(char **lines);
		PMergeMe(const PMergeMe &other);
		PMergeMe &operator=(const PMergeMe &other);
		~PMergeMe();
};

#endif