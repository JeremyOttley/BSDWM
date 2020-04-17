#!/usr/local/bin/bash

SONG=`ncmpcpp --current-song -q`
echo "${SONG}"
