ticker
======

This is a ticker program that displays a file line by line in the
i3status bar.

### Usage:

~~~~
bar {
        status_command i3status -c ~/.i3status.conf | /path/to/ticker /path/to/TODO
		mode dock
		tray_output primary 
}
~~~~

In your i3config for the stauts bar section, pipe the output of
i3status to the ticker executable and you'll see each line of the file
you specify after it tick by in your status bar. This is mostly useful
for TODOs and reminders, I find.



