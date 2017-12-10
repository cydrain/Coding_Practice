import string

def check_conflict(sec_word, dict_word, encode_table = {}, decode_table = {}):
    word_len = len(sec_word)
    conflict = 0
    for i in range(word_len):
        if (decode_table.has_key(sec_word[i])):
            if (decode_table[sec_word[i]] != dict_word[i]):
                conflict = 1
                break
        else:
            decode_table[sec_word[i]] = dict_word[i]

        if (encode_table.has_key(dict_word[i])):
            if (encode_table[dict_word[i]] != sec_word[i]):
                conflict = 1
                break
        else:
            encode_table[dict_word[i]] = sec_word[i]
    return conflict

# get the list of words which match the pattern of sec_word
def word_match(sec_word, dictionary):
    #print "sec_word =", sec_word
    word_len = len(sec_word)
    match_list = []
    encode_table = {}
    decode_table = {}
    for dict_word in dictionary[word_len]:
        #print "dict_word =", dict_word
        if (not check_conflict(sec_word, dict_word, encode_table, decode_table)):
            match_list.append(dict_word)
        encode_table.clear()
        decode_table.clear()
    #print "match_list =", match_list
    return match_list

def msg_match(sec_words, dictionary, ml=[]):
    #print "sec_words =", sec_words
    for i in range (len(sec_words)):
        ml.append(word_match(sec_words[i], dictionary))

# iterate all permutations 
def all_perms(n, ml, state=()):
    for i in range(len(ml[n-1])):
        if (n == 1):
            yield (ml[n-1][i],)
        else:
            for result in all_perms(n-1, ml, state+(ml[n-1][i],)):
                yield result + (ml[n-1][i],)

# among all of the permutations, the one with no conflict is the solution
def decode_secret(sec_words, dictionary):
    #print "sec_words =", sec_words
    ml = []
    msg_match(sec_words, dictionary, ml)
    decode_table = {}
    encode_table = {}
    for solution in list(all_perms(len(ml), ml)):
        conflict = 0
        for i in range(len(sec_words)):
            if (check_conflict(sec_words[i], solution[i], encode_table, decode_table)):
                conflict = 1
                break
        if (not conflict):
            return solution
        #print "decode_table =", decode_table
        #print "encode_table =", encode_table
        decode_table.clear()
        encode_table.clear()

def pretty_print(sec_words, solution):
    word_num = len(sec_words)
    for i in range(word_num):
        print sec_words[i],
    print '=',
    for i in range(word_num):
        if (i == word_num-1):
            print solution[i]
        else:
            print solution[i],
    #print '\n'
    
is_dict = 0
is_secret = 0
dictionary = {}
secret = []
match_list_all = []

#fp = open(sys.argv[1], 'r')
fp = open("input00.txt", 'r')
for line in fp.readlines():
    word = line.strip()
    #print "word = ", word
    if (len(word) == 0):
        break
    if (word == '//dict'):
        is_dict = 1
        is_secret = 0
        #print "start record dict"
    elif (word == '//secret'):
        is_dict = 0
        is_secret = 1
        #print "start record secret"
    else:
        if (is_dict == 1):
            word_len = len(word)
            if (dictionary.has_key(word_len)):
                dictionary[word_len].append(word)
            else:
                dictionary[word_len] = []
                dictionary[word_len].append(word)
            #print directory
        if (is_secret == 1):
            secret.append(string.split(word))
#print dictionary
#print secret

for i in range(len(secret)):
    pretty_print(secret[i], decode_secret(secret[i], dictionary))
