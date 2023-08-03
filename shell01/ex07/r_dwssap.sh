cat /etc/passwd | cut -d ":" -f1 | sed -n '2~2p' | rev | sort -r | awk  "NR >= $FT_LINE1  && NR <= $FT_LINE2" | tr "\n" ",  " |  sed 's/,/, /g' | sed 's/, $/./'
