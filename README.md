# Sistema-solare
Simulazione di un sistema solare


Per ora utilizzo pattern composite per la struttura del sistema solare, più una classe evolve per aggiornare lo stato del sistema.

Pattern strategy implementata ma per semplicità ancora si utilizza una dinamica "seriale", non sono ancora riuscito a farla diventare "sincrona"


I dati sono presi dal sito della [NASA](https://nssdc.gsfc.nasa.gov/planetary/factsheet/)

Dati più precisi sono sul [sito](https://ssd.jpl.nasa.gov/horizons/)

Il risultato è:
![immagine](https://github.com/m9rc0/Sistema-solare/blob/main/SistemaSolare.png)

L'andamento del momento angolare del sistema utilizzando Runge-Kutta 2 è:
![immagine](https://github.com/m9rc0/Sistema-solare/blob/main/momentoAngolare.png)


Prossimi step sono:
- Aggiungere le lune su giove e analizzare il loro comportamento
- Provare a derivare da body una classe space-ship e cercare di raggiungere altri pianeti
- Aggiungere algoritmi di integrazione (possibilmente RK4 e verlet, magari anche qualcosa con adaptive stepsize)
