#ifndef FACADE_RADIO_H_
#define FACADE_RADIO_H_

#include "car.h"

namespace facade {
namespace car {

class Radio {
  private:
    double frequency;
    bool current_state;
    int volume;
    
    Radio(const Radio &);
    void operator=(const Radio &);

  public:
    Radio(double freq, bool state) :
            frequency(freq), current_state(state) {
    }

    void show_station() const {
        std::cout << "Listening to: " << frequency << std::endl;
   }

   void turn_on() {
       std::cout << "Turning on the radio." << std::endl;
       current_state = true;
   }

   void turn_off() {
       std::cout << "Turning off the radio." << std::endl;
       current_state = false;
   }

   void set_volume(int vol) {
       std::cout << "Setting the radio volume to: " << vol << std::endl;
       volume = vol;
   }

   void set_frequency(double freq) {
       std::cout << "Setting the frequency to: " << frequency << std::endl;
       frequency = freq;
    }
};
}
}
#endif
