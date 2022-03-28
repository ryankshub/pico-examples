# Raspberry Pi Pico SDK Examples

This is a modified forked version of the Pico Examples. Please follow the guide in the pico-sdk for the [quardrature_endcoder](pio/quadrature_encoder) example. 

## Getting started

See [Getting Started with the Raspberry Pi Pico](https://rptl.io/pico-get-started) and the README in the [pico-sdk](https://github.com/raspberrypi/pico-sdk) for information
on getting up and running.

### CMake

App|Description
---|---
[build_variants](cmake/build_variants)| Builds two version of the same app with different configurations


### PIO

App|Description
---|---
[quadrature_encoder](pio/quadrature_encoder)| A quadrature encoder using PIO to maintain counts independent of the CPU. 


#### SDK build example 
App|Description
---|---
[dev_hid_composite](usb/device/dev_hid_composite) | A copy of the TinyUSB device example with the same name, but with a CMakeLists.txt which demonstrates how to add a dependency on the TinyUSB device libraries with the Raspberry Pi Pico SDK

#### Low Level example
App|Description
---|---
[dev_lowlevel](usb/device/dev_lowlevel) | A USB Bulk loopback implemented with direct access to the USB hardware (no TinyUSB)

### USB Host

All the USB host examples come directly from the TinyUSB host examples directory [here](https://github.com/hathach/tinyusb/tree/master/examples/host).
Those that are supported on RP2040 devices are automatically included as part of the pico-examples
build as targets named `tinyusb_host_<example_name>`, e.g. https://github.com/hathach/tinyusb/tree/master/examples/host/cdc_msc_hid
is built as `tinyusb_host_cdc_msc_hid`.

At the time of writing, there is only one host example available:

- tinyusb_host_cdc_msc_hid

### Watchdog

App|Description
---|---
[hello_watchdog](watchdog/hello_watchdog) | Set the watchdog timer, and let it expire. Detect the reboot, and halt.
