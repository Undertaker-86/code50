from fuel import convert
from fuel import gauge
import pytest

def test_convert():
    assert convert("1/2") == 50
    with pytest.raises(ValueError):
        convert("3/1")
    with pytest.raises(ZeroDivisionError):
        assert convert("1/0") == ZeroDivisionError

def test_gauge():
    assert gauge(100) == "F"
    assert gauge(99) == "F"
    assert gauge(0) == "E"
    assert gauge(1) == "E"
    assert gauge(50) == "50%"