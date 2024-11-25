## Determine what the default values for the WAKE_EN, SLEEP_EN, and ENABLE registers are.
* WAKE_EN =0x1
* SLEEP_EN =0x1
* ENABLE =0x0


## Measure the power consumption of the following scenarios:

### Blinking with sleep_ms:
* vsupply: 4.992 v
* csupply: 21.9 mA

### Blinking with vtask_delay
* csuply: 21.6 mA
* vsupplky: 4.99 v

### Blinking with busy loop
* vsupply: 4.99
* csupply: 22 mA 

### Blinking with external signal generator interrupt
#### 1MHz
* vsupply: 4.99
* csupply: 27.8 mA

#### 1 kHz.
* vsupply: 4.99
* csupply: 25.41 mA

#### 10 kHz.
* vsupply: 4.99
* csupply: 25.78 mA

#### Sleep Mode.
* vsupply: 4.99
* csupply: 11.8 mA when awake & 3.7 mA when sleeping 

#### Dormant Mode.
* vsupply: 4.99
* csupply: 11.8 mA when awake & 2.88 mA when sleeping 