#include "Save.hpp"

void save(const std::string &file, std::vector<nts::IComponent *> components)
{
    std::ofstream save(file + ".nts");

    save << ".chipsets:" << std::endl;
    for (auto it = components.begin(); it != components.end(); ++it)
        save << dynamic_cast<nts::AComponent *>(*it)->save() << std::endl;
    save << std::endl << ".links:" << std::endl;
    for (auto it = components.begin(); it != components.end(); ++it)
        save << *dynamic_cast<nts::AComponent *>(*it)->save_pins() << std::endl;
}