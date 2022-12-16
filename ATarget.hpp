#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <string>
#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
    protected:
        std::string type;

    public:
        ATarget();
        ATarget(const std::string type);
        ATarget(const ATarget &ref);
        ATarget &operator=(const ATarget &ref);
        virtual ~ATarget();

        const std::string &getType() const;
        void getHitBySpell(const ASpell &spell) const;

        virtual ATarget *clone() = 0;
};

#endif