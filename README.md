# Sugar

Sugar was designed as a session manager started by a display manager, providing a graphical command shell and full-screen window manager.  This is how Sugar is deployed on children's laptops and desktop computers.  Examples are OLPC OS, Fedora SoaS, and Debian SugarBlend.

# Sugar Runner

Sugar Runner is for running Sugar as an application inside a desktop environment.  It provides a desktop menu item and icon.

You can run it from a text console or from inside another X session. By default it runs in fullscreen but you can specify the window size using the --resolution option.

# Precautions

Sugar Runner should not be used with naive learners, as they may escape from Sugar and do harm to the outer system.

Sugar Runner should not be used by testers, as the testing will miss critical aspects of the session interaction, such as shutdown and restart.

# How It Works

* unsets variables inherited from the existing session,
* substitutes an alternate home directory for XDG data,
* turns off the Sugar shutdown and restart options,
* forks Xvfb with Xephyr.

# How To Build And Test

./autogen.sh

make

sudo make install

## You will need to install Xephyr:

sudo dnf install Xephyr

## Set up some environment variables:

export GI_TYPELIB_PATH=/usr/local/lib/girepository-1.0

export LD_LIBRARY_PATH=/usr/local/lib:$LD_LIBRARY_PATH

## Then run:

sugar-runner

At this time all that will happen is Xephyr tries to open and fails.
