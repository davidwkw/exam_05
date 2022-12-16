#ifndef ASPELL_HPP
# define ASPELL_HPP

#include <string>
#include <iostream>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
    protected:
        std::string name;
        std::string effects;
    public:
        ASpell();
        ASpell(const std::string name, const std::string effects);
        ASpell(const ASpell &ref);
        ASpell &operator=(const ASpell &ref);
        virtual ~ASpell();

        const std::string getName() const;
        const std::string getEffects() const;
        virtual ASpell *clone() = 0;

        void launch(const ATarget &target) const;
};

#endif