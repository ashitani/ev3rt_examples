#!/bin/sh
docker compose exec ev3dev bash -c "cd /ev3rt/hrp3/sdk/ev3rt_examples;make app="$1
