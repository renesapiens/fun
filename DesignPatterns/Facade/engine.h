#ifndef FACADE_ENGINE_H //The format of the symbol name should be <PROJECT>_<PATH>_<FILE>_H_
#define FACADE_ENGINE_H
#include "car.h"

namespace facade {
namespace car {

class Engine {
  private:
    std::string description;
    bool state;

    Engine(const Engine&);
    void operator=(const Engine&);

  public:
    Engine(std::string desc, bool status) :
            description(desc), state(status) {
    }

    void start() const {
        std::cout << description << " Starting engine" << std::endl;
    }
    void stop() const {
        std::cout << description << " Turning off the engine" << std::endl;
    }
    void turn_on_pistons() const {
        std::cout << description << " Turning on pistons" << std::endl;
    }
    void save_energy() const {
        std::cout << description << " Entering save mode." << std::endl;
    }
};
}
}
#endif
