#ifndef PRU_LOADER_NCLUDED
#define PRU_LOADER_INCLUDED

int pru_init(void);
void pru_load(int, char*, char*);
void pru_stop(int PRU_NUM);
int read_int(int32_t*, size_t);
int write_int(int32_t*, size_t);

#endif /* PRU_LOADER_INCLUDED */
