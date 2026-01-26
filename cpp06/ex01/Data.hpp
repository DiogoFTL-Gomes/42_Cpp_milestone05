#ifndef DATA_H
# define DATA_H

class Data {
	public:
		Data();
		Data(const Data &other);
		Data	&operator=(const Data &other);
		~Data();

		int		id;
		double	value;
};

#endif