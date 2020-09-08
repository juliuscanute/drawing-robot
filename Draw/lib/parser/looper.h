#ifndef LOOPER_H_INCLUDED
#define LOOPER_H_INCLUDED
#include "arduino.pb.h"
#include "encoder.h"
#include "decoder.h"
enum action {ACTION1, ACTION2, ACTION3};
action read_input();
Message process_action(action read_action);
bool send_output(Message *message);
void looper();
#endif