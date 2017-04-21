#include "prussdrv.h"
#include "pruss_intc_mapping.h"
#include <stdint.h>

int pru_init(void)
{
	tpruss_intc_initdata pruss_intc_initdata = PRUSS_INTC_INITDATA;

	prussdrv_init();

	if (prussdrv_open(PRU_EVTOUT_0))
	{
		return -1;
	}
	else
	{
		prussdrv_pruintc_init(&pruss_intc_initdata);
		return 0;
	}
}

void pru_load(int pru_num, char* datafile, char* codefile)
{
	/* write data from data.bin */
	prussdrv_load_datafile(pru_num, datafile);				//DATA_FILE is defined in the build script

	/* execute code on pru0 */
	prussdrv_exec_program(pru_num, codefile);				//BIN_FILE is defined in the build script
}

void pru_stop(int pru_num)
{
	prussdrv_pru_disable(pru_num);
	prussdrv_exit();	
}

int read_int(int32_t* x, size_t offset)
{
	volatile int32_t* p;

	prussdrv_map_prumem(PRUSS0_SHARED_DATARAM, (void**)&p);

	x[0] = p[2048 + offset];
  
	return 0;
}


int write_int(int32_t* x, size_t offset)
{
	volatile int32_t* p;

	prussdrv_map_prumem(PRUSS0_SHARED_DATARAM, (void**)&p);

	p[2048 + offset] = x[0];

	return 0;
}
