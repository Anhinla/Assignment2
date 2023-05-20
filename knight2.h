#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType {PhoenixI,PhoenixII,PhoenixIII,PhoenixIV,Antidote};
//////////////
/********************    FUNCTION   ******************/

/// ////////////
class BaseKnight;
class Events;
class BaseItem {

    public:
  ItemType type;
  
  BaseItem(ItemType type)
  {
    this->type = type;
  }
  void setType(ItemType type)
  {
    this->type = type;
  }
  ItemType getType()
  {
    return type;
  }
     virtual bool canUse ( BaseKnight * knight ){return true;} 
     virtual void use ( BaseKnight * knight ) {
        cout<<"";
     }
    // DESTRUCTOR
     ~BaseItem(){
     }
};
/////////// Child class of base item//////////
class anti: public BaseItem{
private:
    bool Tornbery;
public:
    
    void setTornbery(bool Tornbery){
        this->Tornbery = Tornbery;
    }
    bool getTornbery(){
        return Tornbery;
    }
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    anti(ItemType type) : BaseItem(type) {}
};
class PhoenixDownI: public BaseItem{
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    PhoenixDownI(ItemType type) : BaseItem(type) {}
};
class PhoenixDownII: public BaseItem{
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    PhoenixDownII(ItemType type) : BaseItem(type) {}
};
class PhoenixDownIII: public BaseItem{
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    PhoenixDownIII(ItemType type) : BaseItem(type) {}
};
class PhonenixDownIV: public BaseItem{
public:
    bool canUse(BaseKnight* knight);
    void use(BaseKnight* knight);
    PhonenixDownIV(ItemType type) : BaseItem(type) {}
};



class BaseBag {
public:
    BaseItem* item;
    BaseBag* next;
    BaseBag* head;
   BaseBag(BaseItem* item){
       this->item = item;
       this->next = NULL;
   }
    virtual bool insertFirst(BaseItem *item, int max);

    virtual BaseBag* get(ItemType itemType);

    virtual string toString() ;
};


class Item : public BaseItem
{
public:
  Item(ItemType type) : BaseItem(type) {}
  bool canUse(BaseKnight* knight){
      return true;
  }
  void use(BaseKnight* knight){
      cout<<"hi";
  }
};
/////////////////////////



/// @brief ////////

/// @brief /////////
class BaseOpponent{
public:
    BaseOpponent(int id, int no){
        this->event_id = id;
        this->event_no = no;
    }
    int event_id;
    int event_no;

    int* fight_event;
    // void setEventID(int event_id){
    //     this->event_id = event_id;
    // }
    // int getEventID(){
    //     return event_id;
    // }
    // void setEventNo(int event_no){
    //     this->event_no = event_no;
    // }
    // int getEventNo(){
    //     return event_no;
    // }
};




enum KnightType { PALADIN = 0, LANCELOT, DRAGON, NORMAL };
/// @brief //////


/// @brief ////////////
class BaseKnight {
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    BaseBag * bag;
    KnightType knightType;
    bool poison = false;
    int slot;
public:

    BaseBag* head;
    void setTornbery(bool poison){
        this->poison = poison;
    }
    bool getTornbery(){
        return poison;
    }
    void setSlot(int slot){
        this->slot = slot;
    }
    int getSlot(){
        return slot;
    }
    void setHead(BaseBag* head){
        this->head = head;
    }
    void setId(int id){
        this->id = id;
    }
    int getId(){
        return id;
    }
     void setHp(int hp){
        this->hp = hp;
    }
    int getHp(){
        return hp;
    }
     void setMaxHp(int maxhp){
        this->maxhp = maxhp;
    }
    int getMaxHp(){
        return maxhp;
    }
     void setLevel(int level){
        this->level = level;
    }
    int getLevel(){
        return level;
    }
     void setAntidote(int antidote){
        this->antidote = antidote;
    }
    int getAntidote(){
        return antidote;
    }
    void setGil(int gil){
        this->gil = gil;
    }
    int getGil(){
        return gil;
    }
    void setBaseBag(BaseBag* bag) {
    this->bag = bag;
    }
    BaseBag * getBaseBag(){
        return bag;
    }
    void setKnightType(KnightType knightType){
        this->knightType = knightType;
    }
    KnightType getKnightType(){
        return knightType;
    }
    // Constructor tao mang
    BaseKnight(){

    }
    //
    static BaseKnight * create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
   
   string toString();
   //
   void HpRefill(BaseBag* bag);
   void Reborn(BaseKnight* knight);
};
/// @brief //////////

/// @brief //////////
class ArmyKnights{
public:
    bool PaladinShield = false;
    bool LanceLotSpear = false;
    bool GuinevereHair = false;
    bool ExcaliburSword = false;
    bool MeetOmega = false;
    bool MeetHades = false;
    static int Knightnum;
    BaseKnight* knight;
    int Knightmax ;
    ArmyKnights(const string& file_armyknights);
ArmyKnights(){}
    ~ArmyKnights();
    bool fight(BaseOpponent * opponent);

    bool adventure (Events * events);
    
    int count() const;
    BaseKnight * lastKnight() const;
    bool hasPaladinShield() const{
        return PaladinShield;
    }
    bool hasLancelotSpear() const{
        return LanceLotSpear;
    }
    bool hasGuinevereHair() const{
        return GuinevereHair;
    }
    bool hasExcaliburSword() const{
        
        return ExcaliburSword;
    }

    void printInfo() const;
    void printResult(bool win) const;
    // User added
    void PassGil(int &pass, int size);
    void Collect(int i);
    void CollectPhoe(int i);
    void PassItem(BaseItem* item);
    bool fightUltimecia();
};


class Events {
public:
     int numEvent;
    int* event;
    Events(const string& file_events);
    int count() const{
        return numEvent;
    }
    int get(int i) const{
        return event[i];
    }
    ~Events(){}
};

class KnightAdventure {
private:
    ArmyKnights * armyKnights;
    Events * events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__
