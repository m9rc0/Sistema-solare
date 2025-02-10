./main.exe

gawk '/Sun/ {print $2" "$3" "$4}' simulazione.txt > Sun.txt
gawk '/Mercury/ {print $2" "$3" "$4}' simulazione.txt > Mercury.txt
gawk '/Venus/ {print $2" "$3" "$4}' simulazione.txt > Venus.txt
gawk '/Earth/ {print $2" "$3" "$4}' simulazione.txt > Earth.txt
gawk '/Moon/ {print $2" "$3" "$4}' simulazione.txt > Moon.txt
gawk '/Mars/ {print $2" "$3" "$4}' simulazione.txt > Mars.txt
gawk '/Jupiter/ {print $2" "$3" "$4}' simulazione.txt > Jupiter.txt
gawk '/Saturn/ {print $2" "$3" "$4}' simulazione.txt > Saturn.txt
gawk '/Uranus/ {print $2" "$3" "$4}' simulazione.txt > Uranus.txt
gawk '/Neptune/ {print $2" "$3" "$4}' simulazione.txt > Neptune.txt
gawk '/Pluto/ {print $2" "$3" "$4}' simulazione.txt > Pluto.txt
