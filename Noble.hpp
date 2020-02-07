//
//  Noble.hpp
//  hw07
//
//  Created by Ethan Yao on 4/22/19.
//  Copyright © 2019 Ethan Yao. All rights reserved.
//

#ifndef Noble_hpp
#define Noble_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

namespace WarriorCraft
{
    //noble header file
    class Protector;
    
    //highest inheritance noble class
    class Noble
    {
    public:
        Noble(const string& name);
        
        string getName() const;
        
        bool isDead() const;
        
        void setDead(bool death);
        
    private:
        string name;
        bool dead = false;
    };
    
    //personwithstrength subclass of noble
    class PersonWithStrengthToFight: public Noble
    {
    public:
        
        PersonWithStrengthToFight (const string& name, int strength);
        
        void battle(PersonWithStrengthToFight& opponent);
        
        int getStrength() const;
        
        void setPower(int newStrength);
        
        void noise() const;
        
    private:
        int strength;
    };
    
    //lord subclass of noble
    class Lord: public Noble
    {
    public:
        Lord(const string& name);
        
        void hires(Protector& protector_name);
        
        void fire(Protector& protector_name);
        
        void display() const;
        
        void battle(PersonWithStrengthToFight& person_name);
        
        void battle(Lord& opponent_name);
        
        int getPower();
        
    private:
        vector<Protector*> army; //vector of lord's army
        int strength;
    };
}

#endif /* Noble_hpp */
