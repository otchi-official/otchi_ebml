from bs4 import BeautifulSoup
import os

bs = BeautifulSoup(open('Scripts/ebml_matroska.xml'), "html.parser")
elements = bs.find_all('element')

for element in elements:
    name = element['name']
    path = element['path']
    id_ = element['id']
    t = element['type']
    type_map = {
        "integer": "i",
        "uinteger": "u",
        "float": "d",
        "string": "s",
        "utf-8": "8",
        "date": "D",
        "master": "m",
        "binary": "b"
    }
    t = type_map[t]
    os.system(f"python Scripts/generate_tag.py {name.lower()} {name} {id_} {path} -t {t}")
