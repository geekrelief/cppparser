#!/bin/bash

sed -i -e 's/\[ZZVALID;]/\/*[ZZVALID;]*\//g' -e 's/\(\[.*\]\)$/\/*&*\//g' -e 's/\(\[\)$/\/*&/g' -e 's/\(\]\)$/&*\//g' -e '290,1370s/\({\)$/\/*&/g' -e '290,1370s/\(^[ \t]*\}\)$/&*\//g' parser.y

