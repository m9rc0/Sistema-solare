# Sistema-solare
Simulazione di un sistema solare


Per ora utilizzo pattern composite per la struttura del sistema solare, più una classe evolve per aggiornare lo stato del sistema.

Pattern strategy implementata ma per semplicità ancora si utilizza una dinamica "seriale", non sono ancora riuscito a farla diventare "sincrona"

Per le condizioni iniziali dei pianeti si prova a tenere conto della inclinazione dell'orbita, ma con un modello molto semplice, in cui tutte le ellissi sono inizialmente orientate nello stesso verso e in modo che le rotazioni siano semplici da fare. 

I dati sono presi dal sito della [NASA](https://nssdc.gsfc.nasa.gov/planetary/factsheet/)

Dati più precisi sono sul [sito](https://ssd.jpl.nasa.gov/horizons/)
