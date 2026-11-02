#!/bin/sh
# Restores every share/map/*/mon_*.csv.orig written by apply.sh.
S="$1"; [ -d "$S/share/map" ] || { echo "usage: sh revert.sh SERVER_DIR"; exit 1; }
for o in "$S"/share/map/*/mon_*.csv.orig; do [ -f "$o" ] && mv "$o" "${o%.orig}" && echo "restored ${o%.orig}"; done
