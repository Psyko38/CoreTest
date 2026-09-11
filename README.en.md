# CoreTest

This is a proof-of-concept project to test the idea of a mini OS called Core, designed to run on an M5 Cardputer ADV with an ESP32-S3.

This repository is not a finished project and it does not include a provided build. It is meant to validate whether the design theory works before moving to a more structured system: driver management, screen management, and eventually a more complete environment.

## Project goal

The main goal is to validate the architectural foundation of an embedded mini OS, starting with the most essential building blocks:

- keyboard drivers
- screen drivers
- modular code organization
- feasibility study on real hardware

The basic idea is to test the core building blocks before building a larger system.

## Current state

### ✅ Done

- keyboard driver initialization
- reading keyboard state
- detecting changes and pressed keys
- basic handling of Backspace, Enter, and text input
- displaying entered text on the screen

### 🔜 Next step

- screen driver initialization
- abstraction of display primitives
- window / text area / basic UI handling

### ❌ Not planned for now

- Wi-Fi
- Bluetooth
- network management
- advanced system services

## Why this project exists

This project acts as a testing laboratory to validate whether the “Core” architecture is viable before continuing toward a complete mini OS.

In other words:

- this is not the real OS yet
- this is not a final build
- this is the experimental ground before the real base system

## Tech stack

- PlatformIO
- Arduino Framework
- M5Cardputer library
- ESP32-S3
- M5 Cardputer ADV

## Prerequisites

- PlatformIO installed
- VS Code with the PlatformIO extension
- M5 Cardputer ADV connected
- USB drivers for ESP32-S3 depending on your operating system

## Quick start

1. Open the project in VS Code.
2. Check the configuration in `platformio.ini`.
3. Build and upload the firmware:

```bash
pio run -t upload
```

4. If needed, open the serial monitor:

```bash
pio device monitor
```

## Project structure

```text
CoreTest/
├── include/
├── lib/
├── src/
│   ├── main.cpp
│   └── driver/
│       └── keyboard/
│           ├── KeyboardDriver.h
│           └── KeyboardDriver.cpp
├── compile_commands.json
├── platformio.ini
├── README.md
├── README.en.md
└── test/
```

## Important files

- `src/main.cpp`: main program loop, component initialization, and display logic
- `src/driver/keyboard/KeyboardDriver.h`: keyboard driver interface
- `src/driver/keyboard/KeyboardDriver.cpp`: keyboard driver implementation
- `platformio.ini`: build configuration for the target board

## Roadmap

### Step 1 — base system

- [x] keyboard init
- [ ] screen init
- [ ] driver abstraction
- [ ] basic text rendering / UI

### Step 2 — extensions

- [ ] Wi-Fi
- [ ] Bluetooth
- [ ] system services
- [ ] first application modules

## Design note

The project follows an incremental progression model:

1. test a driver in isolation
2. verify the behavior on real hardware
3. structure the code cleanly
4. move to the next layer

This allows validation of assumptions without jumping directly into a complete mini OS, while avoiding wasted effort on features that are not yet necessary.

## License

This is a testing and design-research project, without any final publication goal or final build for the moment.
