#ifndef FACADE_LIGHTS_H_
#define FACADE__LIGHTS_H_
#include "car.h"

namespace facade {
namespace car {

class Lights {
  private:
    std::string description;
    bool state;
    bool back_lights_state;
    bool front_lights_state;

    Lights(const Lights&);
    void operator=(const Lights&);

  public:
    Lights(std::string desc, bool curr_state) :
            description(desc), state(curr_state) {
    }

    void turn_on() {
        std::cout << description << "Turning on interior lights" << std::endl;
        state = true;
    }

    void turn_off() {
        std::cout << description << " Turning off interior lights" << std::endl;
        state = false;
    }

    void turn_on_back_lights() {
        std::cout << description << " Turning on back lights" << std::endl;
        back_lights_state = true;
    }

    void turn_on_front_lights() {
        std::cout << description << " Turning on front lights." << std::endl;
        front_lights_state = true;
    }

    void turn_off_front_lights() {
        std::cout << description << " Turning off front lights." << std::endl;
        front_lights_state = false;
    }

    void turn_off_back_lights() {
        std::cout << description << " Turning off back lights" << std::endl;
        back_lights_state = false;
    }
};

}
}
#endif
