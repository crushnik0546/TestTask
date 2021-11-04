#include "dbus_echo.h"
 
int main() {
    DBusConnection *connection = NULL;
    DBusError error;
    DBusObjectPathVTable vtable;
 
    dbus_error_init(&error);
    connection = dbus_bus_get(DBUS_BUS_SESSION, &error);
    check_and_abort(&error);

    dbus_bus_request_name(connection, object_interface, DBUS_NAME_FLAG_REPLACE_EXISTING, &error);
    check_and_abort(&error);

    vtable.unregister_function = NULL;
    vtable.message_function = dbus_process_message;

    dbus_connection_try_register_object_path(connection, object_path, &vtable, NULL, &error);
    check_and_abort(&error);

    while (dbus_connection_read_write_dispatch(connection, -1));
 
    return 0;
}

void check_and_abort(DBusError *error) {
    if (dbus_error_is_set(error)) {
        puts(error->message);
        dbus_error_free(error);
        abort();
    }
}

DBusHandlerResult dbus_process_message(DBusConnection *connection, DBusMessage *message, void *user_data)
{
    const char *message_interface = dbus_message_get_interface(message);
    const char *method_name = dbus_message_get_member(message);

    if ((0 == strcmp(message_interface, object_interface)) && (0 == strcmp(method_name, send_method_name)))
    {
        send_method(connection, message);
        return DBUS_HANDLER_RESULT_HANDLED;
    }
    else
    {
        return DBUS_HANDLER_RESULT_NOT_YET_HANDLED;
    }
}

void send_method(DBusConnection *connection, DBusMessage *message)
{
    DBusError error;
    DBusMessage *reply;
    const char *reply_str = "This is reply from dbus-echo";
    char *message_arg_string;

    dbus_error_init(&error);

    dbus_message_get_args(message, &error, DBUS_TYPE_STRING, &message_arg_string, DBUS_TYPE_INVALID);
    check_and_abort(&error);
    puts(message_arg_string);
    
    reply = dbus_message_new_method_return(message);
    dbus_message_append_args(reply, DBUS_TYPE_STRING, &reply_str, DBUS_TYPE_INVALID);

    dbus_connection_send(connection, reply, NULL);

    dbus_message_unref(reply);
}