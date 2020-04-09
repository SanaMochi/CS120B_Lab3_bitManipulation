# Test file for "Lab3_bitManipulation"


# commands.gdb provides the following functions for ease:
#   test "<message>"
#       Where <message> is the message to print. Must call this at the beginning of every test
#       Example: test "PINA: 0x00 => expect PORTC: 0x01"
#   checkResult
#       Verify if the test passed or failed. Prints "passed." or "failed." accordingly, 
#       Must call this at the end of every test.
#   expectPORTx <val>
#       With x as the port (A,B,C,D)
#       The value the port is epected to have. If not it will print the erroneous actual value
#   setPINx <val>
#       With x as the port or pin (A,B,C,D)
#       The value to set the pin to (can be decimal or hexidecimal
#       Example: setPINA 0x01
#   printPORTx f OR printPINx f 
#       With x as the port or pin (A,B,C,D)
#       With f as a format option which can be: [d] decimal, [x] hexadecmial (default), [t] binary 
#       Example: printPORTC d
#   printDDRx
#       With x as the DDR (A,B,C,D)
#       Example: printDDRB

echo ======================================================\n
echo Running all tests..."\n\n

# Example test:
#test "PINA: 0x00, PINB: 0x00 => PORTC: 0"
# Set inputs
#setPINA 0x00
#setPINB 0x00
# Continue for several ticks
#continue 2
# Set expect values
#expectPORTC 0
# Check pass/fail
#checkResult

# Add tests below

#Test 1 below min
test "PIND: 0x05 => PORTB: 0x00"
setPIND 0x05
continue 5
expectPORTB 0x00
checkresult

#Test 2 above max
test "PIND: 0x77 => PORTB: 0x02"
setPIND 0x77
continue 5
expectPORTB 0x02
checkresult


#Test 3 at max
test "PIND: 0x46 => PORTB: 0x02"
setPIND 0x46
continue 5
expectPORTB 0x02
checkresult

#Test 4 mid range
test "PIND: 0x0A => PORTB: 0x04"
setPIND 0x0A
continue 5
expectPORTB 0x04
checkresult

# Report on how many tests passed/tests ran
set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n