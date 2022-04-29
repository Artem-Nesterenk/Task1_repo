#ifndef SENDER_H
#define SENDER_H
#include <mqueue.h>
#include <stdint.h>

void set_sender_allowence_ro_run(uint8_t allowence);

void sender_thread(void);
#endif // SENDER_H
