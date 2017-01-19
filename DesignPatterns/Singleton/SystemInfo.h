#ifndef SINGLETON_SYSTEMINFO_H_
#define SINGLETON_SYSTEMINFO_H_

#define NUM_REG 5

namespace singleton {
namespace systeminfo {

class SystemInfo {
  private:
    // s_instance is the static variable that will hold the instance
    // for this singleton class. Note how it is declared private and
    // static.
    static SystemInfo* s_instance;
    bool out_of_date;
    int registers[NUM_REG];


    SystemInfo(const SystemInfo&); //Don't allow copy constructor.
    void operator=(const SystemInfo&); //Don't allow the assignment operator.

    SystemInfo() {
        std::fill_n(registers, NUM_REG, 0);
        out_of_date = true;
    }

    ~SystemInfo() {
        s_instance = NULL;
    }


  public:
    // It will only return the instance to singleton class. No new instance is
    // created.
    static SystemInfo* GetInstance() {
        if (!s_instance) {
            std::cout << "Creating the UNIQUE instance of SystemInfo." << std::endl;
            s_instance = new SystemInfo();
        }
        std::cout << "Instance of SystemInfo returned" << std::endl;
        return s_instance;
    }

    void UpdateRegisters(int *regs) {
        if (out_of_date) {
            //Generate random data simulating that are values provided by cpu.
            for (int i = 0; i < NUM_REG; i++) {
                registers[i] = regs[i];
            }
            std::cout << "Registers updated." << std::endl;
        } else {
            std::cout << "Registers already up to date." << std::endl;
        }
    }

    void PrintRegisters() {
        for (int i = 0; i < NUM_REG; i++)
            std::cout << "Reg[" << i << "]: " << registers[i] << std::endl;
    }

    void SetUpdate() {
        out_of_date = true; //The registers need to be updated.
    }
};

}
}
#endif
