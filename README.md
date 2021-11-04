# TestTask

1. Write a small program on C or C++ that connects to dbus and listens for messages according to some interface and output those messages to stdout.
2. Write a small python script that when executed with some arguments sends a message to the program on C or C++ described above.

So in one terminal the program 1 runs like this: ./dbus-echo

In another terminal the script 2 runs like this: python sender.py send “Hello world!”

When the python script is executed, text “Hello world” appears in terminal where program 1 is running.