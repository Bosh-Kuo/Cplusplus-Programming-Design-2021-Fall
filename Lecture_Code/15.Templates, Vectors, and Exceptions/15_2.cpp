// Using vectors to revise Team
// ===========================================================================
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename KeyType>
class Team
{
private:
  vector<Character<KeyType>*> member;
public:
  Team();
  ~Team();
  void addWarrior(KeyType name, int lv);
  void addWizard(KeyType name, int lv);
  void memberBeatMonster(KeyType name, int exp);
  void printMember(KeyType name);
};

template <typename KeyType>
Team<KeyType>::Team()
{
}

template <typename KeyType>
Team<KeyType>::~Team()
{
  while(this->member.size() > 0)
  {
    delete this->member.back();
    this->member.pop_back();
  }
}

template <typename KeyType>
void Team<KeyType>::addWarrior(KeyType name, int lv) 
{
  Warrior<KeyType>* wPtr = new Warrior<KeyType>(name, lv); 
  this->member.push_back(wPtr);
}

template <typename KeyType>
void Team<KeyType>::addWizard(KeyType name, int lv)
{
  Wizard<KeyType>* wPtr = new Wizard<KeyType>(name, lv); 
  this->member.push_back(wPtr);
}

template <typename KeyType>
void Team<KeyType>::memberBeatMonster(KeyType name, int exp)
{
  for(int i = 0; i < this->member.size(); i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->beatMonster(exp);
      break;
    }
  }  
}

template <typename KeyType>
void Team<KeyType>::printMember(KeyType name)
{
  for(int i = 0; i < this->member.size(); i++)
  {
    if(this->member[i]->getName() == name)
    {
      this->member[i]->print();
      break;
    }
  }
}
// ===========================================================================
// End of using vector to revise Team
// ===========================================================================
