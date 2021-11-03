import dbus

session_bus = dbus.SessionBus()
# names = session_bus.list_names()
# for service in names:
#    print(service)
dbus_object = session_bus.get_object("tt.test.testName", "/tt/test/testName")

dbus_object.Send("Hello, world!", dbus_interface = "tt.test.testName")

print("Message sent")
