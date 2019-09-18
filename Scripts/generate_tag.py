#!/usr/bin/env python3

import argparse
import sys

parser = argparse.ArgumentParser(description="Generate a new tag for the ebml parser")
parser.add_argument("file_name", help="The name for the file to be created")
parser.add_argument("class_name", help="The name for the class to be created")
parser.add_argument("--type", choices=['i', 'u', 'd', 's', '8', 'D', 'm', 'b'], default="m")
parser.add_argument("-u", "--username", default="Jorge Paravicini")
parser.add_argument("-o", "--orgname", default="Otchi Org")
parser.add_argument("-n", "--namespace", default="otchi_ebml")
args = parser.parse_args(sys.argv[1:])

type_map = {
    "i": "kSInt",
    "u": "kUInt",
    "d": "kDouble",
    "s": "kString",
    "8": "kUTF8",
    "D": "kDate",
    "m": "kMaster",
    "b": "kBinary"
}

