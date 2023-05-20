#include "knight2.h"
#github is powerful
/********************    FUNCTION   ******************/
string TypeK(KnightType a){
    if(a==PALADIN){
        return"PALADIN";
    }else if(a==DRAGON){
        return "DRAGON";
    }else if(a==LANCELOT){
        return "LANCELOT";
    }else return "NORMAL";
}
int getLength(const BaseBag* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
bool isPaladin(int maxHp){
    if(maxHp<=1) return false;
    for(int i=2;i<maxHp;i++){
        if(maxHp%i==0) return false;
    }
    return true;
}
bool isDragon(int maxHp){
    if(maxHp/100==0) return false;
    int a = maxHp%10;
    int b = (maxHp/10)%10;
    int c = (maxHp/100);
    if(a==0 || b==0 || c == 0) return false;
    if((a*a==b*b + c*c)||(b*b == a*a + c*c)||(c*c == a*a + b*b)){
        return true;
    }
    return false;
} 
int Min(int x,int y){
    if(x>=y) return y;
    else return x;
}
int DamCal(int lv,int event_id, int i){
    int levelO = (i+event_id)%10 + 1;
    int base = 0;
    switch(event_id){
        case 1:
            base = 10;
            break;
        case 2:
            base = 15;
            break;
        case 3:
            base = 45;
            break;
        case 4:
            base = 75;
            break;
        case 5:
            base = 95;
            break;
    }
    return base*(levelO-lv);
}
int LevelO(int id, int no){
    return (id+no)%10 + 1;
}

string Type(BaseItem* head,string itemType[]){
    string tmp;
    if(head->getType()==Antidote){
        tmp = itemType[0];
    }else if(head->getType()==PhoenixI){
        tmp = itemType[1];
    }else if(head->getType()==PhoenixII){
        tmp = itemType[2];
    }else if(head->getType()==PhoenixIII){
        tmp = itemType[3];
    }else{
        tmp = itemType[4];
    }
    return tmp;
}




BaseBag* DeleteHead(BaseBag*& head){
    if(head == NULL || head->next == NULL) {return NULL;}
    BaseBag* tmp = head;
    head = head->next;
    delete tmp;
   return head;
}

int SpecialDam(BaseKnight knight){
    int dam = 0;
    switch(knight.getKnightType()){
        case LANCELOT:
            dam = knight.getHp()*knight.getLevel()*0.05;
            break;
        case PALADIN:
             dam = knight.getHp()*knight.getLevel()*0.06;
            break;
        case DRAGON:
             dam = knight.getHp()*knight.getLevel()*0.075;
            break;
    }
    return dam;
}





/* * * BEGIN implementation of class BaseBag * * */


/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class antinode * * */
bool anti::canUse(BaseKnight* knight){
            if(this->type == Antidote && knight->getTornbery()==true){
                return true;
            }   
    return false;
}
void anti::use(BaseKnight* knight){
    if(this->canUse(knight)){
        knight->setTornbery(false);
    }
}
/* * * BEGIN implementation of class PhoenixdownI * * */
bool PhoenixDownI::canUse(BaseKnight* knight){
            if(this->type == PhoenixI && knight->getHp()<=0){
                return true;
            }
    return false;
}
void PhoenixDownI::use(BaseKnight* knight){
        knight->setHp(knight->getMaxHp());
}
/* * * BEGIN implementation of class PhoenixdownII * * */
bool PhoenixDownII::canUse(BaseKnight* knight){
    
            if(this->type == PhoenixII && knight->getHp()<= knight->getMaxHp()/4){
                return true;
            }
        return false;
    }
    void PhoenixDownII::use(BaseKnight* knight){
            knight->setHp(knight->getMaxHp());
        
    }

/* * * BEGIN implementation of class PhoenixdownIII * * */
bool PhoenixDownIII::canUse(BaseKnight* knight){
            if(this->type == PhoenixIII && knight->getHp()<= knight->getMaxHp()/4){
                return true;
            }
        return false;
    }
    void PhoenixDownIII::use(BaseKnight* knight){
            if(this->canUse(knight)&&knight->getHp()<=0){
            knight->setHp(knight->getMaxHp()/3);
        }else if(this->canUse(knight)){
            knight->setHp(knight->getHp()+knight->getMaxHp()/4);
        }
    }
/* * * BEGIN implementation of class PhoenixdownIV * * */
bool PhonenixDownIV::canUse(BaseKnight* knight){
        
            if(this->type == PhoenixIV && knight->getHp()<= knight->getMaxHp()/2){
                return true;
            }
        
        return false;
    }
    void PhonenixDownIV:: use(BaseKnight* knight){
        if(this->canUse(knight)&&knight->getHp()<=0){
            knight->setHp(knight->getMaxHp()/2);
        }else if(this->canUse(knight)){
            knight->setHp(knight->getHp()+knight->getMaxHp()/5);
        }
    }
/* * * BEGIN implementation of class BaseBag * * */
bool BaseBag::insertFirst(BaseItem* item,int max){
    
      if(getLength(this->head)<=max){
        BaseBag* tmp = new BaseBag(item);
        tmp->next = this->head;
        this->head = tmp;
        return true;
        }
        return false;
    }
BaseBag* BaseBag::get(ItemType itemType){
    if(this->head == NULL) return NULL;
    if(this->head->item->type == PhoenixI) return NULL;
     BaseBag* tmp = this->head;
    while(tmp->item->type != itemType && tmp->next!=NULL){
        tmp = tmp ->next;
    }
    if(tmp->next == NULL){
        return NULL;
    }
    BaseItem* temp = tmp->item;
    tmp->item = head->item;
    head->item = temp;
    return head;
}
 string BaseBag::toString() {
     string itemType[5] = {"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
    int cnt = 0;
    string s("");
 
    BaseBag* temp = this->head;
    s += "Bag[count=";
    string tmp ="";
    if(temp==NULL | temp->next == NULL) {
        tmp = tmp + to_string(cnt)+ ";]";
        s = s+ tmp;
        return s;
    }
    while(temp->next!= NULL){
        if (cnt > 0) {
            tmp += ",";
        }
        string tmp1 = Type(temp->item,itemType);
        cnt++;
        tmp = tmp + tmp1 ;
        temp = temp->next;  // fix: move to next node
    }

    s = s + to_string(cnt) + ";" + tmp +"]";

    return s;
    }

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString()  {
        string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(this->getId()) 
        + ",hp:" + to_string(this->getHp()) 
        + ",maxhp:" + to_string(this->getMaxHp())
        + ",level:" + to_string(this->getLevel())
        + ",gil:" + to_string(this->getGil())
        + "," + this->getBaseBag()->toString()
        + ",knight_type:" + TypeK(this->getKnightType())
        + "]";
    return s;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI){
    BaseKnight* knight = new BaseKnight();
        knight->setId(id+1);
        knight->setMaxHp(maxhp);
        knight->setHp(maxhp);
        knight->setLevel(level);
        knight->setAntidote(antidote);
        knight->setGil(gil);
        // find KnightType
        if(knight->getMaxHp()==888){
            knight->setKnightType(LANCELOT);
            knight->setSlot(16);
        }else if(isPaladin(knight->getMaxHp())){
            knight->setKnightType(PALADIN);
            knight->setSlot(10000);
        }else if(isDragon(knight->getMaxHp())){
            knight->setKnightType(DRAGON);
            knight->setSlot(14);
        }else{
            knight->setKnightType(NORMAL);
            knight->setSlot(19);
        }
        // Insert phonenix into bag
        //Create base bag for knight
        BaseItem* item = new BaseItem(PhoenixI);

    BaseBag* bag = new BaseBag(item);
    knight->setBaseBag(bag);
    knight->getBaseBag()->head = bag;
    //Insert PhoenixI to the bag
    for(int i=0;i<phoenixdownI;i++){
        BaseItem* item = new PhoenixDownI(PhoenixI);
        bag->insertFirst(item,knight->getSlot());
    
    }
        if(antidote>=1 && knight->getKnightType()!=DRAGON){
            for(int i=0;i<antidote;i++){
                 BaseItem* item = new anti(Antidote);
                 bag->insertFirst(item,knight->getSlot());
            }
        }

        return knight;
}
void BaseKnight::Reborn(BaseKnight* knight){
    if(this->getGil()>=100){
        this->setHp(this->getMaxHp()/2);
        this->setGil(this->getGil()-100);
    }
}
/* * * END implementation of class BaseKnight * * */
Events::Events(const string& file_events){
    ifstream Event(file_events);
        Event >> numEvent;
     
        event = new int[numEvent]();
        for(int i=0;i<numEvent;i++){
            Event >> event[i];
        }
}
/* * * BEGIN implementation of class ArmyKnights * * */
int ArmyKnights::Knightnum =0;
void ArmyKnights::printInfo() const {

    cout << "No. knights: " << this->count();
    
    if (this->count() > 0) {
        BaseKnight* tmp;
    int i = this->Knightmax-1;
    while(this->knight[i].getHp()<=0) i--;
    if(i>=0){
    tmp = &(this->knight[i]); // last knight
        cout << ";" << tmp->toString();
    }
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
        << ";LancelotSpear:" << this->hasLancelotSpear()
        << ";GuinevereHair:" << this->hasGuinevereHair()
        << ";ExcaliburSword:" << this->hasExcaliburSword()
        << endl
        << string(50, '-') << endl;
}

void ArmyKnights::printResult(bool win) const {
    cout << (win ? "WIN" : "LOSE") << endl;
}
ArmyKnights::~ArmyKnights(){
    for(int i=0;i<Knightnum;i++){
            if(this->knight!=NULL) delete this->knight; 
        }
        Knightnum = 0;
        this->knight = NULL;
}
ArmyKnights::ArmyKnights(const string& file_armyknights){
    ifstream Army(file_armyknights);
        Army >> Knightnum;
        Knightmax = Knightnum;
        string trash;
        getline(Army,trash);
        knight = new BaseKnight[Knightnum];
        for (int i = 0; i < Knightnum; i++){
            int id, maxhp, level, gil, antidote, phoenixdownI;
            string tmp;
            getline(Army, tmp);
            stringstream ss(tmp);
            ss >> maxhp;
            ss >> level;
            ss >> phoenixdownI;
            ss >> gil;
            ss >> antidote;
           
            BaseKnight* temp = BaseKnight::create(i, maxhp, level, gil, antidote, phoenixdownI);
            knight[i] = *temp;
            delete temp;
        }
        Army.close();
        
}
void ArmyKnights::PassGil(int &pass,int size){
    if(size==0|| pass<=0) return;
    int tmp = this->knight[size-1].getGil();            
    this->knight[size-1].setGil(Min(999,tmp+pass));
    pass = pass - (999-tmp);
    PassGil(pass,size-1);
}
bool CheckItem(BaseBag* head){
    BaseBag* tmp = head;
    while(tmp->next!=NULL){
        if(tmp->item->type == PhoenixI||
        tmp->item->type == PhoenixII ||
        tmp->item->type == PhoenixIII ||
        tmp->item->type == PhoenixIV)
        return true;
    }
    return false;
}

    
void BaseKnight::HpRefill(BaseBag* head){
    string itemType[5] = {"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
    BaseBag* tmp = head;
    while(tmp->next!=NULL){
        if(tmp->item->canUse(this)){
             tmp->item->use(this);
            this->getBaseBag()->get(tmp->item->type);
           
            this->getBaseBag()->head = DeleteHead(head); // done
       
            break;
        }else{
            tmp = tmp->next;
        }
    }
    return;
}

bool ArmyKnights::fight(BaseOpponent * opponent){
    bool tmp = true;
    string itemType[5] = {"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
    if(opponent->event_id>=1 && opponent->event_id<=5){ 
          // Mad bear
        if(this->lastKnight()->getKnightType()==LANCELOT||this->lastKnight()->getKnightType()==PALADIN || this->lastKnight()->getLevel()>=LevelO(opponent->event_id,opponent->event_no)){
          
            switch(opponent->event_id){
                case 1:
                    this->lastKnight()->setGil(this->lastKnight()->getGil()+100);
                    break;
                case 2:
                    this->lastKnight()->setGil(this->lastKnight()->getGil()+150);
                    break;
                case 3: 
                    this->lastKnight()->setGil(this->lastKnight()->getGil()+450);
                    break;
                case 4:
                    this->lastKnight()->setGil(this->lastKnight()->getGil()+750);
                    break;
                case 5:
                    this->lastKnight()->setGil(this->lastKnight()->getGil()+800);
                    break;
            }
            int pass = this->lastKnight()->getGil()-999;
            this->PassGil(pass,Knightnum-1);
            this->lastKnight()->setGil(Min(999,this->lastKnight()->getGil()));
        }else{
            this->lastKnight()->setHp(this->lastKnight()->getHp()-DamCal(this->lastKnight()->getLevel(),opponent->event_id,opponent->event_no));
            this->lastKnight()->HpRefill(this->lastKnight()->getBaseBag()->head);
            if(this->lastKnight()->getHp()<=0) this->lastKnight()->Reborn(this->lastKnight());
            if(this->lastKnight()->getHp()<=0) tmp = false;
        }
    }else if (opponent->event_id==6){
        int lvO = LevelO(opponent->event_id,opponent->event_no);
        if(this->lastKnight()->getLevel()>= lvO){
            if(this->lastKnight()->getLevel()<=9){
                this->lastKnight()->setLevel(this->lastKnight()->getLevel()+1);
            }
        }else{
            if(this->lastKnight()->getKnightType() == DRAGON){
                  this->lastKnight()->setTornbery(false);
                tmp = true;
            }else 
            if(this->lastKnight()->getKnightType() != DRAGON &&this->lastKnight()->getBaseBag()->get(Antidote)!=NULL){
                DeleteHead(this->lastKnight()->getBaseBag()->head);
                this->lastKnight()->setTornbery(false);
            }else{
                this->lastKnight()->setTornbery(true);
                if(getLength(this->lastKnight()->getBaseBag()->head)<=3 && getLength(this->lastKnight()->getBaseBag()->head)>0 &&this->lastKnight()->getKnightType() != PALADIN) {
                    BaseItem* item = new BaseItem(PhoenixI);

                    BaseBag* bag = new BaseBag(item);
                     this->lastKnight()->setBaseBag(bag);
                    this->lastKnight()->getBaseBag()->head = bag;
                
                }else{
                    for(int i=0;i<3;i++){
                        DeleteHead(this->lastKnight()->getBaseBag()->head);
                    }
                }
            }
        
            if(this->lastKnight()->getTornbery()) this->lastKnight()->setHp(this->lastKnight()->getHp()-10);
            this->lastKnight()->HpRefill(this->lastKnight()->getBaseBag()->head);

            if(this->lastKnight()->getHp()<=0) this->lastKnight()->Reborn(this->lastKnight());
            if(this->lastKnight()->getHp()<=0) tmp = false;
        }
    }else if(opponent->event_id==7){  // Gap Queen of cards
        int lvO = LevelO(opponent->event_id,opponent->event_no);
        if(this->lastKnight()->getLevel()>= lvO){
            this->lastKnight()->setGil(this->lastKnight()->getGil()*2);
            int pass = this->lastKnight()->getGil()-999;
            this->PassGil(pass,Knightnum-1);
             this->lastKnight()->setGil(Min(999,this->lastKnight()->getGil()));
            // Nho qua ben adventure nho xet gil > 999 thi chuyen qua hiep si tiep theo
        }else if(this->lastKnight()->getKnightType()!=PALADIN && this->lastKnight()->getLevel()< lvO){
            this->lastKnight()->setGil(this->lastKnight()->getGil()/2);
        }
    }else if(opponent->event_id==8){ // gap nina de rings
        if(this->lastKnight()->getGil()<50 && this->lastKnight()->getKnightType()!=PALADIN) return tmp;
        else if(this->lastKnight()->getKnightType()==PALADIN){
            if(this->lastKnight()->getHp()< this->lastKnight()->getMaxHp()/3){
                this->lastKnight()->setHp(this->lastKnight()->getHp()+this->lastKnight()->getMaxHp()/5);
            }
        }else if(this->lastKnight()->getKnightType()!=PALADIN && this->lastKnight()->getGil()>=50){
            if(this->lastKnight()->getHp()< this->lastKnight()->getMaxHp()/3){
                this->lastKnight()->setHp(this->lastKnight()->getHp()+this->lastKnight()->getMaxHp()/5);
                this->lastKnight()->setGil(this->lastKnight()->getGil()-50);
            }
        }
    }else if(opponent->event_id==9){ // Gap Durian Garden
        this->lastKnight()->setHp(this->lastKnight()->getMaxHp());
    } else if(opponent->event_id==10){ // omega weapon
        
        if(this->MeetOmega==false){
            if(this->lastKnight()->getKnightType()==DRAGON){
                this->lastKnight()->setLevel(10);
                this->lastKnight()->setGil(999);
            }else if(this->lastKnight()->getKnightType()!=DRAGON && this->lastKnight()->getLevel()<10){
                 this->lastKnight()->setHp(0);
        
                 if(CheckItem(this->lastKnight()->getBaseBag()->head)){
                       this->lastKnight()->HpRefill(this->lastKnight()->getBaseBag()->head);
                     tmp = true;
                 }else if (this->lastKnight()->getGil()>=100){
                     this->lastKnight()->setHp(this->lastKnight()->getMaxHp()/2);
                     this->lastKnight()->setGil(this->lastKnight()->getGil()-100);
                     tmp = true;
                 }else{
                     tmp = false;
                 }
                
            }else if( this->lastKnight()->getKnightType()!=DRAGON && this->lastKnight()->getLevel()==10 ){
                if(this->lastKnight()->getHp()== this->lastKnight()->getMaxHp()){
                    tmp = true;
                    this->lastKnight()->setLevel(10);
                    this->lastKnight()->setGil(999);
                }else if(CheckItem(this->lastKnight()->getBaseBag()->head)){
                      this->lastKnight()->HpRefill(this->lastKnight()->getBaseBag()->head);
                    tmp = true;
                }else if (this->lastKnight()->getGil()>=100){
                    this->lastKnight()->setHp(this->lastKnight()->getMaxHp()/2);
                    this->lastKnight()->setGil(this->lastKnight()->getGil()-100);
                    tmp = true;
                }else{
                    tmp = false;
                }
            }
            if(tmp==true) this->MeetOmega = true;
        }
    }else if(opponent->event_id==11){ 
         // Hades
        if(this->MeetHades==false){
            if((this->lastKnight()->getKnightType()==PALADIN && this->lastKnight()->getLevel()>=8) || this->lastKnight()->getLevel()==10){
                this->PaladinShield = true;
            }else {
                this->lastKnight()->setHp(0);
                if(CheckItem(this->lastKnight()->getBaseBag()->head)){
                      this->lastKnight()->HpRefill(this->lastKnight()->getBaseBag()->head);
                    tmp = true;
                }else if (this->lastKnight()->getGil()>=100){
                    this->lastKnight()->setHp(this->lastKnight()->getMaxHp()/2);
                    this->lastKnight()->setGil(this->lastKnight()->getGil()-100);
                    tmp = true;
                }else{
                    tmp = false;
                }
            }
            if(tmp==true) this->MeetHades = true;
        }
    }
    return tmp;
}

int ArmyKnights::count() const{
        return Knightnum;
    }

 


BaseKnight * ArmyKnights::lastKnight() const {
    if(Knightnum==0) return NULL;

    return &(this->knight[Knightnum-1]);
}
/// @brief ///////////
/// @param head /

void ArmyKnights::Collect(int i){
    switch (i){
        case 95:
            this->PaladinShield = true;
            break;
        case 96:
            this->LanceLotSpear = true;
            break;
        case 97:
            this->GuinevereHair = true;
            break;
    }
}
void ArmyKnights::PassItem(BaseItem* item){
    int i = Knightnum-1;
    for(;i>=0;i--){
        if(this->knight[i].getBaseBag()->insertFirst(item,this->knight[i].getSlot())) break;
    }
}
void ArmyKnights::CollectPhoe(int id){
    if(id == 112){
            BaseItem* item = new PhoenixDownII(PhoenixII);
            this->PassItem(item);
    }else if(id==113){
            BaseItem* item = new PhoenixDownIII(PhoenixIII);
           this->PassItem(item);
    }else if(id==114){ 
            BaseItem* item = new PhonenixDownIV(PhoenixIV);
            this->PassItem(item);
    }
}
bool ArmyKnights::fightUltimecia(){
    int BossHp = 5000;
    int tmp = Knightmax-1;
    if(this->hasExcaliburSword()) return true;
    if(!this->hasGuinevereHair()||!this->hasLancelotSpear()||!this->hasPaladinShield()) {Knightnum=0; return false;}
    for(int i = tmp;i>=0;i--){
        if(this->knight[i].getKnightType()!=NORMAL&&this->knight[i].getHp()>0){
            BossHp = BossHp - SpecialDam(this->knight[i]);
            if(BossHp<=0) {
                return true;}
            else {this->knight[i].setHp(0);Knightnum--;}
        }
    }
    Knightnum = 0;
    return false;
}
/// @brief //////

bool ArmyKnights::adventure (Events * events){
    int len = events->count();
    bool res;
    bool all;
    bool fight = true;
    for(int i=0;i<len;i++){
        int id = events->get(i);
        BaseOpponent* oppo = new BaseOpponent(id,i);
        if(id>=1 && id<=11) {
             res = this->fight(oppo);
           
             if(!res) {this->lastKnight()->setHp(-1);Knightnum--;}
            //  if(Knightnum<=0) {
            //      this->printInfo();
            //      return false;
             
            //  break;}
            //  continue;}
            
        }
        else if(id>=95 && id<=97) this->Collect(id);
        else if(id>=112 && id<=114) this->CollectPhoe(id);
        else if(id==98){
            if(this->hasGuinevereHair()&&this->hasLancelotSpear()&&this->hasPaladinShield()){
                this->ExcaliburSword = true;
            }
        }else if(id == 99){
            all = this->fightUltimecia();
        }
        if(Knightnum>0) {
            this->printInfo();
        }
        else if(!all||Knightnum<0) {
            this->printInfo();
            return false;
        }
    }
    return all;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure() {
    armyKnights = nullptr;
    events = nullptr;
}
KnightAdventure::~KnightAdventure(){
    // if(armyKnights!=NULL) delete armyKnights;
    // if(events !=NULL) delete events;
}
void KnightAdventure::loadArmyKnights(const string &file){
      armyKnights = new ArmyKnights(file);
}
void KnightAdventure::loadEvents(const string &file){
    events = new Events(file);
}
void KnightAdventure::run(){
    if(events!=NULL && armyKnights!=NULL){
        bool result = armyKnights->adventure(events);
        armyKnights->printResult(result);
    }
}
/* * * END implementation of class KnightAdventure * * */
