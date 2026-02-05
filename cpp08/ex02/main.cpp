#include <iostream>

#include "MutantStack.hpp"

int main(){
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
}


/*#include <list>

int main(){
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	//[...]
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite){
		std::cout << *it << std::endl;
		++it;
	}
	return 0;
}*/

/*#include <vector>
#include <iostream>

int main() {
	std::vector<int> vec;

	vec.push_back(5);
	vec.push_back(17);

	std::cout << vec.back() << std::endl;   // equivalente a top()
	vec.pop_back();

	std::cout << vec.size() << std::endl;

	vec.push_back(3);
	vec.push_back(5);
	vec.push_back(737);
	vec.push_back(0);

	std::vector<int>::iterator it = vec.begin();
	std::vector<int>::iterator ite = vec.end();

	++it;
	--it;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}

	return 0;
}*/