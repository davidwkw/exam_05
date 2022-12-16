#include "ATarget.hpp"

ATarget::ATarget() : type()
{

}

ATarget::ATarget(const std::string type) : type(type)
{

}

ATarget::ATarget(const ATarget &ref) : type(ref.type)
{
    *this = ref;
}

ATarget &ATarget::operator=(const ATarget &ref)
{
    this->type = ref.type;
    return *this;
}

ATarget::~ATarget()
{

}

const std::string &ATarget::getType() const
{
    return this->type;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << this->type << " has been " << spell.getEffects() << "!" << std::endl;
}
