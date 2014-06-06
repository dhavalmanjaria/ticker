ticker
======

This is a ticker primarily to be used for Conky. But hopefully it can be used in other places as well.

### test.c

This is a file that tests how we can get the output of i3status from
stdin.

### test2.c

This file tests how we can append our own string to i3status' output
that we recieve, and output that as a whole.

### readFile.c

Readfile is a simple function to get data from the TODO file and store
it in temp. Eventually the string that we return from readFile, will
be appended to the i3status output as shown in test.c and we'll have
something to work with there.

### main.c

This file is deprecated.
