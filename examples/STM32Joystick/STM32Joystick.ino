#include <IBusBM.h>
#include <USBComposite.h>

USBHID HID;
HIDJoystick Joystick(HID);
IBusBM IBus;

void setup()
{
  IBus.begin(Serial);
  HID.begin(HID_JOYSTICK);
  Joystick.setManualReportMode(true);
}

void loop()
{
    Joystick.Y(map(IBus.readChannel(2), 1000, 2000, 1023, 0));
    Joystick.X(map(IBus.readChannel(1), 1000, 2000, 0, 1023));
    Joystick.Xrotate(map(IBus.readChannel(0), 1000, 2000, 0, 1023));
    Joystick.Yrotate(map(IBus.readChannel(3), 1000, 2000, 0, 1023));
    Joystick.button(1,IBus.readChannel(4) > 1800);
    Joystick.button(2,IBus.readChannel(5) > 1800);
    Joystick.send();
}
