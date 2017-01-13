#include "car.h"

using namespace facade::car;


int main (int argc, char* argv[]) {

    std::unique_ptr<Engine> engine(new Engine("SUPER_CAR:", true));
    std::unique_ptr<Lights> lights(new Lights("Car lights", true));
    std::unique_ptr<Radio> radio(new Radio(103.3, true));
    std::unique_ptr<AirConditioner> air_conditioner(new AirConditioner(77, true));

    std::unique_ptr<CarFacade> car(new CarFacade(engine.get(), radio.get(),
                                 air_conditioner.get(), lights.get()));

    car->start_car();
    car->stop_car();

    return 0;
}
