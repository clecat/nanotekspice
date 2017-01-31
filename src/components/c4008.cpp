#include "c4008.hpp"

namespace nts
{
    c4008::c4008()
    {
        this->pins[0].setMode(nts::Pin::I);
        this->pins[1].setMode(nts::Pin::I);
        this->pins[2].setMode(nts::Pin::I);
        this->pins[3].setMode(nts::Pin::I);
        this->pins[4].setMode(nts::Pin::I);
        this->pins[5].setMode(nts::Pin::I);
        this->pins[6].setMode(nts::Pin::I);
        this->pins[8].setMode(nts::Pin::I);
        this->pins[9].setMode(nts::Pin::O);
        this->pins[10].setMode(nts::Pin::O);
        this->pins[11].setMode(nts::Pin::O);
        this->pins[12].setMode(nts::Pin::O);
        this->pins[13].setMode(nts::Pin::O);
        this->pins[14].setMode(nts::Pin::I);
    }

    nts::Tristate c4008::Compute(std::size_t pin_num_this)
    {
        if (pin_num_this < 1 || pin_num_this > 16)
            return (UNDEFINED);
        pin_num_this--;
        if (this->pins[pin_num_this].getMode() == Pin::I)
            return (this->pins[pin_num_this].compute());
        else
        {
            Tristate A = this->pins[5].compute();
            Tristate B = this->pins[6].compute();
            Tristate C = this->pins[8].compute();
            Tristate XOR = (A || B) && !(A && B);
            if (pin_num_this == 9)
                return ((XOR || C) && !(XOR && C));
            C = (A && B) || (A && C) || (B && C);
            A = this->pins[3].compute();
            B = this->pins[4].compute();
            XOR = (A || B) && !(A && B);
            if (pin_num_this == 10)
                return ((XOR || C) && !(XOR && C));
            C = (A && B) || (A && C) || (B && C);
            A = this->pins[1].compute();
            B = this->pins[2].compute();
            XOR = (A || B) && !(A && B);
            if (pin_num_this == 11)
                return ((XOR || C) && !(XOR && C));
            C = (A && B) || (A && C) || (B && C);
            A = this->pins[14].compute();
            B = this->pins[0].compute();
            XOR = (A || B) && !(A && B);
            if (pin_num_this == 12)
                return ((XOR || C) && !(XOR && C));
            return ((A && B) || (A && C) || (B && C));
        }
    }

    void c4008::SetLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target)
    {
        if (pin_num_this < 1 || pin_num_this > 16)
            return ;
        pin_num_this--;
        this->pins[pin_num_this].setComponent(component);        
        this->pins[pin_num_this].setTarget(pin_num_target);        
    }

    void c4008::Dump(void) const
    {
        std::cout << "Chipset 4008" << std::endl;
    }

    c4008::~c4008(void)
    {
    }
}