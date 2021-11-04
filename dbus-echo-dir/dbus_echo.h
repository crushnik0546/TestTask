#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dbus/dbus.h>

const char *object_interface = "tt.test.testName";
const char *object_path = "/tt/test/testName";
const char *send_method_name = "Send";

void check_and_abort(DBusError *error);
DBusHandlerResult dbus_process_message(DBusConnection *connection, DBusMessage *message, void *user_data);
void send_method(DBusConnection *connection, DBusMessage *message);