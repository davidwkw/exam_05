#ifndef WARLOCK_HPP
# define WARLOCK_HPP

#include <string>
#include <iostream>
#include <map>
#include <utility>
#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock 
{
    private:
        std::string name;
        std::string title;
        std::map<std::string, ASpell *> memory;

        Warlock();
        Warlock(const Warlock &ref);
        Warlock &operator=(const Warlock &ref);

    public:
        Warlock(const std::string name, const std::string title);
        ~Warlock();

        const std::string &getName() const;
        const std::string &getTitle() const;

        void setTitle(const std::string &title);
        void introduce() const;

        void learnSpell(ASpell *spell);
        void forgetSpell(const std::string &spellName);
        void launchSpell(const std::string &spellName, ATarget &target);
};

#endif