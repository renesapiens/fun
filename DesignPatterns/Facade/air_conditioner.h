#ifndef FACADE_AIR_CONDITIONER_H_
#define FACADE_AIR_CONDITIONER_H_

#include "car.h"

namespace facade {
namespace car {

class AirConditioner {
  private:
    bool state;
    int temperature;

    AirConditioner(const AirConditioner&);
    void operator=(const AirConditioner&);

  public:
    AirConditioner(int temp, bool on_off) :
                  state(on_off), temperature(temp) {
    }

    void turn_on() {
        std::cout << "Turning on air conditioner" << std:: endl;
        state = true;
    }

    void turn_off() {
        std::cout << "Turning off air conditioner" << std::endl;
        state = false;
    }

    void set_temperature(int temp) {
        std::cout << "Setting air conditioner temperature to: " << temp << std::endl;
        temperature = temp;
    }
};
}
}
#endif
