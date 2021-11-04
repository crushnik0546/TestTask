import dbus
import sys

if len(sys.argv) < 3:
    print("Not enough aeguments\nExample: ./sender.py send \"Hello world\"")
elif len(sys.argv) > 3:
    print("Too much arguments\nExample: ./sender.py send \"Hello world\"")
elif sys.argv[1] == "send":
    try:
        session_bus = dbus.SessionBus()
        dbus_object = session_bus.get_object("tt.test.testName", "/tt/test/testName")
        reply = dbus_object.Send(sys.argv[2], dbus_interface = "tt.test.testName")
        print(reply)
    except BaseException:
        print("Can not connect to dbus (tt.test.testName)")  
else:
    print("Undefind command \"" + sys.argv[1] + "\"\nExample: ./sender.py send \"Hello world\"")
