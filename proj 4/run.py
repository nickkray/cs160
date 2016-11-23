from subprocess import *
import os
FNULL = open(os.devnull, 'w')
BAD_LOCATION = "tests/bad_tests/"
GOOD_LOCATION = "tests/good_tests/"
keys = {2: ['no main'],
        3: ['the Main procedure has arguments'],
        4: ['duplicate procedure names in same scope'],
        5: ['duplicate variable names in same scope'],
        6: ['call to undefined procedure'],
        7: ['undefined variable'],
        8: ['procedure call has different number of args than declartion'],
        9: ['argument type mismatch'],
        10: ['type mismatch in return statement'],
        11: ['type mismatch in procedure call args'],
        12: ['predicate of if statement is not boolean'],
        13: ['predicate of while statement is not boolean'],
        14: ['array index not integer'],
        15: ['attempt to index non-array variable'],
        16: ['type of expr and var do not match in assignment'],
        17: ['incompatible types used in expression', 'absolute value can only be applied to integers and strings'],
        18: ['invalid pointer arithmetic'],
        19: ['AddressOf can only be applied to integers, chars, and indexed strings'],
        20: ['Deref can only be applied to integer pointers and char pointers'],
        }

list_process = Popen(["ls", BAD_LOCATION], stdout=PIPE)
out = [(int(p.split('_')[0]), p) for p in list_process.communicate()[0].split('\n')[:-1] ]

bad_total = len(out)
bad_success = bad_total
for test in out:
    cat_process = Popen(["cat", BAD_LOCATION+test[1]], stdout=PIPE)
    csimple = Popen(["./csimple"], stdin=cat_process.stdout, stderr=PIPE, stdout=FNULL)
    o, err = csimple.communicate()

    found = False
    for string in keys[test[0]]:
        if string in err:
            found = True
    if found == False:
        bad_success-=1
        print "File: ", test
        print "Err: ", err,
        print "Err: ", keys[test[0]]
        print "Out: ", o
        print "\n\n\n"



list_process = Popen(["ls", GOOD_LOCATION], stdout=PIPE)
out = list_process.communicate()[0].split('\n')[:-1]

good_total = len(out)
good_success = good_total
for test in out:
    cat_process = Popen(["cat", GOOD_LOCATION+test], stdout=PIPE)
    csimple = Popen(["./csimple"], stdin=cat_process.stdout, stderr=PIPE, stdout=FNULL)
    o, err = csimple.communicate()

    if err:
        good_success-=1
        print "File: ", test
        print "Err: ", err,
        print "Out: ", o
        print "\n\n\n"


print "Good tests: ", good_success, "/", good_total
print "Bad tests: ", bad_success, "/", bad_total
