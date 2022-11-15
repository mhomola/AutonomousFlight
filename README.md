
# Autonomous Vision-based Flight 

This remote was used for code development and testing throughout the entire project. Iti is based on the paparazzi/tudelft remote and it uses the exact same folder structure.


All our _C/Cpp_ files are all under:
>sw/airborne/modules

- orange_avoider_group11

- course_CV

  - size_divergence.c
  - opticflow_calculator.c

- dynamic_window_navigation

- computer_vision

  - floor_detecion.x

The *Python* code for *obstacle avoidence ROC analysis* and *optical flow sensitivity analysis* can be found on the CV_dev branch. They are kep separtae for better integration during hardware testing.


**Heads-up!** To print more informative messages in the Paparazzi Ground station, one file in telemetry was adjsuted. That file is not automatically tracked byt git but it is tracked in our project. Hence, all our changes are up-to-date. If that still produces a compiler error, feel free to disable the message. 




# Paparazzi README



[![Build Status](https://travis-ci.org/paparazzi/paparazzi.png?branch=master)](https://travis-ci.org/paparazzi/paparazzi) [![Gitter chat](https://badges.gitter.im/paparazzi/discuss.svg)](https://gitter.im/paparazzi/discuss)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/811c4398588f435fa8bc926f53d40e9f)](https://app.codacy.com/app/gautierhattenberger/paparazzi?utm_source=github.com&utm_medium=referral&utm_content=paparazzi/paparazzi&utm_campaign=Badge_Grade_Dashboard)
<a href="https://scan.coverity.com/projects/paparazzi-paparazzi">
  <img alt="Coverity Scan Build Status"
       src="https://scan.coverity.com/projects/4928/badge.svg"/>
</a>

Paparazzi is a free open source software package for Unmanned (Air) Vehicle Systems.
For many years, the system has been used successfuly by hobbyists, universities and companies all over the world, on vehicles of various sizes (11.9g to 25kg).
Paparazzi supports fixed wing, rotorcraft, hybrids, flapping vehicles and it is even possible to use it for boats and surface vehicles.

Up to date information is available on the wiki http://wiki.paparazziuav.org

To get in touch, subscribe to the mailing list [paparazzi-devel@nongnu.org] (http://savannah.nongnu.org/mail/?group=paparazzi), the IRC channel (freenode, #paparazzi) and Gitter (https://gitter.im/paparazzi/discuss).

Required software
-----------------

Instructions for installation can be found on the wiki (http://wiki.paparazziuav.org/wiki/Installation).

For Ubuntu users, required packages are available in the [paparazzi-uav PPA] (https://launchpad.net/~paparazzi-uav/+archive/ppa),
Debian users can use the [OpenSUSE Build Service repository] (http://download.opensuse.org/repositories/home:/flixr:/paparazzi-uav/Debian_7.0/)

Debian/Ubuntu packages:
- **paparazzi-dev** is the meta-package on which the Paparazzi software depends to compile and run the ground segment and simulator.
- **paparazzi-jsbsim** is needed for using JSBSim as flight dynamics model for the simulator.

Recommended cross compiling toolchain: https://launchpad.net/gcc-arm-embedded


Directories quick and dirty description:
----------------------------------------

_conf_: the configuration directory (airframe, radio, ... descriptions).

_data_: where to put read-only data (e.g. maps, terrain elevation files, icons)

_doc_: documentation (diagrams, manual source files, ...)

_sw_: software (onboard, ground station, simulation, ...)

_var_: products of compilation, cache for the map tiles, ...


Compilation and demo simulation
-------------------------------

1. type "make" in the top directory to compile all the libraries and tools.

2. "./paparazzi" to run the Paparazzi Center

3. Select the "Microjet" aircraft in the upper-left A/C combo box.
  Select "sim" from upper-middle "target" combo box. Click "Build".
  When the compilation is finished, select "Simulation" from
  the upper-right session combo box and click "Execute".

4. In the GCS, wait about 10s for the aircraft to be in the "Holding point" navigation block.
  Switch to the "Takeoff" block (lower-left blue airway button in the strip).
  Takeoff with the green launch button.

Uploading the embedded software
----------------------------------

1. Power the flight controller board while it is connected to the PC with the USB cable.

2. From the Paparazzi center, select the "ap" target, and click "Upload".


Flight
------

1.  From the Paparazzi Center, select the flight session and ... do the same as in simulation !

