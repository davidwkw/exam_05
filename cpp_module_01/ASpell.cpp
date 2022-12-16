#include "ASpell.hpp"

ASpell::ASpell() : name(), effects()
{

}

ASpell::ASpell(const std::string name, const std::string effects) : name(name), effects(effects)
{

}

ASpell::ASpell(const ASpell &ref) : name(ref.name), effects(ref.effects)
{
    *this = ref;
}

ASpell &ASpell::operator=(const ASpell &ref)
{
    this->name = ref.name;
    this->effects = ref.effects;
    return *this;
}

ASpell::~ASpell(){

}

const std::string ASpell::getName() const
{
    return this->name;
}

const std::string ASpell::getEffects() const
{
    return this->effects;
}

void ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}
