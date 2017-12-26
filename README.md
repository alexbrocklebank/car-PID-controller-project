# CarND-Controls-PID
Udacity Self-Driving Car Engineer Nanodegree Program

---

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `./install-mac.sh` or `./install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.
* Simulator. You can download these from the [project intro page](https://github.com/udacity/self-driving-car-sim/releases) in the classroom.

## Basic Build Instructions

1. Clone this repo.
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./pid`.

## PID Class

The PID class template was implemented in the existing code.  All I had to complete was the
implementation of `PID::Init()`, `PID::UpdateError()`, and `PID::TotalError()`.   These functions
initialize the variables, update them, and complete the PID controller equation respectively.

The equation that does all the work for the PID controller is simply:

 `total_error = -Kp * p_error - Ki * i_error - Kd * d_error;`

## Main

Most of the changes needed to this project in order to implement a PID controller was within
the `main.cpp` file.  Here I create two PID objects, one for steering and one for throttle
(to be implemented next).  Once I figured out that all I needed to do was update the `steer_value`
variable in order to steer the vehicle in the simulation, it was relatively easy to get it up and running.
The code actually only consists of two lines that perform this feat: `pid.UpdateError(cte);` and
`steer_value = pid.TotalError()`.  All the implementation is within the function itself.

## Parameterization

I modified and tested each of the parameters, `Kp`, `Ki`, and `Kd` by hand and reran the simulator,
modifying only one parameter at a time with each run either up or down.  The key was realizing
which parameters effected the different characteristics of the PID controller, such as instantaneous
change to gradual updates to the steering angle.  `Kp` seemed to greatly effect sudden steering
angle changes, while `Kd` seemed to modify gradual long term tweaks to the steering angle.
`Ki` made drastic changes to behavior with extremely tiny values.  My final values were:

* `Kp`: 0.13
* `Ki`: 0.0007
* `Kd`: 4.0

## Reflection

I do wish I could have implemented Twiddle and utilized it to fine-tune the parameters without having to do it all manually and by hand.  On top of this I could have used it to get the parameters for the throttle PID controller, but I ran out of time due to the tedious nature of manual parameterization.  However, I created a git branch for Twiddle implementation and will continue to work on it.  Once I can implement Twiddle I will also work on utilizing it on a throttle controller.
