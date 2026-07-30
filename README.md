# MCAL Driver 
MCAL Driver is device drivers for MCU. The objective is to standardize driver function header across multiple porjects. 

This driver structure should
- Have unit testing to support TDD
- Able to build, compile & run using MCU or Linux/WSL
- Be use as static library

---

## Project Setup 

| Month    | Tools | Platform | Version |
| - | - | - | - |
| IDE | Vscode | Windows | v1.130.0 |
| Debug Server | GDB Server | Ubuntu/WSL | v1.0.1 |
| Debugger | STlink | Windows | - |
| Unit Test | Ceedling | Ubuntu/WSL | v1.0.1 |

## Folder Structure

```bash
├── build
│   └── mcal
├── CAN
│   ├── inc
│   └── src
├── UART
│   ├── inc
│   └── src
├── unittest
│   ├── config
│   ├── MCU
│   └── test
│       ├── can
│       │   └── test_can.c
│       ├── uart
│       │   └── test_can.c
│       └── support
│       
├── project.yml
└── README.md
```
| Folder    | Description |
| - | - |
|`build/`|Generated build artifacts and intermediate files created during compilation of unit test.|
|`CAN/`,`UART/`|Device driver implementations. Each driver contains<br> `inc/` directory for public header files <br> `src/` directory for source code implementation.|
|`unittest/`|Unit test environment and test cases for validating device drivers.<br> `config/mixins/` Ceedling configuration files, mixins, mocks, and unit test settings. Contain project setting for each device drivers<br> `MCU/` MCU-specific stubs, fake HAL implementations, and hardware abstraction used during unit testing.<br> |
|`unittest/test/`|Contains all unit test source files organized by driver. <br>`can/` , `uart/` Unit tests for the device driver.<br> `support/`Shared helper functions, utilities, and custom assertions used by multiple test suites.|
|`project.yml`|Main Ceedling project configuration file defining build options, source paths, include paths, compiler settings, plugins, and test configuration.|
|`README.md`|Project documentation, usage instructions, folder structure, build steps, and testing guidelines.|

 


