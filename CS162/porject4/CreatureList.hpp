#include <iostream>
#include "ListNode.cpp"
#include "Creature.hpp"

using std::cout;
using std::endl;



class CreatureList
{
	private:
		ListNode* head;
		ListNode* tail;
		int numOfElements;
		
	public:
		CreatureList();
		~CreatureList();
		void printListReverse();
		void printTail();
		void printList();
		void deleteTail();
		void deleteHead();
		void printHead();
		void addNodeTail(Creature* newMonster);
		void addNodeHead(Creature* newMonster);
};
