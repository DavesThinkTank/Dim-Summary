/**************************************************************************

Dim Summary: Arduino Version 2025.10 by Dave's Think Tank

  Version History
  
  Version: 2025.10 by Dave's Think Tank

  - Program tests the light-dimming feature of the RPU. Does it work with LEDs?

**************************************************************************/



#include "DimSummary.h"
#include "RPU_Config.h"
#include "RPU.h"

int  i, j, k;
byte DimIt = 0;
unsigned long CurrentTime = 0;
unsigned long NextTime = 0;

void setup() {
  // Set up the chips and interrupts
  RPU_InitializeMPU(RPU_CMD_BOOT_ORIGINAL_IF_CREDIT_RESET | RPU_CMD_BOOT_ORIGINAL_IF_NOT_SWITCH_CLOSED | RPU_CMD_PERFORM_MPU_TEST);
  RPU_DisableSolenoidStack();
  RPU_SetDisableFlippers(true);

  RPU_SetDisplay(0, 0, true, 2);
  RPU_SetDisplayBlank(1, 0x00);
  RPU_SetDisplayBlank(2, 0x00);
  RPU_SetDisplayBlank(3, 0x00);
}

void loop() {
  // This line has to be in the main loop
  RPU_DataRead(0);

  CurrentTime = millis();

  if (CurrentTime >= NextTime) {
    RPU_SetDisplay(0, DimIt, true, 2);
    for (i = 0; i < RPU_MAX_LAMPS; ++i) RPU_SetLampState(i, 1, DimIt, 0);
    if (++DimIt > 3) DimIt = 0;
    NextTime = CurrentTime + 1000;
  }

  RPU_ApplyFlashToLamps(CurrentTime);
  RPU_UpdateTimedSolenoidStack(CurrentTime);
}
