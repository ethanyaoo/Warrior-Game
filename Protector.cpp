//
//  Protector.cpp
//  hw07
//
//  Created by Ethan Yao on 4/22/19.
//  Copyright © 2019 Ethan Yao. All rights reserved.
//

#include "Protector.hpp"
#include "Noble.hpp"

namespace WarriorCraft
{
    //cpp file for protector
    //initializes protector class
    Protector::Protector (const string& name, int strength) : name(name),
    strength(strength), employed(false) {}
    
    //get name function for protector
    string Protector::getName() const
    {
        return name;
    }
    
    //returns strength of protector
    int Protector::getPower() const
    {
        return strength;
    }
    
    //sets strength of protector
    void Protector::setStrength(int newStrength)
    {
        strength = newStrength;
    }
    
    //sets bool of whether protector is employed or not
    void Protector::setEmployed(bool boolean)
    {
        employed = boolean;
    }
    
    //returns whether protector is employed or not
    bool Protector::isEmployed() const
    {
        return employed;
    }
    
    //sets the employer of the protector
    void Protector::setEmployer(Lord* warr_employer)
    {
        employer = warr_employer;
    }
    
    //returns name of employer
    string Protector::getEmployer() const
    {
        return employer -> getName();
    }
    
    //function that allows protector to runaway
    void Protector::runaway()
    {
        cout << name << " flees in terror, abandoning his lord, " << employer->getName();
        employer -> fire(*this);
        setEmployer(nullptr);
        setEmployed(false);
        
    }
    
    //noise produced by each protector
    void Protector::noise() const
    {
    }
    
    //constructor for warrior subclass
    Warrior::Warrior (const string& name, int strength) : Protector(name, strength) {}
    
    //returns warrior sound
    void Warrior::noise() const
    {
        cout << getName() << " says: Take that in the name of my lord, " << Protector::getEmployer();
    }
    
    //constructor for wizard subclass
    Wizard::Wizard (const string& name, int strength) : Protector(name, strength) {}
    
    //returns wizard sound
    void Wizard::noise() const
    {
        cout << "POOF! ";
    }
    
    //constructor for archer subsubclass
    Archer::Archer (const string& name, int strength) : Warrior(name, strength) {}
    
    //returns archer noise
    void Archer::noise() const
    {
        cout << "TWANG!  ";
        Warrior::noise();
    }
    
    //constructor for swordsman subsubclass
    Swordsman::Swordsman (const string& name, int strength) : Warrior(name, strength) {}
    
    //returns swordsman noise
    void Swordsman::noise() const
    {
        cout << "CLANG!  ";
        Warrior::noise();
    }

}
