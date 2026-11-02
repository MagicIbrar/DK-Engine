#!/bin/sh
# NOT RUN. Applies the staged spawn filters to an A2 server folder.
# Usage: sh apply.sh /path/to/dekaron_serverfiles_action2_hellspider
# Each original is kept as <file>.orig (an existing .orig is never overwritten).
# Takes effect only after the A2 game/channel server is restarted.
set -e
S="$1"; [ -d "$S/share/map" ] || { echo "usage: sh apply.sh SERVER_DIR"; exit 1; }
cd "$(dirname "$0")/staged"
for f in */mon_*.csv; do
  t="$S/share/map/$f"
  [ -f "$t.orig" ] || cp -p "$t" "$t.orig"
  cp "$f" "$t"; echo "patched $f"
done
