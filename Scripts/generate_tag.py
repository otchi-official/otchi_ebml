#!/usr/bin/env python3

import argparse
import sys
import datetime
import os

parser = argparse.ArgumentParser(description="Generate a new tag for the ebml parser")
parser.add_argument("file_name", help="The name for the file to be created")
parser.add_argument("tag_name")
parser.add_argument("tag_id")
parser.add_argument("path")
parser.add_argument("-d", "--description", default="")
parser.add_argument("-t", "--type", choices=['i', 'u', 'd', 's', '8', 'D', 'm', 'b'], default="m")
parser.add_argument("-u", "--username", default="Jorge Paravicini")
parser.add_argument("-o", "--orgname", default="Otchi Org")
parser.add_argument("-n", "--namespace", default="otchi_ebml")
parser.add_argument("-p", "--file_path", default="include/otchi_ebml/tags/")
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

header_map = {
    "i": "int.h",
    "u": "uint.h",
    "d": "double.h",
    "s": "string.h",
    "8": "utf8.h",
    "D": "date.h",
    "m": "master.h",
    "b": "binary.h"
}

header = f"otchi_ebml/elements/ebml_element_{header_map[args.type]}"

if not args.file_name.endswith(".h"):
    args.file_name += ".h"

if not args.file_path.endswith("/"):
    args.file_path += "/"

file_path = f"{args.file_path}{args.file_name}"

args.file_name = args.file_name[:-2]
header_guard = f"INCLUDE_OTCHI_EBML_{args.file_name.upper()}_H"
content = f"" \
          f"//\n" \
          f"// Created by {args.username} on {datetime.date.today()}\n" \
          f"// Copyright (c) {datetime.date.today().year} {args.orgname}. All Rights reserved\n" \
          f"//\n" \
          f"\n" \
          f"#ifndef {header_guard}\n" \
          f"#define {header_guard}\n" \
          f"\n" \
          f"#include \"{header}\"\n" \
          f"\n" \
          f"namespace {args.namespace} {{\n" \
          f"\n"\
          f"    constexpr EBMLId {args.tag_name} = {args.tag_id};\n" \
          f"\n" \
          f"    class {args.tag_name} : public EBMLElement<EBMLType::{type_map[args.type]}> {{\n" \
          f"    public:\n" \
          f"        using EBMLElement<EBMLType::{type_map[args.type]}>::EBMLElement;\n" \
          f"\n" \
          f"        [[nodiscard]] std::string getName() const override {{\n" \
          f"            return {args.tag_name};\n" \
          f"        }}\n" \
          f"\n" \
          f"        [[nodiscard]] EBMLId getId() const override {{\n" \
          f"            return {args.tag_name};\n" \
          f"        }}\n" \
          f"\n" \
          f"        [[nodiscard]] EBMLPath getPath() const override {{\n" \
          f"            return EBMLPath(\"{args.path}\";\n" \
          f"        }}\n" \
          f"\n" \
          f"        [[nodiscard]] std::string getDescription() const override {{\n" \
          f"            return \"{args.description}\";\n" \
          f"        }}\n" \
          f"    }};\n" \
          f"\n" \
          f"    class {args.tag_name}Factory : public IEBMLElementFactory {{\n" \
          f"    public:\n" \
          f"        EBMLBaseElement *create(EBMLSize idSize, EBMLSize dataSize, EBMLSize dataContentSize,\n" \
          f"                                EBMLPosition position) override {{\n" \
          f"            return new {args.tag_name}(idSize, dataSize, dataContentSize, position);\n" \
          f"        }}\n" \
          f"    }};\n" \
          f"}}\n" \
          f"\n" \
          f"#endif //{header_guard}\n"


if not os.path.isfile(file_path):
    f = open(file_path, "x")
    f.write(content)
    f.close()
