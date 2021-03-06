#include "Variables.h"
#include "Configuration.h"
#include "Datatypes.h"

//this is the version of our host software
unsigned int host_version = 0;

//are we paused?
bool is_machine_paused = false;
bool is_machine_aborted = false;

//how many queued commands have we processed?
//this will be used to keep track of our current progress.
unsigned long finishedPoints = 0;
uint8_t commandMode = COMMAND_MODE_IDLE;
