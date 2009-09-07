//this is the version of our host software
unsigned int host_version = 0;

//these are our packet classes
SimplePacket hostPacket(serial_tx);

//are we paused?
boolean is_machine_paused = false;
boolean is_machine_aborted = false;

//buffer for our commands
uint8_t underlyingBuffer[COMMAND_BUFFER_SIZE];
CircularBuffer commandBuffer(COMMAND_BUFFER_SIZE, underlyingBuffer);

//how many queued commands have we processed?
//this will be used to keep track of our current progress.
unsigned long finishedCommands = 0;
unsigned long finishedPoints = 0;
uint8_t commandMode = COMMAND_MODE_IDLE;

#ifdef USE_SD_CARD
//SD CARD STUFF.
RepRapSDCard card;
File f;
#endif

//our buffer of bytes.
#define BUFFSIZE 64
char buffer[BUFFSIZE];
byte bufferIndex = 0;
byte error = 0;