import os

base = 5
altezza = 10
risultato = 0
pid = os.fork()
if pid < 0:
  print ("ERRORE")
elif pid == 0:
  perimetro = (base + altezza) * 2
  print("PROCESSO FIGLIO,perimetro:", perimetro)
  os._exit(0)
else: 
  os.waitpid(pid, 0)
  area = base * altezza
  print("PROCESSO  PADRE, Area:", area)
