from twttr import shorten

def test_shorten():
    assert shorten("twitter") == "twttr"
    assert shorten("Twitter") == "Twttr"
    assert shorten("hello world") == "hll wrld"
    assert shorten("Gets desire") == "Gts dsr"
    assert shorten("HELLO WORLD") == "HLL WRLD"
    assert shorten("10 digit") == "10 dgt"
    assert shorten("Nozonda, sekai") == "Nznd, sk"