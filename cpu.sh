#!/usr/bin/env sh

cpu_usage() {

   cpu_0=$(conky -qdc /path/to/conky.conf)

   echo -n "$cpu_0"
}

echo $(cpu_usage)
