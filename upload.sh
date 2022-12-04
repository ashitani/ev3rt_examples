#!/bin/bash
ip=10.0.10.1
from="app"
to=$1
curl -f --noproxy "*" -H "Content-Type: ev3rt/app" -H 'Content-Disposition: inline; filename="'${to}'"' --data-binary @${from} http://${ip}/upload > /dev/null
