# !/bin/bash

. D:/CodeSnippet/shellscript/func1.sh

func1 "1" "2" "3"

SCRIPT_NAME=$(basename "$0" .sh)

echo ${SCRIPT_NAME}