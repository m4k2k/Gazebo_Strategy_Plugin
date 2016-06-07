#!/bin/sh

if [ -n "$DESTDIR" ] ; then
    case $DESTDIR in
        /*) # ok
            ;;
        *)
            /bin/echo "DESTDIR argument must be absolute... "
            /bin/echo "otherwise python's distutils will bork things."
            exit 1
    esac
    DESTDIR_ARG="--root=$DESTDIR"
fi

echo_and_run() { echo "+ $@" ; "$@" ; }

echo_and_run cd "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki_desktop/kobuki_dashboard"

# snsure that Python install destination exists
echo_and_run mkdir -p "$DESTDIR/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/install/lib/python2.7/dist-packages"

# Note that PYTHONPATH is pulled from the environment to support installing
# into one location when some dependencies were installed in another
# location, #123.
echo_and_run /usr/bin/env \
    PYTHONPATH="/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/install/lib/python2.7/dist-packages:/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/lib/python2.7/dist-packages:$PYTHONPATH" \
    CATKIN_BINARY_DIR="/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build" \
    "/usr/bin/python" \
    "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/src/kobuki_desktop/kobuki_dashboard/setup.py" \
    build --build-base "/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/build/kobuki_desktop/kobuki_dashboard" \
    install \
    $DESTDIR_ARG \
    --install-layout=deb --prefix="/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/install" --install-scripts="/home/ubu/Gazebo_Strategy_Plugin/turtle/kobiplug_overlay/install/bin"
