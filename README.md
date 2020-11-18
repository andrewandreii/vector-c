## C vectors

### Requirements for vector.c

`mcheck.h` - should be available on linux ([how to use mtrace?](https://en.wikipedia.org/wiki/Mtrace))

`stdio.h` `string.h` and `stdlib.h` - are most likely already on your machine

### How to test

```sh
source test
```

if you see just one memory leak everything is good

### How to build

to make the static library and the shared object:
```sh
make
```
to make the .so file:
```sh
make sharedobj
```
to make the .a file:
```sh
make staticlib
```

### How to use

the man page:
```sh
make manfile
man -l man/vector.1
```

## Example code
see in the directory `example`
