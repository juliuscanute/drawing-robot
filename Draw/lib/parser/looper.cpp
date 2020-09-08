#include <looper.h>
void looper() {
    action input_action = read_input();
    Message send_message = process_action(input_action);
    send_output(&send_message);
}