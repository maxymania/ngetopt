# ngetopt
ngetopt, a getopt like function, little more fancy.

# NAME
ngetopt - get commandline options

# SYNOPSIS

```
#include <ngetopt.h>

int ngetopt(int argc,const char* const* argv,const char* desc);

const char* noptarg;
int noptind;

```

# DESCRIPTION

The `ngetopt()` function parses the command-line arguments. Its arguments
`argc` and `argv` are the argument count and array as passed to the main()
function, as well as a string with the legitimate characters. If one of those
characters is followed by an ':'-character, it is interpreted as an
requirement for an parameter.

The varible `noptind` is the index one ahead the next element to be processed,
except the next element to be processed does not start with `'-'`.

If the format `noptarg` contains the current option's argument, if this option
requires one.


# RETURN VALUE

If an option sucessfully found, then `ngetopt()` returns the option character.
If all command-line options have been parsed, then getopt returns -1. If a
non-defined option character was found, it returns '?' and prints an error
message to `stderr`.

# SEE ALSO

getopt(1)
