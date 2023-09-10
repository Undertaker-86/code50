from plates import is_valid

def test_is_valid():
    assert is_valid("CS50") == True
    assert is_valid("01Test") == False
    assert is_valid("Alongonelikethis") == False
    assert is_valid("NS") == True
    assert is_valid("GZ03") == False
    assert is_valid("TI-39") == False
    assert is_valid("HE39HR") == False
    assert is_valid("@ABC") == False
    assert is_valid("C4") == False