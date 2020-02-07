//
//  Noble.cpp
//  hw07
//
//  Created by Ethan Yao on 4/22/19.
//  Copyright © 2019 Ethan Yao. All rights reserved.
//

#include "Protector.hpp"
#include "Noble.hpp"

namespace WarriorCraft
{
    //constructor for Noble class
    Noble::Noble(const string& name) : name(name){}
    
    //gets name of noble
    string Noble::getName() const
    {
        return name;
    }
    
    //checks if noble is dead
    bool Noble::isDead() const
    {
        return dead;
    }
    
    //sets whether noble is dead or not
    void Noble::setDead(bool death)
    {
        dead = death;
    }
    
    //constructor for PersonwithStrength subclass
    PersonWithStrengthToFight::PersonWithStrengthToFight (const string& name,
                                                          int strength) : Noble::Noble(name), strength(strength) {}
    
    //sets strength of person
    void PersonWithStrengthToFight::setPower(int new_strength)
    {
        strength = new_strength;
    }
    
    //returns strength of person
    int PersonWithStrengthToFight::getStrength() const
    {
        return strength;
    }
    
    void PersonWithStrengthToFight::noise() const
    {
        cout << "UGH!!!" << endl;
    }
    
    //constructor for lord subclass
    Lord::Lord(const string& name) : Noble::Noble(name){}
    
    //hire function for lord
    void Lord::hires(Protector& protector){
        if ((protector.isEmployed() == false) || !(isDead()))
        {
            protector.setEmployed(true);
            protector.setEmployer(this);
            army.push_back(&protector);
        }
        else if (isDead())
        {
            cout << "";
        }
        else
        {
            cout << protector.getName() << " is already hired." << endl;
        }
    }
    
    //fire function for lord subclass
    void Lord::fire(Protector& protector)
    {
        size_t pos = 0;
        for (size_t i = 0; i < army.size(); i++)
        {
            if (army[i] == &protector)
            {
                pos = i;
                break;
            }
        }
        for (size_t j = pos; j < army.size() - 1; j++)
        {
            army[j] = army[j + 1];
        }
        protector.setEmployed(false);
        army.pop_back();
    }
    
    //display function for lord subcless
    void Lord::display() const
    {
        cout << getName() << " has an army of " << army.size() << endl;
        for (size_t i = 0; i < army.size(); i++)
        {
            cout << "\t" << army[i] -> getName() << ": " << army[i] -> getPower() << endl;
        }
    }
    
    int Lord::getPower()
    {
        int strength = 0;
        for (size_t i = 0; i < army.size(); i ++)
        {
            strength += army[i] -> getPower();
        }
        return strength;
    }
    
    //battle function for lord class against another lord
    void Lord::battle(Lord& enemy)
    {
        int strengthOne = 0;
        int strengthTwo = 0;
        string name = getName();
        string enemyName = enemy.getName();
        cout << name << " battles " << enemyName << endl;
        if (!isDead()) { //checks if dead then adds army if not
            strengthOne = getPower();
        }
        if (!enemy.isDead())
        { //checks if enemy is dead then adds army if not
            strengthTwo = enemy.getPower();
        }
        if (isDead() && enemy.isDead())
        { //if both dead
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
        }
        else if (isDead())
        { //if first is dead
            cout << "He's dead " << enemyName << endl;
        }
        else if (enemy.isDead())
        { //if enemy dead
            cout << "He's dead " << name << endl;
        }
        else if(strengthOne == strengthTwo)
        { //if strengths equal
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i]->setStrength(0);
                army[i] -> noise();
            }
            for (size_t i = 0; i < enemy.army.size(); i++)
            {
                enemy.army[i] -> setStrength(0);
                enemy.army[i] -> noise();
            }
            cout << "Mutual Annihalation: " << name << " and " << enemyName <<" die at each other's hands" << endl;
            enemy.setDead(true);
            setDead(true);
        }
        else if(strengthOne > strengthTwo)
        { //if army is stronger than enemy
            float ratio = 1 - (float)(strengthTwo/strengthOne);
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i] -> noise();
                army[i] -> setStrength((int)(army[i] -> getPower() * ratio));
            }
            for (size_t i = 0; i < enemy.army.size(); i++)
            {
                enemy.army[i] -> noise();
                enemy.army[i] -> setStrength(0);
            }
            cout << name << " defeats " << enemyName << endl;
            enemy.setDead(true);
        }
        else
        { //if enemy is stronger
            cout << enemyName << " defeats " << name << endl;
            float ratio = 1 - (float)(strengthOne/strengthTwo);
            for (size_t i = 0; i < enemy.army.size(); i++)
            {
                enemy.army[i] -> setStrength((int)(enemy.army[i] -> getPower() * ratio));
            }
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i] -> setStrength(0);
            }
            setDead(true);
        }
        
    }
    
    //battle function for lord against a person with strength
    //same as if battling another lord but no for loop to go through enemy army
    void Lord::battle(PersonWithStrengthToFight& enemy)
    {
        string name = getName();
        string enemyName = enemy.getName();
        cout << name << " battles " << enemyName << endl;
        int strengthOne = 0;
        int strengthTwo = enemy.getStrength();
        if (!isDead())
        {
            strengthOne = getPower();
            for (size_t i = 0; i < army.size(); i ++)
            {
                army[i]->noise();
                cout << endl;
            }
        }
        if (isDead() && enemy.isDead())
        {
            cout << "Oh, NO!  They're both dead!  Yuck!" << endl;
            setDead(true);
            enemy.setDead(true);
        }
        else if (enemy.isDead())
        {
            cout << "He's dead " << enemyName << endl;
            enemy.setDead(true);
        }
        else if (isDead())
        {
            cout << "He's dead " << enemyName << endl;
            setDead(true);
        }
        else if (strengthOne == strengthTwo)
        {
            enemy.noise();
            cout << "Mutual Annihalation: " << name << " and "
                << enemyName <<" die at each other's hands" << endl;
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i]->setStrength(0);
            }
            enemy.setPower(0);
            setDead(true);
            enemy.setDead(true);
        }
        else if(strengthOne > strengthTwo)
        {
            enemy.noise();
            cout << name << " defeats " << enemyName << endl;
            float ratio = 1 - (float)(strengthTwo/strengthOne);
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i] -> setStrength((int)(army[i] -> getPower() * ratio));
            }
            enemy.setDead(true);
        }
        else
        { //enemy stronger than first person
            enemy.noise();
            cout << enemyName << " defeats " << name << endl;
            float ratio = 1 - (float)(strengthOne/strengthTwo);
            enemy.setPower((int)(enemy.getStrength() * ratio));
            for (size_t i = 0; i < army.size(); i++)
            {
                army[i] -> setStrength(0);
            }
            setDead(true);
        }
    }
}
