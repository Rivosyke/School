#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>


using std::string;

class Person
{
	protected:
		string name;
		int age;
	public:
		Person(string tempName, int tempAge);
		virtual ~Person();
		virtual void do_work(int work);
        string getName();
};




#endif // PERSON_HPP


