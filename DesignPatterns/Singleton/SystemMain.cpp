#include "Registers.h"

using namespace singleton::systeminfo;

// Global static pointer used to ensure a single instance of the class.
SystemInfo* SystemInfo::s_instance = 0;

int main() {
    int regs[NUM_REG];
    SystemInfo* current_info = SystemInfo::GetInstance();

    srand(time(NULL));
    //Fill in random data to simulate register values.
    for (int i = 0; i < NUM_REG; i++) {
        regs[i] = rand() % 1000;
        std::cout << "Value to save = " << regs[i] << std::endl;
    }

    // Let's try to get an instance of the SystemInfo.
    // Observe how we get the same instance as for current_info.
    SystemInfo* current_info2 = SystemInfo::GetInstance();

    if (current_info == current_info2)
        std::cout << "Correct: Same instance obtained!" << std::endl;
    else
        std::cout << "Error:  we got a different instance!"<< std::endl;
    // Observe how we use either current_info or current_info2 indistinctly
    // and we still get the same results, since we have the same instance of
    // SystemInfo class.
    current_info->SetUpdate();
    current_info2->UpdateRegisters(regs);
    current_info->PrintRegisters();

    return 0;
}
