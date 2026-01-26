#ifndef IDENTIFY_H
# define IDENTIFY_H

class Base;
class A;
class B;
class C;

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif