#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>


using std::string;

class People
{
	protected:
		string name;
		int age;
	public:
		People(string tempName, int tempAge);
		virtual ~People();
		virtual void do_work(int work);
};




#endif // PERSON_HPP


