//
//  Protector.hpp
//  hw07
//
//  Created by Ethan Yao on 4/22/19.
//  Copyright © 2019 Ethan Yao. All rights reserved.
//

//header file for Protector and protector subclasses
#ifndef Protector_hpp
#define Protector_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;

namespace WarriorCraft
{
    class Lord;
    
    //Highest protector class
    class Protector{
    public:
        Protector (const string& name, int strength);
        
        string getName() const;
        
        int getPower() const;
        
        void setStrength(int newStrength);
        
        void setEmployed(bool boolean);
        
        bool isEmployed() const;
        
        void setEmployer(Lord* employer);
        
        string getEmployer() const;
        
        void runaway();
        
        virtual void noise() const = 0;
        
    private:
        string name;
        int strength;
        bool employed;
        Lord* employer;
    };
    
    //Subclass warrior for protector
    class Warrior : public Protector{
    public:
        Warrior (const string& name, int strength);
        
        void noise() const;
    };
    
    
    //subclass wizard for protector
    class Wizard : public Protector{
    public:
        Wizard (const string& name, int strength);
        
        void noise() const;
    };
    
    
    //subclass archer for warrior
    class Archer : public Warrior{
    public:
        Archer (const string& name, int strength);
        
        void noise() const;
    };
    
    
    //subclass swordsman for warrior
    class Swordsman : public Warrior{
    public:
        Swordsman (const string& name, int strength);
        
        void noise() const;
    };
}

#endif /* Protector_hpp */
