f = open("tags", "r")
f2 = open("tags2", "w")
inicio = 'cout<<'

for x in f:
    if len(x) > 1:
        string = repr(x).replace('"','"<<"')
        f2.write(inicio + string.replace("'",'"')+ ";" + '\n')
        print(inicio + string.replace("'",'"')+ ";")
        



f.close()
f2.close()

