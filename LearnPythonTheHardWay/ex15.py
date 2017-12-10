from sys import argv

script, name1 = argv

file1 = open(name1);

print "Here's your file %r: " % name1
print file1.read()

while (True):
    print "Type the filename again:"
    name2 = raw_input("> ")
    if (name2 == 'exit'):
        break
    try:
        file2 = open(name2)
        print file2.read()
    except Exception, e:
        print e

