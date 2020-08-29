#include "Bus.h"

Bus::Bus() {
	//Clear the RAM
	for (auto& i : ram) i = 0x00;

	cpu.connectBus(this);
}

Bus::~Bus() {

}
void Bus::write(uint16_t addr, uint8_t data) {
	//Guard RAM out of bond
	if (addr >= 0x0000 && addr <= 0xFFFF)
		ram[addr] = data;
}

uint8_t Bus::read(uint16_t addr, bool bReadOnly) {
	if (addr >= 0x0000 && addr <= 0xFFFF)
		return ram[addr];
	return 0x00;
}