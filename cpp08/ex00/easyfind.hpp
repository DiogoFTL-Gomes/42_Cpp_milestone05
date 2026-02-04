#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template <typename T>
typename T::const_iterator	easyfind(const T &container, int toFind){
	return (std::find(container.begin(), container.end(), toFind));
}

#endif