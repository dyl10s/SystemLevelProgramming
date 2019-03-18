#command line args / positional parameters ($0, $1, $2, $3 ...)
echo
echo this is command line arg 0: $0
echo this is command line arg 1: $1
echo this is command line arg 2: $2
echo this is command line arg 3: $3
echo
# $# is the count, $* (List of stings) or $@ (1 big string) show all args
echo There are $# command line args total
echo All Args: $@

set this is a new value
echo 'Setting new args'
echo new args: $@
echo 'Shifting'
shift
echo After shift: $@
