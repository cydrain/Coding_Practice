from dict import dict

def lookup(dict, word):
    for type in dict:
        if word in dict[type]:
            return (type, word)
    return None

def scan(sentence):
    result = []
    words = sentence.split()
    for word in words:
        if word.isdigit():
            result.append(('number', int(word)))
        else:
            pair = lookup(dict, word)
            if not pair:
                result.append(('error', word))
            else:
                result.append(pair)
    return result

