import os
for path, subdirs, files in os.walk('.'):
    for name in files:
        if '.c' in name or '.cc' in name:
            if 'node_modules' not in path and '.css' not in name and 'unittest' not in name and 'xcode' in name:
                newName = os.path.join(path, name)
                newS = '../Horoscopes'+ newName[1:]
                print newS
