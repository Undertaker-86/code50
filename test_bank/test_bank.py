from bank import value

def test_value():
    assert value("hello") == 0
    assert value("Hello") == 0
    assert value("Harry") == 20
    assert value("Ohayo") == 100
    assert value("Hello, Zesiro") == 0