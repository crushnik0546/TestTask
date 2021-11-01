#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus.h>

void check_and_abort(DBusError *error);
 
int main() {
    DBusConnection *connection = NULL;
    DBusError error;
    char buffer[1024];
 
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
    check_and_abort(&error);
 
    puts("This is my unique name");
    puts(dbus_bus_get_unique_name(connection));
    fgets(buffer, sizeof(buffer), stdin);
     
    return 0;
}

void check_and_abort(DBusError *error) {
    if (dbus_error_is_set(error)) {
        puts(error->message);
        abort();
    }
}