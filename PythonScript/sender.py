import dbus

print("Hello Crushnik!")
session_bus = dbus.SessionBus()
#names = session_bus.list_names()
#for service in names:
#    print(service)

dbus_object = session_bus.get_object('org.freedesktop.DBus',
                                     '/org/freedesktop/DBus')
dbus_iface = dbus.Interface(dbus_object, 'org.freedesktop.DBus')
services = dbus_iface.ListNames()
services.sort()
for service in services:
    print(service)