#ifndef DIE_HPP
#define DIE_HPP


class Die
{
    protected:
        int numOfSides;
        
    public:
        Die(int);
        virtual ~Die();
        virtual int rollDice();
};
    

#endif // DIE_HPP
