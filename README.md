# Otchi EBML Parser

This library is a lightweight EBML Parser, it is focused on parsing Matroska files but can be
used to parse any valid EBML file.

**It is still under development**

The Otchi Video Player takes use of this library to stream its torrent files.

## Usage

To use the library make sure all tags are implemented first, take a look at the already
implemented tags under include/otchi_ebml/tags. Each possible tag needs its own class to work.
All Matroska Tags are already implemented.

To use the parser just create a new parser element and call the `parse` function.

```C++
using namespace otchi_ebml;
auto parser = EBMLParser("test1.mkv");
auto elements = parser.parse();
```

To print the ebml content print each value:

```C++
for (auto element : elements) {
    element->print();
}
```