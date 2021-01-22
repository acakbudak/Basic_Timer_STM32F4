# Basic_Timer_STM32F4

  ##A simple implemention of timers on STM32F446RE.  
  ##uVision5 used 
  (!ATTENTION!)Keil's own STM32F4 MCU specific header file used 
-------------------------------------------------------------
  ## Defining Prescaler and Auto-Reload Register values for calculating dedicated interrupt time
    time = (bus_clk_value)/((PSC+1)*(ARR+1))
