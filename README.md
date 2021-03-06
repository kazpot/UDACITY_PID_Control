# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

---

## Introduction

The purpose of this project is to build PID controller and tune the hyperparameters. 
The built solution was tested on the simulater provided by Udacity. 
The simulator sends cross-track error (CTE), speed, and steering angle to the PID contoller via tiny websocket. 
The goal is to reliabliy run the car on the simulater by contollling steering angle and throttle using the PID controller. 

## Rubic Discussion

* Describe the effect each of the P, I, D components had in your implementation

  * P (Proportional) eror is proportional to the cross-track error (CTE). 
 It makes car quickly react to the CTE. If the car runs on far rihght, it makes it turns to the left sharply to bring the car to the center line and vice versa. 
 Increasing the weight Kp enables car to react quickly to the CTE, but the car might tend to oscillate and overshoot.
 So only increasing Kp might lead to unstable run. 

  * D (Differential) error is proportional to the change of CTE. 
  It makes car react to the overshoot caused by increasing Kp weight and ease the overshoot.
  The proper Kd weight will control car to the center line very smoothly. 

  * I (Integral) error is proportional to the integral of CTE. The constant error that accumulates as car runs. 
  It prevents the constant error from accumurating and enables car to run in the stable state for a while. 

* Describe how the final hyperparameters were chosen
  * I tuned parameters manually. I first set Kp value and zero to Ki and Kd for observing its behavior. 
  Increasing Kp makes high reaction to CTE so car stars circling and doesn't run straight. 
  So I decreased Kp to get proper value, but car still oscillates strongly and overshoots at the curve.
  Secondly I set Kd value and start increasing this value until the oscillation is reduced properly.
  This enables car to run in stable state, but car couldn't react to the sharp turn. 
  I increased gradually Kp and Kd value until the car runs on the track reliably and react to the sharp turn. 
  Thirdly I set tiny value to Ki and increased little by little until car runs on the track reliably in the most stable state. 
  The final values used by my implementation are: Kp = 0.16, Ki = 0.0005, and Kd = 0.5.
   

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets) == 0.13, but the master branch will probably work just fine
  * Follow the instructions in the [uWebSockets README](https://github.com/uWebSockets/uWebSockets/blob/master/README.md) to get setup for your platform. You can download the zip of the appropriate version from the [releases page](https://github.com/uWebSockets/uWebSockets/releases). Here's a link to the [v0.13 zip](https://github.com/uWebSockets/uWebSockets/archive/v0.13.0.zip).
  * If you run OSX and have homebrew installed you can just run the ./install-mac.sh script to install this
* Simulator. You can download these from the [project intro page](https://github.com/udacity/CarND-PID-Control-Project/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`. 

## Editor Settings

We've purposefully kept editor configuration files out of this repo in order to
keep it as simple and environment agnostic as possible. However, we recommend
using the following settings:

* indent using spaces
* set tab width to 2 spaces (keeps the matrices in source code aligned)

## Code Style

Please (do your best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Project Instructions and Rubric

Note: regardless of the changes you make, your project must be buildable using
cmake and make!

More information is only accessible by people who are already enrolled in Term 2
of CarND. If you are enrolled, see [the project page](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/f1820894-8322-4bb3-81aa-b26b3c6dcbaf/lessons/e8235395-22dd-4b87-88e0-d108c5e5bbf4/concepts/6a4d8d42-6a04-4aa6-b284-1697c0fd6562)
for instructions and the project rubric.

## Hints!

* You don't have to follow this directory structure, but if you do, your work
  will span all of the .cpp files here. Keep an eye out for TODOs.

## Call for IDE Profiles Pull Requests

Help your fellow students!

We decided to create Makefiles with cmake to keep this project as platform
agnostic as possible. Similarly, we omitted IDE profiles in order to we ensure
that students don't feel pressured to use one IDE or another.

However! I'd love to help people get up and running with their IDEs of choice.
If you've created a profile for an IDE that you think other students would
appreciate, we'd love to have you add the requisite profile files and
instructions to ide_profiles/. For example if you wanted to add a VS Code
profile, you'd add:

* /ide_profiles/vscode/.vscode
* /ide_profiles/vscode/README.md

The README should explain what the profile does, how to take advantage of it,
and how to install it.

Frankly, I've never been involved in a project with multiple IDE profiles
before. I believe the best way to handle this would be to keep them out of the
repo root to avoid clutter. My expectation is that most profiles will include
instructions to copy files to a new location to get picked up by the IDE, but
that's just a guess.

One last note here: regardless of the IDE used, every submitted project must
still be compilable with cmake and make./

## Alternative way to build
g++ -o pid PID.cpp PID.h json.hpp main.cpp -std=c++11 -luWS -luv -lz -lssl
