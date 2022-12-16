#include "Warlock.hpp"

Warlock::Warlock() : name(), title(){}
Warlock::Warlock(const Warlock &ref){
    *this = ref;
}

Warlock &Warlock::operator=(const Warlock &ref)
{
    this->name = ref.name;
    this->title = ref.title;
    return (*this);
}

Warlock::Warlock(const std::string name, const std::string title) : name(name), title(title)
{
    std::cout << this->name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
    std::map<std::string, ASpell *>::iterator it = this->memory.begin();
    std::map<std::string, ASpell *>::iterator ite = this->memory.end();
    while (it != ite)
    {
        delete it->second;
        ++it;
    }
    this->memory.clear();
    std::cout << this->name << ": My job here is done!" << std::endl;
}

const std::string &Warlock::getName() const
{
    return this->name;
}

const std::string &Warlock::getTitle() const
{
    return this->title;
}

void Warlock::setTitle(const std::string &title)
{
    this->title = title;
}

void Warlock::introduce() const
{
    std::cout << this->name << ": I am " << this->name << ", " << this->title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell != NULL)
        this->memory.insert(std::pair<std::string, ASpell *>(spell->getName(), spell));
}

void Warlock::forgetSpell(const std::string &spellName)
{
    std::map<std::string, ASpell *>::iterator it;
    it = this->memory.find(spellName);
    if (it != this->memory.end())
        delete it->second;
    this->memory.erase(spellName);
}

void Warlock::launchSpell(const std::string &spellName, ATarget &target)
{
    ASpell *spell = this->memory[spellName];
    if (spell != NULL)
        spell->launch(target);
}
