#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>

class PMergeMe {
	private:
		std::vector<int>	vec;
		std::deque<int>		deq;

		void	importValues(std::string line);
	public:
		PMergeMe(std::string line);
		PMergeMe(const PMergeMe &other);
		PMergeMe &operator=(const PMergeMe &other);
		~PMergeMe();
};

#endif