#ifndef FACADE_CAR_FACADE_H_
#define FACADE_CAR_FACADE_H_

#include "car.h"

namespace facade {
namespace car {

class CarFacade {
  private:
    Engine* eng;
    Radio* radio;
    AirConditioner* ac;
    Lights* lights;

    CarFacade(const CarFacade&);
    void operator=(const CarFacade&);

  public:
    CarFacade(Engine *e, Radio* r, AirConditioner* Ac, Lights* l) :
                eng(e), radio(r), ac(Ac), lights(l) {
    }

    void start_car() {
        eng->start();
        lights->turn_on();
        lights->turn_on_front_lights();
        lights->turn_on_back_lights();
        ac->turn_on();
        ac->set_temperature(77);
        radio->turn_on();
        radio->set_frequency(100.1);
        radio->set_volume(10);
    }

    void stop_car() {
        radio->turn_off();
        lights->turn_off();
        lights->turn_off_front_lights();
        lights->turn_off_back_lights();
        ac->turn_off();
        eng->stop();
    }

    void start_radio(double frequency, int volume) {
        radio->turn_on();
        radio->set_volume(volume);
        radio->set_frequency(frequency);
    }
};

}
}
#endif
