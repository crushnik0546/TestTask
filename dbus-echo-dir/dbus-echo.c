#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus.h>

const char *object_interface = "tt.test.testName";
const char *send_method = "Send";

void check_and_abort(DBusError *error);
DBusHandlerResult dbus_process_message(DBusConnection *connection, DBusMessage *message, void *user_data);
 
int main() {
    DBusConnection *connection = NULL;
    DBusError error;
    char buffer[1024];
    DBusObjectPathVTable vtable;
 
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
    check_and_abort(&error);

    dbus_bus_request_name(connection, object_interface, DBUS_NAME_FLAG_REPLACE_EXISTING, &error);
    check_and_abort(&error);

    dbus_connection_try_register_object_path(connection, "/tt/test/testName", &vtable, NULL, &error);
    check_and_abort(&error);

    while (dbus_connection_read_write_dispatch(connection, -1))
 
    // puts("This is my unique name");
    // puts(dbus_bus_get_unique_name(connection));
    fgets(buffer, sizeof(buffer), stdin);
     
    return 0;
}

void check_and_abort(DBusError *error) {
    if (dbus_error_is_set(error)) {
        puts(error->message);
        abort();
    }
}

DBusHandlerResult dbus_process_message(DBusConnection *connection, DBusMessage *message, void *user_data)
{
    char *message_interface = dbus_message_get_interface(message);
    char *method_name = dbus_message_get_member(message);

    if ((0 == strcmp(message_interface, object_interface)) && (0 == strcmp(method_name, send_method)))
    {
        send(connection, message);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
}

void send(DBusConnection *connection, DBusMessage *message)
{

}