# #!/bin/bash

echo "this is func1.sh"

func1() {
    shift
    shift
    echo "this is func1() and the param is ${1}"
}